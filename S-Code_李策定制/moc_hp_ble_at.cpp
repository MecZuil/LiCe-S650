/****************************************************************************
** Meta object code from reading C++ file 'hp_ble_at.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_ble_at.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_ble_at.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Hp_Ble_At_t {
    QByteArrayData data[19];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Hp_Ble_At_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Hp_Ble_At_t qt_meta_stringdata_Hp_Ble_At = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Hp_Ble_At"
QT_MOC_LITERAL(1, 10, 17), // "signal_search_end"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 25), // "signal_sync_searched_list"
QT_MOC_LITERAL(4, 55, 23), // "signal_sync_paired_list"
QT_MOC_LITERAL(5, 79, 19), // "signal_sync_connect"
QT_MOC_LITERAL(6, 99, 10), // "BLE_DEVICE"
QT_MOC_LITERAL(7, 110, 7), // "headset"
QT_MOC_LITERAL(8, 118, 22), // "signal_sync_disconnect"
QT_MOC_LITERAL(9, 141, 18), // "signal_old_connect"
QT_MOC_LITERAL(10, 160, 4), // "conn"
QT_MOC_LITERAL(11, 165, 17), // "signal_add_string"
QT_MOC_LITERAL(12, 183, 3), // "str"
QT_MOC_LITERAL(13, 187, 20), // "signal_ui_add_string"
QT_MOC_LITERAL(14, 208, 8), // "position"
QT_MOC_LITERAL(15, 217, 26), // "signal_ui_add_match_string"
QT_MOC_LITERAL(16, 244, 5), // "count"
QT_MOC_LITERAL(17, 250, 21), // "signal_ui_label_state"
QT_MOC_LITERAL(18, 272, 9) // "state_ble"

    },
    "Hp_Ble_At\0signal_search_end\0\0"
    "signal_sync_searched_list\0"
    "signal_sync_paired_list\0signal_sync_connect\0"
    "BLE_DEVICE\0headset\0signal_sync_disconnect\0"
    "signal_old_connect\0conn\0signal_add_string\0"
    "str\0signal_ui_add_string\0position\0"
    "signal_ui_add_match_string\0count\0"
    "signal_ui_label_state\0state_ble"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hp_Ble_At[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,
       8,    0,   70,    2, 0x06 /* Public */,
       9,    1,   71,    2, 0x06 /* Public */,
      11,    1,   74,    2, 0x06 /* Public */,
      13,    2,   77,    2, 0x06 /* Public */,
      15,    1,   82,    2, 0x06 /* Public */,
      17,    1,   85,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   12,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void Hp_Ble_At::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Hp_Ble_At *_t = static_cast<Hp_Ble_At *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_search_end(); break;
        case 1: _t->signal_sync_searched_list(); break;
        case 2: _t->signal_sync_paired_list(); break;
        case 3: _t->signal_sync_connect((*reinterpret_cast< BLE_DEVICE(*)>(_a[1]))); break;
        case 4: _t->signal_sync_disconnect(); break;
        case 5: _t->signal_old_connect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->signal_add_string((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->signal_ui_add_string((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->signal_ui_add_match_string((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->signal_ui_label_state((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Hp_Ble_At::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Ble_At::signal_search_end)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Hp_Ble_At::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Ble_At::signal_sync_searched_list)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Hp_Ble_At::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Ble_At::signal_sync_paired_list)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Hp_Ble_At::*)(BLE_DEVICE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Ble_At::signal_sync_connect)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Hp_Ble_At::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Ble_At::signal_sync_disconnect)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Hp_Ble_At::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Ble_At::signal_old_connect)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Hp_Ble_At::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Ble_At::signal_add_string)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Hp_Ble_At::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Ble_At::signal_ui_add_string)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Hp_Ble_At::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Ble_At::signal_ui_add_match_string)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Hp_Ble_At::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Ble_At::signal_ui_label_state)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Hp_Ble_At::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Hp_Ble_At.data,
      qt_meta_data_Hp_Ble_At,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Hp_Ble_At::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hp_Ble_At::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Hp_Ble_At.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Hp_Ble_At::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Hp_Ble_At::signal_search_end()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Hp_Ble_At::signal_sync_searched_list()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Hp_Ble_At::signal_sync_paired_list()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Hp_Ble_At::signal_sync_connect(BLE_DEVICE _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Hp_Ble_At::signal_sync_disconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Hp_Ble_At::signal_old_connect(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Hp_Ble_At::signal_add_string(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Hp_Ble_At::signal_ui_add_string(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Hp_Ble_At::signal_ui_add_match_string(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Hp_Ble_At::signal_ui_label_state(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
