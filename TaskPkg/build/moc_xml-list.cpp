/****************************************************************************
** Meta object code from reading C++ file 'xml-list.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../machine/xml-list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xml-list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_XmlList_t {
    QByteArrayData data[14];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XmlList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XmlList_t qt_meta_stringdata_XmlList = {
    {
QT_MOC_LITERAL(0, 0, 7), // "XmlList"
QT_MOC_LITERAL(1, 8, 13), // "init_xml_list"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "uinit_xml_list"
QT_MOC_LITERAL(4, 38, 16), // "jump_to_pre_page"
QT_MOC_LITERAL(5, 55, 17), // "jump_to_next_page"
QT_MOC_LITERAL(6, 73, 16), // "get_current_page"
QT_MOC_LITERAL(7, 90, 14), // "get_total_page"
QT_MOC_LITERAL(8, 105, 26), // "get_current_page_xml_count"
QT_MOC_LITERAL(9, 132, 19), // "get_total_xml_count"
QT_MOC_LITERAL(10, 152, 28), // "get_currentPage_xml_by_index"
QT_MOC_LITERAL(11, 181, 5), // "index"
QT_MOC_LITERAL(12, 187, 20), // "set_select_xml_index"
QT_MOC_LITERAL(13, 208, 16) // "del_xml_by_index"

    },
    "XmlList\0init_xml_list\0\0uinit_xml_list\0"
    "jump_to_pre_page\0jump_to_next_page\0"
    "get_current_page\0get_total_page\0"
    "get_current_page_xml_count\0"
    "get_total_xml_count\0get_currentPage_xml_by_index\0"
    "index\0set_select_xml_index\0del_xml_by_index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XmlList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x02 /* Public */,
       3,    0,   70,    2, 0x02 /* Public */,
       4,    0,   71,    2, 0x02 /* Public */,
       5,    0,   72,    2, 0x02 /* Public */,
       6,    0,   73,    2, 0x02 /* Public */,
       7,    0,   74,    2, 0x02 /* Public */,
       8,    0,   75,    2, 0x02 /* Public */,
       9,    0,   76,    2, 0x02 /* Public */,
      10,    1,   77,    2, 0x02 /* Public */,
      12,    1,   80,    2, 0x02 /* Public */,
      13,    1,   83,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void XmlList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XmlList *_t = static_cast<XmlList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->init_xml_list();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->uinit_xml_list();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->jump_to_pre_page();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->jump_to_next_page();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->get_current_page();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->get_total_page();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->get_current_page_xml_count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->get_total_xml_count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->get_currentPage_xml_by_index((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->set_select_xml_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->del_xml_by_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject XmlList::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_XmlList.data,
      qt_meta_data_XmlList,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *XmlList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XmlList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XmlList.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int XmlList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
