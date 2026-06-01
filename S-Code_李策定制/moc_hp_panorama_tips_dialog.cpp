/****************************************************************************
** Meta object code from reading C++ file 'hp_panorama_tips_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_panorama_tips_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_panorama_tips_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Hp_Panorama_Tips_Dialog_t {
    QByteArrayData data[10];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Hp_Panorama_Tips_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Hp_Panorama_Tips_Dialog_t qt_meta_stringdata_Hp_Panorama_Tips_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 23), // "Hp_Panorama_Tips_Dialog"
QT_MOC_LITERAL(1, 24, 21), // "signal_panorama_start"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 20), // "signal_panorama_stop"
QT_MOC_LITERAL(4, 68, 25), // "signal_update_lcdoff_time"
QT_MOC_LITERAL(5, 94, 12), // "isScreenShot"
QT_MOC_LITERAL(6, 107, 25), // "on_pushButton_ok_released"
QT_MOC_LITERAL(7, 133, 29), // "on_pushButton_cancel_released"
QT_MOC_LITERAL(8, 163, 25), // "slot_panorama_dialog_type"
QT_MOC_LITERAL(9, 189, 4) // "type"

    },
    "Hp_Panorama_Tips_Dialog\0signal_panorama_start\0"
    "\0signal_panorama_stop\0signal_update_lcdoff_time\0"
    "isScreenShot\0on_pushButton_ok_released\0"
    "on_pushButton_cancel_released\0"
    "slot_panorama_dialog_type\0type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hp_Panorama_Tips_Dialog[] = {

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
       8,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void Hp_Panorama_Tips_Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Hp_Panorama_Tips_Dialog *_t = static_cast<Hp_Panorama_Tips_Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_panorama_start(); break;
        case 1: _t->signal_panorama_stop(); break;
        case 2: _t->signal_update_lcdoff_time((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_ok_released(); break;
        case 4: _t->on_pushButton_cancel_released(); break;
        case 5: _t->slot_panorama_dialog_type((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Hp_Panorama_Tips_Dialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Panorama_Tips_Dialog::signal_panorama_start)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Hp_Panorama_Tips_Dialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Panorama_Tips_Dialog::signal_panorama_stop)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Hp_Panorama_Tips_Dialog::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Panorama_Tips_Dialog::signal_update_lcdoff_time)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Hp_Panorama_Tips_Dialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Hp_Panorama_Tips_Dialog.data,
      qt_meta_data_Hp_Panorama_Tips_Dialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Hp_Panorama_Tips_Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hp_Panorama_Tips_Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Hp_Panorama_Tips_Dialog.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Hp_Panorama_Tips_Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Hp_Panorama_Tips_Dialog::signal_panorama_start()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Hp_Panorama_Tips_Dialog::signal_panorama_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Hp_Panorama_Tips_Dialog::signal_update_lcdoff_time(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
