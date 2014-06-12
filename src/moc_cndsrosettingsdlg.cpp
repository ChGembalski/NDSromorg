/****************************************************************************
** Meta object code from reading C++ file 'cndsrosettingsdlg.h'
**
** Created: Mon Jan 13 21:13:00 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cndsrosettingsdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cndsrosettingsdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CndsroSettingsDlg[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      40,   18,   18,   18, 0x0a,
      59,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CndsroSettingsDlg[] = {
    "CndsroSettingsDlg\0\0CMD_CANCEL_clicked()\0"
    "CMD_HELP_clicked()\0CMD_OK_clicked()\0"
};

const QMetaObject CndsroSettingsDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CndsroSettingsDlg,
      qt_meta_data_CndsroSettingsDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CndsroSettingsDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CndsroSettingsDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CndsroSettingsDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CndsroSettingsDlg))
        return static_cast<void*>(const_cast< CndsroSettingsDlg*>(this));
    if (!strcmp(_clname, "Ui::NDSROsettingsDlg"))
        return static_cast< Ui::NDSROsettingsDlg*>(const_cast< CndsroSettingsDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CndsroSettingsDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: CMD_CANCEL_clicked(); break;
        case 1: CMD_HELP_clicked(); break;
        case 2: CMD_OK_clicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
