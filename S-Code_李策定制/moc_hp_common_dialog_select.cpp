/****************************************************************************
** Meta object code from reading C++ file 'hp_common_dialog_select.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_common_dialog_select.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_common_dialog_select.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hp_common_dialog_select_t {
    QByteArrayData data[8];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hp_common_dialog_select_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hp_common_dialog_select_t qt_meta_stringdata_hp_common_dialog_select = {
    {
QT_MOC_LITERAL(0, 0, 23), // "hp_common_dialog_select"
QT_MOC_LITERAL(1, 24, 18), // "hp_signal_bt_click"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 6), // "select"
QT_MOC_LITERAL(4, 51, 26), // "on_pushButton_task_clicked"
QT_MOC_LITERAL(5, 78, 7), // "checked"
QT_MOC_LITERAL(6, 86, 28), // "on_pushButton_normal_clicked"
QT_MOC_LITERAL(7, 115, 28) // "on_pushButton_cancel_clicked"

    },
    "hp_common_dialog_select\0hp_signal_bt_click\0"
    "\0select\0on_pushButton_task_clicked\0"
    "checked\0on_pushButton_normal_clicked\0"
    "on_pushButton_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hp_common_dialog_select[] = {

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
       4,    1,   37,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       7,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void hp_common_dialog_select::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        hp_common_dialog_select *_t = static_cast<hp_common_dialog_select *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hp_signal_bt_click((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_task_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_normal_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_cancel_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hp_common_dialog_select::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_common_dialog_select::hp_signal_bt_click)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject hp_common_dialog_select::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_hp_common_dialog_select.data,
      qt_meta_data_hp_common_dialog_select,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *hp_common_dialog_select::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hp_common_dialog_select::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hp_common_dialog_select.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int hp_common_dialog_select::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void hp_common_dialog_select::hp_signal_bt_click(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
