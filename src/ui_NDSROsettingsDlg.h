/********************************************************************************
** Form generated from reading UI file 'NDSROsettingsDlg.ui'
**
** Created: Mon Jan 13 21:12:42 2014
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NDSROSETTINGSDLG_H
#define UI_NDSROSETTINGSDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_NDSROsettingsDlg
{
public:
    QFrame *frame;
    QDialogButtonBox *CMD_BOX;
    QFrame *frame_2;
    QGroupBox *groupBox;
    QLineEdit *m_nds_rom_dir;
    QFrame *frame_3;
    QGroupBox *groupBox_2;
    QLineEdit *m_ndsro_data_dir;
    QFrame *frame_4;
    QGroupBox *groupBox_3;
    QLineEdit *m_nds_memcard_dir;

    void setupUi(QDialog *NDSROsettingsDlg)
    {
        if (NDSROsettingsDlg->objectName().isEmpty())
            NDSROsettingsDlg->setObjectName(QString::fromUtf8("NDSROsettingsDlg"));
        NDSROsettingsDlg->setWindowModality(Qt::ApplicationModal);
        NDSROsettingsDlg->resize(686, 249);
        NDSROsettingsDlg->setMinimumSize(QSize(686, 249));
        NDSROsettingsDlg->setMaximumSize(QSize(686, 249));
        NDSROsettingsDlg->setModal(true);
        frame = new QFrame(NDSROsettingsDlg);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(519, 10, 161, 231));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        CMD_BOX = new QDialogButtonBox(frame);
        CMD_BOX->setObjectName(QString::fromUtf8("CMD_BOX"));
        CMD_BOX->setGeometry(QRect(10, 10, 141, 151));
        CMD_BOX->setOrientation(Qt::Vertical);
        CMD_BOX->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok|QDialogButtonBox::RestoreDefaults);
        frame_2 = new QFrame(NDSROsettingsDlg);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 10, 501, 71));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        groupBox = new QGroupBox(frame_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 481, 51));
        groupBox->setAutoFillBackground(false);
        groupBox->setFlat(false);
        m_nds_rom_dir = new QLineEdit(groupBox);
        m_nds_rom_dir->setObjectName(QString::fromUtf8("m_nds_rom_dir"));
        m_nds_rom_dir->setGeometry(QRect(0, 20, 481, 27));
        m_nds_rom_dir->setFrame(false);
        frame_3 = new QFrame(NDSROsettingsDlg);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 90, 501, 71));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 481, 51));
        m_ndsro_data_dir = new QLineEdit(groupBox_2);
        m_ndsro_data_dir->setObjectName(QString::fromUtf8("m_ndsro_data_dir"));
        m_ndsro_data_dir->setGeometry(QRect(0, 20, 481, 27));
        m_ndsro_data_dir->setFrame(false);
        frame_4 = new QFrame(NDSROsettingsDlg);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(10, 170, 501, 71));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Sunken);
        groupBox_3 = new QGroupBox(frame_4);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 481, 51));
        m_nds_memcard_dir = new QLineEdit(groupBox_3);
        m_nds_memcard_dir->setObjectName(QString::fromUtf8("m_nds_memcard_dir"));
        m_nds_memcard_dir->setGeometry(QRect(0, 20, 481, 27));
        m_nds_memcard_dir->setFrame(false);

        retranslateUi(NDSROsettingsDlg);
        QObject::connect(CMD_BOX, SIGNAL(accepted()), NDSROsettingsDlg, SLOT(CMD_OK_clicked()));
        QObject::connect(CMD_BOX, SIGNAL(helpRequested()), NDSROsettingsDlg, SLOT(CMD_HELP_clicked()));
        QObject::connect(CMD_BOX, SIGNAL(rejected()), NDSROsettingsDlg, SLOT(CMD_CANCEL_clicked()));

        QMetaObject::connectSlotsByName(NDSROsettingsDlg);
    } // setupUi

    void retranslateUi(QDialog *NDSROsettingsDlg)
    {
        NDSROsettingsDlg->setWindowTitle(QApplication::translate("NDSROsettingsDlg", "Einstellungen", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NDSROsettingsDlg", "NDS ROM Directory", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("NDSROsettingsDlg", "NDSRO Data Directory", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("NDSROsettingsDlg", "NDS Memory Card", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NDSROsettingsDlg: public Ui_NDSROsettingsDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NDSROSETTINGSDLG_H
