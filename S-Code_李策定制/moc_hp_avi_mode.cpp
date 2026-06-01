/****************************************************************************
** Meta object code from reading C++ file 'hp_avi_mode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_avi_mode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_avi_mode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HP_Avi_mode_t {
    QByteArrayData data[9];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HP_Avi_mode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HP_Avi_mode_t qt_meta_stringdata_HP_Avi_mode = {
    {
QT_MOC_LITERAL(0, 0, 11), // "HP_Avi_mode"
QT_MOC_LITERAL(1, 12, 37), // "signal_core_key_record_avi_mo..."
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 37), // "signal_core_key_record_hir_mo..."
QT_MOC_LITERAL(4, 89, 19), // "signal_avi_hir_mode"
QT_MOC_LITERAL(5, 109, 4), // "mode"
QT_MOC_LITERAL(6, 114, 26), // "on_pushButton_avi_released"
QT_MOC_LITERAL(7, 141, 26), // "on_pushButton_hir_released"
QT_MOC_LITERAL(8, 168, 22) // "on_toolButton_released"

    },
    "HP_Avi_mode\0signal_core_key_record_avi_mode_start\0"
    "\0signal_core_key_record_hir_mode_start\0"
    "signal_avi_hir_mode\0mode\0"
    "on_pushButton_avi_released\0"
    "on_pushButton_hir_released\0"
    "on_toolButton_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HP_Avi_mode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    1,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HP_Avi_mode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HP_Avi_mode *_t = static_cast<HP_Avi_mode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_core_key_record_avi_mode_start(); break;
        case 1: _t->signal_core_key_record_hir_mode_start(); break;
        case 2: _t->signal_avi_hir_mode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_avi_released(); break;
        case 4: _t->on_pushButton_hir_released(); break;
        case 5: _t->on_toolButton_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HP_Avi_mode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HP_Avi_mode::signal_core_key_record_avi_mode_start)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HP_Avi_mode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HP_Avi_mode::signal_core_key_record_hir_mode_start)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HP_Avi_mode::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HP_Avi_mode::signal_avi_hir_mode)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HP_Avi_mode::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HP_Avi_mode.data,
      qt_meta_data_HP_Avi_mode,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HP_Avi_mode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HP_Avi_mode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HP_Avi_mode.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HP_Avi_mode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void HP_Avi_mode::signal_core_key_record_avi_mode_start()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void HP_Avi_mode::signal_core_key_record_hir_mode_start()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HP_Avi_mode::signal_avi_hir_mode(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
