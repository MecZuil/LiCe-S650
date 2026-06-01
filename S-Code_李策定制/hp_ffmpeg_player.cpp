#include "hp_ffmpeg_player.h"

hp_ffmpeg_player::hp_ffmpeg_player(QWidget *parent) : QWidget(parent)
{
    player_index = 0;
    player_rotate = 0;
    player_width = 800;
    player_height = 480;
    fastnum = 0;
    player_nowFrame = 0;
    player_zonFrame = 0;
    player_nowTime = -1;
    input_index = 0;
    lowoffset = 0;
    highoffset = 0;
    player_changeindex = false;
    player_fastspeed = false;

    audio_thread = new hp_ffmpeg_audio();

    connect(audio_thread,SIGNAL(seekOK()),this,SLOT(seekok()));
}
void hp_ffmpeg_player::hp_Video_Play(QString filename,QLabel *labelname)
{
    //初始化并获取[视频句柄结构体]-->获取视频解码器-->开辟帧空间-->帧读取-->帧转化-->帧显示
    //                                                        ↑---------------↓
//    QString fa =  "Hp_ffmpeg_Player_ret" + filename.mid(filename.lastIndexOf("."));;
//    QString fa_cp = "cp " + filename + " " + fa;
//    QByteArray ba = fa_cp.toUtf8();
//    char *mm = ba.data();
//    system(mm);
    qDebug() << "--Hp_ffmpeg_Player::hp_Video_Play-- filename = " << filename;
    AVFormatContext *pFormatCtx;//用于存储视频头部信息
    int videoIndex = -1;//用于存储视频索引，有视频流还有音频流等等其他可能
    int audioIndex = -1;//用于存储视频索引
    AVCodecContext *pCodecCtx;//用于存储视频编码信息
    AVCodec *pCodec;//用于存储视频解码器
    AVFrame *pFrame,*pFrameRGB;//用于存储每一帧图像的头部信息
    AVPacket *packet;//用于存储未解压的一帧图像信息
    AVStream *stream;//用于存放流指针
    unsigned char *out_buffer;//用于存储一帧图像的数据信息
    int ret,got_picture;//用于存储返回值
    struct SwsContext *img_convert_ctx;//用于存储图像转化的基本信息
    char filepath[200];//用于存储图像路径
    strcpy(filepath,filename.toUtf8().data());

    av_register_all();//初始
    pFormatCtx = avformat_alloc_context();//初始化视频头部信息结构体
    if(avformat_open_input(&pFormatCtx,filepath,nullptr,nullptr) != 0)//打开视频文件，获取句柄
    {
        qDebug() << "Hp_ffmpeg_Player::hp_Video_Play - avformat_open_input Error";
        return;
    }
    if(avformat_find_stream_info(pFormatCtx,nullptr) < 0)//根据句柄，进一步获取音视频流信息
    {
        qDebug() << "Hp_ffmpeg_Player::hp_Video_Play - avformat_find_stream_info Error";
        return;
    }
    for(int i = 0;i < (int)pFormatCtx->nb_streams;i++)//遍历流信息
    {
        qDebug() << "pFormatCtx->streams[" << i << "]->codec->codec_type = " << pFormatCtx->streams[i]->codec->codec_type;
        if(pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)//若是视频
        {
            videoIndex = i;//获取流位置索引
        }
        if(pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO && audioIndex == -1)//若是视频
        {
            audioIndex = i;//获取流位置索引
        }
    }
    if(videoIndex == -1)//判断是否有找到视频流
    {
        qDebug() << "Hp_ffmpeg_Player::hp_Video_Play - 无视频流 == -1 Error";
        return;
    }
    //视频解码
    pCodecCtx = pFormatCtx->streams[videoIndex]->codec;//获取当前流的编码信息
    stream = pFormatCtx->streams[videoIndex];
    pCodec = avcodec_find_decoder(pCodecCtx->codec_id);//获取解码器
    if(pCodec == nullptr)//若未获取到解码器
    {
        qDebug() << "Hp_ffmpeg_Player::hp_Video_Play - 视频解码器获取失败 == nullptr";
        return;
    }
    if(avcodec_open2(pCodecCtx,pCodec,nullptr) < 0)//打开解码器
    {
        qDebug() << "Hp_ffmpeg_Player::hp_Video_Play - 视频解码器打开失败 Error";
        return;
    }
    fastnum = 0;
    player_nowTime = -1;
    player_nowFrame = 0;
    player_zonFrame = 0;
    player_zonFrame = pFormatCtx->streams[videoIndex]->nb_frames;//获取总帧数
    player_changeindex = false;
    player_fastspeed = false;
    hp_Video_setSpeed(speed_1_0);
    fastnum = 0;
    player_fastspeed = false;
//    pts_time_base = (double)pFormatCtx->streams[videoIndex]->time_base.num / (double)pFormatCtx->streams[videoIndex]->time_base.den;
    duration = pFormatCtx->duration / 1000000;
    qDebug() << "--------------- 文件信息 ----------------";
    av_dump_format(pFormatCtx,0,filepath,0);//打印视频信息
    qDebug() << "-------------------------------------------------";
    pFrame = av_frame_alloc();//创建一帧信息头空间
    pFrameRGB = av_frame_alloc();
    out_buffer = (unsigned char *)av_malloc((size_t)av_image_get_buffer_size(AV_PIX_FMT_RGB32,pCodecCtx->width,pCodecCtx->height,1));//获取并创建一帧数据空间
    av_image_fill_arrays(pFrameRGB->data,pFrameRGB->linesize,out_buffer,AV_PIX_FMT_RGB32,pCodecCtx->width,pCodecCtx->height, 1);//关联帧头结构体与帧数据空间
    packet = (AVPacket *)av_malloc(sizeof(AVPacket));//创建压缩帧空间
    img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height, pCodecCtx->pix_fmt,pCodecCtx->width, pCodecCtx->height, AV_PIX_FMT_RGB32, SWS_BICUBIC, nullptr, nullptr, nullptr);
    //获取帧转化结构体
    player_status = statu_play;
    int fastspeed_num = 0;

    qDebug() << "Hp_ffmpeg_Player::hp_Video_Play - 初始化音频";

//    audio_thread->hp_Audio_play(fa);//这句话开启音频解码

    int64_t start_time = av_gettime();
    int64_t realTime;
    double timeBase = av_q2d(pFormatCtx->streams[videoIndex]->time_base);
    double audioTime = 0;
    audioIsClose = false;//有时候音频会提前结束，所以设置这个是为了让音频结束时，视频正常运转

    while(av_read_frame(pFormatCtx,packet) >= 0)//获取一帧未解码的数据
    {
        realTime = av_gettime() - start_time; //主时钟时间，获取主时钟时间差，就是真实的进度条
        if(packet->stream_index == videoIndex)//判断是否为视频数据
        {
            // 解码一帧视频数据
            ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture, packet);//这个解码占用时间，但是也不得不解码吗？？？
//            qDebug() << "pFrame - > pict_type == > " << pFrame->pict_type;
            if (ret < 0)
            {
                qDebug() << "Hp_ffmpeg_Player::hp_Video_Play - avcodec_decode_video2 Error << " << ret;
                continue;
            }
            if(player_fastspeed)
            {
                if(fastspeed_num < fastnum)
                {
                    fastspeed_num++;
                    continue;//弃帧
                }
            }

            if(packet->pts < 0)
            {
                player_nowTime = packet->dts * timeBase;
            }else{
                player_nowTime = packet->pts * timeBase;
            }
            //音视频同步=========================
            if(audioIsClose)//若音频停止了
            {
                audioTime = realTime;
            }else{
                audioTime = audio_thread->hp_Audio_getAudioTime();
            }

//            qDebug() << "Vidio Print Time == > " << player_nowTime << " ; " << audioTime << " ; "  << realTime / 1000000  << " ; " << duration;

            if(audioTime == -123)
            {
                audioIsClose = true;
            }else{
                while(player_nowTime > audioTime)
                {
                    delay(10);
                    if(audioIsClose)//若音频停止了
                    {
                        audioTime = realTime;
                    }else{
                        audioTime = audio_thread->hp_Audio_getAudioTime();
                    }
                }
            }
            //音视频同步=========================

            if (got_picture)
            {
                sws_scale(img_convert_ctx, (const unsigned char* const*)pFrame->data, pFrame->linesize, 0, pCodecCtx->height,
                                    pFrameRGB->data, pFrameRGB->linesize);
                QImage img((uchar*)pFrameRGB->data[0],pCodecCtx->width,pCodecCtx->height,QImage::Format_RGB32);
                img = img.scaled(player_width,player_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
                if(player_rotate != 0)
                {
                    labelname->setPixmap(QPixmap::fromImage(img).transformed(matrix,Qt::SmoothTransformation));
                }else{
                    labelname->setPixmap(QPixmap::fromImage(img));
                }
                if(player_changeindex)
                {
                    qDebug() << " -- $$$$ video Tartget Index ; Over Index == > " << player_index << " ; " << player_zonFrame;
                    ret = av_seek_frame(pFormatCtx,-1,player_index,AVSEEK_FLAG_BACKWARD);//不会花屏
                    if(ret < 0)
                    {
                        qDebug() << "视频 跳转失败 !!!";
                    }
                    audio_thread->hp_Video_setIndex(input_index);
                    //使用这个 不能跳转到选定位置，只能跳转到选定位置的前一个I帧，这样不会花屏
//                    av_seek_frame(pFormatCtx,-1,player_index,AVSEEK_FLAG_ANY);//会花屏，即使显示了上一个I帧也会，因为图像是根据上一帧来显示的，不是根据上一个I帧来显示的
                }
                delay(1);//若出现按下ctrl+C不退出，则一般都是未加延时导致的
            }
            fastspeed_num = 0;
            player_nowFrame++;
            while(player_status == statu_stop)
            {
                delay(500);
                if(player_status == statu_close)
                {
                    break;
                }
            }
        }
        av_free_packet(packet);

        if(player_status == statu_close)
        {
            break;
        }
    }
    sws_freeContext(img_convert_ctx);
    av_frame_free(&pFrameRGB);
    av_frame_free(&pFrame);
    avcodec_close(pCodecCtx);
    avformat_close_input(&pFormatCtx);
    audio_thread->hp_Audio_setClose();
    player_status = statu_free;
    hp_Video_player_close();
}
// 延时函数
void hp_ffmpeg_player::delay(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void hp_ffmpeg_player::hp_Video_setStop(bool stop)
{
    qDebug() << "--Hp_ffmpeg_Player::hp_Video_setStop-- stop = " << stop;
    if(stop)
    {
        if(player_status != statu_play)
        {
            qDebug() << "--Hp_ffmpeg_Player::hp_Video_setStop-- player does not play !!!";
            return;
        }
        player_status = statu_stop;
    }else
    {
        if(player_status != statu_stop)
        {
            qDebug() << "--Hp_ffmpeg_Player::hp_Video_setStop-- player does not stop !!!";
            return;
        }
        player_status = statu_play;
    }
    audio_thread->hp_Audio_setStop(stop);
}
void hp_ffmpeg_player::hp_Video_setClose()
{
    qDebug() << "--Hp_ffmpeg_Player::hp_Video_setClose-- ";
    if(player_status == statu_free || player_status == statu_close)
    {
        qDebug() << "--Hp_ffmpeg_Player::hp_Video_setClose-- player does not play !!!";
        return;
    }
    player_status = statu_close;
}
void hp_ffmpeg_player::hp_Video_setWH(int width,int height)
{
    qDebug() << "--Hp_ffmpeg_Player::hp_Video_setWH-- width,height = " << width << " , " << height;
    player_width = width;
    player_height = height;
}
void hp_ffmpeg_player::hp_Video_setLowSpeedOffset(int offset)
{
    qDebug() << "--Hp_ffmpeg_Player::hp_Video_setLowSpeedOffset-- 低倍速 倍率偏移 = " << offset;
    if(offset < -49)
    {
        qDebug() << "--Hp_ffmpeg_Player::hp_Video_setLowSpeedOffset-- 低倍速 倍率偏移 值不能小于-49 !!!";
        offset = 0;
        return;
    }
    lowoffset = offset;
}
void hp_ffmpeg_player::hp_Video_setHighSpeedOffset(int offset)
{
    qDebug() << "--Hp_ffmpeg_Player::hp_Video_setHighSpeedOffset-- 高倍数 倍率偏移 = " << offset;
    if(offset < 0)
    {
        qDebug() << "--Hp_ffmpeg_Player::hp_Video_setHighSpeedOffset-- 高倍数 倍率偏移 值不能小于0 !!!";
        offset = 0;
        return;
    }
    highoffset = offset;
}
void hp_ffmpeg_player::hp_Video_setSpeed(Player_speed speed)
{
    qDebug() << "--Hp_ffmpeg_Player::hp_Video_setSpeed-- 播放速度 = " << speed;

    if(speed == speed_0_25)
    {
        fastnum = 150 + lowoffset;
        player_fastspeed = false;
    }else if(speed == speed_0_5)
    {
        fastnum = 100 + lowoffset;
        player_fastspeed = false;
    }else if(speed == speed_0_75)
    {
        fastnum = 50 + lowoffset;
        player_fastspeed = false;
    }else if(speed == speed_1_0)
    {
        fastnum = 0;
        player_fastspeed = false;
    }else if(speed == speed_1_25)
    {
        fastnum = 1 + highoffset;
        player_fastspeed = true;
    }else if(speed == speed_1_5)//经测
    {
        fastnum = 2 + highoffset;
        player_fastspeed = true;
    }else if(speed == speed_2_0)//经测5或6
    {
        fastnum = 5 + highoffset;
        player_fastspeed = true;
    }else if(speed == speed_2_5)
    {
        fastnum = 8 + highoffset;
        player_fastspeed = true;
    }else if(speed == speed_3_0)//经测
    {
        fastnum = 10 + highoffset;
        player_fastspeed = true;
    }
}
void hp_ffmpeg_player::hp_Video_setIndex(double index)
{
    qDebug() << "--Hp_ffmpeg_Player::hp_Video_setIndex-- index = " << index;
    if(player_status != statu_play)
    {
        qDebug() << "--Hp_ffmpeg_Player::hp_Video_setIndex-- 视频未开始播放 !!!";
        return;
    }
    if(player_changeindex)
    {
        qDebug() << "--Hp_ffmpeg_Player::hp_Video_setIndex-- 正在跳转中 !!!";
        return;
    }
    if(index < 0 || index > 1)
    {
        qDebug() << "--Hp_ffmpeg_Player::hp_Video_setIndex-- 跳转数值不能小于0或大于1 !!!";
        return;
    }
    input_index = index;
    player_index = player_zonFrame * input_index;//总帧数
    player_changeindex = true;
}
void hp_ffmpeg_player::hp_Video_setRotate(double rotate)
{
    qDebug() << "--Hp_ffmpeg_Player::hp_Video_setRotate-- 旋转角度 = " << rotate;
    matrix.rotate(-player_rotate);
    player_rotate = rotate;
    matrix.rotate(player_rotate);
}
double hp_ffmpeg_player::hp_Video_getDuration()
{
    if(player_status == statu_close || player_status == statu_free)
    {
        return -1;
    }
    if(player_nowTime < 0)
    {
        return player_zonFrame;//返回总帧
    }else{
        return duration;//秒
    }
}
double hp_ffmpeg_player::hp_Video_getNowTime()
{
    if(player_status == statu_close || player_status == statu_free)
    {
        return -1;
    }
    if(player_nowTime < 0)//若读取时间失败，则返回帧数代替时间
    {
        return player_nowFrame;
    }else{
        return player_nowTime;//当前时间，秒
    }
}
void hp_ffmpeg_player::seekok()
{
    qDebug() << "--Hp_ffmpeg_Player::seekok--";
    player_changeindex = false;
}
bool hp_ffmpeg_player::hp_Video_getSeekOK()
{
    return player_changeindex;
}
