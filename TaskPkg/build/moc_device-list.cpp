/****************************************************************************
** Meta object code from reading C++ file 'device-list.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../machine/device-list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'device-list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeviceList_t {
    QByteArrayData data[10];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceList_t qt_meta_stringdata_DeviceList = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DeviceList"
QT_MOC_LITERAL(1, 11, 15), // "device_selected"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 20), // "outline_ana_selected"
QT_MOC_LITERAL(4, 49, 18), // "fold_list_for_path"
QT_MOC_LITERAL(5, 68, 20), // "device_save_over_sgl"
QT_MOC_LITERAL(6, 89, 17), // "device_tree_ready"
QT_MOC_LITERAL(7, 107, 15), // "level_tree_init"
QT_MOC_LITERAL(8, 123, 18), // "device_save_change"
QT_MOC_LITERAL(9, 142, 15) // "device_shoot_ok"

    },
    "DeviceList\0device_selected\0\0"
    "outline_ana_selected\0fold_list_for_path\0"
    "device_save_over_sgl\0device_tree_ready\0"
    "level_tree_init\0device_save_change\0"
    "device_shoot_ok"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    2,   57,    2, 0x06 /* Public */,
       4,    0,   62,    2, 0x06 /* Public */,
       5,    0,   63,    2, 0x06 /* Public */,
       6,    0,   64,    2, 0x06 /* Public */,
       7,    0,   65,    2, 0x06 /* Public */,
       8,    0,   66,    2, 0x06 /* Public */,
       9,    2,   67,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

void DeviceList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DeviceList *_t = static_cast<DeviceList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->device_selected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->outline_ana_selected((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 2: _t->fold_list_for_path(); break;
        case 3: _t->device_save_over_sgl(); break;
        case 4: _t->device_tree_ready(); break;
        case 5: _t->level_tree_init(); break;
        case 6: _t->device_save_change(); break;
        case 7: _t->device_shoot_ok((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeviceList::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceList::device_selected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DeviceList::*)(QStringList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceList::outline_ana_selected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DeviceList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceList::fold_list_for_path)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DeviceList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceList::device_save_over_sgl)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DeviceList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceList::device_tree_ready)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DeviceList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceList::level_tree_init)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DeviceList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceList::device_save_change)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (DeviceList::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceList::device_shoot_ok)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DeviceList::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DeviceList.data,
      qt_meta_data_DeviceList,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DeviceList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceList.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DeviceList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DeviceList::device_selected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DeviceList::outline_ana_selected(QStringList _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DeviceList::fold_list_for_path()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DeviceList::device_save_over_sgl()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void DeviceList::device_tree_ready()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void DeviceList::level_tree_init()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void DeviceList::device_save_change()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void DeviceList::device_shoot_ok(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
