/********************************************************************************
** Form generated from reading UI file 'NDSROdetailDlg.ui'
**
** Created: Mon Jan 13 21:12:42 2014
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NDSRODETAILDLG_H
#define UI_NDSRODETAILDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *IMGscrollArea;
    QWidget *scrollAreaWidgetContents;
    QFrame *IMGthumbFrame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *CMD_THUMB_LEFT;
    QScrollArea *IMGthumbscrollArea;
    QWidget *THUMBS;
    QVBoxLayout *verticalLayout_15;
    QPushButton *CMD_THUMB_RIGHT;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_14;
    QGridLayout *gridLayout;
    QLabel *label_ROMid;
    QLabel *ROMid;
    QLabel *label_ROMdisplname;
    QLineEdit *ROMdisplname;
    QLabel *label_ROMversion;
    QLabel *ROMversion;
    QLabel *label_ROMserial;
    QLabel *ROMserial;
    QLabel *label_ROMcode;
    QLabel *ROMcode;
    QLabel *label_ROMpublisher;
    QLabel *ROMpublisher;
    QLabel *label_ROMfilesize;
    QLabel *ROMfilesize;
    QLabel *label_ROMccapacity;
    QLabel *ROMcapacity;
    QLabel *label_ROMcrc32;
    QLabel *ROMcrc32;
    QLabel *ROMicon;
    QLabel *label_ROMname;
    QLabel *ROMname;
    QToolButton *CMDcode;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_8;
    QTextEdit *ROMcomment;
    QTabWidget *languageTABS;
    QWidget *tabJPN;
    QVBoxLayout *verticalLayout_5;
    QLabel *JPNname;
    QLabel *JPNsubname;
    QLabel *JPNpublisher;
    QWidget *tabENG;
    QVBoxLayout *verticalLayout_6;
    QLabel *ENGname;
    QLabel *ENGsubname;
    QLabel *ENGpublisher;
    QWidget *tabFRN;
    QVBoxLayout *verticalLayout_9;
    QLabel *FRNname;
    QLabel *FRNsubname;
    QLabel *FRNpublisher;
    QWidget *tabGER;
    QVBoxLayout *verticalLayout_10;
    QLabel *GERname;
    QLabel *GERsubname;
    QLabel *GERpublisher;
    QWidget *tabITL;
    QVBoxLayout *verticalLayout_11;
    QLabel *ITLname;
    QLabel *ITLsubname;
    QLabel *ITLpublisher;
    QWidget *tabSPN;
    QVBoxLayout *verticalLayout_12;
    QLabel *SPNname;
    QLabel *SPNsubname;
    QLabel *SPNpublisher;
    QWidget *tabCHI;
    QVBoxLayout *verticalLayout_13;
    QLabel *CHIname;
    QLabel *CHIsubname;
    QLabel *CHIpublisher;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QDialogButtonBox *CMD;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(1024, 768);
        Dialog->setSizeGripEnabled(true);
        verticalLayout_3 = new QVBoxLayout(Dialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        splitter = new QSplitter(Dialog);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        IMGscrollArea = new QScrollArea(layoutWidget);
        IMGscrollArea->setObjectName(QString::fromUtf8("IMGscrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(IMGscrollArea->sizePolicy().hasHeightForWidth());
        IMGscrollArea->setSizePolicy(sizePolicy1);
        IMGscrollArea->setMinimumSize(QSize(0, 0));
        IMGscrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        IMGscrollArea->setWidgetResizable(false);
        IMGscrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 452, 460));
        IMGscrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(IMGscrollArea);

        IMGthumbFrame = new QFrame(layoutWidget);
        IMGthumbFrame->setObjectName(QString::fromUtf8("IMGthumbFrame"));
        IMGthumbFrame->setMinimumSize(QSize(0, 73));
        IMGthumbFrame->setFrameShape(QFrame::StyledPanel);
        IMGthumbFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(IMGthumbFrame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        CMD_THUMB_LEFT = new QPushButton(IMGthumbFrame);
        CMD_THUMB_LEFT->setObjectName(QString::fromUtf8("CMD_THUMB_LEFT"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CMD_THUMB_LEFT->sizePolicy().hasHeightForWidth());
        CMD_THUMB_LEFT->setSizePolicy(sizePolicy2);
        CMD_THUMB_LEFT->setMaximumSize(QSize(16, 16777215));

        horizontalLayout_2->addWidget(CMD_THUMB_LEFT);

        IMGthumbscrollArea = new QScrollArea(IMGthumbFrame);
        IMGthumbscrollArea->setObjectName(QString::fromUtf8("IMGthumbscrollArea"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(IMGthumbscrollArea->sizePolicy().hasHeightForWidth());
        IMGthumbscrollArea->setSizePolicy(sizePolicy3);
        IMGthumbscrollArea->setFrameShape(QFrame::StyledPanel);
        IMGthumbscrollArea->setFrameShadow(QFrame::Raised);
        IMGthumbscrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        IMGthumbscrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        IMGthumbscrollArea->setWidgetResizable(false);
        IMGthumbscrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        THUMBS = new QWidget();
        THUMBS->setObjectName(QString::fromUtf8("THUMBS"));
        THUMBS->setGeometry(QRect(0, 0, 538, 82));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(THUMBS->sizePolicy().hasHeightForWidth());
        THUMBS->setSizePolicy(sizePolicy4);
        THUMBS->setBaseSize(QSize(0, 0));
        verticalLayout_15 = new QVBoxLayout(THUMBS);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        IMGthumbscrollArea->setWidget(THUMBS);

        horizontalLayout_2->addWidget(IMGthumbscrollArea);

        CMD_THUMB_RIGHT = new QPushButton(IMGthumbFrame);
        CMD_THUMB_RIGHT->setObjectName(QString::fromUtf8("CMD_THUMB_RIGHT"));
        sizePolicy2.setHeightForWidth(CMD_THUMB_RIGHT->sizePolicy().hasHeightForWidth());
        CMD_THUMB_RIGHT->setSizePolicy(sizePolicy2);
        CMD_THUMB_RIGHT->setMaximumSize(QSize(16, 16777215));

        horizontalLayout_2->addWidget(CMD_THUMB_RIGHT);


        verticalLayout->addWidget(IMGthumbFrame);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(layoutWidget1);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(2);
        sizePolicy5.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy5);
        frame->setMinimumSize(QSize(0, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(3, -1, 3, 3);
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(false);
        verticalLayout_14 = new QVBoxLayout(groupBox);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, -1, -1, -1);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_ROMid = new QLabel(groupBox);
        label_ROMid->setObjectName(QString::fromUtf8("label_ROMid"));

        gridLayout->addWidget(label_ROMid, 1, 0, 1, 3);

        ROMid = new QLabel(groupBox);
        ROMid->setObjectName(QString::fromUtf8("ROMid"));

        gridLayout->addWidget(ROMid, 1, 3, 1, 4);

        label_ROMdisplname = new QLabel(groupBox);
        label_ROMdisplname->setObjectName(QString::fromUtf8("label_ROMdisplname"));

        gridLayout->addWidget(label_ROMdisplname, 2, 0, 1, 3);

        ROMdisplname = new QLineEdit(groupBox);
        ROMdisplname->setObjectName(QString::fromUtf8("ROMdisplname"));
        QFont font;
        font.setPointSize(8);
        ROMdisplname->setFont(font);
        ROMdisplname->setAutoFillBackground(true);
        ROMdisplname->setFrame(false);
        ROMdisplname->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout->addWidget(ROMdisplname, 2, 3, 1, 5);

        label_ROMversion = new QLabel(groupBox);
        label_ROMversion->setObjectName(QString::fromUtf8("label_ROMversion"));

        gridLayout->addWidget(label_ROMversion, 4, 0, 1, 3);

        ROMversion = new QLabel(groupBox);
        ROMversion->setObjectName(QString::fromUtf8("ROMversion"));

        gridLayout->addWidget(ROMversion, 4, 3, 1, 5);

        label_ROMserial = new QLabel(groupBox);
        label_ROMserial->setObjectName(QString::fromUtf8("label_ROMserial"));

        gridLayout->addWidget(label_ROMserial, 5, 0, 1, 3);

        ROMserial = new QLabel(groupBox);
        ROMserial->setObjectName(QString::fromUtf8("ROMserial"));

        gridLayout->addWidget(ROMserial, 5, 3, 1, 5);

        label_ROMcode = new QLabel(groupBox);
        label_ROMcode->setObjectName(QString::fromUtf8("label_ROMcode"));

        gridLayout->addWidget(label_ROMcode, 6, 0, 1, 3);

        ROMcode = new QLabel(groupBox);
        ROMcode->setObjectName(QString::fromUtf8("ROMcode"));

        gridLayout->addWidget(ROMcode, 6, 3, 1, 4);

        label_ROMpublisher = new QLabel(groupBox);
        label_ROMpublisher->setObjectName(QString::fromUtf8("label_ROMpublisher"));

        gridLayout->addWidget(label_ROMpublisher, 7, 0, 1, 3);

        ROMpublisher = new QLabel(groupBox);
        ROMpublisher->setObjectName(QString::fromUtf8("ROMpublisher"));

        gridLayout->addWidget(ROMpublisher, 7, 3, 1, 5);

        label_ROMfilesize = new QLabel(groupBox);
        label_ROMfilesize->setObjectName(QString::fromUtf8("label_ROMfilesize"));

        gridLayout->addWidget(label_ROMfilesize, 8, 0, 1, 3);

        ROMfilesize = new QLabel(groupBox);
        ROMfilesize->setObjectName(QString::fromUtf8("ROMfilesize"));

        gridLayout->addWidget(ROMfilesize, 8, 3, 1, 5);

        label_ROMccapacity = new QLabel(groupBox);
        label_ROMccapacity->setObjectName(QString::fromUtf8("label_ROMccapacity"));

        gridLayout->addWidget(label_ROMccapacity, 9, 0, 1, 3);

        ROMcapacity = new QLabel(groupBox);
        ROMcapacity->setObjectName(QString::fromUtf8("ROMcapacity"));

        gridLayout->addWidget(ROMcapacity, 9, 3, 1, 5);

        label_ROMcrc32 = new QLabel(groupBox);
        label_ROMcrc32->setObjectName(QString::fromUtf8("label_ROMcrc32"));

        gridLayout->addWidget(label_ROMcrc32, 10, 0, 1, 3);

        ROMcrc32 = new QLabel(groupBox);
        ROMcrc32->setObjectName(QString::fromUtf8("ROMcrc32"));

        gridLayout->addWidget(ROMcrc32, 10, 3, 1, 5);

        ROMicon = new QLabel(groupBox);
        ROMicon->setObjectName(QString::fromUtf8("ROMicon"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(ROMicon->sizePolicy().hasHeightForWidth());
        ROMicon->setSizePolicy(sizePolicy6);
        ROMicon->setMinimumSize(QSize(64, 64));
        ROMicon->setMaximumSize(QSize(64, 64));
        ROMicon->setFrameShape(QFrame::Box);
        ROMicon->setFrameShadow(QFrame::Sunken);
        ROMicon->setScaledContents(true);

        gridLayout->addWidget(ROMicon, 0, 7, 2, 1);

        label_ROMname = new QLabel(groupBox);
        label_ROMname->setObjectName(QString::fromUtf8("label_ROMname"));

        gridLayout->addWidget(label_ROMname, 3, 0, 1, 3);

        ROMname = new QLabel(groupBox);
        ROMname->setObjectName(QString::fromUtf8("ROMname"));

        gridLayout->addWidget(ROMname, 3, 3, 1, 5);

        CMDcode = new QToolButton(groupBox);
        CMDcode->setObjectName(QString::fromUtf8("CMDcode"));

        gridLayout->addWidget(CMDcode, 6, 7, 1, 1);


        verticalLayout_14->addLayout(gridLayout);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_8 = new QVBoxLayout(groupBox_2);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, -1, 0, -1);
        ROMcomment = new QTextEdit(groupBox_2);
        ROMcomment->setObjectName(QString::fromUtf8("ROMcomment"));

        verticalLayout_8->addWidget(ROMcomment);


        verticalLayout_14->addWidget(groupBox_2);

        languageTABS = new QTabWidget(groupBox);
        languageTABS->setObjectName(QString::fromUtf8("languageTABS"));
        languageTABS->setMaximumSize(QSize(16777215, 120));
        tabJPN = new QWidget();
        tabJPN->setObjectName(QString::fromUtf8("tabJPN"));
        verticalLayout_5 = new QVBoxLayout(tabJPN);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        JPNname = new QLabel(tabJPN);
        JPNname->setObjectName(QString::fromUtf8("JPNname"));

        verticalLayout_5->addWidget(JPNname);

        JPNsubname = new QLabel(tabJPN);
        JPNsubname->setObjectName(QString::fromUtf8("JPNsubname"));

        verticalLayout_5->addWidget(JPNsubname);

        JPNpublisher = new QLabel(tabJPN);
        JPNpublisher->setObjectName(QString::fromUtf8("JPNpublisher"));

        verticalLayout_5->addWidget(JPNpublisher);

        languageTABS->addTab(tabJPN, QString());
        tabENG = new QWidget();
        tabENG->setObjectName(QString::fromUtf8("tabENG"));
        verticalLayout_6 = new QVBoxLayout(tabENG);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        ENGname = new QLabel(tabENG);
        ENGname->setObjectName(QString::fromUtf8("ENGname"));

        verticalLayout_6->addWidget(ENGname);

        ENGsubname = new QLabel(tabENG);
        ENGsubname->setObjectName(QString::fromUtf8("ENGsubname"));

        verticalLayout_6->addWidget(ENGsubname);

        ENGpublisher = new QLabel(tabENG);
        ENGpublisher->setObjectName(QString::fromUtf8("ENGpublisher"));

        verticalLayout_6->addWidget(ENGpublisher);

        languageTABS->addTab(tabENG, QString());
        tabFRN = new QWidget();
        tabFRN->setObjectName(QString::fromUtf8("tabFRN"));
        verticalLayout_9 = new QVBoxLayout(tabFRN);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        FRNname = new QLabel(tabFRN);
        FRNname->setObjectName(QString::fromUtf8("FRNname"));

        verticalLayout_9->addWidget(FRNname);

        FRNsubname = new QLabel(tabFRN);
        FRNsubname->setObjectName(QString::fromUtf8("FRNsubname"));

        verticalLayout_9->addWidget(FRNsubname);

        FRNpublisher = new QLabel(tabFRN);
        FRNpublisher->setObjectName(QString::fromUtf8("FRNpublisher"));

        verticalLayout_9->addWidget(FRNpublisher);

        languageTABS->addTab(tabFRN, QString());
        tabGER = new QWidget();
        tabGER->setObjectName(QString::fromUtf8("tabGER"));
        verticalLayout_10 = new QVBoxLayout(tabGER);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        GERname = new QLabel(tabGER);
        GERname->setObjectName(QString::fromUtf8("GERname"));

        verticalLayout_10->addWidget(GERname);

        GERsubname = new QLabel(tabGER);
        GERsubname->setObjectName(QString::fromUtf8("GERsubname"));

        verticalLayout_10->addWidget(GERsubname);

        GERpublisher = new QLabel(tabGER);
        GERpublisher->setObjectName(QString::fromUtf8("GERpublisher"));

        verticalLayout_10->addWidget(GERpublisher);

        languageTABS->addTab(tabGER, QString());
        tabITL = new QWidget();
        tabITL->setObjectName(QString::fromUtf8("tabITL"));
        verticalLayout_11 = new QVBoxLayout(tabITL);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        ITLname = new QLabel(tabITL);
        ITLname->setObjectName(QString::fromUtf8("ITLname"));

        verticalLayout_11->addWidget(ITLname);

        ITLsubname = new QLabel(tabITL);
        ITLsubname->setObjectName(QString::fromUtf8("ITLsubname"));

        verticalLayout_11->addWidget(ITLsubname);

        ITLpublisher = new QLabel(tabITL);
        ITLpublisher->setObjectName(QString::fromUtf8("ITLpublisher"));

        verticalLayout_11->addWidget(ITLpublisher);

        languageTABS->addTab(tabITL, QString());
        tabSPN = new QWidget();
        tabSPN->setObjectName(QString::fromUtf8("tabSPN"));
        verticalLayout_12 = new QVBoxLayout(tabSPN);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        SPNname = new QLabel(tabSPN);
        SPNname->setObjectName(QString::fromUtf8("SPNname"));

        verticalLayout_12->addWidget(SPNname);

        SPNsubname = new QLabel(tabSPN);
        SPNsubname->setObjectName(QString::fromUtf8("SPNsubname"));

        verticalLayout_12->addWidget(SPNsubname);

        SPNpublisher = new QLabel(tabSPN);
        SPNpublisher->setObjectName(QString::fromUtf8("SPNpublisher"));

        verticalLayout_12->addWidget(SPNpublisher);

        languageTABS->addTab(tabSPN, QString());
        tabCHI = new QWidget();
        tabCHI->setObjectName(QString::fromUtf8("tabCHI"));
        verticalLayout_13 = new QVBoxLayout(tabCHI);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        CHIname = new QLabel(tabCHI);
        CHIname->setObjectName(QString::fromUtf8("CHIname"));

        verticalLayout_13->addWidget(CHIname);

        CHIsubname = new QLabel(tabCHI);
        CHIsubname->setObjectName(QString::fromUtf8("CHIsubname"));

        verticalLayout_13->addWidget(CHIsubname);

        CHIpublisher = new QLabel(tabCHI);
        CHIpublisher->setObjectName(QString::fromUtf8("CHIpublisher"));

        verticalLayout_13->addWidget(CHIpublisher);

        languageTABS->addTab(tabCHI, QString());

        verticalLayout_14->addWidget(languageTABS);


        verticalLayout_7->addWidget(groupBox);


        verticalLayout_2->addWidget(frame);

        splitter->addWidget(layoutWidget1);

        verticalLayout_3->addWidget(splitter);

        frame_2 = new QFrame(Dialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 50));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        CMD = new QDialogButtonBox(frame_2);
        CMD->setObjectName(QString::fromUtf8("CMD"));
        CMD->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Save);

        verticalLayout_4->addWidget(CMD);


        verticalLayout_3->addWidget(frame_2);


        retranslateUi(Dialog);

        languageTABS->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "ROM Details", 0, QApplication::UnicodeUTF8));
        CMD_THUMB_LEFT->setText(QApplication::translate("Dialog", "<", 0, QApplication::UnicodeUTF8));
        CMD_THUMB_RIGHT->setText(QApplication::translate("Dialog", ">", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Dialog", "Daten", 0, QApplication::UnicodeUTF8));
        label_ROMid->setText(QApplication::translate("Dialog", "ID", 0, QApplication::UnicodeUTF8));
        ROMid->setText(QString());
        label_ROMdisplname->setText(QApplication::translate("Dialog", "Name", 0, QApplication::UnicodeUTF8));
        label_ROMversion->setText(QApplication::translate("Dialog", "Version", 0, QApplication::UnicodeUTF8));
        ROMversion->setText(QString());
        label_ROMserial->setText(QApplication::translate("Dialog", "Serial", 0, QApplication::UnicodeUTF8));
        ROMserial->setText(QString());
        label_ROMcode->setText(QApplication::translate("Dialog", "Code", 0, QApplication::UnicodeUTF8));
        ROMcode->setText(QString());
        label_ROMpublisher->setText(QApplication::translate("Dialog", "Verleger", 0, QApplication::UnicodeUTF8));
        ROMpublisher->setText(QString());
        label_ROMfilesize->setText(QApplication::translate("Dialog", "Dateigr\303\266\303\237e", 0, QApplication::UnicodeUTF8));
        ROMfilesize->setText(QString());
        label_ROMccapacity->setText(QApplication::translate("Dialog", "Kapazit\303\244t", 0, QApplication::UnicodeUTF8));
        ROMcapacity->setText(QString());
        label_ROMcrc32->setText(QApplication::translate("Dialog", "CRC32", 0, QApplication::UnicodeUTF8));
        ROMcrc32->setText(QString());
        ROMicon->setText(QString());
        label_ROMname->setText(QApplication::translate("Dialog", "Name (intern)", 0, QApplication::UnicodeUTF8));
        ROMname->setText(QString());
        CMDcode->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Dialog", "Kommentar", 0, QApplication::UnicodeUTF8));
        JPNname->setText(QString());
        JPNsubname->setText(QString());
        JPNpublisher->setText(QString());
        languageTABS->setTabText(languageTABS->indexOf(tabJPN), QApplication::translate("Dialog", "JPN", 0, QApplication::UnicodeUTF8));
        ENGname->setText(QString());
        ENGsubname->setText(QString());
        ENGpublisher->setText(QString());
        languageTABS->setTabText(languageTABS->indexOf(tabENG), QApplication::translate("Dialog", "ENG", 0, QApplication::UnicodeUTF8));
        FRNname->setText(QString());
        FRNsubname->setText(QString());
        FRNpublisher->setText(QString());
        languageTABS->setTabText(languageTABS->indexOf(tabFRN), QApplication::translate("Dialog", "FRN", 0, QApplication::UnicodeUTF8));
        GERname->setText(QString());
        GERsubname->setText(QString());
        GERpublisher->setText(QString());
        languageTABS->setTabText(languageTABS->indexOf(tabGER), QApplication::translate("Dialog", "GER", 0, QApplication::UnicodeUTF8));
        ITLname->setText(QString());
        ITLsubname->setText(QString());
        ITLpublisher->setText(QString());
        languageTABS->setTabText(languageTABS->indexOf(tabITL), QApplication::translate("Dialog", "ITL", 0, QApplication::UnicodeUTF8));
        SPNname->setText(QString());
        SPNsubname->setText(QString());
        SPNpublisher->setText(QString());
        languageTABS->setTabText(languageTABS->indexOf(tabSPN), QApplication::translate("Dialog", "SPN", 0, QApplication::UnicodeUTF8));
        CHIname->setText(QString());
        CHIsubname->setText(QString());
        CHIpublisher->setText(QString());
        languageTABS->setTabText(languageTABS->indexOf(tabCHI), QApplication::translate("Dialog", "CHI", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NDSRODETAILDLG_H
