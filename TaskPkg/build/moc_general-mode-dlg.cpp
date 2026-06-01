/****************************************************************************
** Meta object code from reading C++ file 'general-mode-dlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../machine/general-mode-dlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'general-mode-dlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GeneralModeDlg_t {
    QByteArrayData data[15];
    char stringdata0[256];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeneralModeDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeneralModeDlg_t qt_meta_stringdata_GeneralModeDlg = {
    {
QT_MOC_LITERAL(0, 0, 14), // "GeneralModeDlg"
QT_MOC_LITERAL(1, 15, 18), // "update_import_file"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 22), // "first_btn_pressed_slot"
QT_MOC_LITERAL(4, 58, 21), // "prev_btn_pressed_slot"
QT_MOC_LITERAL(5, 80, 21), // "last_btn_pressed_slot"
QT_MOC_LITERAL(6, 102, 21), // "next_btn_pressed_slot"
QT_MOC_LITERAL(7, 124, 23), // "delete_btn_pressed_slot"
QT_MOC_LITERAL(8, 148, 15), // "btns_click_slot"
QT_MOC_LITERAL(9, 164, 5), // "n_pos"
QT_MOC_LITERAL(10, 170, 13), // "update_status"
QT_MOC_LITERAL(11, 184, 5), // "i_pos"
QT_MOC_LITERAL(12, 190, 18), // "set_prev_image_pos"
QT_MOC_LITERAL(13, 209, 18), // "get_prev_image_pos"
QT_MOC_LITERAL(14, 228, 27) // "get_current_file_list_count"

    },
    "GeneralModeDlg\0update_import_file\0\0"
    "first_btn_pressed_slot\0prev_btn_pressed_slot\0"
    "last_btn_pressed_slot\0next_btn_pressed_slot\0"
    "delete_btn_pressed_slot\0btns_click_slot\0"
    "n_pos\0update_status\0i_pos\0set_prev_image_pos\0"
    "get_prev_image_pos\0get_current_file_list_count"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneralModeDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       3,    0,   77,    2, 0x0a /* Public */,
       4,    0,   78,    2, 0x0a /* Public */,
       5,    0,   79,    2, 0x0a /* Public */,
       6,    0,   80,    2, 0x0a /* Public */,
       7,    0,   81,    2, 0x0a /* Public */,
       8,    1,   82,    2, 0x0a /* Public */,
      10,    1,   85,    2, 0x0a /* Public */,
      10,    0,   88,    2, 0x2a /* Public | MethodCloned */,
      12,    1,   89,    2, 0x0a /* Public */,
      13,    0,   92,    2, 0x0a /* Public */,
      14,    0,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,    9,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void GeneralModeDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GeneralModeDlg *_t = static_cast<GeneralModeDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_import_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->first_btn_pressed_slot(); break;
        case 2: _t->prev_btn_pressed_slot(); break;
        case 3: _t->last_btn_pressed_slot(); break;
        case 4: _t->next_btn_pressed_slot(); break;
        case 5: _t->delete_btn_pressed_slot(); break;
        case 6: _t->btns_click_slot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->update_status((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->update_status(); break;
        case 9: { int _r = _t->set_prev_image_pos((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->get_prev_image_pos();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->get_current_file_list_count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GeneralModeDlg::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GeneralModeDlg.data,
      qt_meta_data_GeneralModeDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GeneralModeDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeneralModeDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralModeDlg.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GeneralModeDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
