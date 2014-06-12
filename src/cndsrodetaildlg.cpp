/***************************************************************************
 *   Copyright (C) 2013 by Christoph Gembalski   *
 *   christoph.gembalski@web.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                         *
 *   In addition, as a special exception, the copyright holders give       *
 *   permission to link the code of this program with any edition of       *
 *   the Qt library by Trolltech AS, Norway (or with modified versions     *
 *   of Qt that use the same license as Qt), and distribute linked         *
 *   combinations including the two.  You must obey the GNU General        *
 *   Public License in all respects for all of the code used other than    *
 *   Qt.  If you modify this file, you may extend this exception to        *
 *   your version of the file, but you are not obligated to do so.  If     *
 *   you do not wish to do so, delete this exception statement from        *
 *   your version.                                                         *
 ***************************************************************************/

#include "cndsrodetaildlg.h"
#include "NDSdebug.h"
#include <QMessageBox>
#include <QString>
#include <QImage>

/***************************************************************************
 * define
 ***************************************************************************/
#define MB	(1024*1024)

/***************************************************************************
 * CTor
 ***************************************************************************/
CNDSROdetailDlg::CNDSROdetailDlg(CNDSdbIfc * dbifc, QWidget* parent, Qt::WFlags fl)
: QDialog( parent, fl ), Ui::Dialog()
{
	this->m_InitDone = false;
	setupUi(this);

	this->m_DBIfc = dbifc;
	this->m_ROM = NULL;
	this->m_THUMBpos = 0;
	this->m_EnableSave = true;

	THUMBS->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	if (THUMBS->layout() != NULL)
	{
		delete THUMBS->layout();
	}
	m_THUMBgrid = new QGridLayout(THUMBS);

	// Create first THUMB to drop or load into
	this->CreateNextTHUMB();
	
	DBG("setupUi done.");
}

/***************************************************************************
 * DTor
 ***************************************************************************/
CNDSROdetailDlg::~CNDSROdetailDlg()
{
}

/***************************************************************************
 * 
 * PUBLIC
 * 
 ***************************************************************************/

/***************************************************************************
 * showROM
 ***************************************************************************/
void CNDSROdetailDlg::showROM(CNDSromData * rd, bool enableSave)
{
	if (rd == NULL)
		return;

	this->m_EnableSave = enableSave;
	if (checkIMGloading(rd))
	{
		this->m_DBIfc->readIMAGES(rd);
	}
	this->romDataToGui(rd);
	if (m_THUMBlist.size() != 0)
	{
		THUMB_clicked(m_THUMBlist.first());
	}

	DBG("isROM?" << rd->isROM);
	if (rd->isROM)
	{
		this->m_ROM = rd;
		this->exec();
		rd = this->m_ROM;
	}
	else
	{
		QMessageBox::information(
			this,
			"ROMinfo",
			QString("Kein Nintendo DS ROM."),
			QMessageBox::Ok,
			QMessageBox::Ok);
	}
	DBG("showROM done.");
}

/***************************************************************************
 * 
 * PROTECTED
 * 
 ***************************************************************************/

/***************************************************************************
 * event
 ***************************************************************************/
bool CNDSROdetailDlg::event(QEvent *event)
{
	int res;

	res = QWidget::event(event);

	if (event->type() == QEvent::Show)
	{
		if (!this->m_InitDone)
		{
			// Doing Init here 
			this->Init();
			return true;
		}
	}

	return (res);
}

/***************************************************************************
 * 
 * PRIVATE
 * 
 ***************************************************************************/

/***************************************************************************
 * Init
 ***************************************************************************/
void CNDSROdetailDlg::Init()
{
	connectActions();
	DBG("connect Actions done.");

	this->m_InitDone = true;
}

/***************************************************************************
 * connectActions
 ***************************************************************************/
void CNDSROdetailDlg::connectActions()
{
	connect(CMD, SIGNAL(clicked(QAbstractButton *)), this, SLOT(CMD_clicked(QAbstractButton *)));
	connect(CMD_THUMB_LEFT, SIGNAL(clicked()), this, SLOT(CMD_THUMB_LEFT_clicked()));
	connect(CMD_THUMB_RIGHT, SIGNAL(clicked()), this, SLOT(CMD_THUMB_RIGHT_clicked()));
	connect(CMDcode, SIGNAL(clicked()), this, SLOT(CMDcode_clicked()));
}

/***************************************************************************
 * romDataToGui
 ***************************************************************************/
void CNDSROdetailDlg::romDataToGui(CNDSromData * rd)
{
	QString	s;

	if (rd == NULL)
		return;

	if (!rd->isROM)
		return;

	// ID
	s.setNum(rd->ROMid);
	ROMid->setText(s);
	// Icon
	switch(rd->ROMstate)
	{
	case STATE_NONE: break;
	case STATE_NO_ROM: break;
	case STATE_CRC32:
	case STATE_ON_DEVICE:
	case STATE_FILE_STORED:
	case STATE_ONLY_DATA:
		{
			ROMicon->setPixmap(rd->getROMpixmap());
			break;
		}
	}
	// ROMdisplname
	ROMdisplname->setText(rd->ROMdisplname);
	// ROMname
	ROMname->setText(rd->ROMname);
	// ROMversion
	s.setNum(rd->ROMversion);
	ROMversion->setText(s);
	// ROMserial
	ROMserial->setText(rd->ROMserial);
	// ROMcode
	ROMcode->setText(rd->ROMcode);
	// ROMpublisher
	ROMpublisher->setText(rd->ROMpublisher);
	// ROMfilesize
	s.setNum(rd->ROMfilesize/(float)MB);
	s += " MB";
	ROMfilesize->setText(s);
	// ROMunitcode
	//ROMunitcode->setText(rd->ROMunitcode);
	// CRC32
	s.setNum(rd->ROMcrc32, 16);
	ROMcrc32->setText(s.toUpper().rightJustified(8, '0'));
	// ROMcapacity
	if (rd->ROMcapacity > 1000)
	{
		s.setNum(rd->ROMcapacity / 1024);
		s += " GBit";
	}
	else
	{
		s.setNum(rd->ROMcapacity);
		s += " MBit";
	}
	ROMcapacity->setText(s);

	// ROMcomment
	ROMcomment->setPlainText(rd->ROMcomment);

	// Languagaes
	JPNname->setText(rd->ROMlanguage[JPN].Name);
	JPNsubname->setText(rd->ROMlanguage[JPN].SubName);
	JPNpublisher->setText(rd->ROMlanguage[JPN].Publisher);
	ENGname->setText(rd->ROMlanguage[ENG].Name);
	ENGsubname->setText(rd->ROMlanguage[ENG].SubName);
	ENGpublisher->setText(rd->ROMlanguage[ENG].Publisher);
	FRNname->setText(rd->ROMlanguage[FRN].Name);
	FRNsubname->setText(rd->ROMlanguage[FRN].SubName);
	FRNpublisher->setText(rd->ROMlanguage[FRN].Publisher);
	GERname->setText(rd->ROMlanguage[GER].Name);
	GERsubname->setText(rd->ROMlanguage[GER].SubName);
	GERpublisher->setText(rd->ROMlanguage[GER].Publisher);
	ITLname->setText(rd->ROMlanguage[ITL].Name);
	ITLsubname->setText(rd->ROMlanguage[ITL].SubName);
	ITLpublisher->setText(rd->ROMlanguage[ITL].Publisher);
	SPNname->setText(rd->ROMlanguage[SPN].Name);
	SPNsubname->setText(rd->ROMlanguage[SPN].SubName);
	SPNpublisher->setText(rd->ROMlanguage[SPN].Publisher);
	if (rd->ROMversion > 1)
	{
		CHIname->setText(rd->ROMlanguage[CHI].Name);
		CHIsubname->setText(rd->ROMlanguage[CHI].SubName);
		CHIpublisher->setText(rd->ROMlanguage[CHI].Publisher);
	}

	// ROMImages
	foreach(SNDSromPicture pic, rd->ROMpicList)
	{
		DBG("No:" << pic.No);
		m_THUMBlist.last()->setPixmapEx(pic.ROMpixmap);
	}
}

/***************************************************************************
 * romDataFromGui
 ***************************************************************************/
void CNDSROdetailDlg::romDataFromGui(CNDSromData * rd)
{
	int	imgno;
	bool	bSaveROM;
	bool	bSaveIMG;

	bSaveROM = false;
	bSaveIMG = false;

	// ROMdisplname
	if (rd->ROMdisplname.compare(ROMdisplname->text(), Qt::CaseSensitive) != 0)
	{
		DBG("ROMdisplname changed.");
		rd->ROMdisplname = ROMdisplname->text();
		bSaveROM = true;
	}
	// ROMcomment
	if (rd->ROMcomment.compare(ROMcomment->toPlainText(), Qt::CaseSensitive) != 0)
	{
		DBG("ROMcomment changed.");
		rd->ROMcomment = ROMcomment->toPlainText();
		bSaveROM = true;
	}
	// ROMpublisher
	if (rd->ROMpublisher.compare(ROMpublisher->text(), Qt::CaseSensitive) != 0)
	{
		DBG("ROMpublisher changed.");
		rd->ROMpublisher = ROMpublisher->text();
		bSaveROM = true;
	}
	// ROMimages
	imgno = 0;
	DBG("clear ROMpicList.");
	rd->ROMpicList.clear();
	DBG("Check images.");
	foreach(QClickableLabel * lbl, this->m_THUMBlist)
	{
		if (lbl->pixmap() != NULL)
		{
			SNDSromPicture	rp;
	
			rp.ROMcode = rd->ROMcode;
			rp.No = imgno;
			rp.ROMpixmap = *lbl->pixmap();
			rd->ROMpicList.append(rp);
			imgno++;
			bSaveIMG = true;
		}
	}
	DBG("Check images done.");

	// Save enabled?
	if (this->m_EnableSave)
	{
		// save ROM
		if (bSaveROM)
		{
			DBG("Save ROM data");
			bSaveROM = this->m_DBIfc->updateROM(rd);
			DBG("bSaveROM=" << bSaveROM);
		}
		// save IMAGES
		if (bSaveIMG)
		{
			DBG("Save IMG data");
			bSaveIMG = this->m_DBIfc->writeIMAGES(rd);
			DBG("bSaveIMG=" << bSaveIMG);
		}
	}
}

/***************************************************************************
 * showIMG
 ***************************************************************************/
void CNDSROdetailDlg::showIMG(const QPixmap * pixmap)
{
	QLabel *	IMG;

	if (pixmap == NULL)
		return;

	IMG = (QLabel *)IMGscrollArea->takeWidget();
	if (IMG != NULL)
	{
		delete IMG;
		IMG = NULL;
	}
	IMG = new QLabel();
	IMG->setBackgroundRole(QPalette::Base);
	IMG->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	IMG->setScaledContents(true);
	IMG->setPixmap(*pixmap);
	IMG->resize(pixmap->width(), pixmap->height());
	IMGscrollArea->setWidget(IMG);
}

/***************************************************************************
 * showIMG
 ***************************************************************************/
void CNDSROdetailDlg::showIMG(const QImage * tmpIMG)
{
	QPixmap	pixmap;

	pixmap = QPixmap::fromImage(*tmpIMG);

	showIMG(&pixmap);
}

/***************************************************************************
 * checkIMGloading
 ***************************************************************************/
bool CNDSROdetailDlg::checkIMGloading(CNDSromData * rd)
{
	QList<SNDSromPicture>	refList;
	int			i;

	if (rd == NULL)
		return (false);

	// List empty?
	DBG("check list empty.");
	if (rd->ROMpicList.size() == 0)
		return (true);

	// We have a List need List from DB
	DBG("read ref list");
	if (!this->m_DBIfc->readIMAGES(rd, &refList))
		return (true);

	// Compare Lists
	DBG("compare list size rd[" << rd->ROMpicList.size() << "] ref[" << refList.size() << "]");
	if (rd->ROMpicList.size() != refList.size())
		return (true);

	DBG("compare list crc32");
	for (i=0; i<rd->ROMpicList.size(); i++)
	{
		// check crc
		if (rd->ROMpicList.at(i).crc32 != refList.at(i).crc32)
			return (true);
	}

	DBG("old Image cache valid.");
	return (false);
}

/***************************************************************************
 * 
 * SLOTS
 * 
 ***************************************************************************/

/***************************************************************************
 * THUMBfront_clicked
 ***************************************************************************/
void CNDSROdetailDlg::THUMB_clicked(QClickableLabel * item)
{
	showIMG(item->pixmap());
}

/***************************************************************************
 * CMD_clicked
 ***************************************************************************/
void CNDSROdetailDlg::CMD_clicked (QAbstractButton * button)
{
	if (button != NULL)
	{
		switch(CMD->standardButton(button))
		{
		case QDialogButtonBox::Ok:
		{
			this->close();
			break;
		}
		case QDialogButtonBox::Save:
		{
			this->romDataFromGui(this->m_ROM);
			this->close();
			break;
		}
		default: break;
		}
	}
}

/***************************************************************************
 * CreateNextTHUMB
 ***************************************************************************/
void CNDSROdetailDlg::CreateNextTHUMB()
{
	QClickableLabel *	tmpTHUMB;

	DBG("CreateNextTHUMB");
	// Create Labe to drop into
	tmpTHUMB = new QClickableLabel("", THUMBS);
	DBG("X=" << ((this->m_THUMBlist.size() * 10) + (this->m_THUMBlist.size() * 64) + 10));
	tmpTHUMB->createIMAGE((QPixmap *)NULL, ((m_THUMBlist.size() * 10) + (m_THUMBlist.size() * 64) + 10), 0);
	connect(tmpTHUMB, SIGNAL(pixmapset()), this, SLOT(CreateNextTHUMB()));
	connect(tmpTHUMB, SIGNAL(clicked(QClickableLabel *)), this, SLOT(THUMB_clicked(QClickableLabel *)));
	tmpTHUMB->show();
	m_THUMBgrid->addWidget(tmpTHUMB, 0, m_THUMBlist.size());
	THUMBS->resize((((this->m_THUMBlist.size() + 1) * 10) + ((this->m_THUMBlist.size() + 1) * 64) + 10), 74);
	this->m_THUMBlist.append(tmpTHUMB);
}

/***************************************************************************
 * CMD_THUMB_LEFT_clicked
 ***************************************************************************/
void CNDSROdetailDlg::CMD_THUMB_LEFT_clicked()
{
	this->m_THUMBpos--;
	if (this->m_THUMBpos < 0)
		this->m_THUMBpos = 0;

	IMGthumbscrollArea->ensureWidgetVisible(m_THUMBlist.at(this->m_THUMBpos),10 , 0);
}

/***************************************************************************
 * CMD_THUMB_RIGHT_clicked
 ***************************************************************************/
void CNDSROdetailDlg::CMD_THUMB_RIGHT_clicked()
{
	uint	rPos;

	rPos = (IMGthumbscrollArea->width() - 10) / 74;
	rPos += this->m_THUMBpos;

	if (rPos >= (uint)m_THUMBlist.size())
	{
		rPos = m_THUMBlist.size();
		this->m_THUMBpos = rPos - ((IMGthumbscrollArea->width() - 10) / 74);
	}
	else
	{
		this->m_THUMBpos++;
		if (this->m_THUMBpos > m_THUMBlist.size())
			this->m_THUMBpos = m_THUMBlist.size();
	}

	IMGthumbscrollArea->ensureWidgetVisible(m_THUMBlist.at(rPos),10 , 0);
}

/***************************************************************************
 * CMDcode_clicked
 ***************************************************************************/
void CNDSROdetailDlg::CMDcode_clicked()
{
	QString	publisher;

	publisher = m_ROM->ROMlanguage[languageTABS->currentIndex()].Publisher;
	this->ROMpublisher->setText(publisher);

	// Update Publisher DB
	this->m_DBIfc->updateVendor(
		m_ROM->ROMcode.left(1).data()->unicode(),
		m_ROM->ROMcode.right(1).data()->unicode(),
		publisher);
}

/***************************************************************************
 * 
 ***************************************************************************/
