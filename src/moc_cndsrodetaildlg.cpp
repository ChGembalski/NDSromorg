/****************************************************************************
** Meta object code from reading C++ file 'cndsrodetaildlg.h'
**
** Created: Mon Jan 13 21:13:02 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cndsrodetaildlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cndsrodetaildlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CNDSROdetailDlg[] = {

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
      22,   17,   16,   16, 0x08,
      61,   54,   16,   16, 0x08,
      91,   16,   16,   16, 0x08,
     109,   16,   16,   16, 0x08,
     134,   16,   16,   16, 0x08,
     160,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CNDSROdetailDlg[] = {
    "CNDSROdetailDlg\0\0item\0"
    "THUMB_clicked(QClickableLabel*)\0button\0"
    "CMD_clicked(QAbstractButton*)\0"
    "CreateNextTHUMB()\0CMD_THUMB_LEFT_clicked()\0"
    "CMD_THUMB_RIGHT_clicked()\0CMDcode_clicked()\0"
};

const QMetaObject CNDSROdetailDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CNDSROdetailDlg,
      qt_meta_data_CNDSROdetailDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CNDSROdetailDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CNDSROdetailDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CNDSROdetailDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CNDSROdetailDlg))
        return static_cast<void*>(const_cast< CNDSROdetailDlg*>(this));
    if (!strcmp(_clname, "Ui::Dialog"))
        return static_cast< Ui::Dialog*>(const_cast< CNDSROdetailDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CNDSROdetailDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: THUMB_clicked((*reinterpret_cast< QClickableLabel*(*)>(_a[1]))); break;
        case 1: CMD_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 2: CreateNextTHUMB(); break;
        case 3: CMD_THUMB_LEFT_clicked(); break;
        case 4: CMD_THUMB_RIGHT_clicked(); break;
        case 5: CMDcode_clicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
