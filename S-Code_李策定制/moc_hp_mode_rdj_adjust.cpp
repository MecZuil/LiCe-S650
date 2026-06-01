/****************************************************************************
** Meta object code from reading C++ file 'hp_mode_rdj_adjust.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_mode_rdj_adjust.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_mode_rdj_adjust.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Hp_Mode_Rdj_Adjust_t {
    QByteArrayData data[16];
    char stringdata0[368];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Hp_Mode_Rdj_Adjust_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Hp_Mode_Rdj_Adjust_t qt_meta_stringdata_Hp_Mode_Rdj_Adjust = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Hp_Mode_Rdj_Adjust"
QT_MOC_LITERAL(1, 19, 16), // "sync_fusion_para"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 25), // "signal_update_lcdoff_time"
QT_MOC_LITERAL(4, 63, 5), // "iskey"
QT_MOC_LITERAL(5, 69, 34), // "on_doubleSpinBox_high_valueCh..."
QT_MOC_LITERAL(6, 104, 4), // "arg1"
QT_MOC_LITERAL(7, 109, 33), // "on_doubleSpinBox_low_valueCha..."
QT_MOC_LITERAL(8, 143, 35), // "on_doubleSpinBox_above_valueC..."
QT_MOC_LITERAL(9, 179, 35), // "on_doubleSpinBox_below_valueC..."
QT_MOC_LITERAL(10, 215, 30), // "on_toolButton_default_released"
QT_MOC_LITERAL(11, 246, 29), // "on_toolButton_finish_released"
QT_MOC_LITERAL(12, 276, 33), // "rdj_current_current_index_cha..."
QT_MOC_LITERAL(13, 310, 5), // "value"
QT_MOC_LITERAL(14, 316, 40), // "on_listWidget_rdj_type_curren..."
QT_MOC_LITERAL(15, 357, 10) // "currentRow"

    },
    "Hp_Mode_Rdj_Adjust\0sync_fusion_para\0"
    "\0signal_update_lcdoff_time\0iskey\0"
    "on_doubleSpinBox_high_valueChanged\0"
    "arg1\0on_doubleSpinBox_low_valueChanged\0"
    "on_doubleSpinBox_above_valueChanged\0"
    "on_doubleSpinBox_below_valueChanged\0"
    "on_toolButton_default_released\0"
    "on_toolButton_finish_released\0"
    "rdj_current_current_index_changed\0"
    "value\0on_listWidget_rdj_type_currentRowChanged\0"
    "currentRow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hp_Mode_Rdj_Adjust[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   68,    2, 0x08 /* Private */,
       7,    1,   71,    2, 0x08 /* Private */,
       8,    1,   74,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      10,    0,   80,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,
      12,    1,   82,    2, 0x08 /* Private */,
      14,    1,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

void Hp_Mode_Rdj_Adjust::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Hp_Mode_Rdj_Adjust *_t = static_cast<Hp_Mode_Rdj_Adjust *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sync_fusion_para(); break;
        case 1: _t->signal_update_lcdoff_time((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_doubleSpinBox_high_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_doubleSpinBox_low_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_doubleSpinBox_above_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_doubleSpinBox_below_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_toolButton_default_released(); break;
        case 7: _t->on_toolButton_finish_released(); break;
        case 8: _t->rdj_current_current_index_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_listWidget_rdj_type_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Hp_Mode_Rdj_Adjust::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Mode_Rdj_Adjust::sync_fusion_para)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Hp_Mode_Rdj_Adjust::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_Mode_Rdj_Adjust::signal_update_lcdoff_time)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Hp_Mode_Rdj_Adjust::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Hp_Mode_Rdj_Adjust.data,
      qt_meta_data_Hp_Mode_Rdj_Adjust,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Hp_Mode_Rdj_Adjust::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hp_Mode_Rdj_Adjust::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Hp_Mode_Rdj_Adjust.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Hp_Mode_Rdj_Adjust::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Hp_Mode_Rdj_Adjust::sync_fusion_para()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Hp_Mode_Rdj_Adjust::signal_update_lcdoff_time(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
