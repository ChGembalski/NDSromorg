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

#ifndef NDS_ROMDATA_H
#define NDS_ROMDATA_H

/***************************************************************************
 * include
 ***************************************************************************/
#include <QString>
#include <QIcon>
#include <QPixmap>
#include <QList>

/***************************************************************************
 * define
 ***************************************************************************/

/***************************************************************************
 * ENDSromLanguage
 ***************************************************************************/
enum ENDSromLanguage
{
	JPN = 0,
	ENG = 1,
	FRN = 2,
	GER = 3,
	ITL = 4,
	SPN = 5,
	CHI = 6,
	EOLanguage
};

/***************************************************************************
 * ENDSromSQL
 ***************************************************************************/
enum ENDSromSQL
{
	SQL_READ, SQL_READ_MIN, SQL_WRITE, SQL_DELETE, SQL_UPDATE
};

/***************************************************************************
 * ENDSromState
 ***************************************************************************/
enum ENDSromState
{
	STATE_NONE,
	STATE_CRC32,
	STATE_NO_ROM,
	STATE_ON_DEVICE,
	STATE_FILE_STORED,
	STATE_ONLY_DATA,
	STATE_DIRECTORY
};

/***************************************************************************
 * SNDSromLanguage
 ***************************************************************************/
struct SNDSromLanguage
{
	QString		Name;
	QString		SubName;
	QString		Publisher;
};

/***************************************************************************
 * SNDSromPicture
 ***************************************************************************/
struct SNDSromPicture
{
	QString		ROMcode;
	uint		No;
	uint		crc32;
	uint		size;
	QPixmap		ROMpixmap;
};

/***************************************************************************
 * CNDSromData
 ***************************************************************************/
class CNDSromData
{
public:
	CNDSromData();
	~CNDSromData();

	uint			ROMid;
	QString			ROMicon;
	QString			ROMdisplname;
	QString			ROMname;
	uint			ROMversion;
	SNDSromLanguage		ROMlanguage[EOLanguage];
	QString			ROMserial;
	QString			ROMcode;
	QString			ROMpublisher;
	uint			ROMfilesize;
	QString			ROMunitcode;
	uint			ROMcrc32;
	uint			ROMcapacity;

	QString			ROMpath;
	QString			ROMfilename;
	bool			isROM;
	ENDSromState		ROMstate;
	QString			ROMcomment;
	QList<SNDSromPicture>	ROMpicList;

	void fixROMlanguage();
	QString buildSQL(ENDSromSQL t);
	QString buildSQLlang(ENDSromSQL t, ENDSromLanguage l = EOLanguage);
	QString buildSQLicon(ENDSromSQL t);
	QString buildSQLpic(ENDSromSQL t);
	QIcon getROMicon();
	QPixmap getROMpixmap();
	QString getROMiconBase64();
	void setROMiconBase64(QString * s);

private:
};

/***************************************************************************
 * 
 ***************************************************************************/

#endif // NDS_ROMDATA_H
