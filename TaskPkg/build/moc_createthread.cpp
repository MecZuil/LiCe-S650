/****************************************************************************
** Meta object code from reading C++ file 'createthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../analysis/createthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_createThread_t {
    QByteArrayData data[23];
    char stringdata0[353];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_createThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_createThread_t qt_meta_stringdata_createThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "createThread"
QT_MOC_LITERAL(1, 13, 14), // "get_unit_count"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "get_unit_name"
QT_MOC_LITERAL(4, 43, 5), // "index"
QT_MOC_LITERAL(5, 49, 21), // "get_historyData_count"
QT_MOC_LITERAL(6, 71, 11), // "get_maxTemp"
QT_MOC_LITERAL(7, 83, 11), // "get_minTemp"
QT_MOC_LITERAL(8, 95, 17), // "get_temp_by_index"
QT_MOC_LITERAL(9, 113, 11), // "deviceIndex"
QT_MOC_LITERAL(10, 125, 9), // "partIndex"
QT_MOC_LITERAL(11, 135, 19), // "reset_current_index"
QT_MOC_LITERAL(12, 155, 17), // "pre_current_index"
QT_MOC_LITERAL(13, 173, 18), // "next_current_index"
QT_MOC_LITERAL(14, 192, 18), // "get_pre_btn_status"
QT_MOC_LITERAL(15, 211, 19), // "get_next_btn_status"
QT_MOC_LITERAL(16, 231, 17), // "get_current_index"
QT_MOC_LITERAL(17, 249, 21), // "exist_history_by_info"
QT_MOC_LITERAL(18, 271, 14), // "QList<QString>"
QT_MOC_LITERAL(19, 286, 8), // "infoList"
QT_MOC_LITERAL(20, 295, 18), // "reset_capture_flag"
QT_MOC_LITERAL(21, 314, 27), // "reset_capture_flag_by_index"
QT_MOC_LITERAL(22, 342, 10) // "deviceInfo"

    },
    "createThread\0get_unit_count\0\0get_unit_name\0"
    "index\0get_historyData_count\0get_maxTemp\0"
    "get_minTemp\0get_temp_by_index\0deviceIndex\0"
    "partIndex\0reset_current_index\0"
    "pre_current_index\0next_current_index\0"
    "get_pre_btn_status\0get_next_btn_status\0"
    "get_current_index\0exist_history_by_info\0"
    "QList<QString>\0infoList\0reset_capture_flag\0"
    "reset_capture_flag_by_index\0deviceInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_createThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x02 /* Public */,
       3,    1,   90,    2, 0x02 /* Public */,
       5,    0,   93,    2, 0x02 /* Public */,
       6,    0,   94,    2, 0x02 /* Public */,
       7,    0,   95,    2, 0x02 /* Public */,
       8,    2,   96,    2, 0x02 /* Public */,
      11,    1,  101,    2, 0x02 /* Public */,
      12,    0,  104,    2, 0x02 /* Public */,
      13,    0,  105,    2, 0x02 /* Public */,
      14,    0,  106,    2, 0x02 /* Public */,
      15,    0,  107,    2, 0x02 /* Public */,
      16,    0,  108,    2, 0x02 /* Public */,
      17,    1,  109,    2, 0x02 /* Public */,
      20,    0,  112,    2, 0x02 /* Public */,
      21,    1,  113,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,    4,
    QMetaType::Int,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Int,
    QMetaType::Int, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,

       0        // eod
};

void createThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        createThread *_t = static_cast<createThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->get_unit_count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->get_unit_name((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->get_historyData_count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { float _r = _t->get_maxTemp();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 4: { float _r = _t->get_minTemp();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 5: { float _r = _t->get_temp_by_index((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->reset_current_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->pre_current_index(); break;
        case 8: _t->next_current_index(); break;
        case 9: { bool _r = _t->get_pre_btn_status();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->get_next_btn_status();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->get_current_index();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->exist_history_by_info((*reinterpret_cast< QList<QString>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->reset_capture_flag(); break;
        case 14: _t->reset_capture_flag_by_index((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject createThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_createThread.data,
      qt_meta_data_createThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *createThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *createThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_createThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int createThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
