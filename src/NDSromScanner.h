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

#ifndef NDS_ROMSCANNER_H
#define NDS_ROMSCANNER_H

/***************************************************************************
 * include
 ***************************************************************************/
#include "NDSromData.h"
#include "NDSrominfo.h"
#include "NDSdbIfc.h"
#include <QTableWidget>
#include <QList>
#include <QString>
#include <QObject>

/***************************************************************************
 * define
 ***************************************************************************/
#define MB              (1024*1024)

/***************************************************************************
 * typedef
 ***************************************************************************/

/***************************************************************************
 * CNDSromScanner
 ***************************************************************************/
class CNDSromScanner : public QObject
{
	Q_OBJECT

public:
	CNDSromScanner();
	~CNDSromScanner();

	ENDSromLanguage		NameLanguage;

	QList<CNDSromData> ScanDir(QString d, CNDSdbIfc * dbIfc, bool bAddDirs = false);

	void ListToTable(QList<CNDSromData> * lst, QTableWidget * tbl);
	QString POSIXfilename(QString fname);

public slots:
	void Status(QString s, uint delay = 0);

protected:

protected slots:

private:
	bool ScanRom(QString d, QString f, nds_rom_info_t * rom_info);
	int get_nds_info(FILE* rom_file, nds_rom_info_t *rom_info);
	uint get_romstring_size(uint8_t * s, uint max);


private slots:

signals:
	void StatusChanged(QString s, uint delay);
};

/***************************************************************************
 * 
 ***************************************************************************/

#endif // NDS_ROMSCANNER_H
