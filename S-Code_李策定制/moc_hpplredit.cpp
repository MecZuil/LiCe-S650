/****************************************************************************
** Meta object code from reading C++ file 'hpplredit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hpplredit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hpplredit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HpPLREdit_t {
    QByteArrayData data[21];
    char stringdata0[400];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HpPLREdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HpPLREdit_t qt_meta_stringdata_HpPLREdit = {
    {
QT_MOC_LITERAL(0, 0, 9), // "HpPLREdit"
QT_MOC_LITERAL(1, 10, 23), // "signal_temptype_changed"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "index"
QT_MOC_LITERAL(4, 41, 27), // "signal_part_radTable_change"
QT_MOC_LITERAL(5, 69, 2), // "id"
QT_MOC_LITERAL(6, 72, 5), // "value"
QT_MOC_LITERAL(7, 78, 25), // "signal_part_radTable_mode"
QT_MOC_LITERAL(8, 104, 4), // "mode"
QT_MOC_LITERAL(9, 109, 23), // "signal_cb_refer_clicked"
QT_MOC_LITERAL(10, 133, 7), // "checked"
QT_MOC_LITERAL(11, 141, 25), // "signal_update_lcdoff_time"
QT_MOC_LITERAL(12, 167, 5), // "isKey"
QT_MOC_LITERAL(13, 173, 27), // "SignalRefreshDisplayMaxRect"
QT_MOC_LITERAL(14, 201, 34), // "on_cb_temptype_currentIndexCh..."
QT_MOC_LITERAL(15, 236, 40), // "on_listWidget_temptype_curren..."
QT_MOC_LITERAL(16, 277, 10), // "currentRow"
QT_MOC_LITERAL(17, 288, 20), // "on_pb_cancle_clicked"
QT_MOC_LITERAL(18, 309, 20), // "on_pb_finish_clicked"
QT_MOC_LITERAL(19, 330, 28), // "on_checkBox_radiance_clicked"
QT_MOC_LITERAL(20, 359, 40) // "on_listWidget_radiance_curren..."

    },
    "HpPLREdit\0signal_temptype_changed\0\0"
    "index\0signal_part_radTable_change\0id\0"
    "value\0signal_part_radTable_mode\0mode\0"
    "signal_cb_refer_clicked\0checked\0"
    "signal_update_lcdoff_time\0isKey\0"
    "SignalRefreshDisplayMaxRect\0"
    "on_cb_temptype_currentIndexChanged\0"
    "on_listWidget_temptype_currentRowChanged\0"
    "currentRow\0on_pb_cancle_clicked\0"
    "on_pb_finish_clicked\0on_checkBox_radiance_clicked\0"
    "on_listWidget_radiance_currentRowChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HpPLREdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    2,   77,    2, 0x06 /* Public */,
       7,    1,   82,    2, 0x06 /* Public */,
       9,    1,   85,    2, 0x06 /* Public */,
      11,    1,   88,    2, 0x06 /* Public */,
      13,    0,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   92,    2, 0x08 /* Private */,
      15,    1,   95,    2, 0x08 /* Private */,
      17,    0,   98,    2, 0x08 /* Private */,
      18,    0,   99,    2, 0x08 /* Private */,
      19,    1,  100,    2, 0x08 /* Private */,
      20,    1,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void HpPLREdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HpPLREdit *_t = static_cast<HpPLREdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_temptype_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signal_part_radTable_change((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->signal_part_radTable_mode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->signal_cb_refer_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->signal_update_lcdoff_time((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->SignalRefreshDisplayMaxRect(); break;
        case 6: _t->on_cb_temptype_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_listWidget_temptype_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_pb_cancle_clicked(); break;
        case 9: _t->on_pb_finish_clicked(); break;
        case 10: _t->on_checkBox_radiance_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_listWidget_radiance_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HpPLREdit::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HpPLREdit::signal_temptype_changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HpPLREdit::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HpPLREdit::signal_part_radTable_change)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HpPLREdit::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HpPLREdit::signal_part_radTable_mode)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (HpPLREdit::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HpPLREdit::signal_cb_refer_clicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (HpPLREdit::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HpPLREdit::signal_update_lcdoff_time)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (HpPLREdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HpPLREdit::SignalRefreshDisplayMaxRect)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HpPLREdit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HpPLREdit.data,
      qt_meta_data_HpPLREdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HpPLREdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HpPLREdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HpPLREdit.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HpPLREdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void HpPLREdit::signal_temptype_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HpPLREdit::signal_part_radTable_change(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HpPLREdit::signal_part_radTable_mode(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HpPLREdit::signal_cb_refer_clicked(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void HpPLREdit::signal_update_lcdoff_time(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void HpPLREdit::SignalRefreshDisplayMaxRect()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
