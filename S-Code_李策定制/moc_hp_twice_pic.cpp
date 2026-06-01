/****************************************************************************
** Meta object code from reading C++ file 'hp_twice_pic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_twice_pic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_twice_pic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HP_Twice_Pic_t {
    QByteArrayData data[10];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HP_Twice_Pic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HP_Twice_Pic_t qt_meta_stringdata_HP_Twice_Pic = {
    {
QT_MOC_LITERAL(0, 0, 12), // "HP_Twice_Pic"
QT_MOC_LITERAL(1, 13, 25), // "signal_update_lcdoff_time"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 5), // "iskey"
QT_MOC_LITERAL(4, 46, 17), // "slot_pic_kjg_open"
QT_MOC_LITERAL(5, 64, 4), // "file"
QT_MOC_LITERAL(6, 69, 29), // "on_pushButton_return_released"
QT_MOC_LITERAL(7, 99, 26), // "on_pushButton_cut_released"
QT_MOC_LITERAL(8, 126, 22), // "SlotSendDateFolderPath"
QT_MOC_LITERAL(9, 149, 4) // "path"

    },
    "HP_Twice_Pic\0signal_update_lcdoff_time\0"
    "\0iskey\0slot_pic_kjg_open\0file\0"
    "on_pushButton_return_released\0"
    "on_pushButton_cut_released\0"
    "SlotSendDateFolderPath\0path"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HP_Twice_Pic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x08 /* Private */,
       7,    0,   46,    2, 0x08 /* Private */,
       8,    1,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void HP_Twice_Pic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HP_Twice_Pic *_t = static_cast<HP_Twice_Pic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_update_lcdoff_time((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->slot_pic_kjg_open((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_return_released(); break;
        case 3: _t->on_pushButton_cut_released(); break;
        case 4: _t->SlotSendDateFolderPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HP_Twice_Pic::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HP_Twice_Pic::signal_update_lcdoff_time)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HP_Twice_Pic::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HP_Twice_Pic.data,
      qt_meta_data_HP_Twice_Pic,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HP_Twice_Pic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HP_Twice_Pic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HP_Twice_Pic.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HP_Twice_Pic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void HP_Twice_Pic::signal_update_lcdoff_time(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
