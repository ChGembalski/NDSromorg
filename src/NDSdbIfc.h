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

#ifndef NDS_DB_IFC_H
#define NDS_DB_IFC_H

/***************************************************************************
 * include
 ***************************************************************************/
#include <QSqlDatabase>
#include <QString>
#include <QList>
#include <QStringList>
#include "NDSromData.h"
#include <QPixmap>
#include <QByteArray>

/***************************************************************************
 * define
 ***************************************************************************/
#define DB_META_NAME		"META.db"
#define DB_DATA_NAME		"DATA.db"
#define DB_IMG_NAME		"IMG.db"

#define VENDOR_UNKNOWN		"Unbekannt"

/***************************************************************************
 * typedef
 ***************************************************************************/

/***************************************************************************
 * ENDSdb
 ***************************************************************************/
enum ENDSdb
{
	DB_META = 1,
	DB_DATA = 2,
	DB_IMG = 3
};

/***************************************************************************
 * CNDSdbIfc
 ***************************************************************************/
class CNDSdbIfc
{
public:
	CNDSdbIfc();
	~CNDSdbIfc();

	void setWorkDir(QString d);

	bool Open(ENDSdb db);
	bool Close(ENDSdb db);
	bool isOpen(ENDSdb db);

	bool updateVendor(int c0, int c1, QString name);
	QString readVendor(int c0, int c1);
	bool deleteVendor(int c0, int c1);

	bool readPathList(QStringList * list);
	bool writePathList(QStringList * list);

	bool writeROM(CNDSromData * rom);
	bool readROMS(QList<CNDSromData> * rom_list);
	bool deleteROM(CNDSromData * rom);
	bool existROM(CNDSromData * rom);
	bool updateROM(CNDSromData * rom);
	ENDSromState getROMstate(CNDSromData * rom);

	bool writeIMAGES(CNDSromData * rom);
	bool readIMAGES(CNDSromData * rom);
	bool readIMAGES(CNDSromData * rom, QList<SNDSromPicture> * lst);
	bool deleteIMAGES(CNDSromData * rom);
	bool readIMAGES(QList<SNDSromPicture> * lst);
	bool readIMAGE(QByteArray * bArray, SNDSromPicture * pic);
	bool existIMAGE(SNDSromPicture * pic);
	bool writeIMAGE(SNDSromPicture * pic, QByteArray * bArray);

private:
	QSqlDatabase 		m_DB_Meta;
	QSqlDatabase 		m_DB_Data;
	QSqlDatabase 		m_DB_Img;

	void createInitialTables(ENDSdb d);
	void createInitialMetadata();
	
};

/***************************************************************************
 * 
 ***************************************************************************/

#endif // NDS_DB_IFC_H
