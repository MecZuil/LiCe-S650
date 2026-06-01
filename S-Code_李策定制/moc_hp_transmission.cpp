/****************************************************************************
** Meta object code from reading C++ file 'hp_transmission.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_transmission.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_transmission.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hp_transmission_t {
    QByteArrayData data[34];
    char stringdata0[603];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hp_transmission_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hp_transmission_t qt_meta_stringdata_hp_transmission = {
    {
QT_MOC_LITERAL(0, 0, 15), // "hp_transmission"
QT_MOC_LITERAL(1, 16, 28), // "signal_set_transmission_addr"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 4), // "addr"
QT_MOC_LITERAL(4, 51, 29), // "signal_transmission_init_over"
QT_MOC_LITERAL(5, 81, 32), // "signal_transmission_allow_upload"
QT_MOC_LITERAL(6, 114, 34), // "signal_transmission_send_hear..."
QT_MOC_LITERAL(7, 149, 32), // "signal_transmission_get_download"
QT_MOC_LITERAL(8, 182, 23), // "signal_stop_get_bleInfo"
QT_MOC_LITERAL(9, 206, 7), // "bleInfo"
QT_MOC_LITERAL(10, 214, 39), // "signal_transmission_send_uplo..."
QT_MOC_LITERAL(11, 254, 22), // "slot_link_transmission"
QT_MOC_LITERAL(12, 277, 18), // "slot_start_get_xml"
QT_MOC_LITERAL(13, 296, 22), // "slot_start_get_bleInfo"
QT_MOC_LITERAL(14, 319, 21), // "slot_stop_get_bleInfo"
QT_MOC_LITERAL(15, 341, 10), // "setBleMode"
QT_MOC_LITERAL(16, 352, 4), // "mode"
QT_MOC_LITERAL(17, 357, 27), // "slot_timer_get_ble_link_msg"
QT_MOC_LITERAL(18, 385, 21), // "hp_start_transmission"
QT_MOC_LITERAL(19, 407, 20), // "hp_stop_transmission"
QT_MOC_LITERAL(20, 428, 17), // "hp_upload_xml_dat"
QT_MOC_LITERAL(21, 446, 14), // "uploadFileList"
QT_MOC_LITERAL(22, 461, 11), // "datFilePath"
QT_MOC_LITERAL(23, 473, 11), // "xmlFilePath"
QT_MOC_LITERAL(24, 485, 5), // "isZip"
QT_MOC_LITERAL(25, 491, 17), // "packDatFilesToZip"
QT_MOC_LITERAL(26, 509, 8), // "datFiles"
QT_MOC_LITERAL(27, 518, 13), // "outputZipPath"
QT_MOC_LITERAL(28, 532, 13), // "createDatFile"
QT_MOC_LITERAL(29, 546, 17), // "hp_setFactoryName"
QT_MOC_LITERAL(30, 564, 11), // "factoryName"
QT_MOC_LITERAL(31, 576, 13), // "hp_setEquipID"
QT_MOC_LITERAL(32, 590, 9), // "equipType"
QT_MOC_LITERAL(33, 600, 2) // "ID"

    },
    "hp_transmission\0signal_set_transmission_addr\0"
    "\0addr\0signal_transmission_init_over\0"
    "signal_transmission_allow_upload\0"
    "signal_transmission_send_heartbeat\0"
    "signal_transmission_get_download\0"
    "signal_stop_get_bleInfo\0bleInfo\0"
    "signal_transmission_send_upload_success\0"
    "slot_link_transmission\0slot_start_get_xml\0"
    "slot_start_get_bleInfo\0slot_stop_get_bleInfo\0"
    "setBleMode\0mode\0slot_timer_get_ble_link_msg\0"
    "hp_start_transmission\0hp_stop_transmission\0"
    "hp_upload_xml_dat\0uploadFileList\0"
    "datFilePath\0xmlFilePath\0isZip\0"
    "packDatFilesToZip\0datFiles\0outputZipPath\0"
    "createDatFile\0hp_setFactoryName\0"
    "factoryName\0hp_setEquipID\0equipType\0"
    "ID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hp_transmission[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       4,    0,  122,    2, 0x06 /* Public */,
       5,    0,  123,    2, 0x06 /* Public */,
       6,    0,  124,    2, 0x06 /* Public */,
       7,    0,  125,    2, 0x06 /* Public */,
       8,    1,  126,    2, 0x06 /* Public */,
      10,    0,  129,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  130,    2, 0x0a /* Public */,
      12,    0,  133,    2, 0x0a /* Public */,
      13,    0,  134,    2, 0x0a /* Public */,
      14,    1,  135,    2, 0x0a /* Public */,
      15,    1,  138,    2, 0x0a /* Public */,
      17,    0,  141,    2, 0x0a /* Public */,
      18,    0,  142,    2, 0x0a /* Public */,
      19,    0,  143,    2, 0x0a /* Public */,
      20,    4,  144,    2, 0x0a /* Public */,
      25,    2,  153,    2, 0x0a /* Public */,
      25,    1,  158,    2, 0x2a /* Public | MethodCloned */,
      28,    1,  161,    2, 0x0a /* Public */,
      29,    1,  164,    2, 0x0a /* Public */,
      31,    2,  167,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   21,   22,   23,   24,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString,   26,   27,
    QMetaType::Void, QMetaType::QStringList,   26,
    QMetaType::QString, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::QString,   30,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   32,   33,

       0        // eod
};

void hp_transmission::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        hp_transmission *_t = static_cast<hp_transmission *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_set_transmission_addr((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signal_transmission_init_over(); break;
        case 2: _t->signal_transmission_allow_upload(); break;
        case 3: _t->signal_transmission_send_heartbeat(); break;
        case 4: _t->signal_transmission_get_download(); break;
        case 5: _t->signal_stop_get_bleInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->signal_transmission_send_upload_success(); break;
        case 7: _t->slot_link_transmission((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->slot_start_get_xml(); break;
        case 9: _t->slot_start_get_bleInfo(); break;
        case 10: _t->slot_stop_get_bleInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->setBleMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->slot_timer_get_ble_link_msg(); break;
        case 13: _t->hp_start_transmission(); break;
        case 14: _t->hp_stop_transmission(); break;
        case 15: _t->hp_upload_xml_dat((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 16: _t->packDatFilesToZip((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 17: _t->packDatFilesToZip((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 18: { QString _r = _t->createDatFile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->hp_setFactoryName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->hp_setEquipID((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hp_transmission::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_transmission::signal_set_transmission_addr)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (hp_transmission::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_transmission::signal_transmission_init_over)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (hp_transmission::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_transmission::signal_transmission_allow_upload)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (hp_transmission::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_transmission::signal_transmission_send_heartbeat)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (hp_transmission::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_transmission::signal_transmission_get_download)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (hp_transmission::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_transmission::signal_stop_get_bleInfo)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (hp_transmission::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_transmission::signal_transmission_send_upload_success)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject hp_transmission::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_hp_transmission.data,
      qt_meta_data_hp_transmission,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *hp_transmission::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hp_transmission::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hp_transmission.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int hp_transmission::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void hp_transmission::signal_set_transmission_addr(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void hp_transmission::signal_transmission_init_over()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void hp_transmission::signal_transmission_allow_upload()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void hp_transmission::signal_transmission_send_heartbeat()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void hp_transmission::signal_transmission_get_download()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void hp_transmission::signal_stop_get_bleInfo(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void hp_transmission::signal_transmission_send_upload_success()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
