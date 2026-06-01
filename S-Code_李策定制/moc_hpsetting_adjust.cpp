/****************************************************************************
** Meta object code from reading C++ file 'hpsetting_adjust.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hpsetting_adjust.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hpsetting_adjust.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HpSetting_adjust_t {
    QByteArrayData data[6];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HpSetting_adjust_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HpSetting_adjust_t qt_meta_stringdata_HpSetting_adjust = {
    {
QT_MOC_LITERAL(0, 0, 16), // "HpSetting_adjust"
QT_MOC_LITERAL(1, 17, 29), // "signal_dangwei_jingtou_adjust"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 5), // "state"
QT_MOC_LITERAL(4, 54, 25), // "on_pushButton_ok_released"
QT_MOC_LITERAL(5, 80, 29) // "on_pushButton_cancel_released"

    },
    "HpSetting_adjust\0signal_dangwei_jingtou_adjust\0"
    "\0state\0on_pushButton_ok_released\0"
    "on_pushButton_cancel_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HpSetting_adjust[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HpSetting_adjust::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HpSetting_adjust *_t = static_cast<HpSetting_adjust *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_dangwei_jingtou_adjust((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_ok_released(); break;
        case 2: _t->on_pushButton_cancel_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HpSetting_adjust::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HpSetting_adjust::signal_dangwei_jingtou_adjust)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HpSetting_adjust::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HpSetting_adjust.data,
      qt_meta_data_HpSetting_adjust,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HpSetting_adjust::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HpSetting_adjust::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HpSetting_adjust.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HpSetting_adjust::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void HpSetting_adjust::signal_dangwei_jingtou_adjust(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
