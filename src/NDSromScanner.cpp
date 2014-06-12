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

#include "NDSromScanner.h"
#include "NDSdebug.h"
#include "NDSromCRC32.h"
#include <QDir>
#include <QTableWidgetItem>
#include <QDirIterator>
#include "NDSbgr555.h"

/***************************************************************************
 * CTor
 ***************************************************************************/
CNDSromScanner::CNDSromScanner()
: QObject()
{
	this->NameLanguage = GER;
}

/***************************************************************************
 * DTor
 ***************************************************************************/
CNDSromScanner::~CNDSromScanner()
{
}

/***************************************************************************
 * 
 * PUBLIC
 * 
 ***************************************************************************/

/***************************************************************************
 * ScanDir
 ***************************************************************************/
QList<CNDSromData> CNDSromScanner::ScanDir(QString d, CNDSdbIfc * dbIfc, bool bAddDirs)
{
	QList<CNDSromData>	res;
	QDirIterator *		di;
	QFileInfo		fi;
	nds_rom_info_t		rom_info;
	uint			i;
	CNDSbgr555		bgr;

	this->Status("Scan gestartet.", 2000);
	if (bAddDirs)
	{
		di = new QDirIterator(d, QDirIterator::NoIteratorFlags);
	}
	else
	{
		di = new QDirIterator(d, QDirIterator::Subdirectories | QDirIterator::FollowSymlinks);
	}

	while (di->hasNext())
	{
		di->next();
		fi = di->fileInfo();
		if (fi.isFile())
		{
			CNDSromData rd;

			rd.ROMpath = fi.absolutePath();
			DBG("ROMpath:" << rd.ROMpath);

			rd.ROMfilename = fi.fileName();
			DBG("ROMfilename:" << rd.ROMfilename);
			rd.ROMfilesize = (uint) fi.size();
			DBG("ROMfilesize:" << rd.ROMfilesize);

			this->Status(rd.ROMfilename);
			// Run ROM through Scanner
			if (this->ScanRom(rd.ROMpath, rd.ROMfilename, &rom_info))
			{
				rd.isROM = true;

				// ROM Version
				rd.ROMversion = rom_info.icon.version;
				DBG("ROMversion:" << rd.ROMversion);
				// CRC32
				rd.ROMcrc32 = (uint)rom_info.file_crc32;
				DBG("ROMcrc32:" << rd.ROMcrc32);
				// Internal ROM Name
				rd.ROMname = QString::fromUtf8((char *)rom_info.hdr.game_title, 
					get_romstring_size(rom_info.hdr.game_title, 12)).trimmed();
				DBG("ROMname:" << rd.ROMname);
				// ROM Serial
				rd.ROMserial = "NTR-" + QString::fromUtf8((char *)rom_info.hdr.game_code, 4) + "-";
				for (i=0; i<(sizeof(nds_rom_countries) / sizeof(nds_rom_countries[0])); i++)
				{
					if (nds_rom_countries[i].C == rom_info.hdr.game_code[3])
					{
						rd.ROMserial += QString(nds_rom_countries[i].Name);
						break;
					}
				}
				DBG("ROMserial:" << rd.ROMserial);
				// Game Title in native Languages
				rd.ROMlanguage[JPN].Name = QString::fromUtf16(rom_info.icon.title_jpn);
				DBG("ROMlanguage[JPN]:" << rd.ROMlanguage[JPN].Name);
				rd.ROMlanguage[ENG].Name = QString::fromUtf16(rom_info.icon.title_eng);
				DBG("ROMlanguage[ENG]:" << rd.ROMlanguage[ENG].Name);
				rd.ROMlanguage[FRN].Name = QString::fromUtf16(rom_info.icon.title_frn);
				DBG("ROMlanguage[FRN]:" << rd.ROMlanguage[FRN].Name);
				rd.ROMlanguage[GER].Name = QString::fromUtf16(rom_info.icon.title_grm);
				DBG("ROMlanguage[GER]:" << rd.ROMlanguage[GER].Name);
				rd.ROMlanguage[ITL].Name = QString::fromUtf16(rom_info.icon.title_itl);
				DBG("ROMlanguage[ITL]:" << rd.ROMlanguage[ITL].Name);
				rd.ROMlanguage[SPN].Name = QString::fromUtf16(rom_info.icon.title_spn);
				DBG("ROMlanguage[SPN]:" << rd.ROMlanguage[SPN].Name);
				// Only if Version > 1
				if (rd.ROMversion > 1)
				{
					rd.ROMlanguage[CHI].Name = QString::fromUtf16(rom_info.icon.title_chi);
					DBG("ROMlanguage[CHI]:" << rd.ROMlanguage[CHI].Name);
				}
				// ROM Code
				rd.ROMcode = QString::fromUtf8((char *)rom_info.hdr.maker_code, 
					get_romstring_size(rom_info.hdr.maker_code, 2)).trimmed();
				DBG("ROMcode:" << rd.ROMcode);
				// ROM Publisher
				rd.ROMpublisher = dbIfc->readVendor(
					rd.ROMcode.left(1).data()->unicode(),
					rd.ROMcode.right(1).data()->unicode());
				DBG("ROMpublisher:" << rd.ROMpublisher);
				// ROM Unitcode
				rd.ROMunitcode.setNum(rom_info.hdr.unit_code, 16);
				DBG("ROMunitcode:" << rd.ROMunitcode);
				// ROM Capacity
				rd.ROMcapacity = (((128*1024) << rom_info.hdr.dev_capacity)*8/(float)MB);
				DBG("ROMcapacity:" << rd.ROMcapacity);

				// ROM Displayname
				rd.ROMdisplname = rd.ROMfilename;
				rd.ROMdisplname.resize(rd.ROMdisplname.length() - 4);
				DBG("ROMdisplname:" << rd.ROMdisplname);

				rd.fixROMlanguage();

				// Create Icon
				rd.ROMicon = bgr.createIcon(&rom_info.icon);

			}

			res << rd;
			
		}
		else
		{
			if (bAddDirs)
			{
				bool	bSkipDir;

				bSkipDir = ((fi.fileName().compare(".") == 0) | (fi.fileName().compare("..") == 0));

				if (!bSkipDir)
				{
					CNDSromData rd;
	
					rd.ROMstate = STATE_DIRECTORY;
					rd.ROMpath = fi.absolutePath();
					DBG("ROMpath:" << rd.ROMpath);
					rd.ROMname = fi.fileName();
					DBG("ROMfilename:" << rd.ROMname);
	
					res << rd;
				}
			}
		}
	}

	this->Status("Scan abgeschlossen.", 2000);

	return (res);
}

/***************************************************************************
 * ListToTable
 ***************************************************************************/
void CNDSromScanner::ListToTable(QList<CNDSromData> * lst, QTableWidget * tbl)
{
	int			i;
	CNDSromData		rd;
	QString			s;
	QTableWidgetItem *	itm;
	int			rsize;

	i = 0;
	s = "";
	itm = NULL;
	rsize = 0;

	if (lst == NULL)
		return;
	if (tbl == NULL)
		return;

	// Clear Table
	tbl->setRowCount(0);

	// Fill Table
	for (i = 0; i < lst->size(); ++i) 
	{
		rd = lst->at(i);

		tbl->setRowCount(i + 1);

		// ID
		s.setNum(rd.ROMid);
		itm = new QTableWidgetItem(s.rightJustified(8, '0'));
		itm->setFlags(Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsEnabled);
		tbl->setItem(i, 0, itm);
		// Icon
		switch(rd.ROMstate)
		{
		case STATE_NONE: break;
		case STATE_NO_ROM: break;
		case STATE_DIRECTORY: break;
		case STATE_CRC32:
		case STATE_ON_DEVICE:
		case STATE_FILE_STORED:
		case STATE_ONLY_DATA: 
			{
				itm = new QTableWidgetItem(rd.getROMicon(), "");
				itm->setFlags(Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsEnabled);
				tbl->setItem(i, 1, itm);
				break;
			}
		}
		// Status
		s = "";
		switch(rd.ROMstate)
		{
		case STATE_NONE: s = rd.ROMpath; break;
		case STATE_CRC32: s = "CRC32 vorhanden"; break;
		case STATE_NO_ROM: s = "kein NDS ROM"; break;
		case STATE_ON_DEVICE: s = "auf DEVICE"; break;
		case STATE_FILE_STORED: s = "im Archiv"; break;
		case STATE_ONLY_DATA: s = "Metadaten"; break;
		case STATE_DIRECTORY: s = "Ordner"; break;
		}
		itm = new QTableWidgetItem(s);
		itm->setFlags(Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsEnabled);
		tbl->setItem(i, 2, itm);
		// Name
		itm = new QTableWidgetItem(rd.ROMlanguage[this->NameLanguage].Name + " " + rd.ROMlanguage[this->NameLanguage].SubName);
		itm->setFlags(Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsEnabled);
		tbl->setItem(i, 3, itm);
		// ROMname
		itm = new QTableWidgetItem(rd.ROMname);
		itm->setFlags(Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsEnabled);
		tbl->setItem(i, 4, itm);
		// ROMserial
		itm = new QTableWidgetItem(rd.ROMserial);
		itm->setFlags(Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsEnabled);
		tbl->setItem(i, 5, itm);
		// CRC32
		s.setNum(rd.ROMcrc32, 16);
		itm = new QTableWidgetItem(s.toUpper().rightJustified(8, '0'));
		itm->setTextAlignment(Qt::AlignVCenter | Qt::AlignCenter);
		itm->setFlags(Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsEnabled);
		tbl->setItem(i, 6, itm);
		// ROMsize
		rsize = rd.ROMfilesize/(float)MB;
		if (rsize < 1)
			rsize = 0;
		itm = new QTableWidgetItem(s.setNum(rsize) + " MB");
		itm->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);
		itm->setFlags(Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsEnabled);
		tbl->setItem(i, 7, itm);
		// Verleger
		itm = new QTableWidgetItem(rd.ROMlanguage[this->NameLanguage].Publisher);
		itm->setFlags(Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsEnabled);
		tbl->setItem(i, 8, itm);
		
	}
}

/***************************************************************************
 * POSIXfilename
 ***************************************************************************/
QString CNDSromScanner::POSIXfilename(QString fname)
{
	const QString	POSIXc = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789._-";
	
	foreach(QChar c, fname)
	{
		if (!POSIXc.contains(c))
		{
			return(this->POSIXfilename(fname.remove(c)));
		}
	}
	return (fname);
}

/***************************************************************************
 * 
 * PRIVATE
 * 
 ***************************************************************************/

/***************************************************************************
 * ScanRom
 ***************************************************************************/
bool CNDSromScanner::ScanRom(QString d, QString f, nds_rom_info_t * rom_info)
{
	FILE *		rom_file;
	QString		rom_filename;
	QByteArray	rom_filenameBA;

	if (rom_info == NULL)
		return (false);

	memset(rom_info, 0, sizeof(nds_rom_info_t));
	rom_file = NULL;

	// Check if ROM end exists
	rom_filename = d + QDir::separator() + f;
	if (!rom_filename.endsWith("nds", Qt::CaseInsensitive))
		return (false);
	if (!QFile::exists(rom_filename))
		return (false);

	rom_filenameBA = rom_filename.toUtf8();

	// Open nds file
	if ((rom_file=fopen(rom_filenameBA.constData(), "rb")) == NULL)
	{
		return (false);
	}

	// populate ROM info structure
	if (get_nds_info(rom_file, rom_info) == 0)
	{
		// Now calculate crc32
		fseek(rom_file, 0, SEEK_SET);
		if (CNDSromCRC32::crc32fromFile(rom_file, &rom_info->file_crc32) != 0)
		{
			rom_info->file_crc32 = 0;
		}
	}

	// Cleanup
	if (rom_file != NULL )
	{
		if (fclose(rom_file) == EOF)
		{
			return (false);
		}
	}

	return (true);
}

/***************************************************************************
 * get_nds_info
 ***************************************************************************/
int CNDSromScanner::get_nds_info(FILE* rom_file, nds_rom_info_t *rom_info)
{
	int		res;
	unsigned int	total_bytes_read;
	uint32_t	icon_title_offset;

	res = 0;
	total_bytes_read = 0;
	icon_title_offset = 0;

	do
	{
		if ((rom_info == NULL) || (rom_file == NULL))
        	{
			res = -1;
			break;
		}

		//
        	// read in header, should only read in one item
        	//
		total_bytes_read = fread(&rom_info->hdr, 1, sizeof(nds_rom_hdr_t), rom_file);
        	if (total_bytes_read != sizeof(nds_rom_hdr_t))
        	{
			res = -1;
			break;
		}

		icon_title_offset = endian_32(rom_info->hdr.icon_title_off);
		if (icon_title_offset != 0 )
		{
			if (fseek(rom_file, icon_title_offset, SEEK_SET))
			{
				res = -1;
				break;
			}
			if ((fread(&rom_info->icon, sizeof(nds_rom_icon_title_t), 1, rom_file)) != 1)
			{
				res = -1;
				break;
			}
		}

		break;
	}
	while (0);

	return (res);
}

/***************************************************************************
 * get_romstring_size
 ***************************************************************************/
uint CNDSromScanner::get_romstring_size(uint8_t * s, uint max)
{
	uint	res;

	for (res = 0; res < max; res ++)
	{
		if (s[res] == 0)
		{
			break;
		}
	}
	
	return (res);
}

/***************************************************************************
 * 
 * SLOTS
 * 
 ***************************************************************************/

/***************************************************************************
 * Status
 ***************************************************************************/
void CNDSromScanner::Status(QString s, uint delay)
{
	emit StatusChanged(s, delay);
}

/***************************************************************************
 * 
 ***************************************************************************/
