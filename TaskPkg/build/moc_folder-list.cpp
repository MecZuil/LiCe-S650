/****************************************************************************
** Meta object code from reading C++ file 'folder-list.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../machine/folder-list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'folder-list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FolderList_t {
    QByteArrayData data[17];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FolderList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FolderList_t qt_meta_stringdata_FolderList = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FolderList"
QT_MOC_LITERAL(1, 11, 28), // "signal_delete_table_analysis"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 9), // "tableName"
QT_MOC_LITERAL(4, 51, 15), // "add_folder_list"
QT_MOC_LITERAL(5, 67, 16), // "get_folder_count"
QT_MOC_LITERAL(6, 84, 15), // "get_folder_name"
QT_MOC_LITERAL(7, 100, 1), // "i"
QT_MOC_LITERAL(8, 102, 14), // "get_folder_pos"
QT_MOC_LITERAL(9, 117, 15), // "str_folder_name"
QT_MOC_LITERAL(10, 133, 13), // "delete_folder"
QT_MOC_LITERAL(11, 147, 20), // "get_task_select_list"
QT_MOC_LITERAL(12, 168, 21), // "get_task_select_count"
QT_MOC_LITERAL(13, 190, 20), // "get_task_select_name"
QT_MOC_LITERAL(14, 211, 19), // "get_task_select_pos"
QT_MOC_LITERAL(15, 231, 20), // "str_task_select_name"
QT_MOC_LITERAL(16, 252, 18) // "delete_task_select"

    },
    "FolderList\0signal_delete_table_analysis\0"
    "\0tableName\0add_folder_list\0get_folder_count\0"
    "get_folder_name\0i\0get_folder_pos\0"
    "str_folder_name\0delete_folder\0"
    "get_task_select_list\0get_task_select_count\0"
    "get_task_select_name\0get_task_select_pos\0"
    "str_task_select_name\0delete_task_select"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FolderList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    0,   72,    2, 0x02 /* Public */,
       5,    0,   73,    2, 0x02 /* Public */,
       6,    1,   74,    2, 0x02 /* Public */,
       8,    1,   77,    2, 0x02 /* Public */,
      10,    1,   80,    2, 0x02 /* Public */,
      11,    0,   83,    2, 0x02 /* Public */,
      12,    0,   84,    2, 0x02 /* Public */,
      13,    1,   85,    2, 0x02 /* Public */,
      14,    1,   88,    2, 0x02 /* Public */,
      16,    1,   91,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,    7,
    QMetaType::Int, QMetaType::QString,    9,
    QMetaType::Bool, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,    7,
    QMetaType::Int, QMetaType::QString,   15,
    QMetaType::Bool, QMetaType::QString,   15,

       0        // eod
};

void FolderList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FolderList *_t = static_cast<FolderList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_delete_table_analysis((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->add_folder_list(); break;
        case 2: { int _r = _t->get_folder_count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->get_folder_name((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->get_folder_pos((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->delete_folder((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->get_task_select_list(); break;
        case 7: { int _r = _t->get_task_select_count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->get_task_select_name((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->get_task_select_pos((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->delete_task_select((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FolderList::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FolderList::signal_delete_table_analysis)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FolderList::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FolderList.data,
      qt_meta_data_FolderList,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FolderList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FolderList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FolderList.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FolderList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void FolderList::signal_delete_table_analysis(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
