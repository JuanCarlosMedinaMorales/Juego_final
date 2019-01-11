/****************************************************************************
** Meta object code from reading C++ file 'iniciar_juego.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../juego_final/iniciar_juego.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iniciar_juego.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_iniciar_juego_t {
    QByteArrayData data[17];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iniciar_juego_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iniciar_juego_t qt_meta_stringdata_iniciar_juego = {
    {
QT_MOC_LITERAL(0, 0, 13), // "iniciar_juego"
QT_MOC_LITERAL(1, 14, 13), // "keyPressEvent"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "QKeyEvent*"
QT_MOC_LITERAL(4, 40, 5), // "event"
QT_MOC_LITERAL(5, 46, 8), // "on_pegar"
QT_MOC_LITERAL(6, 55, 3), // "mov"
QT_MOC_LITERAL(7, 59, 3), // "par"
QT_MOC_LITERAL(8, 63, 5), // "pegar"
QT_MOC_LITERAL(9, 69, 5), // "salto"
QT_MOC_LITERAL(10, 75, 4), // "grav"
QT_MOC_LITERAL(11, 80, 13), // "mov_proyectil"
QT_MOC_LITERAL(12, 94, 21), // "on_actiongo_triggered"
QT_MOC_LITERAL(13, 116, 23), // "on_actionstop_triggered"
QT_MOC_LITERAL(14, 140, 27), // "on_progressBar_valueChanged"
QT_MOC_LITERAL(15, 168, 5), // "value"
QT_MOC_LITERAL(16, 174, 21) // "on_pushButton_clicked"

    },
    "iniciar_juego\0keyPressEvent\0\0QKeyEvent*\0"
    "event\0on_pegar\0mov\0par\0pegar\0salto\0"
    "grav\0mov_proyectil\0on_actiongo_triggered\0"
    "on_actionstop_triggered\0"
    "on_progressBar_valueChanged\0value\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iniciar_juego[] = {

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
       1,    1,   74,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,
      14,    1,   86,    2, 0x08 /* Private */,
      16,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,

       0        // eod
};

void iniciar_juego::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        iniciar_juego *_t = static_cast<iniciar_juego *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 1: _t->on_pegar(); break;
        case 2: _t->mov(); break;
        case 3: _t->par(); break;
        case 4: _t->pegar(); break;
        case 5: _t->salto(); break;
        case 6: _t->grav(); break;
        case 7: _t->mov_proyectil(); break;
        case 8: _t->on_actiongo_triggered(); break;
        case 9: _t->on_actionstop_triggered(); break;
        case 10: _t->on_progressBar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject iniciar_juego::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_iniciar_juego.data,
      qt_meta_data_iniciar_juego,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *iniciar_juego::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iniciar_juego::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_iniciar_juego.stringdata0))
        return static_cast<void*>(const_cast< iniciar_juego*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int iniciar_juego::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
