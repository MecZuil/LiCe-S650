/****************************************************************************
** Meta object code from reading C++ file 'select-task-dlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../machine/select-task-dlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'select-task-dlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SelectTaskDlg_t {
    QByteArrayData data[8];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelectTaskDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelectTaskDlg_t qt_meta_stringdata_SelectTaskDlg = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SelectTaskDlg"
QT_MOC_LITERAL(1, 14, 18), // "regist_is_activate"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 21), // "down_btn_pressed_slot"
QT_MOC_LITERAL(4, 56, 23), // "cancel_btn_pressed_slot"
QT_MOC_LITERAL(5, 80, 19), // "ok_btn_pressed_slot"
QT_MOC_LITERAL(6, 100, 20), // "ok_btn_continue_slot"
QT_MOC_LITERAL(7, 121, 19) // "up_btn_pressed_slot"

    },
    "SelectTaskDlg\0regist_is_activate\0\0"
    "down_btn_pressed_slot\0cancel_btn_pressed_slot\0"
    "ok_btn_pressed_slot\0ok_btn_continue_slot\0"
    "up_btn_pressed_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectTaskDlg[] = {

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
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SelectTaskDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectTaskDlg *_t = static_cast<SelectTaskDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->regist_is_activate(); break;
        case 1: _t->down_btn_pressed_slot(); break;
        case 2: _t->cancel_btn_pressed_slot(); break;
        case 3: { bool _r = _t->ok_btn_pressed_slot();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->ok_btn_continue_slot(); break;
        case 5: _t->up_btn_pressed_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SelectTaskDlg::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SelectTaskDlg::regist_is_activate)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SelectTaskDlg::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SelectTaskDlg.data,
      qt_meta_data_SelectTaskDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SelectTaskDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectTaskDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SelectTaskDlg.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SelectTaskDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void SelectTaskDlg::regist_is_activate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
