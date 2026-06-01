/****************************************************************************
** Meta object code from reading C++ file 'hpsebiao.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hpsebiao.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hpsebiao.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HpSebiao_t {
    QByteArrayData data[8];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HpSebiao_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HpSebiao_t qt_meta_stringdata_HpSebiao = {
    {
QT_MOC_LITERAL(0, 0, 8), // "HpSebiao"
QT_MOC_LITERAL(1, 9, 25), // "signal_update_lcdoff_time"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "iskey"
QT_MOC_LITERAL(4, 42, 25), // "signal_sebiao_set_reverse"
QT_MOC_LITERAL(5, 68, 9), // "isReverse"
QT_MOC_LITERAL(6, 78, 23), // "on_checkbox_set_reverse"
QT_MOC_LITERAL(7, 102, 9) // "isChecked"

    },
    "HpSebiao\0signal_update_lcdoff_time\0\0"
    "iskey\0signal_sebiao_set_reverse\0"
    "isReverse\0on_checkbox_set_reverse\0"
    "isChecked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HpSebiao[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void HpSebiao::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HpSebiao *_t = static_cast<HpSebiao *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_update_lcdoff_time((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->signal_sebiao_set_reverse((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_checkbox_set_reverse((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HpSebiao::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HpSebiao::signal_update_lcdoff_time)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HpSebiao::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HpSebiao::signal_sebiao_set_reverse)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HpSebiao::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HpSebiao.data,
      qt_meta_data_HpSebiao,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HpSebiao::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HpSebiao::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HpSebiao.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HpSebiao::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void HpSebiao::signal_update_lcdoff_time(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HpSebiao::signal_sebiao_set_reverse(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
