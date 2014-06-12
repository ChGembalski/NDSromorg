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

#ifndef CNDSROMAINDLG_H
#define CNDSROMAINDLG_H

/***************************************************************************
 * include
 ***************************************************************************/
#include <QMainWindow>
#include "ui_NDSROmainDlg.h"
#include "NDSromScanner.h"
#include "NDSdbIfc.h"
#include "NDStransfer.h"

/***************************************************************************
 * define
 ***************************************************************************/
#define STORAGE_HEADER		"LZ4!"

/***************************************************************************
 * CNDSROmainDlg
 ***************************************************************************/
class CNDSROmainDlg : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT

public:
	CNDSROmainDlg(QWidget* parent = 0, Qt::WFlags fl = 0 );
	~CNDSROmainDlg();
	/*$PUBLIC_FUNCTIONS$*/

public slots:
	/*$PUBLIC_SLOTS$*/

protected:
	/*$PROTECTED_FUNCTIONS$*/
	bool event(QEvent *event);

protected slots:
	/*$PROTECTED_SLOTS$*/

private:
	bool			m_InitDone;
	CNDSromScanner *	m_ROMscanner;
	CNDSdbIfc *		m_DBIfc;
	CNDStransfer *		m_ROMtransfer;
	bool			m_DEVICEscanned;
	QString			m_DEVICEsubdir;
	bool			m_DEVICEisClick;

	QList<CNDSromData>	m_ROMList;
	QList<CNDSromData>	m_SCANList;
	QList<CNDSromData> *	m_ACTIVEList;
	QList<CNDSromData>	m_DEVICEList;

	void Init();
	void connectActions();
	void clearNameCheck(ENDSromLanguage l);
	ENDSromLanguage getNameChecked();
	void loadDirectories();
	void saveDirectories();
	void reloadROMList();
	CNDSromData getROMbyID(QList<CNDSromData> * lst, uint id);
	void updateROMList(QList<CNDSromData> * lst, CNDSromData * rd);
	bool copyROMtoStorage(CNDSromData * rd);
	bool copyROMtoFilesystem(CNDSromData * rd, QString fpath);

private slots:
	// menu
	void ImportROMListe();
	void ImportROMDataListe();
	void ImportROMCodeListe();
	void ImportIMGListe();
	void ExportROMListe();
	void ExportROMDataListe();
	void ExportROMCodeListe();
	void ExportIMGListe();
	void CNDSROmainDlg_close();
	void EditSettings();
	void SelectTabROMS();
	void SelectTabDEVICE();
	void SelectTabFAVORITES();
	void SelectTabTOOLS();
	void SelectTabDIRS();
	void CNDSROmainDlg_about();
	void SelectNameJPN();
	void SelectNameENG();
	void SelectNameFRN();
	void SelectNameGER();
	void SelectNameITL();
	void SelectNameSPN();
	void SelectNameCHI();
	// ROMtools
	void ROMStools_scan_click();
	void ROMStools_romlist_click();
	void ROMStools_scanlist_click();
	void ROMStools_scanclear_click();
	void ROMStools_delete_click();
	void ROMStools_copy_click();
	// DEVICEtools
	void DEVICEtools_scan_click();
	void DEVICEtools_remove_click();
	// FAVORITEStools
	// TOOLStools
	// DIRStools
	void DIRStools_add_click();
	void DIRStools_del_click();
	// Status for ROMscanner
	void Status(QString s, uint delay = 0);

	// ROMStable
	void ROMStable_cellDoubleClicked(int row, int column);
	// DEVICEtable
	void DEVICEtable_cellDoubleClicked(int row, int column);
};

/***************************************************************************
 * 
 ***************************************************************************/

#endif

