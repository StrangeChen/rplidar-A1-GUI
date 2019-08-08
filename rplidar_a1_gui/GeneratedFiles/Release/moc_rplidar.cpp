/****************************************************************************
** Meta object code from reading C++ file 'rplidar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rplidar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rplidar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Rplidar_t {
    QByteArrayData data[12];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Rplidar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Rplidar_t qt_meta_stringdata_Rplidar = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Rplidar"
QT_MOC_LITERAL(1, 8, 13), // "scanCompleted"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 13), // "QList<QPoint>"
QT_MOC_LITERAL(4, 37, 5), // "point"
QT_MOC_LITERAL(5, 43, 11), // "reportError"
QT_MOC_LITERAL(6, 55, 4), // "_err"
QT_MOC_LITERAL(7, 60, 16), // "sendNearestPoint"
QT_MOC_LITERAL(8, 77, 3), // "cmd"
QT_MOC_LITERAL(9, 81, 2), // "d1"
QT_MOC_LITERAL(10, 84, 2), // "d2"
QT_MOC_LITERAL(11, 87, 2) // "d3"

    },
    "Rplidar\0scanCompleted\0\0QList<QPoint>\0"
    "point\0reportError\0_err\0sendNearestPoint\0"
    "cmd\0d1\0d2\0d3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Rplidar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,
       7,    4,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Char, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,   11,

       0        // eod
};

void Rplidar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Rplidar *_t = static_cast<Rplidar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->scanCompleted((*reinterpret_cast< QList<QPoint>(*)>(_a[1]))); break;
        case 1: _t->reportError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendNearestPoint((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QPoint> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Rplidar::*_t)(QList<QPoint> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Rplidar::scanCompleted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Rplidar::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Rplidar::reportError)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Rplidar::*_t)(char , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Rplidar::sendNearestPoint)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Rplidar::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Rplidar.data,
      qt_meta_data_Rplidar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Rplidar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Rplidar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Rplidar.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Rplidar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Rplidar::scanCompleted(QList<QPoint> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Rplidar::reportError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Rplidar::sendNearestPoint(char _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
