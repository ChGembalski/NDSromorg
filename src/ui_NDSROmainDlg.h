/********************************************************************************
** Form generated from reading UI file 'NDSROmainDlg.ui'
**
** Created: Mon Jan 13 21:12:42 2014
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NDSROMAINDLG_H
#define UI_NDSROMAINDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionSettings;
    QAction *actionROMS;
    QAction *actionDEVICE;
    QAction *actionFAVORITES;
    QAction *actionTOOLS;
    QAction *actionDIRS;
    QAction *actionAbout;
    QAction *actionAboutOt;
    QAction *actionJPN;
    QAction *actionENG;
    QAction *actionFRN;
    QAction *actionGER;
    QAction *actionITL;
    QAction *actionSPN;
    QAction *actionCHI;
    QAction *actionExportROMListe;
    QAction *actionExportIMGListe;
    QAction *actionImportROMListe;
    QAction *actionImportIMGListe;
    QAction *actionImportROMDataListe;
    QAction *actionExportROMDataListe;
    QAction *actionImportROMCodeListe;
    QAction *actionExportROMCodeListe;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *functionTabs;
    QWidget *tabROMS;
    QVBoxLayout *verticalLayout_2;
    QFrame *ROMStools;
    QToolButton *ROMStools_scan;
    QToolButton *ROMStools_romlist;
    QToolButton *ROMStools_scanlist;
    QToolButton *ROMStools_scanclear;
    QFrame *ROMStools_line1;
    QFrame *ROMStools_line2;
    QToolButton *ROMStools_copy;
    QToolButton *ROMStools_delete;
    QFrame *line;
    QTableWidget *ROMStable;
    QWidget *tabDEVICE;
    QVBoxLayout *verticalLayout_3;
    QFrame *DEVICEtools;
    QToolButton *DEVICEtools_scan;
    QFrame *DEVICEtools_line1;
    QToolButton *DEVICEtools_remove;
    QTableWidget *DEVICEtable;
    QWidget *tabFAVORITES;
    QVBoxLayout *verticalLayout_4;
    QFrame *FAVORITEStools;
    QSplitter *splitter;
    QListWidget *FAVORITESlist;
    QTableWidget *FAVORITEStable;
    QWidget *tabTOOLS;
    QVBoxLayout *verticalLayout_6;
    QFrame *TOOLStools;
    QTableWidget *TOOLStable;
    QWidget *tabDIRS;
    QVBoxLayout *verticalLayout_5;
    QFrame *DIRStools;
    QToolButton *DIRStools_add;
    QToolButton *DIRStools_del;
    QListWidget *DIRSlist;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuExport;
    QMenu *menuImport;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuName;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionROMS = new QAction(MainWindow);
        actionROMS->setObjectName(QString::fromUtf8("actionROMS"));
        actionDEVICE = new QAction(MainWindow);
        actionDEVICE->setObjectName(QString::fromUtf8("actionDEVICE"));
        actionFAVORITES = new QAction(MainWindow);
        actionFAVORITES->setObjectName(QString::fromUtf8("actionFAVORITES"));
        actionTOOLS = new QAction(MainWindow);
        actionTOOLS->setObjectName(QString::fromUtf8("actionTOOLS"));
        actionDIRS = new QAction(MainWindow);
        actionDIRS->setObjectName(QString::fromUtf8("actionDIRS"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAboutOt = new QAction(MainWindow);
        actionAboutOt->setObjectName(QString::fromUtf8("actionAboutOt"));
        actionJPN = new QAction(MainWindow);
        actionJPN->setObjectName(QString::fromUtf8("actionJPN"));
        actionJPN->setCheckable(true);
        actionENG = new QAction(MainWindow);
        actionENG->setObjectName(QString::fromUtf8("actionENG"));
        actionENG->setCheckable(true);
        actionFRN = new QAction(MainWindow);
        actionFRN->setObjectName(QString::fromUtf8("actionFRN"));
        actionFRN->setCheckable(true);
        actionGER = new QAction(MainWindow);
        actionGER->setObjectName(QString::fromUtf8("actionGER"));
        actionGER->setCheckable(true);
        actionGER->setChecked(true);
        actionITL = new QAction(MainWindow);
        actionITL->setObjectName(QString::fromUtf8("actionITL"));
        actionITL->setCheckable(true);
        actionSPN = new QAction(MainWindow);
        actionSPN->setObjectName(QString::fromUtf8("actionSPN"));
        actionSPN->setCheckable(true);
        actionCHI = new QAction(MainWindow);
        actionCHI->setObjectName(QString::fromUtf8("actionCHI"));
        actionCHI->setCheckable(true);
        actionExportROMListe = new QAction(MainWindow);
        actionExportROMListe->setObjectName(QString::fromUtf8("actionExportROMListe"));
        actionExportIMGListe = new QAction(MainWindow);
        actionExportIMGListe->setObjectName(QString::fromUtf8("actionExportIMGListe"));
        actionImportROMListe = new QAction(MainWindow);
        actionImportROMListe->setObjectName(QString::fromUtf8("actionImportROMListe"));
        actionImportIMGListe = new QAction(MainWindow);
        actionImportIMGListe->setObjectName(QString::fromUtf8("actionImportIMGListe"));
        actionImportROMDataListe = new QAction(MainWindow);
        actionImportROMDataListe->setObjectName(QString::fromUtf8("actionImportROMDataListe"));
        actionExportROMDataListe = new QAction(MainWindow);
        actionExportROMDataListe->setObjectName(QString::fromUtf8("actionExportROMDataListe"));
        actionImportROMCodeListe = new QAction(MainWindow);
        actionImportROMCodeListe->setObjectName(QString::fromUtf8("actionImportROMCodeListe"));
        actionExportROMCodeListe = new QAction(MainWindow);
        actionExportROMCodeListe->setObjectName(QString::fromUtf8("actionExportROMCodeListe"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        functionTabs = new QTabWidget(centralwidget);
        functionTabs->setObjectName(QString::fromUtf8("functionTabs"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(functionTabs->sizePolicy().hasHeightForWidth());
        functionTabs->setSizePolicy(sizePolicy);
        functionTabs->setMinimumSize(QSize(0, 0));
        functionTabs->setSizeIncrement(QSize(0, 0));
        functionTabs->setTabPosition(QTabWidget::North);
        functionTabs->setTabShape(QTabWidget::Rounded);
        functionTabs->setElideMode(Qt::ElideNone);
        tabROMS = new QWidget();
        tabROMS->setObjectName(QString::fromUtf8("tabROMS"));
        verticalLayout_2 = new QVBoxLayout(tabROMS);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ROMStools = new QFrame(tabROMS);
        ROMStools->setObjectName(QString::fromUtf8("ROMStools"));
        ROMStools->setMinimumSize(QSize(0, 50));
        ROMStools->setFrameShape(QFrame::StyledPanel);
        ROMStools->setFrameShadow(QFrame::Raised);
        ROMStools_scan = new QToolButton(ROMStools);
        ROMStools_scan->setObjectName(QString::fromUtf8("ROMStools_scan"));
        ROMStools_scan->setGeometry(QRect(20, 10, 31, 31));
        ROMStools_scan->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        ROMStools_romlist = new QToolButton(ROMStools);
        ROMStools_romlist->setObjectName(QString::fromUtf8("ROMStools_romlist"));
        ROMStools_romlist->setGeometry(QRect(90, 10, 31, 31));
        ROMStools_scanlist = new QToolButton(ROMStools);
        ROMStools_scanlist->setObjectName(QString::fromUtf8("ROMStools_scanlist"));
        ROMStools_scanlist->setGeometry(QRect(140, 10, 31, 31));
        ROMStools_scanclear = new QToolButton(ROMStools);
        ROMStools_scanclear->setObjectName(QString::fromUtf8("ROMStools_scanclear"));
        ROMStools_scanclear->setGeometry(QRect(190, 10, 31, 31));
        ROMStools_line1 = new QFrame(ROMStools);
        ROMStools_line1->setObjectName(QString::fromUtf8("ROMStools_line1"));
        ROMStools_line1->setGeometry(QRect(60, 10, 20, 31));
        ROMStools_line1->setFrameShape(QFrame::VLine);
        ROMStools_line1->setFrameShadow(QFrame::Sunken);
        ROMStools_line2 = new QFrame(ROMStools);
        ROMStools_line2->setObjectName(QString::fromUtf8("ROMStools_line2"));
        ROMStools_line2->setGeometry(QRect(230, 10, 20, 31));
        ROMStools_line2->setFrameShape(QFrame::VLine);
        ROMStools_line2->setFrameShadow(QFrame::Sunken);
        ROMStools_copy = new QToolButton(ROMStools);
        ROMStools_copy->setObjectName(QString::fromUtf8("ROMStools_copy"));
        ROMStools_copy->setGeometry(QRect(330, 10, 31, 31));
        ROMStools_delete = new QToolButton(ROMStools);
        ROMStools_delete->setObjectName(QString::fromUtf8("ROMStools_delete"));
        ROMStools_delete->setGeometry(QRect(260, 10, 31, 31));
        line = new QFrame(ROMStools);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(300, 10, 20, 31));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(ROMStools);

        ROMStable = new QTableWidget(tabROMS);
        if (ROMStable->columnCount() < 9)
            ROMStable->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        ROMStable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        ROMStable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        ROMStable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        ROMStable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        ROMStable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        ROMStable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        ROMStable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ROMStable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        ROMStable->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        ROMStable->setObjectName(QString::fromUtf8("ROMStable"));
        ROMStable->setEditTriggers(QAbstractItemView::DoubleClicked);
        ROMStable->setDragEnabled(true);
        ROMStable->setDragDropMode(QAbstractItemView::DragOnly);
        ROMStable->setAlternatingRowColors(true);
        ROMStable->setSelectionMode(QAbstractItemView::ExtendedSelection);
        ROMStable->setSelectionBehavior(QAbstractItemView::SelectRows);
        ROMStable->setSortingEnabled(true);
        ROMStable->horizontalHeader()->setStretchLastSection(true);
        ROMStable->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(ROMStable);

        functionTabs->addTab(tabROMS, QString());
        tabDEVICE = new QWidget();
        tabDEVICE->setObjectName(QString::fromUtf8("tabDEVICE"));
        verticalLayout_3 = new QVBoxLayout(tabDEVICE);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        DEVICEtools = new QFrame(tabDEVICE);
        DEVICEtools->setObjectName(QString::fromUtf8("DEVICEtools"));
        DEVICEtools->setMinimumSize(QSize(0, 50));
        DEVICEtools->setFrameShape(QFrame::StyledPanel);
        DEVICEtools->setFrameShadow(QFrame::Raised);
        DEVICEtools_scan = new QToolButton(DEVICEtools);
        DEVICEtools_scan->setObjectName(QString::fromUtf8("DEVICEtools_scan"));
        DEVICEtools_scan->setGeometry(QRect(20, 10, 31, 31));
        DEVICEtools_line1 = new QFrame(DEVICEtools);
        DEVICEtools_line1->setObjectName(QString::fromUtf8("DEVICEtools_line1"));
        DEVICEtools_line1->setGeometry(QRect(60, 10, 16, 31));
        DEVICEtools_line1->setFrameShape(QFrame::VLine);
        DEVICEtools_line1->setFrameShadow(QFrame::Sunken);
        DEVICEtools_remove = new QToolButton(DEVICEtools);
        DEVICEtools_remove->setObjectName(QString::fromUtf8("DEVICEtools_remove"));
        DEVICEtools_remove->setGeometry(QRect(90, 10, 31, 31));

        verticalLayout_3->addWidget(DEVICEtools);

        DEVICEtable = new QTableWidget(tabDEVICE);
        if (DEVICEtable->columnCount() < 9)
            DEVICEtable->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        DEVICEtable->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        DEVICEtable->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        DEVICEtable->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        DEVICEtable->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        DEVICEtable->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        DEVICEtable->setHorizontalHeaderItem(5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        DEVICEtable->setHorizontalHeaderItem(6, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        DEVICEtable->setHorizontalHeaderItem(7, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        DEVICEtable->setHorizontalHeaderItem(8, __qtablewidgetitem17);
        DEVICEtable->setObjectName(QString::fromUtf8("DEVICEtable"));
        DEVICEtable->setSelectionBehavior(QAbstractItemView::SelectRows);
        DEVICEtable->setSortingEnabled(true);
        DEVICEtable->horizontalHeader()->setStretchLastSection(true);
        DEVICEtable->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(DEVICEtable);

        functionTabs->addTab(tabDEVICE, QString());
        tabFAVORITES = new QWidget();
        tabFAVORITES->setObjectName(QString::fromUtf8("tabFAVORITES"));
        verticalLayout_4 = new QVBoxLayout(tabFAVORITES);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        FAVORITEStools = new QFrame(tabFAVORITES);
        FAVORITEStools->setObjectName(QString::fromUtf8("FAVORITEStools"));
        FAVORITEStools->setMinimumSize(QSize(0, 50));
        FAVORITEStools->setFrameShape(QFrame::StyledPanel);
        FAVORITEStools->setFrameShadow(QFrame::Raised);

        verticalLayout_4->addWidget(FAVORITEStools);

        splitter = new QSplitter(tabFAVORITES);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy1);
        splitter->setOrientation(Qt::Horizontal);
        FAVORITESlist = new QListWidget(splitter);
        FAVORITESlist->setObjectName(QString::fromUtf8("FAVORITESlist"));
        FAVORITESlist->setSelectionBehavior(QAbstractItemView::SelectRows);
        splitter->addWidget(FAVORITESlist);
        FAVORITEStable = new QTableWidget(splitter);
        if (FAVORITEStable->columnCount() < 9)
            FAVORITEStable->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        FAVORITEStable->setHorizontalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        FAVORITEStable->setHorizontalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        FAVORITEStable->setHorizontalHeaderItem(2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        FAVORITEStable->setHorizontalHeaderItem(3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        FAVORITEStable->setHorizontalHeaderItem(4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        FAVORITEStable->setHorizontalHeaderItem(5, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        FAVORITEStable->setHorizontalHeaderItem(6, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        FAVORITEStable->setHorizontalHeaderItem(7, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        FAVORITEStable->setHorizontalHeaderItem(8, __qtablewidgetitem26);
        FAVORITEStable->setObjectName(QString::fromUtf8("FAVORITEStable"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(FAVORITEStable->sizePolicy().hasHeightForWidth());
        FAVORITEStable->setSizePolicy(sizePolicy2);
        FAVORITEStable->setSelectionBehavior(QAbstractItemView::SelectRows);
        splitter->addWidget(FAVORITEStable);

        verticalLayout_4->addWidget(splitter);

        functionTabs->addTab(tabFAVORITES, QString());
        tabTOOLS = new QWidget();
        tabTOOLS->setObjectName(QString::fromUtf8("tabTOOLS"));
        verticalLayout_6 = new QVBoxLayout(tabTOOLS);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        TOOLStools = new QFrame(tabTOOLS);
        TOOLStools->setObjectName(QString::fromUtf8("TOOLStools"));
        TOOLStools->setMinimumSize(QSize(0, 50));
        TOOLStools->setFrameShape(QFrame::StyledPanel);
        TOOLStools->setFrameShadow(QFrame::Raised);

        verticalLayout_6->addWidget(TOOLStools);

        TOOLStable = new QTableWidget(tabTOOLS);
        TOOLStable->setObjectName(QString::fromUtf8("TOOLStable"));
        TOOLStable->setSelectionMode(QAbstractItemView::SingleSelection);
        TOOLStable->setSelectionBehavior(QAbstractItemView::SelectRows);
        TOOLStable->horizontalHeader()->setStretchLastSection(true);
        TOOLStable->verticalHeader()->setVisible(false);

        verticalLayout_6->addWidget(TOOLStable);

        functionTabs->addTab(tabTOOLS, QString());
        tabDIRS = new QWidget();
        tabDIRS->setObjectName(QString::fromUtf8("tabDIRS"));
        verticalLayout_5 = new QVBoxLayout(tabDIRS);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        DIRStools = new QFrame(tabDIRS);
        DIRStools->setObjectName(QString::fromUtf8("DIRStools"));
        DIRStools->setMinimumSize(QSize(0, 50));
        DIRStools->setFrameShape(QFrame::StyledPanel);
        DIRStools->setFrameShadow(QFrame::Raised);
        DIRStools_add = new QToolButton(DIRStools);
        DIRStools_add->setObjectName(QString::fromUtf8("DIRStools_add"));
        DIRStools_add->setGeometry(QRect(20, 10, 31, 31));
        DIRStools_add->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        DIRStools_add->setArrowType(Qt::NoArrow);
        DIRStools_del = new QToolButton(DIRStools);
        DIRStools_del->setObjectName(QString::fromUtf8("DIRStools_del"));
        DIRStools_del->setGeometry(QRect(70, 10, 31, 31));
        DIRStools_del->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_5->addWidget(DIRStools);

        DIRSlist = new QListWidget(tabDIRS);
        DIRSlist->setObjectName(QString::fromUtf8("DIRSlist"));
        DIRSlist->setSelectionMode(QAbstractItemView::ExtendedSelection);
        DIRSlist->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_5->addWidget(DIRSlist);

        functionTabs->addTab(tabDIRS, QString());

        verticalLayout->addWidget(functionTabs);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuExport = new QMenu(menuFile);
        menuExport->setObjectName(QString::fromUtf8("menuExport"));
        menuImport = new QMenu(menuFile);
        menuImport->setObjectName(QString::fromUtf8("menuImport"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuName = new QMenu(menuView);
        menuName->setObjectName(QString::fromUtf8("menuName"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(menuImport->menuAction());
        menuFile->addAction(menuExport->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuExport->addAction(actionExportROMListe);
        menuExport->addAction(actionExportROMDataListe);
        menuExport->addAction(actionExportROMCodeListe);
        menuExport->addAction(actionExportIMGListe);
        menuImport->addAction(actionImportROMListe);
        menuImport->addAction(actionImportROMDataListe);
        menuImport->addAction(actionImportROMCodeListe);
        menuImport->addAction(actionImportIMGListe);
        menuEdit->addAction(actionSettings);
        menuView->addAction(actionROMS);
        menuView->addAction(actionDEVICE);
        menuView->addAction(actionFAVORITES);
        menuView->addAction(actionTOOLS);
        menuView->addAction(actionDIRS);
        menuView->addSeparator();
        menuView->addAction(menuName->menuAction());
        menuName->addAction(actionJPN);
        menuName->addAction(actionENG);
        menuName->addAction(actionFRN);
        menuName->addAction(actionGER);
        menuName->addAction(actionITL);
        menuName->addAction(actionSPN);
        menuName->addAction(actionCHI);
        menuHelp->addAction(actionAbout);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAboutOt);

        retranslateUi(MainWindow);

        functionTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "NDS ROM ORG", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Beenden", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindow", "Einstellungen", 0, QApplication::UnicodeUTF8));
        actionROMS->setText(QApplication::translate("MainWindow", "ROMS", 0, QApplication::UnicodeUTF8));
        actionDEVICE->setText(QApplication::translate("MainWindow", "DEVICE", 0, QApplication::UnicodeUTF8));
        actionFAVORITES->setText(QApplication::translate("MainWindow", "Favoriten", 0, QApplication::UnicodeUTF8));
        actionTOOLS->setText(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
        actionDIRS->setText(QApplication::translate("MainWindow", "Verzeichnisse", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "\303\234ber NDS ROM ORG", 0, QApplication::UnicodeUTF8));
        actionAboutOt->setText(QApplication::translate("MainWindow", "\303\234ber Qt", 0, QApplication::UnicodeUTF8));
        actionJPN->setText(QApplication::translate("MainWindow", "JPN", 0, QApplication::UnicodeUTF8));
        actionENG->setText(QApplication::translate("MainWindow", "ENG", 0, QApplication::UnicodeUTF8));
        actionFRN->setText(QApplication::translate("MainWindow", "FRN", 0, QApplication::UnicodeUTF8));
        actionGER->setText(QApplication::translate("MainWindow", "GER", 0, QApplication::UnicodeUTF8));
        actionITL->setText(QApplication::translate("MainWindow", "ITL", 0, QApplication::UnicodeUTF8));
        actionSPN->setText(QApplication::translate("MainWindow", "SPN", 0, QApplication::UnicodeUTF8));
        actionCHI->setText(QApplication::translate("MainWindow", "CHI", 0, QApplication::UnicodeUTF8));
        actionExportROMListe->setText(QApplication::translate("MainWindow", "ROM Liste", 0, QApplication::UnicodeUTF8));
        actionExportIMGListe->setText(QApplication::translate("MainWindow", "IMG Liste", 0, QApplication::UnicodeUTF8));
        actionImportROMListe->setText(QApplication::translate("MainWindow", "ROM Liste", 0, QApplication::UnicodeUTF8));
        actionImportIMGListe->setText(QApplication::translate("MainWindow", "IMG Liste", 0, QApplication::UnicodeUTF8));
        actionImportROMDataListe->setText(QApplication::translate("MainWindow", "ROM Data Liste", 0, QApplication::UnicodeUTF8));
        actionExportROMDataListe->setText(QApplication::translate("MainWindow", "ROM Data Liste", 0, QApplication::UnicodeUTF8));
        actionImportROMCodeListe->setText(QApplication::translate("MainWindow", "ROM Code Liste", 0, QApplication::UnicodeUTF8));
        actionExportROMCodeListe->setText(QApplication::translate("MainWindow", "ROM Code Liste", 0, QApplication::UnicodeUTF8));
        ROMStools_scan->setText(QApplication::translate("MainWindow", "Scan", 0, QApplication::UnicodeUTF8));
        ROMStools_romlist->setText(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
        ROMStools_scanlist->setText(QApplication::translate("MainWindow", "S", 0, QApplication::UnicodeUTF8));
        ROMStools_scanclear->setText(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        ROMStools_copy->setText(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        ROMStools_delete->setText(QApplication::translate("MainWindow", "D", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = ROMStable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = ROMStable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Icon", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = ROMStable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = ROMStable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = ROMStable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "ROM Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = ROMStable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "ROM Serial", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = ROMStable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "CRC32", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = ROMStable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "ROM Gr\303\266\303\237e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = ROMStable->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Verleger", 0, QApplication::UnicodeUTF8));
        functionTabs->setTabText(functionTabs->indexOf(tabROMS), QApplication::translate("MainWindow", "ROMS", 0, QApplication::UnicodeUTF8));
        DEVICEtools_scan->setText(QApplication::translate("MainWindow", "Scan", 0, QApplication::UnicodeUTF8));
        DEVICEtools_remove->setText(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = DEVICEtable->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = DEVICEtable->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Icon", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = DEVICEtable->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = DEVICEtable->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = DEVICEtable->horizontalHeaderItem(4);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "ROM Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = DEVICEtable->horizontalHeaderItem(5);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "ROM Serial", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = DEVICEtable->horizontalHeaderItem(6);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "CRC32", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = DEVICEtable->horizontalHeaderItem(7);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "ROM Gr\303\266\303\237e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = DEVICEtable->horizontalHeaderItem(8);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Verleger", 0, QApplication::UnicodeUTF8));
        functionTabs->setTabText(functionTabs->indexOf(tabDEVICE), QApplication::translate("MainWindow", "DEVICE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = FAVORITEStable->horizontalHeaderItem(0);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = FAVORITEStable->horizontalHeaderItem(1);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Icon", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = FAVORITEStable->horizontalHeaderItem(2);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = FAVORITEStable->horizontalHeaderItem(3);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = FAVORITEStable->horizontalHeaderItem(4);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "ROM Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = FAVORITEStable->horizontalHeaderItem(5);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "ROM Serial", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = FAVORITEStable->horizontalHeaderItem(6);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "CRC32", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = FAVORITEStable->horizontalHeaderItem(7);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "ROM Gr\303\266\303\237e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem26 = FAVORITEStable->horizontalHeaderItem(8);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "Verleger", 0, QApplication::UnicodeUTF8));
        functionTabs->setTabText(functionTabs->indexOf(tabFAVORITES), QApplication::translate("MainWindow", "Favoriten", 0, QApplication::UnicodeUTF8));
        functionTabs->setTabText(functionTabs->indexOf(tabTOOLS), QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
        DIRStools_add->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        DIRStools_del->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        functionTabs->setTabText(functionTabs->indexOf(tabDIRS), QApplication::translate("MainWindow", "Verzeichnisse", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "Datei", 0, QApplication::UnicodeUTF8));
        menuExport->setTitle(QApplication::translate("MainWindow", "Export", 0, QApplication::UnicodeUTF8));
        menuImport->setTitle(QApplication::translate("MainWindow", "Import", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Bearbeiten", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "Ansicht", 0, QApplication::UnicodeUTF8));
        menuName->setTitle(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Hilfe", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NDSROMAINDLG_H
