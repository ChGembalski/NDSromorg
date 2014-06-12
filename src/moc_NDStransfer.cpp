/****************************************************************************
** Meta object code from reading C++ file 'NDStransfer.h'
**
** Created: Mon Jan 13 21:13:03 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "NDStransfer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NDStransfer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CNDStransfer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   14,   13,   13, 0x05,
      45,   43,   13,   13, 0x25,

       0        // eod
};

static const char qt_meta_stringdata_CNDStransfer[] = {
    "CNDStransfer\0\0s,delay\0Status(QString,uint)\0"
    "s\0Status(QString)\0"
};

const QMetaObject CNDStransfer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CNDStransfer,
      qt_meta_data_CNDStransfer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CNDStransfer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CNDStransfer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CNDStransfer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CNDStransfer))
        return static_cast<void*>(const_cast< CNDStransfer*>(this));
    return QObject::qt_metacast(_clname);
}

int CNDStransfer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Status((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 1: Status((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CNDStransfer::Status(QString _t1, uint _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
