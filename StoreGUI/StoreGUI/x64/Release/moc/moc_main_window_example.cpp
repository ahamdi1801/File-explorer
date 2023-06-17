/****************************************************************************
** Meta object code from reading C++ file 'main_window_example.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../main_window_example.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window_example.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindowExample_t {
    QByteArrayData data[11];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindowExample_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindowExample_t qt_meta_stringdata_MainWindowExample = {
    {
QT_MOC_LITERAL(0, 0, 17), // "MainWindowExample"
QT_MOC_LITERAL(1, 18, 15), // "progressChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 20), // "finishedLoadingFiles"
QT_MOC_LITERAL(4, 56, 27), // "on_pushButtonShowID_clicked"
QT_MOC_LITERAL(5, 84, 34), // "on_commandLinkButtonBrowse_cl..."
QT_MOC_LITERAL(6, 119, 12), // "loadFileList"
QT_MOC_LITERAL(7, 132, 11), // "_text_files"
QT_MOC_LITERAL(8, 144, 14), // "setProgressbar"
QT_MOC_LITERAL(9, 159, 16), // "compeleteLoading"
QT_MOC_LITERAL(10, 176, 33) // "on_pushButtonSecondWindow_cli..."

    },
    "MainWindowExample\0progressChanged\0\0"
    "finishedLoadingFiles\0on_pushButtonShowID_clicked\0"
    "on_commandLinkButtonBrowse_clicked\0"
    "loadFileList\0_text_files\0setProgressbar\0"
    "compeleteLoading\0on_pushButtonSecondWindow_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindowExample[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   58,    2, 0x08 /* Private */,
       5,    0,   59,    2, 0x08 /* Private */,
       6,    1,   60,    2, 0x08 /* Private */,
       8,    1,   63,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    7,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindowExample::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindowExample *_t = static_cast<MainWindowExample *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->progressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->finishedLoadingFiles(); break;
        case 2: _t->on_pushButtonShowID_clicked(); break;
        case 3: _t->on_commandLinkButtonBrowse_clicked(); break;
        case 4: _t->loadFileList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 5: _t->setProgressbar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->compeleteLoading(); break;
        case 7: _t->on_pushButtonSecondWindow_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindowExample::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindowExample::progressChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindowExample::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindowExample::finishedLoadingFiles)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindowExample::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindowExample.data,
    qt_meta_data_MainWindowExample,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindowExample::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowExample::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowExample.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowExample::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MainWindowExample::progressChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindowExample::finishedLoadingFiles()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
