/****************************************************************************
** Meta object code from reading C++ file 'hp_ffmpeg_audio.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_ffmpeg_audio.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_ffmpeg_audio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hp_ffmpeg_audio_t {
    QByteArrayData data[3];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hp_ffmpeg_audio_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hp_ffmpeg_audio_t qt_meta_stringdata_hp_ffmpeg_audio = {
    {
QT_MOC_LITERAL(0, 0, 15), // "hp_ffmpeg_audio"
QT_MOC_LITERAL(1, 16, 6), // "seekOK"
QT_MOC_LITERAL(2, 23, 0) // ""

    },
    "hp_ffmpeg_audio\0seekOK\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hp_ffmpeg_audio[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void hp_ffmpeg_audio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        hp_ffmpeg_audio *_t = static_cast<hp_ffmpeg_audio *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->seekOK(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hp_ffmpeg_audio::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_ffmpeg_audio::seekOK)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject hp_ffmpeg_audio::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_hp_ffmpeg_audio.data,
      qt_meta_data_hp_ffmpeg_audio,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *hp_ffmpeg_audio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hp_ffmpeg_audio::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hp_ffmpeg_audio.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int hp_ffmpeg_audio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void hp_ffmpeg_audio::seekOK()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
