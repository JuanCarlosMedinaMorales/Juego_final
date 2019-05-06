/****************************************************************************
** Meta object code from reading C++ file 'iniciar_juego.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Juego_Final01/iniciar_juego.h"
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
    QByteArrayData data[24];
    char stringdata0[249];
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
QT_MOC_LITERAL(5, 46, 15), // "keyReleaseEvent"
QT_MOC_LITERAL(6, 62, 8), // "on_pegar"
QT_MOC_LITERAL(7, 71, 3), // "mov"
QT_MOC_LITERAL(8, 75, 3), // "par"
QT_MOC_LITERAL(9, 79, 5), // "pegar"
QT_MOC_LITERAL(10, 85, 5), // "salto"
QT_MOC_LITERAL(11, 91, 4), // "grav"
QT_MOC_LITERAL(12, 96, 13), // "mov_proyectil"
QT_MOC_LITERAL(13, 110, 15), // "duracion_escudo"
QT_MOC_LITERAL(14, 126, 14), // "movimiento_bot"
QT_MOC_LITERAL(15, 141, 9), // "poderes_J"
QT_MOC_LITERAL(16, 151, 8), // "lanzador"
QT_MOC_LITERAL(17, 160, 5), // "poder"
QT_MOC_LITERAL(18, 166, 7), // "golpear"
QT_MOC_LITERAL(19, 174, 8), // "peleador"
QT_MOC_LITERAL(20, 183, 5), // "mover"
QT_MOC_LITERAL(21, 189, 13), // "movida_player"
QT_MOC_LITERAL(22, 203, 21), // "on_actiongo_triggered"
QT_MOC_LITERAL(23, 225, 23) // "on_actionstop_triggered"

    },
    "iniciar_juego\0keyPressEvent\0\0QKeyEvent*\0"
    "event\0keyReleaseEvent\0on_pegar\0mov\0"
    "par\0pegar\0salto\0grav\0mov_proyectil\0"
    "duracion_escudo\0movimiento_bot\0poderes_J\0"
    "lanzador\0poder\0golpear\0peleador\0mover\0"
    "movida_player\0on_actiongo_triggered\0"
    "on_actionstop_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iniciar_juego[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x08 /* Private */,
       5,    1,   97,    2, 0x08 /* Private */,
       6,    0,  100,    2, 0x08 /* Private */,
       7,    0,  101,    2, 0x08 /* Private */,
       8,    0,  102,    2, 0x08 /* Private */,
       9,    0,  103,    2, 0x08 /* Private */,
      10,    0,  104,    2, 0x08 /* Private */,
      11,    0,  105,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    2,  109,    2, 0x08 /* Private */,
      18,    1,  114,    2, 0x08 /* Private */,
      20,    1,  117,    2, 0x08 /* Private */,
      22,    0,  120,    2, 0x08 /* Private */,
      23,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
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
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Char,   21,
    QMetaType::Void,
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
        case 1: _t->keyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 2: _t->on_pegar(); break;
        case 3: _t->mov(); break;
        case 4: _t->par(); break;
        case 5: _t->pegar(); break;
        case 6: _t->salto(); break;
        case 7: _t->grav(); break;
        case 8: _t->mov_proyectil(); break;
        case 9: _t->duracion_escudo(); break;
        case 10: _t->movimiento_bot(); break;
        case 11: _t->poderes_J((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->golpear((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->mover((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 14: _t->on_actiongo_triggered(); break;
        case 15: _t->on_actionstop_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject iniciar_juego::staticMetaObject = {
    { &iniciar_sesion::staticMetaObject, qt_meta_stringdata_iniciar_juego.data,
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
    return iniciar_sesion::qt_metacast(_clname);
}

int iniciar_juego::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = iniciar_sesion::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
