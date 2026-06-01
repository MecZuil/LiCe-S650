/****************************************************************************
** Meta object code from reading C++ file 'hp_hir_player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_hir_player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_hir_player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hp_hir_player_t {
    QByteArrayData data[22];
    char stringdata0[457];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hp_hir_player_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hp_hir_player_t qt_meta_stringdata_hp_hir_player = {
    {
QT_MOC_LITERAL(0, 0, 13), // "hp_hir_player"
QT_MOC_LITERAL(1, 14, 36), // "signal_core_analysis_hir_twic..."
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 5), // "char*"
QT_MOC_LITERAL(4, 58, 4), // "name"
QT_MOC_LITERAL(5, 63, 38), // "signal_core_annlysis_hir_twic..."
QT_MOC_LITERAL(6, 102, 4), // "type"
QT_MOC_LITERAL(7, 107, 39), // "signal_core_analysis_hir_twic..."
QT_MOC_LITERAL(8, 147, 24), // "signal_start_hir_analyse"
QT_MOC_LITERAL(9, 172, 8), // "filename"
QT_MOC_LITERAL(10, 181, 7), // "checked"
QT_MOC_LITERAL(11, 189, 31), // "signal_core_get_hir_play_status"
QT_MOC_LITERAL(12, 221, 24), // "signal_playstatusTimeout"
QT_MOC_LITERAL(13, 246, 30), // "signal_hir_analyse_get_measure"
QT_MOC_LITERAL(14, 277, 20), // "signal_clear_measure"
QT_MOC_LITERAL(15, 298, 28), // "on_toolButton_close_released"
QT_MOC_LITERAL(16, 327, 29), // "slot_core_get_hir_play_status"
QT_MOC_LITERAL(17, 357, 12), // "return_value"
QT_MOC_LITERAL(18, 370, 5), // "value"
QT_MOC_LITERAL(19, 376, 17), // "playstatusTimeout"
QT_MOC_LITERAL(20, 394, 27), // "on_toolButton_pause_clicked"
QT_MOC_LITERAL(21, 422, 34) // "on_toolButton_hir_analyse_rel..."

    },
    "hp_hir_player\0signal_core_analysis_hir_twice_start\0"
    "\0char*\0name\0signal_core_annlysis_hir_twice_suspend\0"
    "type\0signal_core_analysis_hir_twice_stop_cut\0"
    "signal_start_hir_analyse\0filename\0"
    "checked\0signal_core_get_hir_play_status\0"
    "signal_playstatusTimeout\0"
    "signal_hir_analyse_get_measure\0"
    "signal_clear_measure\0on_toolButton_close_released\0"
    "slot_core_get_hir_play_status\0"
    "return_value\0value\0playstatusTimeout\0"
    "on_toolButton_pause_clicked\0"
    "on_toolButton_hir_analyse_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hp_hir_player[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       5,    1,   82,    2, 0x06 /* Public */,
       7,    0,   85,    2, 0x06 /* Public */,
       8,    2,   86,    2, 0x06 /* Public */,
      11,    0,   91,    2, 0x06 /* Public */,
      12,    0,   92,    2, 0x06 /* Public */,
      13,    0,   93,    2, 0x06 /* Public */,
      14,    0,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,   95,    2, 0x0a /* Public */,
      16,    2,   96,    2, 0x0a /* Public */,
      19,    0,  101,    2, 0x0a /* Public */,
      20,    1,  102,    2, 0x08 /* Private */,
      21,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::Int,   17,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,

       0        // eod
};

void hp_hir_player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        hp_hir_player *_t = static_cast<hp_hir_player *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_core_analysis_hir_twice_start((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 1: _t->signal_core_annlysis_hir_twice_suspend((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signal_core_analysis_hir_twice_stop_cut(); break;
        case 3: _t->signal_start_hir_analyse((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->signal_core_get_hir_play_status(); break;
        case 5: _t->signal_playstatusTimeout(); break;
        case 6: _t->signal_hir_analyse_get_measure(); break;
        case 7: _t->signal_clear_measure(); break;
        case 8: _t->on_toolButton_close_released(); break;
        case 9: _t->slot_core_get_hir_play_status((*reinterpret_cast< unsigned char(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->playstatusTimeout(); break;
        case 11: _t->on_toolButton_pause_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_toolButton_hir_analyse_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hp_hir_player::*)(char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_hir_player::signal_core_analysis_hir_twice_start)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (hp_hir_player::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_hir_player::signal_core_annlysis_hir_twice_suspend)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (hp_hir_player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_hir_player::signal_core_analysis_hir_twice_stop_cut)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (hp_hir_player::*)(QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_hir_player::signal_start_hir_analyse)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (hp_hir_player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_hir_player::signal_core_get_hir_play_status)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (hp_hir_player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_hir_player::signal_playstatusTimeout)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (hp_hir_player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_hir_player::signal_hir_analyse_get_measure)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (hp_hir_player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hp_hir_player::signal_clear_measure)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject hp_hir_player::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_hp_hir_player.data,
      qt_meta_data_hp_hir_player,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *hp_hir_player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hp_hir_player::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hp_hir_player.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int hp_hir_player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void hp_hir_player::signal_core_analysis_hir_twice_start(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void hp_hir_player::signal_core_annlysis_hir_twice_suspend(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void hp_hir_player::signal_core_analysis_hir_twice_stop_cut()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void hp_hir_player::signal_start_hir_analyse(QString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void hp_hir_player::signal_core_get_hir_play_status()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void hp_hir_player::signal_playstatusTimeout()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void hp_hir_player::signal_hir_analyse_get_measure()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void hp_hir_player::signal_clear_measure()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
