/****************************************************************************
** Meta object code from reading C++ file 'hp_calbration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_calbration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_calbration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hp_calbration_t {
    QByteArrayData data[11];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hp_calbration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hp_calbration_t qt_meta_stringdata_hp_calbration = {
    {
QT_MOC_LITERAL(0, 0, 13), // "hp_calbration"
QT_MOC_LITERAL(1, 14, 25), // "signal_update_lcdoff_time"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 29), // "signal_pc_sys_mag_calsw_start"
QT_MOC_LITERAL(4, 71, 28), // "signal_pc_sys_mag_calsw_stop"
QT_MOC_LITERAL(5, 100, 27), // "slot_pc_sys_mag_calsw_start"
QT_MOC_LITERAL(6, 128, 12), // "return_value"
QT_MOC_LITERAL(7, 141, 26), // "slot_pc_sys_mag_calsw_stop"
QT_MOC_LITERAL(8, 168, 21), // "on_toolButton_clicked"
QT_MOC_LITERAL(9, 190, 23), // "on_toolButton_2_clicked"
QT_MOC_LITERAL(10, 214, 21) // "on_pushButton_clicked"

    },
    "hp_calbration\0signal_update_lcdoff_time\0"
    "\0signal_pc_sys_mag_calsw_start\0"
    "signal_pc_sys_mag_calsw_stop\0"
    "slot_pc_sys_mag_calsw_start\0return_value\0"
    "slot_pc_sys_mag_calsw_stop\0"
    "on_toolButton_clicked\0on_toolButton_2_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hp_calbration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    0,   57,    2, 0x06 /* Public */,
       4,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   59,    2, 0x0a /* Public */,
       7,    1,   62,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UChar,    6,
    QMetaType::Void, QMetaType::UChar,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void hp_calbration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        hp_calbration *_t = static_cast<hp_calbration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_update_lcdoff_time((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->signal_pc_sys_mag_calsw_start(); break;
        case 2: _t->signal_pc_sys_mag_calsw_stop(); break;
        case 3: _t->slot_pc_sys_mag_calsw_start((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 4: _t->slot_pc_sys_mag_calsw_stop((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 5: _t->on_toolButton_clicked(); break;
        case 6: _t->on_toolButton_2_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hp_calbration::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_calbration::signal_update_lcdoff_time)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (hp_calbration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_calbration::signal_pc_sys_mag_calsw_start)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (hp_calbration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_calbration::signal_pc_sys_mag_calsw_stop)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject hp_calbration::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_hp_calbration.data,
      qt_meta_data_hp_calbration,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *hp_calbration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hp_calbration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hp_calbration.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int hp_calbration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void hp_calbration::signal_update_lcdoff_time(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void hp_calbration::signal_pc_sys_mag_calsw_start()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void hp_calbration::signal_pc_sys_mag_calsw_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
