/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../main_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[385];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "progressChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 20), // "finishedLoadingFiles"
QT_MOC_LITERAL(4, 49, 27), // "on_pushButtonImport_clicked"
QT_MOC_LITERAL(5, 77, 27), // "on_pushButtonFilter_clicked"
QT_MOC_LITERAL(6, 105, 28), // "on_pushButtonExtract_clicked"
QT_MOC_LITERAL(7, 134, 27), // "on_checkBoxTxt_stateChanged"
QT_MOC_LITERAL(8, 162, 39), // "on_comboBoxFieldName_currentT..."
QT_MOC_LITERAL(9, 202, 5), // "_text"
QT_MOC_LITERAL(10, 208, 31), // "on_treeViewImportedData_clicked"
QT_MOC_LITERAL(11, 240, 11), // "QModelIndex"
QT_MOC_LITERAL(12, 252, 6), // "_index"
QT_MOC_LITERAL(13, 259, 30), // "on_tableViewFolderData_clicked"
QT_MOC_LITERAL(14, 290, 12), // "loadFileList"
QT_MOC_LITERAL(15, 303, 11), // "std::string"
QT_MOC_LITERAL(16, 315, 19), // "_relative_path_file"
QT_MOC_LITERAL(17, 335, 14), // "setProgressbar"
QT_MOC_LITERAL(18, 350, 16), // "compeleteLoading"
QT_MOC_LITERAL(19, 367, 12), // "addFileItems"
QT_MOC_LITERAL(20, 380, 4) // "_dir"

    },
    "MainWindow\0progressChanged\0\0"
    "finishedLoadingFiles\0on_pushButtonImport_clicked\0"
    "on_pushButtonFilter_clicked\0"
    "on_pushButtonExtract_clicked\0"
    "on_checkBoxTxt_stateChanged\0"
    "on_comboBoxFieldName_currentTextChanged\0"
    "_text\0on_treeViewImportedData_clicked\0"
    "QModelIndex\0_index\0on_tableViewFolderData_clicked\0"
    "loadFileList\0std::string\0_relative_path_file\0"
    "setProgressbar\0compeleteLoading\0"
    "addFileItems\0_dir"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    0,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   83,    2, 0x08 /* Private */,
       5,    0,   84,    2, 0x08 /* Private */,
       6,    0,   85,    2, 0x08 /* Private */,
       7,    0,   86,    2, 0x08 /* Private */,
       8,    1,   87,    2, 0x08 /* Private */,
      10,    1,   90,    2, 0x08 /* Private */,
      13,    1,   93,    2, 0x08 /* Private */,
      14,    1,   96,    2, 0x08 /* Private */,
      17,    1,   99,    2, 0x08 /* Private */,
      18,    0,  102,    2, 0x08 /* Private */,
      19,    1,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   20,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->progressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->finishedLoadingFiles(); break;
        case 2: _t->on_pushButtonImport_clicked(); break;
        case 3: _t->on_pushButtonFilter_clicked(); break;
        case 4: _t->on_pushButtonExtract_clicked(); break;
        case 5: _t->on_checkBoxTxt_stateChanged(); break;
        case 6: _t->on_comboBoxFieldName_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_treeViewImportedData_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_tableViewFolderData_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->loadFileList((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 10: _t->setProgressbar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->compeleteLoading(); break;
        case 12: _t->addFileItems((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::progressChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::finishedLoadingFiles)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void MainWindow::progressChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::finishedLoadingFiles()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
