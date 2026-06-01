/****************************************************************************
** Meta object code from reading C++ file 'hp_gstreamer_player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_gstreamer_player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_gstreamer_player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hp_gstreamer_player_t {
    QByteArrayData data[11];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hp_gstreamer_player_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hp_gstreamer_player_t qt_meta_stringdata_hp_gstreamer_player = {
    {
QT_MOC_LITERAL(0, 0, 19), // "hp_gstreamer_player"
QT_MOC_LITERAL(1, 20, 25), // "signal_update_lcdoff_time"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 5), // "iskey"
QT_MOC_LITERAL(4, 53, 12), // "slotTimerout"
QT_MOC_LITERAL(5, 66, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(6, 86, 7), // "checked"
QT_MOC_LITERAL(7, 94, 27), // "on_toolButton_close_clicked"
QT_MOC_LITERAL(8, 122, 29), // "on_verticalSlider_sliderMoved"
QT_MOC_LITERAL(9, 152, 8), // "position"
QT_MOC_LITERAL(10, 161, 27) // "on_toolButton_speed_clicked"

    },
    "hp_gstreamer_player\0signal_update_lcdoff_time\0"
    "\0iskey\0slotTimerout\0on_checkBox_clicked\0"
    "checked\0on_toolButton_close_clicked\0"
    "on_verticalSlider_sliderMoved\0position\0"
    "on_toolButton_speed_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hp_gstreamer_player[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,
       8,    1,   52,    2, 0x08 /* Private */,
      10,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

       0        // eod
};

void hp_gstreamer_player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        hp_gstreamer_player *_t = static_cast<hp_gstreamer_player *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_update_lcdoff_time((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->slotTimerout(); break;
        case 2: _t->on_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_toolButton_close_clicked(); break;
        case 4: _t->on_verticalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_toolButton_speed_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hp_gstreamer_player::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_gstreamer_player::signal_update_lcdoff_time)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject hp_gstreamer_player::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_hp_gstreamer_player.data,
      qt_meta_data_hp_gstreamer_player,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *hp_gstreamer_player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hp_gstreamer_player::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hp_gstreamer_player.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int hp_gstreamer_player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void hp_gstreamer_player::signal_update_lcdoff_time(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
