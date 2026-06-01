/****************************************************************************
** Meta object code from reading C++ file 'hp_mulhom_edit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_mulhom_edit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_mulhom_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hp_mulhom_edit_t {
    QByteArrayData data[8];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hp_mulhom_edit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hp_mulhom_edit_t qt_meta_stringdata_hp_mulhom_edit = {
    {
QT_MOC_LITERAL(0, 0, 14), // "hp_mulhom_edit"
QT_MOC_LITERAL(1, 15, 25), // "signal_update_lcdoff_time"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 5), // "iskey"
QT_MOC_LITERAL(4, 48, 28), // "hp_mulhom_edit_value_changed"
QT_MOC_LITERAL(5, 77, 3), // "num"
QT_MOC_LITERAL(6, 81, 26), // "on_toolButton_back_clicked"
QT_MOC_LITERAL(7, 108, 29) // "scrollBar_mulhom_mouseRelease"

    },
    "hp_mulhom_edit\0signal_update_lcdoff_time\0"
    "\0iskey\0hp_mulhom_edit_value_changed\0"
    "num\0on_toolButton_back_clicked\0"
    "scrollBar_mulhom_mouseRelease"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hp_mulhom_edit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   40,    2, 0x0a /* Public */,
       7,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void hp_mulhom_edit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        hp_mulhom_edit *_t = static_cast<hp_mulhom_edit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_update_lcdoff_time((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->hp_mulhom_edit_value_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_toolButton_back_clicked(); break;
        case 3: _t->scrollBar_mulhom_mouseRelease(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hp_mulhom_edit::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_mulhom_edit::signal_update_lcdoff_time)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (hp_mulhom_edit::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_mulhom_edit::hp_mulhom_edit_value_changed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject hp_mulhom_edit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_hp_mulhom_edit.data,
      qt_meta_data_hp_mulhom_edit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *hp_mulhom_edit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hp_mulhom_edit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hp_mulhom_edit.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int hp_mulhom_edit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void hp_mulhom_edit::signal_update_lcdoff_time(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void hp_mulhom_edit::hp_mulhom_edit_value_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
