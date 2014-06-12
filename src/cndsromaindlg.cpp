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


#include "cndsromaindlg.h"
#include "NDSdebug.h"
#include "NDSROversion.h"
#include "cndsrosettingsdlg.h"
#include "cndsrodetaildlg.h"
#include "NDSROconfig.h"
#include <QFileDialog>
#include <QStringList>
#include <QMessageBox>
#include "lz4.h"

/***************************************************************************
 * CTor
 ***************************************************************************/
CNDSROmainDlg::CNDSROmainDlg(QWidget* parent, Qt::WFlags fl)
: QMainWindow( parent, fl ), Ui::MainWindow()
{
	this->m_InitDone = false;
	setupUi(this);

	// Now for V1 disable some Elements
	if ((NDSRO_VERSION_MAJOR == 1) & (NDSRO_VERSION_MINOR == 0))
	{
		functionTabs->removeTab(3);
		functionTabs->removeTab(2);
		//tabFAVORITES->setVisible(false);
		//tabTOOLS->setVisible(false);
		actionFAVORITES->setVisible(false);
		actionTOOLS->setVisible(false);
		actionImportROMDataListe->setVisible(false);
		actionImportROMCodeListe->setVisible(false);
		actionExportROMDataListe->setVisible(false);
		actionExportROMCodeListe->setVisible(false);
	}

	DBG("setupUi done.");
}

/***************************************************************************
 * DTor
 ***************************************************************************/
CNDSROmainDlg::~CNDSROmainDlg()
{
	if (m_ROMscanner != NULL)
	{
		delete m_ROMscanner;
		m_ROMscanner = NULL;
	}

	if (m_ROMtransfer != NULL)
	{
		delete m_ROMtransfer;
		m_ROMtransfer = NULL;
	}

	if (m_DBIfc != NULL)
	{
		// CLOSE META + DATA DB
		m_DBIfc->Close(DB_META);
		m_DBIfc->Close(DB_DATA);
		m_DBIfc->Close(DB_IMG);
		delete m_DBIfc;
		m_DBIfc = NULL;
	}
}

/***************************************************************************
 * 
 * PROTECTED
 * 
 ***************************************************************************/

/***************************************************************************
 * event
 ***************************************************************************/
bool CNDSROmainDlg::event(QEvent *event)
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
void CNDSROmainDlg::Init()
{
	bool	res;

	this->m_ACTIVEList = &this->m_ROMList;

	// Create ROM Scanner
	m_ROMscanner = new CNDSromScanner();
	m_ROMscanner->NameLanguage = this->getNameChecked();
	DBG("ROM Scanner created.");

	// Create DBIfc
	m_DBIfc = new CNDSdbIfc();
	m_DBIfc->setWorkDir(NDSROconfig->NDSRO_DATA_dir);
	DBG("DBIfc created.");

	// Open META + DATA DB
	res = m_DBIfc->Open(DB_META);
	DBG("DB_META:" << res);
	res = m_DBIfc->Open(DB_DATA);
	DBG("DB_DATA:" << res);
	res = m_DBIfc->Open(DB_IMG);
	DBG("DB_IMG:" << res);

	// Create ROM Transfer
	m_ROMtransfer = new CNDStransfer(this->m_DBIfc);
	DBG("ROM Transfer created.");

	// Load Import Dirs
	this->loadDirectories();
	// Load ROM List
	this->reloadROMList();
	DBG("Loading Data done.");

	connectActions();
	DBG("connect Actions done.");

	this->m_DEVICEscanned = false;
	this->m_DEVICEsubdir = "";
	this->m_DEVICEisClick = false;

	// Disable elements
	ROMStools_romlist->setDisabled(true);
	ROMStools_scanlist->setDisabled(true);
	ROMStools_scanclear->setDisabled(true);

	Status("(C)2014 by IT-Solutions", 2000);

	this->m_InitDone = true;
}

/***************************************************************************
 * connectActions
 ***************************************************************************/
void CNDSROmainDlg::connectActions()
{
	// menuFile
	connect(actionImportROMListe, SIGNAL(triggered()), this, SLOT(ImportROMListe()));
	connect(actionImportROMDataListe, SIGNAL(triggered()), this, SLOT(ImportROMDataListe()));
	connect(actionImportROMCodeListe, SIGNAL(triggered()), this, SLOT(ImportROMCodeListe()));
	connect(actionImportIMGListe, SIGNAL(triggered()), this, SLOT(ImportIMGListe()));
	connect(actionExportROMListe, SIGNAL(triggered()), this, SLOT(ExportROMListe()));
	connect(actionExportROMDataListe, SIGNAL(triggered()), this, SLOT(ExportROMDataListe()));
	connect(actionExportROMCodeListe, SIGNAL(triggered()), this, SLOT(ExportROMCodeListe()));
	connect(actionExportIMGListe, SIGNAL(triggered()), this, SLOT(ExportIMGListe()));
	connect(actionQuit, SIGNAL(triggered()), this, SLOT(CNDSROmainDlg_close()));
	// menuEdit
	connect(actionSettings, SIGNAL(triggered()), this, SLOT(EditSettings()));
	// menuView
	connect(actionROMS, SIGNAL(triggered()), this, SLOT(SelectTabROMS()));
	connect(actionDEVICE, SIGNAL(triggered()), this, SLOT(SelectTabDEVICE()));
	connect(actionFAVORITES, SIGNAL(triggered()), this, SLOT(SelectTabFAVORITES()));
	connect(actionTOOLS, SIGNAL(triggered()), this, SLOT(SelectTabTOOLS()));
	connect(actionDIRS, SIGNAL(triggered()), this, SLOT(SelectTabDIRS()));
	// menuView->Name
	connect(actionJPN, SIGNAL(triggered()), this, SLOT(SelectNameJPN()));
	connect(actionENG, SIGNAL(triggered()), this, SLOT(SelectNameENG()));
	connect(actionFRN, SIGNAL(triggered()), this, SLOT(SelectNameFRN()));
	connect(actionGER, SIGNAL(triggered()), this, SLOT(SelectNameGER()));
	connect(actionITL, SIGNAL(triggered()), this, SLOT(SelectNameITL()));
	connect(actionSPN, SIGNAL(triggered()), this, SLOT(SelectNameSPN()));
	connect(actionCHI, SIGNAL(triggered()), this, SLOT(SelectNameCHI()));
	// menuHelp
	connect(actionAbout, SIGNAL(triggered()), this, SLOT(CNDSROmainDlg_about()));
	connect(actionAboutOt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

	// Toolbars
	// ROMS
	connect(ROMStools_scan, SIGNAL(clicked()), this, SLOT(ROMStools_scan_click()));
	connect(ROMStools_romlist, SIGNAL(clicked()), this, SLOT(ROMStools_romlist_click()));
	connect(ROMStools_scanlist, SIGNAL(clicked()), this, SLOT(ROMStools_scanlist_click()));
	connect(ROMStools_scanclear, SIGNAL(clicked()), this, SLOT(ROMStools_scanclear_click()));
	connect(ROMStools_delete, SIGNAL(clicked()), this, SLOT(ROMStools_delete_click()));
	connect(ROMStools_copy, SIGNAL(clicked()), this, SLOT(ROMStools_copy_click()));
	// DEVICE
	connect(DEVICEtools_scan, SIGNAL(clicked()), this, SLOT(DEVICEtools_scan_click()));
	connect(DEVICEtools_remove, SIGNAL(clicked()), this, SLOT(DEVICEtools_remove_click()));
	// DIRS
	connect(DIRStools_add, SIGNAL(clicked()), this, SLOT(DIRStools_add_click()));
	connect(DIRStools_del, SIGNAL(clicked()), this, SLOT(DIRStools_del_click()));

	// Status for ROMscanner
	connect(m_ROMscanner, SIGNAL(StatusChanged(QString, uint)), this, SLOT(Status(QString, uint)));

	// Status for ROMtransfer
	connect(m_ROMtransfer, SIGNAL(Status(QString, uint)), this, SLOT(Status(QString, uint)));

	// ROMStable
	connect(ROMStable, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(ROMStable_cellDoubleClicked(int, int)));
	// DEVICEtable
	connect(DEVICEtable, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(DEVICEtable_cellDoubleClicked(int, int)));
}

/***************************************************************************
 * clearNameCheck
 ***************************************************************************/
void CNDSROmainDlg::clearNameCheck(ENDSromLanguage l)
{
	actionJPN->setChecked(l == JPN);
	actionENG->setChecked(l == ENG);
	actionFRN->setChecked(l == FRN);
	actionGER->setChecked(l == GER);
	actionITL->setChecked(l == ITL);
	actionSPN->setChecked(l == SPN);
	actionCHI->setChecked(l == CHI);

	// Set new Language
	m_ROMscanner->NameLanguage = l;
	// Update Lists
	m_ROMscanner->ListToTable(this->m_ACTIVEList, ROMStable);
}

/***************************************************************************
 * getNameChecked
 ***************************************************************************/
ENDSromLanguage CNDSROmainDlg::getNameChecked()
{
	if (actionJPN->isChecked())
		return (JPN);
	if (actionENG->isChecked())
		return (ENG);
	if (actionFRN->isChecked())
		return (FRN);
	if (actionGER->isChecked())
		return (GER);
	if (actionITL->isChecked())
		return (ITL);
	if (actionSPN->isChecked())
		return (SPN);
	if (actionCHI->isChecked())
		return (CHI);
	return (GER);
}

/***************************************************************************
 * loadDirectories
 ***************************************************************************/
void CNDSROmainDlg::loadDirectories()
{
	QStringList	list;
	int		i;

	if (m_DBIfc->readPathList(&list))
	{
		for (i = 0; i < list.size(); i++)
		{
			DBG("Path:" << list.at(i));			
			new QListWidgetItem(list.at(i), DIRSlist);
		}
	}
}

/***************************************************************************
 * saveDirectories
 ***************************************************************************/
void CNDSROmainDlg::saveDirectories()
{
	QStringList	list;
	int		i;

	for (i=0; i<DIRSlist->count(); i++)
	{
		list << DIRSlist->item(i)->text();
	}
	m_DBIfc->writePathList(&list);
}

/***************************************************************************
 * reloadROMList
 ***************************************************************************/
void CNDSROmainDlg::reloadROMList()
{
	m_ROMList.clear();
	Status("ROMs einlesen.", 2000);
	if (m_DBIfc->readROMS(&m_ROMList))
	{
		// Put into View
		m_ROMscanner->ListToTable(this->m_ACTIVEList, ROMStable);
	}
	Status("ROMs eingelesen.", 2000);
}

/***************************************************************************
 * getROMbyID
 ***************************************************************************/
CNDSromData CNDSROmainDlg::getROMbyID(QList<CNDSromData> * lst, uint id)
{
	CNDSromData	res;

	if (lst == NULL)
		return (res);

	DBG("Search ID:" << id);
	foreach(CNDSromData rd, *lst)
	{
		if (rd.ROMid == id)
		{
			DBG("Found ID:" << rd.ROMid);
			return (rd);
		}
	}
	return (res);
}

/***************************************************************************
 * updateROMList
 ***************************************************************************/
void CNDSROmainDlg::updateROMList(QList<CNDSromData> * lst, CNDSromData * rd)
{
	int	idx;
	int	i;

	if (lst == NULL)
		return;
	if (rd == NULL)
		return;

	DBG("Search ID:" << rd->ROMid);
	idx = -1;
	for(i = 0; i < lst->size(); i++)
	{
		if (lst->at(i).ROMid == rd->ROMid)
		{
			idx = i;
			break;
		}
	}
	if (idx != -1)
	{
		lst->replace(idx, *rd);
	}
}

/***************************************************************************
 * copyROMtoStorage
 ***************************************************************************/
bool CNDSROmainDlg::copyROMtoStorage(CNDSromData * rd)
{
	QString		srcPathName;
	QString		dstPathName;
	QString		s;
	uint		prefix;
	QByteArray	bArray;
	char *		outBuff;
	int		outSize;
	int		orgSize;
	QFile *		f;

	if (rd == NULL)
		return (false);

	// Build srcPathName
	srcPathName = rd->ROMpath + QDir::separator() + rd->ROMfilename;
	DBG("srcPathName:" << srcPathName);
	// Build dstPathName
	prefix = (rd->ROMcrc32 & 0xFF000000) >> 24;
	s.setNum(prefix, 16);
	dstPathName = NDSROconfig->NDS_ROM_dir + QDir::separator() + s.toUpper().rightJustified(2, '0');
	// Dir exist ?
	if (!QDir(dstPathName).exists())
	{
		DBG("mkpath:" << dstPathName);
		QDir().mkpath(dstPathName);
	}
	s.setNum(rd->ROMcrc32, 16);
	dstPathName += QDir::separator() + s.toUpper().rightJustified(8, '0');
	DBG("dstPathName:" << dstPathName);
	
	DBG(srcPathName << " -> " << dstPathName);

	Status("read  " + rd->ROMfilename);
	// Read all
	f = new QFile(srcPathName);
	if (!f->open(QIODevice::ReadOnly))
	{
		delete f;
		return (false);
	}
	bArray = f->readAll();
	f->close();
	delete f;
	if (bArray.size() == 0)
		return (false);

	// Get output Mem 
	outBuff = new char[LZ4_compressBound(bArray.size())];
	
	Status("pack  " + rd->ROMfilename);
	// Compress
	outSize = LZ4_compress(bArray.constData(), outBuff, bArray.size());
	if (outSize == 0)
	{
		delete [] outBuff;
		return (false);
	}
	
	// Write all
	Status("write " + rd->ROMfilename);
	f = new QFile(dstPathName);
	if (!f->open(QIODevice::WriteOnly))
	{
		delete [] outBuff;
		return (false);
	}
	// Write Header
	f->write(STORAGE_HEADER, sizeof(STORAGE_HEADER));
	// Write size
	orgSize = bArray.size();
	f->write((const char *)&orgSize, sizeof(int));
	// Write Data
	f->write(outBuff, outSize);
	f->close();
	delete f;

	delete [] outBuff;
	return (true);
	// Now only copy file ... later we crunch it
	//return (QFile(srcPathName).copy(dstPathName));
}

/***************************************************************************
 * copyROMtoFilesystem
 ***************************************************************************/
bool CNDSROmainDlg::copyROMtoFilesystem(CNDSromData * rd, QString fpath)
{
	QString		srcPathName;
	QString		dstPathName;
	QString		s;
	uint		prefix;
	QFile *		f;
	QByteArray	bArray;
	int		outSize;
	char *		outBuff;
	int		outSizeDecomp;
	char		bHeader[sizeof(STORAGE_HEADER)];

	if (rd == NULL)
		return (false);

	// Check state first
	if (rd->ROMstate != STATE_FILE_STORED)
		return (false);

	// Build srcPathName
	prefix = (rd->ROMcrc32 & 0xFF000000) >> 24;
	s.setNum(prefix, 16);
	srcPathName = NDSROconfig->NDS_ROM_dir + QDir::separator() + s.toUpper().rightJustified(2, '0');
	s.setNum(rd->ROMcrc32, 16);
	srcPathName += QDir::separator() + s.toUpper().rightJustified(8, '0');
	DBG("srcPathName:" << srcPathName);
	// Build dstPathName
	dstPathName = fpath;
	if (!QDir(dstPathName).exists())
	{
		DBG("mkpath:" << dstPathName);
		QDir().mkpath(dstPathName);
	}
	if (!dstPathName.endsWith(QDir::separator()))
	{
		dstPathName += QDir::separator();
	}
	dstPathName += this->m_ROMscanner->POSIXfilename(rd->ROMdisplname) + ".nds";
	DBG("dstPathName:" << dstPathName);
	
	DBG(srcPathName << " -> " << dstPathName);

	Status("read   " + rd->ROMname);
	// Read all
	f = new QFile(srcPathName);
	if (!f->open(QIODevice::ReadOnly))
	{
		delete f;
		return (false);
	}
	// Read Header
	f->read(bHeader, sizeof(STORAGE_HEADER));
	if (memcmp(bHeader, STORAGE_HEADER, sizeof(STORAGE_HEADER)) != 0)
	{
		DBG("file invalid");
		f->close();
		delete f;
		return (false);
	}
	// Read size
	f->read((char *)&outSize, sizeof(int));
	DBG("size:" << outSize);
	// Read Data
	bArray = f->readAll();
	f->close();
	delete f;
	if (bArray.size() == 0)
		return (false);

	DBG("read size:" << bArray.size());

	// Get output Mem 
	outBuff = new char[outSize];
	memset(outBuff, 0, outSize);

	Status("unpack " + rd->ROMname);
	// Decompress
	outSizeDecomp = LZ4_decompress_safe (bArray.constData(), outBuff, bArray.size(), outSize);
	if (outSize != outSizeDecomp)
	{
		delete [] outBuff;
		return (false);
	}

	// Write all
	Status("write " + rd->ROMname);
	f = new QFile(dstPathName);
	if (!f->open(QIODevice::WriteOnly))
	{
		delete [] outBuff;
		return (false);
	}
	// Write Data
	f->write(outBuff, outSize);
	f->close();
	delete f;

	delete [] outBuff;
	return (true);
}

/***************************************************************************
 * 
 ***************************************************************************/

/***************************************************************************
 * 
 * SLOTS
 * 
 ***************************************************************************/

/***************************************************************************
 * ImportROMListe
 ***************************************************************************/
void CNDSROmainDlg::ImportROMListe()
{
	QFileDialog *	dlg;
	QStringList	lst;
	int		i;
	int		imp_count;
	uint		fail_count;

	fail_count = 0;

	dlg = new QFileDialog(this, tr("ROM Import Datei"));
	dlg->setAcceptMode(QFileDialog::AcceptOpen);
	dlg->setFileMode(QFileDialog::ExistingFile);

	if (dlg->exec())
	{
		lst = dlg->selectedFiles();
		for (i = 0; i < lst.size(); i++)
		{
			if (lst.at(i).isNull())
				continue;
			if (lst.at(i).isEmpty())
				continue;

			// Clear SCANList
			this->m_SCANList.clear();
			// Disable SCANList Button
			ROMStools_romlist->setDisabled(true);
			ROMStools_scanlist->setDisabled(true);
			ROMStools_scanclear->setDisabled(true);

			imp_count = this->m_ROMtransfer->importROMlist(lst.at(i),
				&this->m_ROMList,
				&fail_count,
				&this->m_SCANList);

			if (imp_count >= 0)
			{
				// Enable SCANList Button
				ROMStools_romlist->setDisabled(false);
				ROMStools_scanlist->setDisabled(false);
				ROMStools_scanclear->setDisabled(false);
				// Set Active to ROMS
				this->m_ACTIVEList = &this->m_ROMList;
				// Show List
				m_ROMscanner->ListToTable(this->m_ACTIVEList, ROMStable);

				QMessageBox::information(
					this,
					"ROM Export",
					QString("ROMs importiert\t: %1\nROMs ignoriert\t: %2").arg(imp_count).arg(fail_count),
					QMessageBox::Ok,
					QMessageBox::Ok);
			}
		}
	}

	delete dlg;
}

/***************************************************************************
 * ImportROMDataListe
 ***************************************************************************/
void CNDSROmainDlg::ImportROMDataListe()
{
}

/***************************************************************************
 * ImportROMCodeListe
 ***************************************************************************/
void CNDSROmainDlg::ImportROMCodeListe()
{
}

/***************************************************************************
 * ImportIMGListe
 ***************************************************************************/
void CNDSROmainDlg::ImportIMGListe()
{
	QFileDialog *	dlg;
	QStringList	lst;
	int		i;
	int		imp_count;
	uint		fail_count;

	fail_count = 0;

	dlg = new QFileDialog(this, tr("IMG Import Datei"));
	dlg->setAcceptMode(QFileDialog::AcceptOpen);
	dlg->setFileMode(QFileDialog::ExistingFile);

	if (dlg->exec())
	{
		lst = dlg->selectedFiles();
		for (i = 0; i < lst.size(); i++)
		{
			if (lst.at(i).isNull())
				continue;
			if (lst.at(i).isEmpty())
				continue;

			imp_count = this->m_ROMtransfer->importIMGlist(lst.at(i),
				&fail_count);

			if (imp_count >= 0)
			{
				QMessageBox::information(
					this,
					"ROM Export",
					QString("ROMs importiert\t: %1\nROMs ignoriert\t: %2").arg(imp_count).arg(fail_count),
					QMessageBox::Ok,
					QMessageBox::Ok);
			}
		}
	}

	delete dlg;
}

/***************************************************************************
 * ExportROMListe
 ***************************************************************************/
void CNDSROmainDlg::ExportROMListe()
{
	QFileDialog *	dlg;
	QStringList	lst;
	int		i;
	int		exp_count;

	dlg = new QFileDialog(this, tr("ROM Export Datei"));
	dlg->setAcceptMode(QFileDialog::AcceptSave);
	dlg->setFileMode(QFileDialog::AnyFile);

	if (dlg->exec())
	{
		lst = dlg->selectedFiles();
		for (i = 0; i < lst.size(); i++)
		{
			if (lst.at(i).isNull())
				continue;
			if (lst.at(i).isEmpty())
				continue;

			exp_count = this->m_ROMtransfer->exportROMlist(lst.at(i), this->m_ACTIVEList);

			if (exp_count >= 0)
			{
				QMessageBox::information(
					this,
					"ROM Export",
					QString("ROMs exportiert\t: %1").arg(exp_count),
					QMessageBox::Ok,
					QMessageBox::Ok);
			}
		}
	}

	delete dlg;
}

/***************************************************************************
 * ExportROMDataListe
 ***************************************************************************/
void CNDSROmainDlg::ExportROMDataListe()
{
}

/***************************************************************************
 * ExportROMCodeListe
 ***************************************************************************/
void CNDSROmainDlg::ExportROMCodeListe()
{
}

/***************************************************************************
 * ExportIMGListe
 ***************************************************************************/
void CNDSROmainDlg::ExportIMGListe()
{
	QFileDialog *	dlg;
	QStringList	lst;
	int		i;
	int		exp_count;

	dlg = new QFileDialog(this, tr("IMG Export Datei"));
	dlg->setAcceptMode(QFileDialog::AcceptSave);
	dlg->setFileMode(QFileDialog::AnyFile);

	if (dlg->exec())
	{
		lst = dlg->selectedFiles();
		for (i = 0; i < lst.size(); i++)
		{
			if (lst.at(i).isNull())
				continue;
			if (lst.at(i).isEmpty())
				continue;

			exp_count = this->m_ROMtransfer->exportIMGlist(lst.at(i));

			if (exp_count >= 0)
			{
				QMessageBox::information(
					this,
					"IMG Export",
					QString("IMGs exportiert\t: %1").arg(exp_count),
					QMessageBox::Ok,
					QMessageBox::Ok);
			}
		}
	}

	delete dlg;
}

/***************************************************************************
 * CNDSROmainDlg_close
 ***************************************************************************/
void CNDSROmainDlg::CNDSROmainDlg_close()
{
	// TODO : Check state
	this->close();
}

/***************************************************************************
 * EditSettings
 ***************************************************************************/
void CNDSROmainDlg::EditSettings()
{
	CndsroSettingsDlg * dlg;
	dlg = new CndsroSettingsDlg(this, 0);
	dlg->show();
}

/***************************************************************************
 * SelectTabROMS
 ***************************************************************************/
void CNDSROmainDlg::SelectTabROMS()
{
	functionTabs->setCurrentWidget(tabROMS);
}

/***************************************************************************
 * SelectTabDEVICE
 ***************************************************************************/
void CNDSROmainDlg::SelectTabDEVICE()
{
	functionTabs->setCurrentWidget(tabDEVICE);
}

/***************************************************************************
 * SelectTabFAVORITES
 ***************************************************************************/
void CNDSROmainDlg::SelectTabFAVORITES()
{
	functionTabs->setCurrentWidget(tabFAVORITES);
}

/***************************************************************************
 * SelectTabTOOLS
 ***************************************************************************/
void CNDSROmainDlg::SelectTabTOOLS()
{
	functionTabs->setCurrentWidget(tabTOOLS);
}

/***************************************************************************
 * SelectTabDIRS
 ***************************************************************************/
void CNDSROmainDlg::SelectTabDIRS()
{
	functionTabs->setCurrentWidget(tabDIRS);
}

/***************************************************************************
 * CNDSROmainDlg_about
 ***************************************************************************/
void CNDSROmainDlg::CNDSROmainDlg_about()
{
}

/***************************************************************************
 * SelectNameJPN
 ***************************************************************************/
void CNDSROmainDlg::SelectNameJPN()
{
	clearNameCheck(JPN);
}

/***************************************************************************
 * SelectNameENG
 ***************************************************************************/
void CNDSROmainDlg::SelectNameENG()
{
	clearNameCheck(ENG);
}

/***************************************************************************
 * SelectNameFRN
 ***************************************************************************/
void CNDSROmainDlg::SelectNameFRN()
{
	clearNameCheck(FRN);
}

/***************************************************************************
 * SelectNameGER
 ***************************************************************************/
void CNDSROmainDlg::SelectNameGER()
{
	clearNameCheck(GER);
}

/***************************************************************************
 * SelectNameITL
 ***************************************************************************/
void CNDSROmainDlg::SelectNameITL()
{
	clearNameCheck(ITL);
}

/***************************************************************************
 * SelectNameSPN
 ***************************************************************************/
void CNDSROmainDlg::SelectNameSPN()
{
	clearNameCheck(SPN);
}

/***************************************************************************
 * SelectNameCHI
 ***************************************************************************/
void CNDSROmainDlg::SelectNameCHI()
{
	clearNameCheck(CHI);
}

/***************************************************************************
 * 
 ***************************************************************************/

/***************************************************************************
 * ROMStools_scan_click
 ***************************************************************************/
void CNDSROmainDlg::ROMStools_scan_click()
{
	QStringList		lst;
	int			i;
	QList<CNDSromData>	romlst;
	int			rno;
	int			roms_found;
	int			roms_added;
	int			roms_ignored;
	int			scan_no;

	roms_found = 0;
	roms_added = 0;
	roms_ignored = 0;
	scan_no = 0;

	// Have Dirs?
	if (DIRSlist->count() == 0)
	{
		statusbar->showMessage(tr("Keine Verzeichnisse vorhanden."), 2000);
		return;
	}

	Status("ROM Scan starten.", 2000);

	if (QMessageBox::question(
		this,
		"ROM Scan",
		"ROM Scan starten?",
		QMessageBox::Yes | QMessageBox::No,
		QMessageBox::No) == QMessageBox::No)
	{
		return;
	}

	this->m_SCANList.clear();

	// Get dirs to Scan
	for (i=0; i<DIRSlist->count(); i++)
	{
		lst << DIRSlist->item(i)->text();
	}
	// Scan each dir and show results
	for (i = 0; i < lst.size(); i++)
	{
		DBG("Scanpath:" << lst.at(i));
		romlst = m_ROMscanner->ScanDir(lst.at(i), m_DBIfc);

		Status("Daten abgleichen.", 2000);
		// Check if ROM exist and insert
		for (rno=0; rno<romlst.size(); rno++)
		{
			CNDSromData	rd;

			rd = romlst.at(rno);
			if (!rd.isROM)
			{
				scan_no++;
				rd.ROMid = -scan_no;
				rd.ROMstate = STATE_NO_ROM;
				m_SCANList << rd;
				continue;
			}

			roms_found++;

			if (!m_DBIfc->existROM(&rd))
			{
				if (this->copyROMtoStorage(&rd))
				{
					rd.ROMstate = STATE_FILE_STORED;
				}
				else
				{
					rd.ROMstate = STATE_ONLY_DATA;
				}
				roms_added++;
				m_DBIfc->writeROM(&rd);
			}
			else
			{
				ENDSromState	rdState;
				// Check if ROM File exist
				rdState = this->m_DBIfc->getROMstate(&rd);
				if (rdState == STATE_ONLY_DATA)
				{
					// Add File
					if (this->copyROMtoStorage(&rd))
					{
						rd.ROMstate = STATE_FILE_STORED;
						roms_added++;
						m_DBIfc->writeROM(&rd);
					}
					else
					{
						scan_no++;
						rd.ROMid = -scan_no;
						rd.ROMstate = STATE_CRC32;
						roms_ignored++;
						m_SCANList << rd;
					}
				}
				else
				{
					scan_no++;
					rd.ROMid = -scan_no;
					rd.ROMstate = STATE_CRC32;
					roms_ignored++;
					m_SCANList << rd;
				}
			}
		}
	}

	Status("ROM Scan beendet.", 2000);

	this->reloadROMList();

	QMessageBox::information(
		this,
		"ROM Scan",
		QString("ROMs gefunden\t: %1\nROMs neu\t\t: %2\nROMs ignoriert\t: %3").arg(roms_found).arg(roms_added).arg(roms_ignored),
		QMessageBox::Ok,
		QMessageBox::Ok);

	// Enable SCANList Button
	ROMStools_romlist->setDisabled(false);
	ROMStools_scanlist->setDisabled(false);
	ROMStools_scanclear->setDisabled(false);
}

/***************************************************************************
 * ROMStools_romlist_click
 ***************************************************************************/
void CNDSROmainDlg::ROMStools_romlist_click()
{
	this->m_ACTIVEList = &this->m_ROMList;
	m_ROMscanner->ListToTable(this->m_ACTIVEList, ROMStable);
}

/***************************************************************************
 * ROMStools_scanlist_click
 ***************************************************************************/
void CNDSROmainDlg::ROMStools_scanlist_click()
{
	this->m_ACTIVEList = &this->m_SCANList;
	m_ROMscanner->ListToTable(this->m_ACTIVEList, ROMStable);
}

/***************************************************************************
 * ROMStools_scanclear_click
 ***************************************************************************/
void CNDSROmainDlg::ROMStools_scanclear_click()
{
	this->m_ACTIVEList = &this->m_ROMList;
	m_ROMscanner->ListToTable(this->m_ACTIVEList, ROMStable);
	this->m_SCANList.clear();
	ROMStools_romlist->setDisabled(true);
	ROMStools_scanlist->setDisabled(true);
	ROMStools_scanclear->setDisabled(true);
}

/***************************************************************************
 * ROMStools_delete_click
 ***************************************************************************/
void CNDSROmainDlg::ROMStools_delete_click()
{
}

/***************************************************************************
 * ROMStools_copy_click
 ***************************************************************************/
void CNDSROmainDlg::ROMStools_copy_click()
{
	int			cpyCount;
	int			cpyFailed;
	QList<CNDSromData>	cpyList;

	// List Empty?
	if (this->m_ROMList.size() == 0)
	{
		Status("ROM Liste leer.", 2000);
		return;
	}
	
	// Check if any selected
	if (this->ROMStable->selectedItems().size() == 0)
	{
		Status("Keine Einträge gewählt.", 2000);
		return;
	}
	
	if (!this->m_DEVICEscanned)
	{
		functionTabs->setCurrentWidget(tabDEVICE);
		this->DEVICEtools_scan_click();
		functionTabs->setCurrentWidget(tabROMS);
	}
	
	if (!this->m_DEVICEscanned)
	{
		return;
	}

	// Create copy List
	DBG("itm count:" << this->ROMStable->selectedItems().size());
	foreach (QTableWidgetItem * itm, this->ROMStable->selectedItems())
	{
		DBG(" -> " << itm->text());
		if (itm->column() == 0)
		{
			uint	ID;

			// ID item
			ID = itm->text().toUInt();
			cpyList << this->getROMbyID(&this->m_ROMList, ID);
		}
	}

	DBG("itm count:" << cpyList.size());

	// Do copy ....
	cpyCount = 0;
	cpyFailed = 0;
	foreach(CNDSromData rd, cpyList)
	{
		if (this->copyROMtoFilesystem(&rd, NDSROconfig->NDS_MEM_CARD_dir + this->m_DEVICEsubdir))
		{
			cpyCount++;
		}
		else
		{
			cpyFailed++;
		}
	}
	
	QMessageBox::information(
		this,
		"ROM Scan",
		QString("ROMs kopiert\t: %1\nROMs ignoriert\t: %2").arg(cpyCount).arg(cpyFailed),
		QMessageBox::Ok,
		QMessageBox::Ok);

	functionTabs->setCurrentWidget(tabDEVICE);
	this->m_DEVICEisClick = true;
	this->DEVICEtools_scan_click();
	this->m_DEVICEisClick = false;
	functionTabs->setCurrentWidget(tabROMS);
}

/***************************************************************************
 * DEVICEtools_scan_click
 ***************************************************************************/
void CNDSROmainDlg::DEVICEtools_scan_click()
{
	QList<CNDSromData>	scnList;
	int			rID;
	int			dID;

	rID = 0;
	dID = 0;

	Status("DEVICE Scan starten.", 2000);

	if (!this->m_DEVICEisClick)
	{
		// Ask scan Device?
		if (QMessageBox::question(
			this,
			"DEVICE Scan",
			"DEVICE Scan starten?",
			QMessageBox::Yes | QMessageBox::No,
			QMessageBox::No) == QMessageBox::No)
		{
			return;
		}
	}

	this->m_DEVICEscanned = false;
	this->m_DEVICEList.clear();
	DBG("scan:" << NDSROconfig->NDS_MEM_CARD_dir + this->m_DEVICEsubdir);
	scnList = m_ROMscanner->ScanDir(NDSROconfig->NDS_MEM_CARD_dir + this->m_DEVICEsubdir, m_DBIfc, true);

	if (this->m_DEVICEsubdir != "")
	{
		CNDSromData	rd;

		// Add Up Entry
		rd.ROMstate = STATE_DIRECTORY;
		rd.ROMname = "..";
		dID++;
		rd.ROMid = -dID;
		this->m_DEVICEList << rd;
	}

	// Now Build real List
	foreach (CNDSromData rd, scnList)
	{
		// Dir?
		if (rd.ROMstate == STATE_DIRECTORY)
		{
			dID++;
			rd.ROMid = -dID;
			this->m_DEVICEList << rd;
		}

		// ROM ?
		if (rd.isROM)
		{
			rID++;
			rd.ROMid = rID;
			rd.ROMstate = STATE_ON_DEVICE;
			this->m_DEVICEList << rd;
		}
	}

	this->m_DEVICEscanned = true;

	// Show List
	m_ROMscanner->ListToTable(&this->m_DEVICEList, DEVICEtable);

	Status("DEVICE Scan beendet.", 2000);
}

/***************************************************************************
 * DEVICEtools_remove_click
 ***************************************************************************/
void CNDSROmainDlg::DEVICEtools_remove_click()
{
	int			addCount;
	int			delCount;
	int			delFailed;
	QList<CNDSromData>	delList;

	// List Empty?
	if (this->m_DEVICEList.size() == 0)
	{
		Status("DEVICE Liste leer.", 2000);
		return;
	}
	
	// Check if any selected
	if (this->DEVICEtable->selectedItems().size() == 0)
	{
		Status("Keine Einträge gewählt.", 2000);
		return;
	}

	// Ask scan Device?
	if (QMessageBox::question(
		this,
		"DEVICE",
		"ROMS löschen?",
		QMessageBox::Yes | QMessageBox::No,
		QMessageBox::No) == QMessageBox::No)
	{
		return;
	}

	// Lösch Liste erstellen
	DBG("itm count:" << this->DEVICEtable->selectedItems().size());
	foreach (QTableWidgetItem * itm, this->DEVICEtable->selectedItems())
	{
		DBG(" -> " << itm->text());
		if (itm->column() == 0)
		{
			uint	ID;

			// ID item
			ID = itm->text().toUInt();
			delList << this->getROMbyID(&this->m_DEVICEList, ID);
		}
	}

	DBG("itm count:" << delList.size());

	// Do delete ....
	addCount = 0;
	delCount = 0;
	delFailed = 0;
	foreach(CNDSromData rd, delList)
	{
		if (rd.isROM)
		{
			// Check if in Archive, if not copy first
			if (!m_DBIfc->existROM(&rd))
			{
				Status("Nicht im Archiv : " + rd.ROMname);
				delFailed++;
			}
			else
			{
				if (this->m_DBIfc->getROMstate(&rd) == STATE_ONLY_DATA)
				{
					Status("Nicht im Archiv : " + rd.ROMname);
					delFailed++;
				}
				else
				{
					// Delete
					if (QFile::remove(NDSROconfig->NDS_MEM_CARD_dir + this->m_DEVICEsubdir + QDir::separator() + rd.ROMfilename))
					{
						Status("Gelöscht : " + rd.ROMname);
						delCount++;
					}
					else
					{
						Status("Nicht gelöscht : " + rd.ROMname);
						delFailed++;
					}
				}
			}
		}
		if (rd.ROMstate == STATE_DIRECTORY)
		{
			QDir d(NDSROconfig->NDS_MEM_CARD_dir + this->m_DEVICEsubdir);
			if (d.rmdir(rd.ROMname))
			{
				Status("delete " + rd.ROMname);
				delCount++;
			}
			else
			{
				Status("Ornder nicht leer : " + rd.ROMname);
				delFailed++;
			}
		}
	}
	
	QMessageBox::information(
		this,
		"DEVICE",
		QString("ROMs gelöscht\t: %1\nROMs ignoriert\t: %2\nROMs importiert\t: %3").arg(delCount).arg(delFailed).arg(addCount),
		QMessageBox::Ok,
		QMessageBox::Ok);

	this->m_DEVICEisClick = true;
	this->DEVICEtools_scan_click();
	this->m_DEVICEisClick = false;
}

/***************************************************************************
 * 
 ***************************************************************************/

/***************************************************************************
 * DIRStools_add_click
 ***************************************************************************/
void CNDSROmainDlg::DIRStools_add_click()
{
	QFileDialog *	dlg;
	QStringList	lst;
	int		i;

	dlg = new QFileDialog(this, tr("Verzeichnis wählen."));

	dlg->setAcceptMode(QFileDialog::AcceptOpen);
	dlg->setFileMode(QFileDialog::Directory);
	dlg->setOption(QFileDialog::ShowDirsOnly);
	if (dlg->exec())
	{
		lst = dlg->selectedFiles();
		for (i = 0; i < lst.size(); i++)
		{
			QDir d;

			d.setPath(lst.at(i));
			new QListWidgetItem(d.absolutePath(), DIRSlist);
		}
		this->saveDirectories();
	}

	delete dlg;
}

/***************************************************************************
 * DIRStools_del_click
 ***************************************************************************/
void CNDSROmainDlg::DIRStools_del_click()
{
	if (DIRSlist->count() == 0)
	{
		statusbar->showMessage(tr("Keine Verzeichnisse vorhanden."), 2000);
		return;
	}

	if (DIRSlist->selectedItems().count() == 0)
	{
		statusbar->showMessage(tr("Keine Einträge ausgewählt."), 2000);
		return;
	}

	while (DIRSlist->selectedItems().size() > 0)
	{
		QListWidgetItem * itm;
		
		itm = DIRSlist->takeItem(DIRSlist->row(DIRSlist->selectedItems().at(0)));
		delete itm;
		itm = NULL;
	}

	this->saveDirectories();
}

/***************************************************************************
 * 
 ***************************************************************************/

/***************************************************************************
 * Status
 ***************************************************************************/
void CNDSROmainDlg::Status(QString s, uint delay)
{
	if (delay > 0)
	{
		statusbar->showMessage(s, delay);
	}
	else
	{
		statusbar->showMessage(s);
	}
	this->update();
}

/***************************************************************************
 * 
 ***************************************************************************/

/***************************************************************************
 * 
 ***************************************************************************/

/***************************************************************************
 * 
 ***************************************************************************/

/***************************************************************************
 * ROMStable_cellDoubleClicked
 ***************************************************************************/
void CNDSROmainDlg::ROMStable_cellDoubleClicked(int row, int column)
{
	QTableWidgetItem *	itm;
	CNDSROdetailDlg *	dlg;
	uint			romID;
	CNDSromData		rd;

	// Get Item containing ID
	DBG("row:" << row);
	itm = ROMStable->item(row, 0);

	romID = itm->text().toUInt();
	DBG("romID:" << romID);

	rd = this->getROMbyID(this->m_ACTIVEList, romID);

	dlg = new CNDSROdetailDlg(m_DBIfc, this, Qt::Dialog);
	dlg->showROM(&rd, (this->m_ACTIVEList == &this->m_ROMList));
	this->updateROMList(this->m_ACTIVEList, &rd);

	delete dlg;
	dlg = NULL;
}

/***************************************************************************
 * DEVICEtable_cellDoubleClicked
 ***************************************************************************/
void CNDSROmainDlg::DEVICEtable_cellDoubleClicked(int row, int column)
{
	QTableWidgetItem *	itm;
	CNDSROdetailDlg *	dlg;
	uint			romID;
	CNDSromData		rd;

	// Get Item containing ID
	DBG("row:" << row);
	itm = DEVICEtable->item(row, 0);

	romID = itm->text().toUInt();
	DBG("romID:" << romID);

	rd = this->getROMbyID(&this->m_DEVICEList, romID);

	// isDir?
	if (rd.ROMstate == STATE_DIRECTORY)
	{
		this->m_DEVICEisClick = true;

		// Check if up Dir
		if (rd.ROMname.compare("..") == 0)
		{
			int	dIDX;

			dIDX = this->m_DEVICEsubdir.lastIndexOf(QDir::separator());
			this->m_DEVICEsubdir = this->m_DEVICEsubdir.left(dIDX);
		}
		else
		{
			// Add to m_DEVICEsubdir
			this->m_DEVICEsubdir += QDir::separator() + rd.ROMname;
		}
		DBG("subdir:" << this->m_DEVICEsubdir);
		// rescan
		this->DEVICEtools_scan_click();
		this->m_DEVICEisClick = false;
	}
	else
	{
		dlg = new CNDSROdetailDlg(m_DBIfc, this, Qt::Dialog);
		dlg->showROM(&rd, false);
		this->updateROMList(&this->m_DEVICEList, &rd);
	
		delete dlg;
		dlg = NULL;
	}
}

/***************************************************************************
 * 
 ***************************************************************************/

/***************************************************************************
 * 
 ***************************************************************************/

/***************************************************************************
 * 
 ***************************************************************************/
