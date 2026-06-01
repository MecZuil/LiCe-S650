/****************************************************************************
** Meta object code from reading C++ file 'hp_ble_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_ble_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_ble_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Hp_Ble_Dialog_t {
    QByteArrayData data[8];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Hp_Ble_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Hp_Ble_Dialog_t qt_meta_stringdata_Hp_Ble_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Hp_Ble_Dialog"
QT_MOC_LITERAL(1, 14, 23), // "signal_ble_match_delete"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 11), // "signal_type"
QT_MOC_LITERAL(4, 51, 25), // "on_pushButton_ok_released"
QT_MOC_LITERAL(5, 77, 29), // "on_pushButton_cancel_released"
QT_MOC_LITERAL(6, 107, 20), // "slot_ble_dialog_type"
QT_MOC_LITERAL(7, 128, 4) // "type"

    },
    "Hp_Ble_Dialog\0signal_ble_match_delete\0"
    "\0signal_type\0on_pushButton_ok_released\0"
    "on_pushButton_cancel_released\0"
    "slot_ble_dialog_type\0type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hp_Ble_Dialog[] = {

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
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void Hp_Ble_Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Hp_Ble_Dialog *_t = static_cast<Hp_Ble_Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_ble_match_delete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_ok_released(); break;
        case 2: _t->on_pushButton_cancel_released(); break;
        case 3: _t->slot_ble_dialog_type((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Hp_Ble_Dialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Ble_Dialog::signal_ble_match_delete)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Hp_Ble_Dialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Hp_Ble_Dialog.data,
      qt_meta_data_Hp_Ble_Dialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Hp_Ble_Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hp_Ble_Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Hp_Ble_Dialog.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Hp_Ble_Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Hp_Ble_Dialog::signal_ble_match_delete(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
