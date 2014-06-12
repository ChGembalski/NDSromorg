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

#include "NDSromData.h"
#include "NDSdebug.h"
#include <QStringList>
#include <QByteArray>

/***************************************************************************
 * CTor
 ***************************************************************************/
CNDSromData::CNDSromData()
{
	this->ROMid = 0;
	this->ROMicon = "";
	this->ROMdisplname = "";
	this->ROMname = "";
	this->ROMversion = 0;
	this->ROMlanguage[JPN].Name = "";
	this->ROMlanguage[JPN].SubName = "";
	this->ROMlanguage[JPN].Publisher = "";
	this->ROMlanguage[ENG].Name = "";
	this->ROMlanguage[ENG].SubName = "";
	this->ROMlanguage[ENG].Publisher = "";
	this->ROMlanguage[FRN].Name = "";
	this->ROMlanguage[FRN].SubName = "";
	this->ROMlanguage[FRN].Publisher = "";
	this->ROMlanguage[GER].Name = "";
	this->ROMlanguage[GER].SubName = "";
	this->ROMlanguage[GER].Publisher = "";
	this->ROMlanguage[ITL].Name = "";
	this->ROMlanguage[ITL].SubName = "";
	this->ROMlanguage[ITL].Publisher = "";
	this->ROMlanguage[SPN].Name = "";
	this->ROMlanguage[SPN].SubName = "";
	this->ROMlanguage[SPN].Publisher = "";
	this->ROMlanguage[CHI].Name = "";
	this->ROMlanguage[CHI].SubName = "";
	this->ROMlanguage[CHI].Publisher = "";
	this->ROMserial = "";
	this->ROMcode = "";
	this->ROMpublisher = "";
	this->ROMfilesize = 0;
	this->ROMunitcode = "";
	this->ROMcrc32 = 0;
	this->ROMcapacity = 0;

	this->ROMpath = "";
	this->ROMfilename = "";
	this->isROM = false;
	this->ROMstate = STATE_NONE;
	this->ROMcomment = "";
}

/***************************************************************************
 * DTor
 ***************************************************************************/
CNDSromData::~CNDSromData()
{
}

/***************************************************************************
 * 
 * PUBLIC
 * 
 ***************************************************************************/

/***************************************************************************
 * fixROMlanguage
 ***************************************************************************/
void CNDSromData::fixROMlanguage()
{
	QStringList	res;
	int		l;

	l = JPN;
	while(l != EOLanguage)
	{

		res = this->ROMlanguage[l].Name.split(QRegExp("\\n"), QString::SkipEmptyParts);
		DBG("ROMlanguage[" << (ENDSromLanguage)l << "]");

		if (res.size() == 2)
		{
			DBG("Name:" << res.at(0));
			this->ROMlanguage[l].Name = res.at(0);
			DBG("Publisher:" << res.at(1));
			this->ROMlanguage[l].Publisher = res.at(1);
		}
		if (res.size() == 3)
		{
			DBG("Name:" << res.at(0));
			this->ROMlanguage[l].Name = res.at(0);
			DBG("SubName:" << res.at(1));
			this->ROMlanguage[l].SubName = res.at(1);
			DBG("Publisher:" << res.at(2));
			this->ROMlanguage[l].Publisher = res.at(2);
		}

		l++;
	}
}

/***************************************************************************
 * buildSQL
 ***************************************************************************/
QString CNDSromData::buildSQL(ENDSromSQL t)
{
	QString	SQL;
	QString	s;

	if (t == SQL_READ)
	{
		SQL = "SELECT id, name, version, serial, code, publisher, filesize, unitcode, crc32, capacity, displname, stat, comment FROM roms WHERE (id=";
		s.setNum(this->ROMid);
		SQL += s;
		SQL += ")";
	}
	if (t == SQL_WRITE)
	{
		SQL = "INSERT INTO roms (id, name, version, serial, code, publisher, filesize, unitcode, crc32, capacity, displname, stat, comment) VALUES(";
		s.setNum(this->ROMid);
		SQL += s;
		SQL += ",'" + this->ROMname;
		s.setNum(this->ROMversion);
		SQL += "'," + s;
		SQL += ",'" + this->ROMserial;
		SQL += "','" + this->ROMcode;
		SQL += "','" + this->ROMpublisher;
		s.setNum(this->ROMfilesize);
		SQL += "'," + s;
		SQL += ",'" + this->ROMunitcode;
		s.setNum(this->ROMcrc32);
		SQL += "'," + s;
		s.setNum(this->ROMcapacity);
		SQL += "," + s;
		SQL += ",'" + this->ROMdisplname;
		s.setNum((uint)this->ROMstate);
		SQL += "'," + s;
		SQL += ",'" + this->ROMcomment;
		SQL += "')";
	}
	if (t == SQL_DELETE)
	{
		SQL = "DELETE FROM roms WHERE (id=";
		s.setNum(this->ROMid);
		SQL += s;
		SQL += ")";
	}
	if (t == SQL_UPDATE)
	{
		SQL = "UPDATE roms SET displname='";
		SQL += this->ROMdisplname;
		SQL += "', comment='";
		SQL += this->ROMcomment;
		SQL += "', publisher='";
		SQL += this->ROMpublisher;
		SQL += "', stat=";
		SQL += this->ROMstate;
		SQL += " WHERE (id=";
		s.setNum(this->ROMid);
		SQL += s;
		SQL += ")";
	}

	return (SQL);
}

/***************************************************************************
 * buildSQLlang
 ***************************************************************************/
QString CNDSromData::buildSQLlang(ENDSromSQL t, ENDSromLanguage l)
{
	QString	SQL;
	QString	s;

	if (t == SQL_READ)
	{
		SQL = "SELECT id, lang, name, subname, publisher FROM romlang WHERE (id=";
		s.setNum(this->ROMid);
		SQL += s;
		SQL += ") ORDER BY lang ASC";
	}
	if (t == SQL_WRITE)
	{
		SQL = "INSERT INTO romlang (id, lang, name, subname, publisher) VALUES(";
		s.setNum(this->ROMid);
		SQL += s;
		s.setNum((uint)l);
		SQL += "," + s;
		SQL += ",'" + this->ROMlanguage[l].Name;
		SQL += "','" + this->ROMlanguage[l].SubName;
		SQL += "','" + this->ROMlanguage[l].Publisher;
		SQL += "')";
	}
	if (t == SQL_DELETE)
	{
		SQL = "DELETE FROM romlang WHERE (id=";
		s.setNum(this->ROMid);
		SQL += s;
		SQL += ")";
	}

	return (SQL);
}

/***************************************************************************
 * buildSQLicon
 ***************************************************************************/
QString CNDSromData::buildSQLicon(ENDSromSQL t)
{
	QString	SQL;
	QString	s;

	if (t == SQL_READ)
	{
		SQL = "SELECT data FROM romicon WHERE (id=";
		s.setNum(this->ROMid);
		SQL += s;
		SQL += ")";
	}
	if (t == SQL_WRITE)
	{
		SQL = "INSERT INTO romicon (id, data) VALUES (";
		s.setNum(this->ROMid);
		SQL += s;
		SQL += ",'";
		SQL += this->ROMicon;
		SQL += "')";
	}
	if (t == SQL_DELETE)
	{
		SQL = "DELETE FROM romicon WHERE (id=";
		s.setNum(this->ROMid);
		SQL += s;
		SQL += ")";
	}

	return (SQL);
}

/***************************************************************************
 * buildSQLicon
 ***************************************************************************/
QString CNDSromData::buildSQLpic(ENDSromSQL t)
{
	QString	SQL;
	QString	s;

	if (t == SQL_READ)
	{
		SQL = "SELECT serial, no, crc32, size, img FROM images WHERE (serial='";
		SQL += this->ROMserial;
		SQL += "') ORDER BY no ASC";
	}
	if (t == SQL_READ_MIN)
	{
		SQL = "SELECT serial, no, crc32, size FROM images WHERE (serial='";
		SQL += this->ROMserial;
		SQL += "') ORDER BY no ASC";
	}
	if (t == SQL_WRITE)
	{
		SQL = "INSERT INTO images (serial, no, crc32, size, img) VALUES (?,?,?,?,?)";
	}
	if (t == SQL_DELETE)
	{
		SQL = "DELETE FROM images WHERE (serial='";
		SQL += this->ROMserial;
		SQL += "')";
	}

	return (SQL);
}

/***************************************************************************
 * getROMicon
 ***************************************************************************/
QIcon CNDSromData::getROMicon()
{
	QIcon		res;
	QStringList	lst;
	QPixmap 	pix;
	char *		xpm;
	char **		xxx;
	int		xpmsize;
	int		lines;

	lst = this->ROMicon.split("\n");

	// Get full data size
	xpmsize = 0;
	foreach(QString s, lst)
    	{
		xpmsize += s.length();
		xpmsize++;
	}
	xpmsize++;
	DBG("xpmsize:" << xpmsize);

	// Alloc 
	lines = lst.size();
	xxx = new char * [lines];
	xpm = new char[xpmsize];

	// Fill buffer
	xpmsize = 0;
	lines = 0;
	foreach(QString s, lst)
    	{
		int len;

		xxx[lines] = &xpm[xpmsize];
		len = strlen(s.toStdString().c_str());
		memcpy(&xpm[xpmsize], s.toStdString().c_str(), len);
		xpmsize += len;
		xpm[xpmsize] = '\0';
		xpmsize++;
		TRACE(s);
		lines++;
	}
	xpm[xpmsize] = '\0';
	xpmsize++;
	DBG("xpmsize:" << xpmsize);

	// Create pixmap
	
	pix = QPixmap(xxx);

	DBG("H:" << pix.size().height());
	DBG("W:" << pix.size().width());

	res = QIcon(pix);

	// Cleanup
	delete [] xpm;
	xpm = NULL;
	delete [] xxx;
	xxx = NULL;

	return (res);
}

/***************************************************************************
 * getROMpixmap
 ***************************************************************************/
QPixmap CNDSromData::getROMpixmap()
{
	QStringList	lst;
	QPixmap 	res;
	char *		xpm;
	char **		xxx;
	int		xpmsize;
	int		lines;

	lst = this->ROMicon.split("\n");

	// Get full data size
	xpmsize = 0;
	foreach(QString s, lst)
    	{
		xpmsize += s.length();
		xpmsize++;
	}
	xpmsize++;
	DBG("xpmsize:" << xpmsize);

	// Alloc 
	lines = lst.size();
	xxx = new char * [lines];
	xpm = new char[xpmsize];

	// Fill buffer
	xpmsize = 0;
	lines = 0;
	foreach(QString s, lst)
    	{
		int len;

		xxx[lines] = &xpm[xpmsize];
		len = strlen(s.toStdString().c_str());
		memcpy(&xpm[xpmsize], s.toStdString().c_str(), len);
		xpmsize += len;
		xpm[xpmsize] = '\0';
		xpmsize++;
		TRACE(s);
		lines++;
	}
	xpm[xpmsize] = '\0';
	xpmsize++;
	DBG("xpmsize:" << xpmsize);

	// Create pixmap
	
	res = QPixmap(xxx);

	DBG("H:" << res.size().height());
	DBG("W:" << res.size().width());

	// Cleanup
	delete [] xpm;
	xpm = NULL;
	delete [] xxx;
	xxx = NULL;

	return (res);
}

/***************************************************************************
 * getROMiconBase64
 ***************************************************************************/
QString CNDSromData::getROMiconBase64()
{
	QByteArray	bArray;
	QString		res;

	bArray = this->ROMicon.toUtf8().toBase64();

	res = QString::fromAscii(bArray.constData());

	return (res);
}

/***************************************************************************
 * setROMiconBase64
 ***************************************************************************/
void CNDSromData::setROMiconBase64(QString * s)
{
	QByteArray	bArray;

	TRACE("s=" << *s);

	bArray = s->toAscii();
	TRACE("bArray=" << bArray);

	this->ROMicon = QString::fromUtf8(QByteArray::fromBase64(bArray).constData());

	TRACE("Icon:" << this->ROMicon);
}

/***************************************************************************
 * 
 ***************************************************************************/
