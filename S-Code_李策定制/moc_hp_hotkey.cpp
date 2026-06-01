/****************************************************************************
** Meta object code from reading C++ file 'hp_hotkey.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_hotkey.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_hotkey.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Hp_hotkey_t {
    QByteArrayData data[10];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Hp_hotkey_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Hp_hotkey_t qt_meta_stringdata_Hp_hotkey = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Hp_hotkey"
QT_MOC_LITERAL(1, 10, 28), // "signal_hotkey_set_key_camera"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 10), // "KEYSETTING"
QT_MOC_LITERAL(4, 51, 5), // "value"
QT_MOC_LITERAL(5, 57, 27), // "signal_hotkey_set_key_focus"
QT_MOC_LITERAL(6, 85, 41), // "on_listWidget_keyCamera_curre..."
QT_MOC_LITERAL(7, 127, 10), // "currentRow"
QT_MOC_LITERAL(8, 138, 40), // "on_listWidget_keyFocus_curren..."
QT_MOC_LITERAL(9, 179, 26) // "on_toolButton_back_clicked"

    },
    "Hp_hotkey\0signal_hotkey_set_key_camera\0"
    "\0KEYSETTING\0value\0signal_hotkey_set_key_focus\0"
    "on_listWidget_keyCamera_currentRowChanged\0"
    "currentRow\0on_listWidget_keyFocus_currentRowChanged\0"
    "on_toolButton_back_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hp_hotkey[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   45,    2, 0x08 /* Private */,
       8,    1,   48,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

       0        // eod
};

void Hp_hotkey::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Hp_hotkey *_t = static_cast<Hp_hotkey *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_hotkey_set_key_camera((*reinterpret_cast< KEYSETTING(*)>(_a[1]))); break;
        case 1: _t->signal_hotkey_set_key_focus((*reinterpret_cast< KEYSETTING(*)>(_a[1]))); break;
        case 2: _t->on_listWidget_keyCamera_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_listWidget_keyFocus_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_toolButton_back_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Hp_hotkey::*)(KEYSETTING );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_hotkey::signal_hotkey_set_key_camera)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Hp_hotkey::*)(KEYSETTING );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_hotkey::signal_hotkey_set_key_focus)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Hp_hotkey::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Hp_hotkey.data,
      qt_meta_data_Hp_hotkey,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Hp_hotkey::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hp_hotkey::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Hp_hotkey.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Hp_hotkey::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Hp_hotkey::signal_hotkey_set_key_camera(KEYSETTING _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Hp_hotkey::signal_hotkey_set_key_focus(KEYSETTING _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
