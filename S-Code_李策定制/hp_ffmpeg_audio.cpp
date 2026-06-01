#include "hp_ffmpeg_audio.h"

#define MAX_AUDIO_FRAME_SIZE 192000

hp_ffmpeg_audio::hp_ffmpeg_audio(QWidget *parent) : QThread(parent)
{
    audio=NULL;

    player_index = 0;
    fastnum = 0;
    input_index = 0;
    lowoffset = 0;
    highoffset = 0;
    player_changeindex = false;
    player_fastspeed = false;

    player_status = statu_free;
}
void hp_ffmpeg_audio::hp_Audio_play(QString filePath)
{
    qDebug() << "--hp_ffmpeg_audio::play-- 音频路径 = " << filePath;
    filename = filePath;
    this->start();
}
bool hp_ffmpeg_audio::initAudio(int SampleRate)
{
    qDebug() << "--hp_ffmpeg_audio::initAudio-- 硬件采样率 = " << SampleRate;
    QAudioFormat format;

    if(audio!=NULL)
        return true;

    //MP4
//    format.setSampleRate(SampleRate);		//设置采样率
//    format.setChannelCount(2);		//设置通道数
//    format.setSampleSize(16);		//样本数据16位
//    format.setCodec("audio/pcm");		//播出格式为pcm格式
//    format.setByteOrder(QAudioFormat::BigEndian);  //默认小端模式
//    format.setSampleType(QAudioFormat::SignedInt);	//无符号整形数

    //avi
    format.setSampleRate(SampleRate);		//设置采样率
    format.setChannelCount(2);		//设置通道数
    format.setSampleSize(16);		//样本数据16位
    format.setCodec("audio/pcm");		//播出格式为pcm格式
    format.setByteOrder(QAudioFormat::LittleEndian);  //默认小端模式
    format.setSampleType(QAudioFormat::SignedInt);	//无符号整形数

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());	//选择默认输出设备

    if (!info.isFormatSupported(format))
    {
        qDebug()<<"输出设备不支持该格式，不能播放音频";
        return false;
    }

    audio = new QAudioOutput(format, this);

    audio->setVolume(1);//设置音量 0~1，默认1,声音太小了   0.1已经很小了，若设置比0.1更小则好的也听不见了   0.005更小，只有超高频才听得见

    audio->setBufferSize(100000);

    return true;
}
void hp_ffmpeg_audio::runAudio()
{
    AVFormatContext	*pFormatCtx;
    int				i, audioStream;
    AVCodecContext	*pCodecCtx;
    AVCodec			*pCodec;
    AVPacket		*packet;
    uint8_t			*out_buffer;
    AVFrame			*pFrame;
    int ret;
    uint32_t len = 0;
    int got_picture;
    int index = 0;
    int64_t in_channel_layout;
    struct SwrContext *au_convert_ctx;

    audio->stop();
    QIODevice*io = audio->start();

    FILE *pFile=fopen("1.pcm", "wb");
//    char url[]="test.avi";

    av_register_all();
    avformat_network_init();
    pFormatCtx = avformat_alloc_context();
    //Open
    if(avformat_open_input(&pFormatCtx,filename.toUtf8().data(),NULL,NULL)!=0){
        printf("Couldn't open input stream.\n");
        return;
    }
    // Retrieve stream information
    if(avformat_find_stream_info(pFormatCtx,NULL)<0){
        printf("Couldn't find stream information.\n");
        return;
    }
    // Dump valid information onto standard error
    av_dump_format(pFormatCtx, 0, filename.toUtf8().data(), false);

    // Find the first audio stream
    audioStream=-1;
    for(i=0; i < pFormatCtx->nb_streams; i++)
        if(pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_AUDIO){
            audioStream=i;
            break;
        }

    if(audioStream==-1){
        printf("Didn't find a audio stream.\n");
        return;
    }

    // Get a pointer to the codec context for the audio stream
    pCodecCtx=pFormatCtx->streams[audioStream]->codec;

    // Find the decoder for the audio stream
    pCodec=avcodec_find_decoder(pCodecCtx->codec_id);
    if(pCodec==NULL){
        printf("Codec not found.\n");
        return;
    }

    // Open codec
    if(avcodec_open2(pCodecCtx, pCodec,NULL)<0){
        printf("Could not open codec.\n");
        return;
    }

    packet=(AVPacket *)av_malloc(sizeof(AVPacket));
    av_init_packet(packet);

    //Out Audio Param
    uint64_t out_channel_layout=AV_CH_LAYOUT_STEREO;
    //nb_samples: AAC-1024 MP3-1152
    int out_nb_samples=pCodecCtx->frame_size;
    AVSampleFormat out_sample_fmt=AV_SAMPLE_FMT_S16;
    int out_sample_rate=8000;
    int out_channels=av_get_channel_layout_nb_channels(out_channel_layout);//获取通道数，个人理解，就是同时有个几个设备在进行音频的采样，这样对上面的公式更好理解，最少为1，一般通道数越多，音质越好。
    //Out Buffer Size
    int out_buffer_size=av_samples_get_buffer_size(NULL,out_channels ,out_nb_samples,out_sample_fmt, 1);//获取 一帧 音频数据 占用的字节大小

    out_buffer=(uint8_t *)av_malloc(MAX_AUDIO_FRAME_SIZE*2);
    pFrame=av_frame_alloc();

    //FIX:Some Codec's Context Information is missing
    in_channel_layout=av_get_default_channel_layout(pCodecCtx->channels);//获取有几通道(双通道，单通道)，与上面的channels是不同的
    //Swr
    au_convert_ctx = swr_alloc();
    au_convert_ctx=swr_alloc_set_opts(au_convert_ctx,out_channel_layout, out_sample_fmt, out_sample_rate,
        in_channel_layout,pCodecCtx->sample_fmt , pCodecCtx->sample_rate,0, NULL);//初始化重采样参数(重采样上下文，输出的layout如：双声道…，输出的样本格式，输出的样本率，输入的layout，输入的样本格式，输入的样本率，日志相关)
    swr_init(au_convert_ctx);

    nowTime = 0;

    double timeBase = av_q2d(pFormatCtx->streams[audioStream]->time_base);

    while(av_read_frame(pFormatCtx, packet)>=0){
        if(packet->stream_index==audioStream){

            ret = avcodec_decode_audio4( pCodecCtx, pFrame,&got_picture, packet);
            if ( ret < 0 ) {
                printf("Error in decoding audio frame.\n");
                return;
            }

            nowTime = packet->pts * timeBase;//因为音频时间是正确的，所以按照音频时间轴做事情

            if ( got_picture > 0 ){
                swr_convert(au_convert_ctx,&out_buffer, MAX_AUDIO_FRAME_SIZE,(const uint8_t **)pFrame->data , pFrame->nb_samples);//重采样 (重采样的上下文，输出数据指针，输出的样本数量，输入数据，输入的样本数量)
                ret = fwrite(out_buffer, 1, out_buffer_size, pFile);//解码解出来的音频是正确的
                while (audio->bytesFree() < ret)//写入4096个则正常，可以通过上一个函数的返回值判断
                {
                    msleep(10);
                }
                io->write((const char *)out_buffer,ret);
                index++;
            }
        }
        while(player_status == statu_stop)
        {
            delay(500);
            if(player_status == statu_close)
            {
                break;
            }
        }
        av_free_packet(packet);
        if(player_changeindex)
        {
            player_index = player_index * pFormatCtx->streams[audioStream]->duration;
            ret = av_seek_frame(pFormatCtx, audioStream, player_index,  AVSEEK_FLAG_BACKWARD);
            if(ret < 0)
            {
                qDebug() << "音频 跳转失败 !!!";
            }
            player_changeindex = false;
            seekOK();
        }
        if(player_status == statu_close)
        {
            break;
        }
    }
    nowTime = -123;
    swr_free(&au_convert_ctx);

    fclose(pFile);

    av_free(out_buffer);
    // Close the codec
    avcodec_close(pCodecCtx);
    // Close the video file
    avformat_close_input(&pFormatCtx);
    player_status = statu_free;
}
double hp_ffmpeg_audio::hp_Audio_getAudioTime()
{
    return nowTime;
}
void hp_ffmpeg_audio::hp_Video_setIndex(double index)
{
    player_index = index;
    player_changeindex = true;
}
#if 0
void hp_ffmpeg_audio::runAudio()
{
    qDebug() << "--hp_ffmpeg_audio::runAudio--";
    int ret;

    int destMs,currentMs;

    if(audio==NULL)
    {
        qDebug() << "输出设备不支持该格式，不能播放音频";
        return ;
    }

    //初始化网络库 （可以打开rtsp rtmp http 协议的流媒体视频）
    avformat_network_init();

    AVFormatContext *pFormatCtx=NULL;
    qDebug() << "Audio file == > " << filename;
    ret = avformat_open_input(&pFormatCtx, filename.toLocal8Bit().data(),NULL, NULL) ;  //打开音视频文件并创建AVFormatContext结构体以及初始化.
    if (ret!= 0)
    {
        qDebug() << "--hp_ffmpeg_audio::runAudio-- 音频文件打开失败";
        return ;
    }
    ret = avformat_find_stream_info(pFormatCtx, NULL);   //初始化流信息
    if (ret!= 0)
    {
        qDebug() << "--hp_ffmpeg_audio::runAudio-- 音频句柄初始化失败";
        return ;
    }
    int audioIndex=-1;
    audioIndex = av_find_best_stream(pFormatCtx, AVMEDIA_TYPE_AUDIO, -1, -1, NULL, 0);//这里查找流的方法不一样
    AVCodec *acodec = avcodec_find_decoder(pFormatCtx->streams[audioIndex]->codecpar->codec_id);//获取codec
//    AVCodec *acodec = avcodec_find_decoder(pFormatCtx->streams[audioIndex]->codec->codec_id);
//    AVCodecContext *pCodecCtx = pFormatCtx->streams[audioIndex]->codec;
    AVCodecContext *pCodecCtx = avcodec_alloc_context3(acodec); //构造AVCodecContext ,并将vcodec填入AVCodecContext中
    avcodec_parameters_to_context(pCodecCtx, pFormatCtx->streams[audioIndex]->codecpar); //初始化AVCodecContext
    ret = avcodec_open2(pCodecCtx, NULL,NULL);  //打开解码器,由于之前调用avcodec_alloc_context3(vcodec)初始化了vc,那么codec(第2个参数)可以填NULL
    if (ret!= 0)
    {
        qDebug() << "--hp_ffmpeg_audio::runAudio-- 音频解码器打开失败";
        return ;
    }
    SwrContext *swrctx =NULL;
    swrctx=swr_alloc_set_opts(swrctx, av_get_default_channel_layout(2),AV_SAMPLE_FMT_S16,8000,
                                av_get_default_channel_layout(pCodecCtx->channels), pCodecCtx->sample_fmt,pCodecCtx->sample_rate, NULL,NULL);
    //av_get_default_channel_layout(pCodecCtx->channels)  MP4和AVI时这个值都为3
    ret = swr_init(swrctx);
    if(ret < 0)
    {
        qDebug() << "--hp_ffmpeg_audio::runAudio-- 音频重采样初始化失败";
        return;
    }
    destMs = av_q2d(pFormatCtx->streams[audioIndex]->time_base)*1000*pFormatCtx->streams[audioIndex]->duration;
    qDebug()<<"码率:"<<pCodecCtx->bit_rate;
    qDebug()<<"格式:"<<pCodecCtx->sample_fmt;
    qDebug()<<"通道:"<<pCodecCtx->channels;
    qDebug()<<"布局:"<<av_get_default_channel_layout(pCodecCtx->channels);
    qDebug()<<"采样率:"<<pCodecCtx->sample_rate;
    qDebug()<<"时长:"<<destMs;
    qDebug()<<"解码器:"<<acodec->name;

    AVPacket * packet =av_packet_alloc();
//    AVPacket * packet;
    AVFrame *frame =av_frame_alloc();

    audio->stop();
    QIODevice*io = audio->start();

    QString outFileName = "./1.pcm";
    QFile file(outFileName); // Qt文件操作
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    qDebug() << "--hp_ffmpeg_audio::runAudio-- 开始音频解码 ";
    while(1)
    {
        ret = av_read_frame(pFormatCtx, packet);//这一句引发的失真
        if (ret!= 0)
        {
            qDebug() << "av_read_frame == 0";
            break ;
        }

        if(packet->stream_index == audioIndex)
        {
            //解码一帧数据
            ret = avcodec_send_packet(pCodecCtx, packet);
            av_packet_unref(packet);//释放空间

            if (ret != 0)
            {
                qDebug() << "avcodec_send_packet";
                continue ;
            }
//            qDebug() << "Audio Print Time == > " << packet->pts;
            while( avcodec_receive_frame(pCodecCtx, frame) == 0)
            {
                uint8_t *data[2] = { 0 };
                int byteCnt=frame->nb_samples * 2 * 2;
                unsigned char *pcm = new uint8_t[byteCnt];     //frame->nb_samples*2*2表示分配样本数据量*两通道*每通道2字节大小
                data[0] = pcm;  //输出格式为AV_SAMPLE_FMT_S16(packet类型),所以转换后的LR两通道都存在data[0]中
                ret = swr_convert(swrctx,
                                  data, frame->nb_samples,		//输出
                                 (const uint8_t**)frame->data,frame->nb_samples );	//输入
                //将重采样后的data数据发送到输出设备,进行播放
                while (audio->bytesFree() < byteCnt)
                {
                    msleep(10);
                }
                file.write((const char *)pcm,byteCnt);//若出问题了  可以打开这一句  然后把生成的文件放到Audacity中分析，因该是  编码方式、声道等写错了
                io->write((const char *)pcm,byteCnt);
                delete[] pcm;
            }
        }


    }
    file.close();
    //释放内存
    av_frame_free(&frame);
    av_packet_free(&packet);
    swr_free(&swrctx);
    avcodec_free_context(&pCodecCtx);
    avformat_close_input(&pFormatCtx);

    qDebug() << "Free -- > " << filename;
    QString fa_cp = "rm " + filename;
    QByteArray ba = fa_cp.toUtf8();
    char *mm = ba.data();
    system(mm);
}
#endif
void hp_ffmpeg_audio::hp_Audio_setLowSpeedOffset(int offset)
{

}
void hp_ffmpeg_audio::hp_Audio_setHighSpeedOffset(int offset)
{

}
void hp_ffmpeg_audio::hp_Audio_setSpeed(Player_speed speed)
{

}
void hp_ffmpeg_audio::hp_Audio_setIndex(double index)//传入时间占比总长
{

}
void hp_ffmpeg_audio::hp_Audio_setStop(bool stop)
{
    qDebug() << "--hp_ffmpeg_audio::hp_Audio_setStop-- stop = " << stop;
    if(stop)
    {
        player_status = statu_stop;
    }else
    {
        player_status = statu_play;
    }
}
void hp_ffmpeg_audio::hp_Audio_setClose()
{
    qDebug() << "--Hp_ffmpeg_Player::hp_Video_setClose-- ";
    if(player_status == statu_free || player_status == statu_close)
    {
        qDebug() << "--Hp_ffmpeg_Player::hp_Video_setClose-- player does not play !!!";
        return;
    }
    player_status = statu_close;
}
// 延时函数
void hp_ffmpeg_audio::delay(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void hp_ffmpeg_audio::run()
{
    qDebug() << "--hp_ffmpeg_audio::run--";
    if(!initAudio(8000))
    {
        qDebug() << "输出设备不支持该格式，不能播放音频";
    }

    runAudio();

}
