/****************************************************************************
** Meta object code from reading C++ file 'ndsromorg.h'
**
** Created: Mon Jan 13 21:12:59 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ndsromorg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ndsromorg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NDSromorg[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      21,   10,   10,   10, 0x08,
      33,   10,   28,   10, 0x08,
      40,   10,   28,   10, 0x08,
      49,   10,   10,   10, 0x08,
      57,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NDSromorg[] = {
    "NDSromorg\0\0newFile()\0open()\0bool\0"
    "save()\0saveAs()\0about()\0documentWasModified()\0"
};

const QMetaObject NDSromorg::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_NDSromorg,
      qt_meta_data_NDSromorg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NDSromorg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NDSromorg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NDSromorg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NDSromorg))
        return static_cast<void*>(const_cast< NDSromorg*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int NDSromorg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newFile(); break;
        case 1: open(); break;
        case 2: { bool _r = save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = saveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: about(); break;
        case 5: documentWasModified(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
