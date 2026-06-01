/****************************************************************************
** Meta object code from reading C++ file 'hp_formatdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hp_formatdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hp_formatdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Hp_FormatDialog_t {
    QByteArrayData data[10];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Hp_FormatDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Hp_FormatDialog_t qt_meta_stringdata_Hp_FormatDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Hp_FormatDialog"
QT_MOC_LITERAL(1, 16, 17), // "signal_set_format"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 20), // "signal_sd_formatting"
QT_MOC_LITERAL(4, 56, 39), // "signal_formatdialog_set_lcd_o..."
QT_MOC_LITERAL(5, 96, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(6, 117, 16), // "QAbstractButton*"
QT_MOC_LITERAL(7, 134, 6), // "button"
QT_MOC_LITERAL(8, 141, 24), // "on_pushButton_ok_clicked"
QT_MOC_LITERAL(9, 166, 28) // "on_pushButton_cancel_clicked"

    },
    "Hp_FormatDialog\0signal_set_format\0\0"
    "signal_sd_formatting\0"
    "signal_formatdialog_set_lcd_offed_state\0"
    "on_buttonBox_clicked\0QAbstractButton*\0"
    "button\0on_pushButton_ok_clicked\0"
    "on_pushButton_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hp_FormatDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Hp_FormatDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Hp_FormatDialog *_t = static_cast<Hp_FormatDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_set_format(); break;
        case 1: _t->signal_sd_formatting(); break;
        case 2: _t->signal_formatdialog_set_lcd_offed_state(); break;
        case 3: _t->on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_ok_clicked(); break;
        case 5: _t->on_pushButton_cancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Hp_FormatDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_FormatDialog::signal_set_format)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Hp_FormatDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_FormatDialog::signal_sd_formatting)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Hp_FormatDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hp_FormatDialog::signal_formatdialog_set_lcd_offed_state)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Hp_FormatDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Hp_FormatDialog.data,
      qt_meta_data_Hp_FormatDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Hp_FormatDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hp_FormatDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Hp_FormatDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Hp_FormatDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Hp_FormatDialog::signal_set_format()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Hp_FormatDialog::signal_sd_formatting()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Hp_FormatDialog::signal_formatdialog_set_lcd_offed_state()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
