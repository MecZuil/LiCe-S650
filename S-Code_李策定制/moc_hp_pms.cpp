/****************************************************************************
** Meta object code from reading C++ file 'hp_pms.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_pms.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_pms.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hp_pms_t {
    QByteArrayData data[17];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hp_pms_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hp_pms_t qt_meta_stringdata_hp_pms = {
    {
QT_MOC_LITERAL(0, 0, 6), // "hp_pms"
QT_MOC_LITERAL(1, 7, 20), // "signal_selectChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "index"
QT_MOC_LITERAL(4, 35, 16), // "signal_close_pms"
QT_MOC_LITERAL(5, 52, 19), // "signal_take_picture"
QT_MOC_LITERAL(6, 72, 16), // "signal_set_focus"
QT_MOC_LITERAL(7, 89, 21), // "signal_upload_pms_dat"
QT_MOC_LITERAL(8, 111, 29), // "signal_relink_last_ble_server"
QT_MOC_LITERAL(9, 141, 29), // "m_hpListWidget_currentChanged"
QT_MOC_LITERAL(10, 171, 10), // "currentRow"
QT_MOC_LITERAL(11, 182, 21), // "on_toolButton_clicked"
QT_MOC_LITERAL(12, 204, 21), // "on_pms_upload_clicked"
QT_MOC_LITERAL(13, 226, 25), // "on_listWidget_itemChanged"
QT_MOC_LITERAL(14, 252, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(15, 269, 4), // "item"
QT_MOC_LITERAL(16, 274, 23) // "on_pms_upload_2_clicked"

    },
    "hp_pms\0signal_selectChanged\0\0index\0"
    "signal_close_pms\0signal_take_picture\0"
    "signal_set_focus\0signal_upload_pms_dat\0"
    "signal_relink_last_ble_server\0"
    "m_hpListWidget_currentChanged\0currentRow\0"
    "on_toolButton_clicked\0on_pms_upload_clicked\0"
    "on_listWidget_itemChanged\0QListWidgetItem*\0"
    "item\0on_pms_upload_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hp_pms[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    0,   72,    2, 0x06 /* Public */,
       5,    0,   73,    2, 0x06 /* Public */,
       6,    0,   74,    2, 0x06 /* Public */,
       7,    0,   75,    2, 0x06 /* Public */,
       8,    0,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   77,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    1,   82,    2, 0x08 /* Private */,
      16,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,

       0        // eod
};

void hp_pms::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        hp_pms *_t = static_cast<hp_pms *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_selectChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signal_close_pms(); break;
        case 2: _t->signal_take_picture(); break;
        case 3: _t->signal_set_focus(); break;
        case 4: _t->signal_upload_pms_dat(); break;
        case 5: _t->signal_relink_last_ble_server(); break;
        case 6: _t->m_hpListWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_toolButton_clicked(); break;
        case 8: _t->on_pms_upload_clicked(); break;
        case 9: _t->on_listWidget_itemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->on_pms_upload_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hp_pms::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_pms::signal_selectChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (hp_pms::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_pms::signal_close_pms)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (hp_pms::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_pms::signal_take_picture)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (hp_pms::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_pms::signal_set_focus)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (hp_pms::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_pms::signal_upload_pms_dat)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (hp_pms::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_pms::signal_relink_last_ble_server)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject hp_pms::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_hp_pms.data,
      qt_meta_data_hp_pms,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *hp_pms::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hp_pms::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hp_pms.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int hp_pms::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void hp_pms::signal_selectChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void hp_pms::signal_close_pms()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void hp_pms::signal_take_picture()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void hp_pms::signal_set_focus()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void hp_pms::signal_upload_pms_dat()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void hp_pms::signal_relink_last_ble_server()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
