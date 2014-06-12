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

#include "NDSdbIfc.h"
#include "NDSdebug.h"
#include <QDir>
#include <QFile>
#include <QSqlQuery>
#include <QVariant>
#include "NDSrommaker.h"
#include <QBuffer>
#include "NDSromCRC32.h"

/***************************************************************************
 * CTor
 ***************************************************************************/
CNDSdbIfc::CNDSdbIfc()
{
	this->m_DB_Meta = QSqlDatabase::addDatabase("QSQLITE", "qt_meta_connection");
	this->m_DB_Data = QSqlDatabase::addDatabase("QSQLITE", "qt_data_connection");
	this->m_DB_Img = QSqlDatabase::addDatabase("QSQLITE", "qt_img_connection");
}

/***************************************************************************
 * DTor
 ***************************************************************************/
CNDSdbIfc::~CNDSdbIfc()
{
}

/***************************************************************************
 * 
 * PUBLIC
 * 
 ***************************************************************************/

/***************************************************************************
 * setWorkDir
 ***************************************************************************/
void CNDSdbIfc::setWorkDir(QString d)
{
	QString	nameMeta;
	QString	nameData;
	QString	nameImg;

	nameMeta = d + QDir::separator() + DB_META_NAME;
	nameMeta = QDir::toNativeSeparators(nameMeta);
	DBG("META DB:" << nameMeta);
	nameData = d + QDir::separator() + DB_DATA_NAME;
	nameData = QDir::toNativeSeparators(nameData);
	DBG("DATA DB:" << nameData);
	nameImg = d + QDir::separator() + DB_IMG_NAME;
	nameImg = QDir::toNativeSeparators(nameImg);
	DBG("IMG DB:" << nameImg);

	this->m_DB_Meta.setDatabaseName(nameMeta);
	this->m_DB_Data.setDatabaseName(nameData);
	this->m_DB_Img.setDatabaseName(nameImg);

	// Create if not existing
	if (!QFile::exists(nameMeta))
	{
		this->Open(DB_META);
		this->createInitialTables(DB_META);
		this->createInitialMetadata();
		this->Close(DB_META);
	}
	if (!QFile::exists(nameData))
	{
		this->Open(DB_DATA);
		this->createInitialTables(DB_DATA);
		this->Close(DB_DATA);
	}
	if (!QFile::exists(nameImg))
	{
		this->Open(DB_IMG);
		this->createInitialTables(DB_IMG);
		this->Close(DB_IMG);
	}
}

/***************************************************************************
 * Open
 ***************************************************************************/
bool CNDSdbIfc::Open(ENDSdb db)
{
	switch (db)
	{
	case DB_META:	return (this->m_DB_Meta.open());
	case DB_DATA:	return (this->m_DB_Data.open());
	case DB_IMG:	return (this->m_DB_Img.open());
	}

	return (false);
}

/***************************************************************************
 * Close
 ***************************************************************************/
bool CNDSdbIfc::Close(ENDSdb db)
{
	switch (db)
	{
	case DB_META:	this->m_DB_Meta.close(); return (true);
	case DB_DATA:	this->m_DB_Data.close(); return (true);
	case DB_IMG:	this->m_DB_Img.close(); return (true);
	}

	return (false);
}

/***************************************************************************
 * isOpen
 ***************************************************************************/
bool CNDSdbIfc::isOpen(ENDSdb db)
{
	switch (db)
	{
	case DB_META:	return (this->m_DB_Meta.isOpen());
	case DB_DATA:	return (this->m_DB_Data.isOpen());
	case DB_IMG:	return (this->m_DB_Img.isOpen());
	}

	return (false);
}

/***************************************************************************
 * updateVendor
 ***************************************************************************/
bool CNDSdbIfc::updateVendor(int c0, int c1, QString name)
{
	QSqlQuery *	stmt;
	QString		SQL;
	QString		sC0;
	QString		sC1;
	bool		res;

	stmt = NULL;
	SQL = "";
	sC0 = "";
	sC1 = "";
	res = false;

	if (!this->isOpen(DB_META))
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Meta);

	sC0.setNum(c0, 10);
	sC1.setNum(c1, 10);

	// delete first
	SQL = "DELETE FROM vendor WHERE (c0=" + 
		sC0 + " AND c1=" + sC1 + ")";
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	// Insert
	SQL = "INSERT INTO vendor (c0, c1, name) VALUES (" +
		sC0 + "," +
		sC1 + ",'" +
		name + "')";
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * readVendor
 ***************************************************************************/
QString CNDSdbIfc::readVendor(int c0, int c1)
{
	QSqlQuery *	stmt;
	QString		SQL;
	QString		sC0;
	QString		sC1;
	QString		res;

	stmt = NULL;
	SQL = "";
	sC0 = "";
	sC1 = "";
	res = VENDOR_UNKNOWN;

	if (!this->isOpen(DB_META))
		return (VENDOR_UNKNOWN);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Meta);

	sC0.setNum(c0, 10);
	sC1.setNum(c1, 10);

	// Select
	SQL = "SELECT name FROM vendor WHERE (c0=" + 
		sC0 + " AND c1=" + sC1 + ")";
	DBG("SQL:" << SQL);
	if (stmt->exec(SQL))
	{
		if (stmt->next())
		{
			TRACE("value(0):" << stmt->value(0).toString());
			res = stmt->value(0).toString();
		}
	}

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * deleteVendor
 ***************************************************************************/
bool CNDSdbIfc::deleteVendor(int c0, int c1)
{
	QSqlQuery *	stmt;
	QString		SQL;
	QString		sC0;
	QString		sC1;
	bool		res;

	stmt = NULL;
	SQL = "";
	sC0 = "";
	sC1 = "";
	res = false;

	if (!this->isOpen(DB_META))
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Meta);

	sC0.setNum(c0, 10);
	sC1.setNum(c1, 10);

	// delete
	SQL = "DELETE FROM vendor WHERE (c0=" + 
		sC0 + " AND c1=" + sC1 + ")";
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * readPathList
 ***************************************************************************/
bool CNDSdbIfc::readPathList(QStringList * list)
{
	QSqlQuery *	stmt;
	QString		SQL;
	bool		res;

	stmt = NULL;
	SQL = "";
	res = false;

	if (!this->isOpen(DB_META))
		return (false);

	if (list == NULL)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Meta);

	SQL = "SELECT name FROM dirs ORDER BY name ASC";
	DBG("SQL:" << SQL);
	list->clear();

	res = stmt->exec(SQL);
	if (res)
	{
		while (stmt->next())
		{
			TRACE("value(0):" << stmt->value(0).toString());
			list->append(stmt->value(0).toString());
		}
	}

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * writePathList
 ***************************************************************************/
bool CNDSdbIfc::writePathList(QStringList * list)
{
	QSqlQuery *	stmt;
	QString		SQL;
	bool		res;
	int		i;

	stmt = NULL;
	SQL = "";
	res = false;

	if (!this->isOpen(DB_META))
		return (false);

	if (list == NULL)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Meta);

	// Clear all
	SQL = "DELETE FROM dirs";
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	// Insert all
	for (i = 0; i < list->size(); i++)
	{
		SQL = "INSERT INTO dirs (name) VALUES('" +
			list->at(i) + "')";
		DBG("SQL:" << SQL);
		res = stmt->exec(SQL);
	}

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * writeROM
 ***************************************************************************/
bool CNDSdbIfc::writeROM(CNDSromData * rom)
{
	QSqlQuery *	stmt;
	QString		SQL;
	bool		res;
	int		i;

	stmt = NULL;
	SQL = "";
	res = false;
	i = 0;

	if (!this->isOpen(DB_DATA))
		return (false);

	if (rom == NULL)
		return (false);

	if (!rom->isROM)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Data);

	// Get next free ID
	SQL = "SELECT MAX(id) FROM roms";
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);
	if (res)
	{
		if (stmt->next())
		{
			TRACE("value(0):" << stmt->value(0).toInt());
			i = stmt->value(0).toInt();
		}
	}
	i++;
	// Set Id
	rom->ROMid = i;

	SQL = rom->buildSQL(SQL_WRITE);
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	for (i=0; i<EOLanguage; i++)
	{
		SQL = rom->buildSQLlang(SQL_WRITE, (ENDSromLanguage)i);
		DBG("SQL:" << SQL);
		res = stmt->exec(SQL);
	}

	SQL = rom->buildSQLicon(SQL_WRITE);
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * readROMS
 ***************************************************************************/
bool CNDSdbIfc::readROMS(QList<CNDSromData> * rom_list)
{
	QSqlQuery *	stmt;
	QSqlQuery *	stmt2;
	QString		SQL;
	bool		res;
	int		i;
	int		l;

	stmt = NULL;
	SQL = "";
	res = false;
	i = 0;
	l = 0;

	if (!this->isOpen(DB_DATA))
		return (false);

	if (rom_list == NULL)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Data);
	stmt2 = new QSqlQuery(this->m_DB_Data);

	SQL = "SELECT id, name, version, serial, code, publisher, filesize, unitcode, crc32, capacity, displname, stat, comment FROM roms ORDER by id ASC";
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);
	if (res)
	{
		while (stmt->next())
		{
			CNDSromData	rd;

			rd.isROM = true;
			TRACE("value(0):" << stmt->value(0).toInt());
			rd.ROMid = stmt->value(0).toInt();
			TRACE("value(1):" << stmt->value(1).toString());
			rd.ROMname = stmt->value(1).toString();
			TRACE("value(2):" << stmt->value(2).toInt());
			rd.ROMversion = stmt->value(2).toInt();
			TRACE("value(3):" << stmt->value(3).toString());
			rd.ROMserial = stmt->value(3).toString();
			TRACE("value(4):" << stmt->value(4).toString());
			rd.ROMcode = stmt->value(4).toString();
			TRACE("value(5):" << stmt->value(5).toString());
			rd.ROMpublisher = stmt->value(5).toString();
			TRACE("value(6):" << stmt->value(6).toInt());
			rd.ROMfilesize = stmt->value(6).toInt();
			TRACE("value(7):" << stmt->value(7).toString());
			rd.ROMunitcode = stmt->value(7).toString();
			TRACE("value(8):" << stmt->value(8).toInt());
			rd.ROMcrc32 = stmt->value(8).toInt();
			TRACE("value(9):" << stmt->value(9).toInt());
			rd.ROMcapacity = stmt->value(9).toInt();
			TRACE("value(10):" << stmt->value(10).toString());
			rd.ROMdisplname = stmt->value(10).toString();
			TRACE("value(11):" << stmt->value(11).toInt());
			rd.ROMstate = (ENDSromState)stmt->value(11).toInt();
			TRACE("value(12):" << stmt->value(12).toString());
			rd.ROMcomment = stmt->value(12).toString();

			// Get Language Data
			SQL = rd.buildSQLlang(SQL_READ);
			DBG("SQL:" << SQL);
			res = stmt2->exec(SQL);
			if (res)
			{
				while (stmt2->next())
				{
					int	lID;

					TRACE("value(1):" << stmt2->value(1).toInt());
					lID = stmt2->value(1).toInt();
					TRACE("value(2):" << stmt2->value(2).toString());
					rd.ROMlanguage[lID].Name = stmt2->value(2).toString();
					TRACE("value(3):" << stmt2->value(3).toString());
					rd.ROMlanguage[lID].SubName = stmt2->value(3).toString();
					TRACE("value(4):" << stmt2->value(4).toString());
					rd.ROMlanguage[lID].Publisher = stmt2->value(4).toString();
				}
			}

			// Get Icon Data
			SQL = rd.buildSQLicon(SQL_READ);
			DBG("SQL:" << SQL);
			res = stmt2->exec(SQL);
			if (res)
			{
				if (stmt2->next())
				{
					TRACE("value(0):" << stmt2->value(0).toString());
					rd.ROMicon = stmt2->value(0).toString();
				}
			}

			rom_list->append(rd);
		}
	}

	// Cleanup
	stmt2->finish();
	delete stmt2;
	stmt2 = NULL;
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * deleteROM
 ***************************************************************************/
bool CNDSdbIfc::deleteROM(CNDSromData * rom)
{
	QSqlQuery *	stmt;
	QString		SQL;
	bool		res;

	stmt = NULL;
	SQL = "";
	res = false;

	if (!this->isOpen(DB_DATA))
		return (false);

	if (rom == NULL)
		return (false);

	if (rom->ROMid == 0)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Data);

	SQL = rom->buildSQL(SQL_DELETE);
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	SQL = rom->buildSQLlang(SQL_DELETE);
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	SQL = rom->buildSQLicon(SQL_DELETE);
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * existROM
 ***************************************************************************/
bool CNDSdbIfc::existROM(CNDSromData * rom)
{
	QSqlQuery *	stmt;
	QString		SQL;
	bool		res;
	QString		s;

	stmt = NULL;
	SQL = "";
	res = false;

	if (!this->isOpen(DB_DATA))
		return (false);

	if (rom == NULL)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Data);

	SQL = "SELECT id FROM roms WHERE (crc32=";
	s.setNum(rom->ROMcrc32);
	SQL += s + ")";
	DBG("SQL:" << SQL);

	res = stmt->exec(SQL);
	if (res)
	{
		res = false;
		if (stmt->next())
		{
			TRACE("value(0):" << stmt->value(0).toUInt());
			rom->ROMid = stmt->value(0).toUInt();
			res = true;
		}
	}

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * updateROM
 ***************************************************************************/
bool CNDSdbIfc::updateROM(CNDSromData * rom)
{
	QSqlQuery *	stmt;
	QString		SQL;
	bool		res;

	stmt = NULL;
	SQL = "";
	res = false;

	if (!this->isOpen(DB_DATA))
		return (false);

	if (rom == NULL)
		return (false);

	if (rom->ROMid == 0)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Data);

	SQL = rom->buildSQL(SQL_UPDATE);
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * getROMstate
 ***************************************************************************/
ENDSromState CNDSdbIfc::getROMstate(CNDSromData * rom)
{
	QSqlQuery *	stmt;
	QString		SQL;
	ENDSromState	res;
	QString		s;

	stmt = NULL;
	SQL = "";
	res = STATE_NONE;

	if (!this->isOpen(DB_DATA))
		return (STATE_NONE);

	if (rom == NULL)
		return (STATE_NONE);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Data);

	SQL = "SELECT stat FROM roms WHERE (crc32=";
	s.setNum(rom->ROMcrc32);
	SQL += s + ")";
	DBG("SQL:" << SQL);

	if (stmt->exec(SQL))
	{
		if (stmt->next())
		{
			TRACE("value(0):" << stmt->value(0).toUInt());
			res = (ENDSromState)stmt->value(0).toUInt();
		}
	}

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * writeIMAGES
 ***************************************************************************/
bool CNDSdbIfc::writeIMAGES(CNDSromData * rom)
{
	QSqlQuery *	stmt;
	QString		SQL;
	bool		res;

	stmt = NULL;
	SQL = "";
	res = false;

	if (!this->isOpen(DB_IMG))
		return (false);

	if (rom == NULL)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Img);

	// delete first
	SQL = rom->buildSQLpic(SQL_DELETE);
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	foreach(SNDSromPicture pic, rom->ROMpicList)
	{
		QByteArray 	bArray;
		QBuffer 	buffer(&bArray);
		uint32_t	crc;

		// Prepare Buffer
		buffer.open(QIODevice::WriteOnly);
		pic.ROMpixmap.save(&buffer, "PNG");

		// calc crc32
		crc = CNDSromCRC32::crc32(0, bArray.constData(), bArray.count());

		SQL = rom->buildSQLpic(SQL_WRITE);
		DBG("SQL:" << SQL);

		stmt->prepare(SQL);
		stmt->bindValue(0, rom->ROMserial);
		stmt->bindValue(1, pic.No);
		stmt->bindValue(2, crc);
		stmt->bindValue(3, bArray.count());
		stmt->bindValue(4, bArray);

		TRACE("SQL:" << stmt->boundValues());
		res = stmt->exec();
	}

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * readIMAGES
 ***************************************************************************/
bool CNDSdbIfc::readIMAGES(CNDSromData * rom)
{
	QSqlQuery *	stmt;
	QString		SQL;
	bool		res;

	stmt = NULL;
	SQL = "";
	res = false;

	if (!this->isOpen(DB_IMG))
		return (false);

	if (rom == NULL)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Img);

	SQL = rom->buildSQLpic(SQL_READ);
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	if (res)
	{
		// Clear old List
		rom->ROMpicList.clear();
	
		while (stmt->next())
		{
			SNDSromPicture	rp;
			QByteArray 	bArray;

			TRACE("value(0):" << stmt->value(0).toString());
			rp.ROMcode = stmt->value(0).toString();
			TRACE("value(1):" << stmt->value(1).toInt());
			rp.No = stmt->value(1).toInt();
			TRACE("value(2):" << stmt->value(2).toUInt());
			rp.crc32 = stmt->value(2).toUInt();
			TRACE("value(3):" << stmt->value(3).toUInt());
			rp.size = stmt->value(3).toUInt();
			TRACE("value(4):" << stmt->value(4).toByteArray());
			bArray = stmt->value(4).toByteArray();
			rp.ROMpixmap.loadFromData(bArray,"PNG");
			rom->ROMpicList.append(rp);
		}
	}

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * readIMAGES
 ***************************************************************************/
bool CNDSdbIfc::readIMAGES(CNDSromData * rom, QList<SNDSromPicture> * lst)
{
	QSqlQuery *	stmt;
	QString		SQL;
	bool		res;

	stmt = NULL;
	SQL = "";
	res = false;

	if (!this->isOpen(DB_IMG))
		return (false);

	if (rom == NULL)
		return (false);

	if (lst == NULL)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Img);

	SQL = rom->buildSQLpic(SQL_READ_MIN);
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	if (res)
	{
		// Clear old List
		lst->clear();
	
		while (stmt->next())
		{
			SNDSromPicture	rp;
			QByteArray 	bArray;

			TRACE("value(0):" << stmt->value(0).toString());
			rp.ROMcode = stmt->value(0).toString();
			TRACE("value(1):" << stmt->value(1).toInt());
			rp.No = stmt->value(1).toInt();
			TRACE("value(2):" << stmt->value(2).toUInt());
			rp.crc32 = stmt->value(2).toUInt();
			TRACE("value(3):" << stmt->value(3).toUInt());
			rp.size = stmt->value(3).toUInt();
			lst->append(rp);
		}
	}

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * deleteIMAGES
 ***************************************************************************/
bool CNDSdbIfc::deleteIMAGES(CNDSromData * rom)
{
	QSqlQuery *	stmt;
	QString		SQL;
	bool		res;

	stmt = NULL;
	SQL = "";
	res = false;

	if (!this->isOpen(DB_IMG))
		return (false);

	if (rom == NULL)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Img);

	SQL = rom->buildSQLpic(SQL_DELETE);
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * readIMAGES
 ***************************************************************************/
bool CNDSdbIfc::readIMAGES(QList<SNDSromPicture> * lst)
{
	QSqlQuery *	stmt;
	QString		SQL;
	bool		res;

	stmt = NULL;
	SQL = "";
	res = false;

	if (!this->isOpen(DB_IMG))
		return (false);

	if (lst == NULL)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Img);

	SQL = "SELECT serial, no, crc32, size FROM images ORDER BY serial, no ASC";
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	if (res)
	{
		// Clear old List
		lst->clear();
	
		while (stmt->next())
		{
			SNDSromPicture	rp;

			TRACE("value(0):" << stmt->value(0).toString());
			rp.ROMcode = stmt->value(0).toString();
			TRACE("value(1):" << stmt->value(1).toInt());
			rp.No = stmt->value(1).toInt();
			TRACE("value(2):" << stmt->value(2).toUInt());
			rp.crc32 = stmt->value(2).toUInt();
			TRACE("value(3):" << stmt->value(3).toUInt());
			rp.size = stmt->value(3).toUInt();
			lst->append(rp);
		}
	}

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * readIMAGE
 ***************************************************************************/
bool CNDSdbIfc::readIMAGE(QByteArray * bArray, SNDSromPicture * pic)
{
	QSqlQuery *	stmt;
	QString		SQL;
	bool		res;
	QString		s;

	stmt = NULL;
	SQL = "";
	res = false;
	s = "";

	if (!this->isOpen(DB_IMG))
		return (false);

	if (bArray == NULL)
		return (false);

	if (pic == NULL)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Img);

	SQL = "SELECT img FROM images WHERE (serial='";
	SQL += pic->ROMcode + "' AND no=";
	s.setNum(pic->No);
	SQL += s + ")";
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);

	if (res)
	{
		if (stmt->next())
		{
			TRACE("value(0):" << stmt->value(0).toByteArray());
			*bArray = stmt->value(0).toByteArray();
		}
	}

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * existIMAGE
 ***************************************************************************/
bool CNDSdbIfc::existIMAGE(SNDSromPicture * pic)
{
	QSqlQuery *	stmt;
	QString		SQL;
	bool		res;
	QString		s;

	stmt = NULL;
	SQL = "";
	res = false;

	if (!this->isOpen(DB_IMG))
		return (false);

	if (pic == NULL)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Img);

	SQL = "SELECT no FROM images WHERE (serial='";
	SQL += pic->ROMcode + "' AND crc32=";
	s.setNum(pic->crc32);
	SQL += s + ")";
	DBG("SQL:" << SQL);

	res = stmt->exec(SQL);
	if (res)
	{
		res = false;
		if (stmt->next())
		{
			res = true;
		}
	}

	DBG("res=" << res);

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * writeIMAGE
 ***************************************************************************/
bool CNDSdbIfc::writeIMAGE(SNDSromPicture * pic, QByteArray * bArray)
{
	QSqlQuery *	stmt;
	QString		SQL;
	bool		res;
	int		i;
	uint32_t	crc;

	stmt = NULL;
	SQL = "";
	res = false;
	i = 0;
	crc = 0;

	if (!this->isOpen(DB_IMG))
		return (false);

	if (pic == NULL)
		return (false);

	if (bArray == NULL)
		return (false);

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Img);

	// Get next No
	SQL = "SELECT MAX(no) FROM images WHERE (serial='";
	SQL += pic->ROMcode + "')";
	DBG("SQL:" << SQL);
	res = stmt->exec(SQL);
	if (res)
	{
		if (stmt->next())
		{
			TRACE("value(0):" << stmt->value(0).toInt());
			i = stmt->value(0).toInt();
			i++;
		}
	}

	SQL = "INSERT INTO images (serial, no, crc32, size, img) VALUES (?,?,?,?,?)";
	DBG("SQL:" << SQL);

	// calc crc32
	if (pic->crc32 == 0)
	{
		crc = CNDSromCRC32::crc32(0, bArray->constData(), bArray->count());
	}
	else
	{
		crc = pic->crc32;
	}
	pic->size = bArray->count();

	stmt->prepare(SQL);
	stmt->bindValue(0, pic->ROMcode);
	stmt->bindValue(1, i);
	stmt->bindValue(2, crc);
	stmt->bindValue(3, pic->size);
	stmt->bindValue(4, *bArray);

	TRACE("SQL:" << stmt->boundValues());
	res = stmt->exec();

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;

	return (res);
}

/***************************************************************************
 * 
 * PRIVATE
 * 
 ***************************************************************************/

/***************************************************************************
 * createInitialTables
 ***************************************************************************/
void CNDSdbIfc::createInitialTables(ENDSdb d)
{
	QSqlQuery *	stmt;
	QString		SQL;

	stmt = NULL;
	SQL = "";

	if (!this->isOpen(d))
		return;

	if (d == DB_META)
	{
		// Prepare STMT
		stmt = new QSqlQuery(this->m_DB_Meta);

		SQL = "CREATE TABLE IF NOT EXISTS vendor (c0 INT, c1 INT, name NVARCHAR(250))";
		DBG("SQL:" << SQL);
		stmt->exec(SQL);

		SQL = "CREATE UNIQUE INDEX IF NOT EXISTS idx_vendor ON vendor (c0, c1)";
		DBG("SQL:" << SQL);
		stmt->exec(SQL);

		SQL = "CREATE TABLE IF NOT EXISTS dirs (name NVARCHAR(2000))";
		DBG("SQL:" << SQL);
		stmt->exec(SQL);

		// Cleanup
		stmt->finish();
		delete stmt;
		stmt = NULL;
	}

	if (d == DB_DATA)
	{
		// Prepare STMT
		stmt = new QSqlQuery(this->m_DB_Data);

		SQL = "CREATE TABLE IF NOT EXISTS roms (id INT, name NVARCHAR(250), version INT, serial NVARCHAR(12), code NVARCHAR(2), publisher NVARCHAR(250), filesize INT, unitcode NVARCHAR(1), crc32 INT, capacity INT, displname NVARCHAR(250), stat INT, comment NVARCHAR(2000))";
		DBG("SQL:" << SQL);
		stmt->exec(SQL);

		SQL = "CREATE UNIQUE INDEX IF NOT EXISTS idx_roms ON roms (id)";
		DBG("SQL:" << SQL);
		stmt->exec(SQL);

		SQL = "CREATE INDEX IF NOT EXISTS idx_roms_crc ON roms (crc32)";
		DBG("SQL:" << SQL);
		stmt->exec(SQL);

		SQL = "CREATE TABLE IF NOT EXISTS romlang (id INT, lang INT, name NVARCHAR(250), subname NVARCHAR(250), publisher NVARCHAR(250))";
		DBG("SQL:" << SQL);
		stmt->exec(SQL);

		SQL = "CREATE UNIQUE INDEX IF NOT EXISTS idx_romlang ON romlang (id, lang)";
		DBG("SQL:" << SQL);
		stmt->exec(SQL);

		SQL = "CREATE TABLE IF NOT EXISTS romicon (id INT, data NVARCHAR(2000))";
		DBG("SQL:" << SQL);
		stmt->exec(SQL);

		SQL = "CREATE UNIQUE INDEX IF NOT EXISTS idx_romicon ON romicon (id)";
		DBG("SQL:" << SQL);
		stmt->exec(SQL);

		// Cleanup
		stmt->finish();
		delete stmt;
		stmt = NULL;
	}

	if (d == DB_IMG)
	{
		// Prepare STMT
		stmt = new QSqlQuery(this->m_DB_Img);

		SQL = "CREATE TABLE IF NOT EXISTS images (serial NVARCHAR(12), no INT, crc32 INT, size INT, img BLOB)";
		DBG("SQL:" << SQL);
		stmt->exec(SQL);

		SQL = "CREATE UNIQUE INDEX IF NOT EXISTS idx_images ON images (serial, no)";
		DBG("SQL:" << SQL);
		stmt->exec(SQL);

		SQL = "CREATE INDEX IF NOT EXISTS idx_images_crc ON images (crc32)";
		DBG("SQL:" << SQL);
		stmt->exec(SQL);

		// Cleanup
		stmt->finish();
		delete stmt;
		stmt = NULL;
	}
}

/***************************************************************************
 * createInitialMetadata
 ***************************************************************************/
void CNDSdbIfc::createInitialMetadata()
{
	QSqlQuery *	stmt;
	QString		SQL;
	int		i;

	stmt = NULL;
	SQL = "";
	i = 0;

	if (!this->isOpen(DB_META))
		return;

	// Prepare STMT
	stmt = new QSqlQuery(this->m_DB_Meta);

	while(maker_table[i].Name != NULL)
	{
		QString	sC0;
		QString	sC1;

		sC0.setNum(maker_table[i].C0, 10);
		sC1.setNum(maker_table[i].C1, 10);

		SQL = "INSERT INTO vendor (c0, c1, name) VALUES (" +
			sC0 + "," +
			sC1 + ",'" +
			maker_table[i].Name + "')";
		DBG("SQL:" << SQL);
		stmt->exec(SQL);
		i++;
	};

	// Cleanup
	stmt->finish();
	delete stmt;
	stmt = NULL;
}

/***************************************************************************
 * 
 ***************************************************************************/
