/****************************************************************************
** Meta object code from reading C++ file 'hp_sis_content.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_sis_content.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_sis_content.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hp_sis_content_t {
    QByteArrayData data[9];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hp_sis_content_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hp_sis_content_t qt_meta_stringdata_hp_sis_content = {
    {
QT_MOC_LITERAL(0, 0, 14), // "hp_sis_content"
QT_MOC_LITERAL(1, 15, 33), // "signal_on_pushButton_ok_or_ca..."
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 4), // "text"
QT_MOC_LITERAL(4, 55, 19), // "slot_set_label_text"
QT_MOC_LITERAL(5, 75, 14), // "unsigned char*"
QT_MOC_LITERAL(6, 90, 4), // "data"
QT_MOC_LITERAL(7, 95, 25), // "on_pushButton_ok_released"
QT_MOC_LITERAL(8, 121, 29) // "on_pushButton_cancel_released"

    },
    "hp_sis_content\0signal_on_pushButton_ok_or_cannal\0"
    "\0text\0slot_set_label_text\0unsigned char*\0"
    "data\0on_pushButton_ok_released\0"
    "on_pushButton_cancel_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hp_sis_content[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   39,    2, 0x0a /* Public */,
       7,    0,   42,    2, 0x08 /* Private */,
       8,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void hp_sis_content::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        hp_sis_content *_t = static_cast<hp_sis_content *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_on_pushButton_ok_or_cannal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->slot_set_label_text((*reinterpret_cast< unsigned char*(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_ok_released(); break;
        case 3: _t->on_pushButton_cancel_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hp_sis_content::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_sis_content::signal_on_pushButton_ok_or_cannal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject hp_sis_content::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_hp_sis_content.data,
      qt_meta_data_hp_sis_content,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *hp_sis_content::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hp_sis_content::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hp_sis_content.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int hp_sis_content::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void hp_sis_content::signal_on_pushButton_ok_or_cannal(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
