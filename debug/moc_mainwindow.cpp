/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_actionAbrir_triggered"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 27), // "on_actionDuplicar_triggered"
QT_MOC_LITERAL(4, 65, 29), // "on_actionHistograma_triggered"
QT_MOC_LITERAL(5, 95, 39), // "on_actionHistograma_Acumulado..."
QT_MOC_LITERAL(6, 135, 35), // "on_actionRango_de_valores_tri..."
QT_MOC_LITERAL(7, 171, 25), // "on_actionTama_o_triggered"
QT_MOC_LITERAL(8, 197, 33), // "on_actionCambiar_Brillo_trigg..."
QT_MOC_LITERAL(9, 231, 25), // "on_actionTramos_triggered"
QT_MOC_LITERAL(10, 257, 17), // "Mouse_current_pos"
QT_MOC_LITERAL(11, 275, 3), // "uno"
QT_MOC_LITERAL(12, 279, 3), // "dos"
QT_MOC_LITERAL(13, 283, 35), // "on_actionEscala_de_grises_tri..."
QT_MOC_LITERAL(14, 319, 35) // "on_actionEcualizar_imagen_tri..."

    },
    "MainWindow\0on_actionAbrir_triggered\0"
    "\0on_actionDuplicar_triggered\0"
    "on_actionHistograma_triggered\0"
    "on_actionHistograma_Acumulado_triggered\0"
    "on_actionRango_de_valores_triggered\0"
    "on_actionTama_o_triggered\0"
    "on_actionCambiar_Brillo_triggered\0"
    "on_actionTramos_triggered\0Mouse_current_pos\0"
    "uno\0dos\0on_actionEscala_de_grises_triggered\0"
    "on_actionEcualizar_imagen_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionAbrir_triggered(); break;
        case 1: _t->on_actionDuplicar_triggered(); break;
        case 2: _t->on_actionHistograma_triggered(); break;
        case 3: _t->on_actionHistograma_Acumulado_triggered(); break;
        case 4: _t->on_actionRango_de_valores_triggered(); break;
        case 5: _t->on_actionTama_o_triggered(); break;
        case 6: _t->on_actionCambiar_Brillo_triggered(); break;
        case 7: _t->on_actionTramos_triggered(); break;
        case 8: _t->Mouse_current_pos(); break;
        case 9: _t->uno(); break;
        case 10: _t->dos(); break;
        case 11: _t->on_actionEscala_de_grises_triggered(); break;
        case 12: _t->on_actionEcualizar_imagen_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
