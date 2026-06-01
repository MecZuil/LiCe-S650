/****************************************************************************
** Meta object code from reading C++ file 'hp_poweroff_warn.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_poweroff_warn.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_poweroff_warn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HP_Poweroff_Warn_t {
    QByteArrayData data[5];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HP_Poweroff_Warn_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HP_Poweroff_Warn_t qt_meta_stringdata_HP_Poweroff_Warn = {
    {
QT_MOC_LITERAL(0, 0, 16), // "HP_Poweroff_Warn"
QT_MOC_LITERAL(1, 17, 31), // "chongdian_on_toolButton_clicked"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 21), // "on_toolButton_clicked"
QT_MOC_LITERAL(4, 72, 7) // "checked"

    },
    "HP_Poweroff_Warn\0chongdian_on_toolButton_clicked\0"
    "\0on_toolButton_clicked\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HP_Poweroff_Warn[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

       0        // eod
};

void HP_Poweroff_Warn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HP_Poweroff_Warn *_t = static_cast<HP_Poweroff_Warn *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->chongdian_on_toolButton_clicked(); break;
        case 1: _t->on_toolButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HP_Poweroff_Warn::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HP_Poweroff_Warn.data,
      qt_meta_data_HP_Poweroff_Warn,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HP_Poweroff_Warn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HP_Poweroff_Warn::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HP_Poweroff_Warn.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HP_Poweroff_Warn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
