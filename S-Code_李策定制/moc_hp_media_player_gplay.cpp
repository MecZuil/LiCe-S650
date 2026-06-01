/****************************************************************************
** Meta object code from reading C++ file 'hp_media_player_gplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_media_player_gplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_media_player_gplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Hp_Media_Player_Gplay_t {
    QByteArrayData data[8];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Hp_Media_Player_Gplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Hp_Media_Player_Gplay_t qt_meta_stringdata_Hp_Media_Player_Gplay = {
    {
QT_MOC_LITERAL(0, 0, 21), // "Hp_Media_Player_Gplay"
QT_MOC_LITERAL(1, 22, 25), // "signal_update_lcdoff_time"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 5), // "iskey"
QT_MOC_LITERAL(4, 55, 28), // "on_toolButton_close_released"
QT_MOC_LITERAL(5, 84, 27), // "on_toolButton_pause_clicked"
QT_MOC_LITERAL(6, 112, 7), // "checked"
QT_MOC_LITERAL(7, 120, 8) // "ReadData"

    },
    "Hp_Media_Player_Gplay\0signal_update_lcdoff_time\0"
    "\0iskey\0on_toolButton_close_released\0"
    "on_toolButton_pause_clicked\0checked\0"
    "ReadData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hp_Media_Player_Gplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   37,    2, 0x0a /* Public */,
       5,    1,   38,    2, 0x08 /* Private */,
       7,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,

       0        // eod
};

void Hp_Media_Player_Gplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Hp_Media_Player_Gplay *_t = static_cast<Hp_Media_Player_Gplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_update_lcdoff_time((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_toolButton_close_released(); break;
        case 2: _t->on_toolButton_pause_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->ReadData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Hp_Media_Player_Gplay::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Media_Player_Gplay::signal_update_lcdoff_time)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Hp_Media_Player_Gplay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Hp_Media_Player_Gplay.data,
      qt_meta_data_Hp_Media_Player_Gplay,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Hp_Media_Player_Gplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hp_Media_Player_Gplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Hp_Media_Player_Gplay.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Hp_Media_Player_Gplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Hp_Media_Player_Gplay::signal_update_lcdoff_time(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
