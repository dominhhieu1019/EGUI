/****************************************************************************
** Meta object code from reading C++ file 'library.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Library/library.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'library.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Library_t {
    QByteArrayData data[10];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Library_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Library_t qt_meta_stringdata_Library = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Library"
QT_MOC_LITERAL(1, 8, 23), // "on_filterButton_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 22), // "on_clearButton_clicked"
QT_MOC_LITERAL(4, 56, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(5, 77, 21), // "on_editButton_clicked"
QT_MOC_LITERAL(6, 99, 30), // "on_bookTable_itemDoubleClicked"
QT_MOC_LITERAL(7, 130, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(8, 148, 4), // "item"
QT_MOC_LITERAL(9, 153, 23) // "on_deleteButton_clicked"

    },
    "Library\0on_filterButton_clicked\0\0"
    "on_clearButton_clicked\0on_addButton_clicked\0"
    "on_editButton_clicked\0"
    "on_bookTable_itemDoubleClicked\0"
    "QTableWidgetItem*\0item\0on_deleteButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Library[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

       0        // eod
};

void Library::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Library *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_filterButton_clicked(); break;
        case 1: _t->on_clearButton_clicked(); break;
        case 2: _t->on_addButton_clicked(); break;
        case 3: _t->on_editButton_clicked(); break;
        case 4: _t->on_bookTable_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->on_deleteButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Library::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Library.data,
    qt_meta_data_Library,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Library::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Library::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Library.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Library::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
