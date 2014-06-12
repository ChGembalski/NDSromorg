/****************************************************************************
** Meta object code from reading C++ file 'cndsromaindlg.h'
**
** Created: Tue Jan 14 11:17:33 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cndsromaindlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cndsromaindlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CNDSROmainDlg[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      32,   14,   14,   14, 0x08,
      53,   14,   14,   14, 0x08,
      74,   14,   14,   14, 0x08,
      91,   14,   14,   14, 0x08,
     108,   14,   14,   14, 0x08,
     129,   14,   14,   14, 0x08,
     150,   14,   14,   14, 0x08,
     167,   14,   14,   14, 0x08,
     189,   14,   14,   14, 0x08,
     204,   14,   14,   14, 0x08,
     220,   14,   14,   14, 0x08,
     238,   14,   14,   14, 0x08,
     259,   14,   14,   14, 0x08,
     276,   14,   14,   14, 0x08,
     292,   14,   14,   14, 0x08,
     314,   14,   14,   14, 0x08,
     330,   14,   14,   14, 0x08,
     346,   14,   14,   14, 0x08,
     362,   14,   14,   14, 0x08,
     378,   14,   14,   14, 0x08,
     394,   14,   14,   14, 0x08,
     410,   14,   14,   14, 0x08,
     426,   14,   14,   14, 0x08,
     449,   14,   14,   14, 0x08,
     475,   14,   14,   14, 0x08,
     502,   14,   14,   14, 0x08,
     530,   14,   14,   14, 0x08,
     555,   14,   14,   14, 0x08,
     578,   14,   14,   14, 0x08,
     603,   14,   14,   14, 0x08,
     630,   14,   14,   14, 0x08,
     652,   14,   14,   14, 0x08,
     682,  674,   14,   14, 0x08,
     705,  703,   14,   14, 0x28,
     732,  721,   14,   14, 0x08,
     769,  721,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CNDSROmainDlg[] = {
    "CNDSROmainDlg\0\0ImportROMListe()\0"
    "ImportROMDataListe()\0ImportROMCodeListe()\0"
    "ImportIMGListe()\0ExportROMListe()\0"
    "ExportROMDataListe()\0ExportROMCodeListe()\0"
    "ExportIMGListe()\0CNDSROmainDlg_close()\0"
    "EditSettings()\0SelectTabROMS()\0"
    "SelectTabDEVICE()\0SelectTabFAVORITES()\0"
    "SelectTabTOOLS()\0SelectTabDIRS()\0"
    "CNDSROmainDlg_about()\0SelectNameJPN()\0"
    "SelectNameENG()\0SelectNameFRN()\0"
    "SelectNameGER()\0SelectNameITL()\0"
    "SelectNameSPN()\0SelectNameCHI()\0"
    "ROMStools_scan_click()\0ROMStools_romlist_click()\0"
    "ROMStools_scanlist_click()\0"
    "ROMStools_scanclear_click()\0"
    "ROMStools_delete_click()\0"
    "ROMStools_copy_click()\0DEVICEtools_scan_click()\0"
    "DEVICEtools_remove_click()\0"
    "DIRStools_add_click()\0DIRStools_del_click()\0"
    "s,delay\0Status(QString,uint)\0s\0"
    "Status(QString)\0row,column\0"
    "ROMStable_cellDoubleClicked(int,int)\0"
    "DEVICEtable_cellDoubleClicked(int,int)\0"
};

const QMetaObject CNDSROmainDlg::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CNDSROmainDlg,
      qt_meta_data_CNDSROmainDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CNDSROmainDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CNDSROmainDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CNDSROmainDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CNDSROmainDlg))
        return static_cast<void*>(const_cast< CNDSROmainDlg*>(this));
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(const_cast< CNDSROmainDlg*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CNDSROmainDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ImportROMListe(); break;
        case 1: ImportROMDataListe(); break;
        case 2: ImportROMCodeListe(); break;
        case 3: ImportIMGListe(); break;
        case 4: ExportROMListe(); break;
        case 5: ExportROMDataListe(); break;
        case 6: ExportROMCodeListe(); break;
        case 7: ExportIMGListe(); break;
        case 8: CNDSROmainDlg_close(); break;
        case 9: EditSettings(); break;
        case 10: SelectTabROMS(); break;
        case 11: SelectTabDEVICE(); break;
        case 12: SelectTabFAVORITES(); break;
        case 13: SelectTabTOOLS(); break;
        case 14: SelectTabDIRS(); break;
        case 15: CNDSROmainDlg_about(); break;
        case 16: SelectNameJPN(); break;
        case 17: SelectNameENG(); break;
        case 18: SelectNameFRN(); break;
        case 19: SelectNameGER(); break;
        case 20: SelectNameITL(); break;
        case 21: SelectNameSPN(); break;
        case 22: SelectNameCHI(); break;
        case 23: ROMStools_scan_click(); break;
        case 24: ROMStools_romlist_click(); break;
        case 25: ROMStools_scanlist_click(); break;
        case 26: ROMStools_scanclear_click(); break;
        case 27: ROMStools_delete_click(); break;
        case 28: ROMStools_copy_click(); break;
        case 29: DEVICEtools_scan_click(); break;
        case 30: DEVICEtools_remove_click(); break;
        case 31: DIRStools_add_click(); break;
        case 32: DIRStools_del_click(); break;
        case 33: Status((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 34: Status((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: ROMStable_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 36: DEVICEtable_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 37;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
