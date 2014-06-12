/****************************************************************************
** Meta object code from reading C++ file 'QClickableLabel.h'
**
** Created: Mon Jan 13 21:13:03 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QClickableLabel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QClickableLabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QClickableLabel[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   17,   16,   16, 0x05,
      57,   48,   16,   16, 0x05,
      83,   16,   16,   16, 0x25,
      93,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     105,   16,   16,   16, 0x0a,
     120,  113,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QClickableLabel[] = {
    "QClickableLabel\0\0item\0clicked(QClickableLabel*)\0"
    "mimeData\0changed(const QMimeData*)\0"
    "changed()\0pixmapset()\0clear()\0pReply\0"
    "fileDownloaded(QNetworkReply*)\0"
};

const QMetaObject QClickableLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_QClickableLabel,
      qt_meta_data_QClickableLabel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QClickableLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QClickableLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QClickableLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QClickableLabel))
        return static_cast<void*>(const_cast< QClickableLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int QClickableLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clicked((*reinterpret_cast< QClickableLabel*(*)>(_a[1]))); break;
        case 1: changed((*reinterpret_cast< const QMimeData*(*)>(_a[1]))); break;
        case 2: changed(); break;
        case 3: pixmapset(); break;
        case 4: clear(); break;
        case 5: fileDownloaded((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QClickableLabel::clicked(QClickableLabel * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QClickableLabel::changed(const QMimeData * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 3
void QClickableLabel::pixmapset()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
