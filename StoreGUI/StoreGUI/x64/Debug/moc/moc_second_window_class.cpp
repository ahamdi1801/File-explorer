/****************************************************************************
** Meta object code from reading C++ file 'second_window_class.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../second_window_class.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'second_window_class.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SecondWindowClass_t {
    QByteArrayData data[12];
    char stringdata0[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SecondWindowClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SecondWindowClass_t qt_meta_stringdata_SecondWindowClass = {
    {
QT_MOC_LITERAL(0, 0, 17), // "SecondWindowClass"
QT_MOC_LITERAL(1, 18, 19), // "secondButtonClicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 31), // "on_pushButtonShowSecond_clicked"
QT_MOC_LITERAL(4, 71, 28), // "on_pushButtonShowMsg_clicked"
QT_MOC_LITERAL(5, 100, 13), // "onNameChanged"
QT_MOC_LITERAL(6, 114, 4), // "text"
QT_MOC_LITERAL(7, 119, 30), // "on_pushButtonBrowseImg_clicked"
QT_MOC_LITERAL(8, 150, 33), // "on_pushButtonBrowseSecond_cli..."
QT_MOC_LITERAL(9, 184, 15), // "showContextMenu"
QT_MOC_LITERAL(10, 200, 15), // "onActionChanged"
QT_MOC_LITERAL(11, 216, 7) // "_action"

    },
    "SecondWindowClass\0secondButtonClicked\0"
    "\0on_pushButtonShowSecond_clicked\0"
    "on_pushButtonShowMsg_clicked\0onNameChanged\0"
    "text\0on_pushButtonBrowseImg_clicked\0"
    "on_pushButtonBrowseSecond_clicked\0"
    "showContextMenu\0onActionChanged\0_action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SecondWindowClass[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   62,    2, 0x08 /* Private */,
       4,    0,   63,    2, 0x08 /* Private */,
       5,    1,   64,    2, 0x08 /* Private */,
       7,    0,   67,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    1,   69,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      10,    1,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QObjectStar,   11,

       0        // eod
};

void SecondWindowClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SecondWindowClass *_t = static_cast<SecondWindowClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->secondButtonClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonShowSecond_clicked(); break;
        case 2: _t->on_pushButtonShowMsg_clicked(); break;
        case 3: _t->onNameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_pushButtonBrowseImg_clicked(); break;
        case 5: _t->on_pushButtonBrowseSecond_clicked(); break;
        case 6: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 7: _t->onActionChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->onActionChanged((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SecondWindowClass::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SecondWindowClass::secondButtonClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SecondWindowClass::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_SecondWindowClass.data,
    qt_meta_data_SecondWindowClass,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SecondWindowClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SecondWindowClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SecondWindowClass.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SecondWindowClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SecondWindowClass::secondButtonClicked(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
