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

#include "NDStransfer.h"
#include "NDSdebug.h"
#include <QFile>
#include <QByteArray>

/***************************************************************************
 * CTor
 ***************************************************************************/
CNDStransfer::CNDStransfer(CNDSdbIfc * dbifc)
: QObject()
{
	this->m_DBIfc = dbifc;
}

/***************************************************************************
 * DTor
 ***************************************************************************/
CNDStransfer::~CNDStransfer()
{
}

/***************************************************************************
 * 
 * PUBLIC
 * 
 ***************************************************************************/

/***************************************************************************
 * exportROMlist
 ***************************************************************************/
int CNDStransfer::exportROMlist(QString fname, QList<CNDSromData> * list)
{
	int			export_count;
	QFile *			f;
	QXmlStreamWriter *	xml;

	export_count = 0;
	f = NULL;
	xml = NULL;

	if (list == NULL)
		return (TRANSFER_ERROR);

	// Create output file
	f = new QFile(fname);
	if (!f->open(QIODevice::WriteOnly))
	{
		emit Status("Fehler beim Erstellen: " + fname, 2000);
		delete f;
		f = NULL;
		return (TRANSFER_ERROR);
	}

	// Create XML
	xml = new QXmlStreamWriter(f);
	xml->setCodec("UTF-8");
	xml->setAutoFormatting(true);

	// Header
	xml->writeStartDocument(TRANSFER_XML_VERSION);
	xml->writeStartElement(TRANSFER_XML_HEADER_ROMLIST);

	// Each Entry separate
	foreach (CNDSromData rd, *list)
	{
		export_count += exportROMlistEntry(xml, &rd);
	}

	xml->writeEndElement();
	xml->writeEndDocument();

	// Cleanup
	delete xml;
	xml = NULL;

	f->flush();
	f->close();

	delete f;
	f = NULL;

	emit Status("Export beendet.", 2000);

	return (export_count);
}

/***************************************************************************
 * exportROMfiles
 ***************************************************************************/
int CNDStransfer::exportROMfiles(QString fname, QList<CNDSromData> * list, uint * invalid)
{
	if (list == NULL)
		return (TRANSFER_ERROR);

	return (TRANSFER_ERROR);
}

/***************************************************************************
 * exportIMGlist
 ***************************************************************************/
int CNDStransfer::exportIMGlist(QString fname)
{
	int			export_count;
	QFile *			f;
	QXmlStreamWriter *	xml;
	QList<SNDSromPicture>	imgList;
	QString			s;

	export_count = 0;
	f = NULL;
	xml = NULL;
	s = "";

	// Create output file
	f = new QFile(fname);
	if (!f->open(QIODevice::WriteOnly))
	{
		emit Status("Fehler beim Erstellen: " + fname, 2000);
		delete f;
		f = NULL;
		return (TRANSFER_ERROR);
	}

	// Create XML
	xml = new QXmlStreamWriter(f);
	xml->setCodec("UTF-8");
	xml->setAutoFormatting(true);

	// Header
	xml->writeStartDocument(TRANSFER_XML_VERSION);
	xml->writeStartElement(TRANSFER_XML_HEADER_IMGLIST);

	// Prepare List
	this->m_DBIfc->readIMAGES(&imgList);

	// Each Entry separate
	foreach (SNDSromPicture rp, imgList)
	{
		QByteArray	bArray;

		// Header
		xml->writeStartElement(TRANSFER_XML_HEADER_IMGLIST_ENTRY);

		// Elements
		xml->writeTextElement(TRANSFER_XML_IMGLIST_ENTRY_CODE, rp.ROMcode);
		s.setNum(rp.No);
		xml->writeTextElement(TRANSFER_XML_IMGLIST_ENTRY_NO, s);
		s.setNum(rp.crc32);
		xml->writeTextElement(TRANSFER_XML_IMGLIST_ENTRY_CRC32, s);
		// Img Data
		if (this->m_DBIfc->readIMAGE(&bArray, &rp))
		{
			xml->writeTextElement(TRANSFER_XML_IMGLIST_ENTRY_PIXMAP, QString::fromAscii(bArray.toBase64().data()));
			export_count++;
		}
		
		xml->writeEndElement();
	}

	xml->writeEndElement();
	xml->writeEndDocument();

	// Cleanup
	delete xml;
	xml = NULL;

	f->flush();
	f->close();

	delete f;
	f = NULL;

	emit Status("Export beendet.", 2000);

	return (export_count);
}

/***************************************************************************
 * importROMlist
 ***************************************************************************/
int CNDStransfer::importROMlist(QString fname, QList<CNDSromData> * list, uint * invalid, QList<CNDSromData> * invlist)
{
	int			import_count;
	QFile *			f;
	QXmlStreamReader *	xml;

	import_count = 0;
	f = NULL;
	xml = NULL;

	if (!QFile::exists(fname))
		return (TRANSFER_ERROR);
	if (list == NULL)
		return (TRANSFER_ERROR);

	// open output file
	f = new QFile(fname);
	if (!f->open(QIODevice::ReadOnly))
	{
		emit Status("Fehler beim Zugriff: " + fname, 2000);
		delete f;
		f = NULL;
		return (TRANSFER_ERROR);
	}

	// Create XML
	xml = new QXmlStreamReader(f);

	while (!xml->atEnd()) 
	{
		xml->readNext();

		DBG("importROMlist:" << xml->qualifiedName().toString());
		if (xml->isStartElement())
		{
			if (xml->qualifiedName().toString() == TRANSFER_XML_HEADER_ROMLIST)
			{
				import_count = this->importROMlistV1(xml, list, invalid, invlist);
			}
		}
		if (xml->isEndElement())
		{
			if (xml->qualifiedName().toString() == TRANSFER_XML_HEADER_ROMLIST)
			{
				DBG("importROMlist: EO TRANSFER_XML_HEADER_ROMLIST");
			}
		}
	}

	if (xml->hasError())
	{
		emit Status("XML Error:" + xml->errorString(), 2000);
	}

	// Cleanup
	f->close();
	delete f;
	f = NULL;

	delete xml;
	xml = NULL;

	return (import_count);
}

/***************************************************************************
 * importROMfiles
 ***************************************************************************/
int CNDStransfer::importROMfiles(QString fname, QList<CNDSromData> * list, uint * invalid, QList<CNDSromData> * invlist)
{

	if (!QFile::exists(fname))
		return (TRANSFER_ERROR);
	if (list == NULL)
		return (TRANSFER_ERROR);

	return (TRANSFER_ERROR);
}

/***************************************************************************
 * importIMGlist
 ***************************************************************************/
int CNDStransfer::importIMGlist(QString fname, uint * invalid)
{
	int			import_count;
	QFile *			f;
	QXmlStreamReader *	xml;

	import_count = 0;
	f = NULL;
	xml = NULL;

	if (!QFile::exists(fname))
		return (TRANSFER_ERROR);

	// open output file
	f = new QFile(fname);
	if (!f->open(QIODevice::ReadOnly))
	{
		emit Status("Fehler beim Zugriff: " + fname, 2000);
		delete f;
		f = NULL;
		return (TRANSFER_ERROR);
	}

	// Create XML
	xml = new QXmlStreamReader(f);

	while (!xml->atEnd()) 
	{
		xml->readNext();

		DBG("importIMGlist:" << xml->qualifiedName().toString());
		if (xml->isStartElement())
		{
			if (xml->qualifiedName().toString() == TRANSFER_XML_HEADER_IMGLIST)
			{
				import_count = this->importIMGlistV1(xml, invalid);
			}
		}
		if (xml->isEndElement())
		{
			if (xml->qualifiedName().toString() == TRANSFER_XML_HEADER_IMGLIST)
			{
				DBG("importIMGlist: EO TRANSFER_XML_HEADER_IMGLIST");
			}
		}
	}

	if (xml->hasError())
	{
		emit Status("XML Error:" + xml->errorString(), 2000);
	}

	// Cleanup
	f->close();
	delete f;
	f = NULL;

	delete xml;
	xml = NULL;

	return (import_count);
}

/***************************************************************************
 * 
 * PROTECTED
 * 
 ***************************************************************************/

/***************************************************************************
 * 
 ***************************************************************************/

/***************************************************************************
 * 
 * PRIVATE
 * 
 ***************************************************************************/

/***************************************************************************
 * exportROMlistEntry
 ***************************************************************************/
int CNDStransfer::exportROMlistEntry(QXmlStreamWriter * xml, CNDSromData * rd)
{
	int	i;
	QString	s;

	i = 0;
	s = "";

	if (xml == NULL)
		return (0);
	if (rd == NULL)
		return (0);

	emit Status("Export :" + rd->ROMname);

	// Header
	xml->writeStartElement(TRANSFER_XML_HEADER_ROMLIST_ENTRY);

	// Elements
	xml->writeTextElement(TRANSFER_XML_ROMLIST_ENTRY_DISPLNAME, rd->ROMdisplname);
	xml->writeTextElement(TRANSFER_XML_ROMLIST_ENTRY_NAME, rd->ROMname);
	s.setNum(rd->ROMversion);
	xml->writeTextElement(TRANSFER_XML_ROMLIST_ENTRY_VERSION, s);
	xml->writeTextElement(TRANSFER_XML_ROMLIST_ENTRY_SERIAL, rd->ROMserial);
	xml->writeTextElement(TRANSFER_XML_ROMLIST_ENTRY_CODE, rd->ROMcode);
	xml->writeTextElement(TRANSFER_XML_ROMLIST_ENTRY_PUBLISHER, rd->ROMpublisher);
	s.setNum(rd->ROMfilesize);
	xml->writeTextElement(TRANSFER_XML_ROMLIST_ENTRY_FILESIZE, s);
	xml->writeTextElement(TRANSFER_XML_ROMLIST_ENTRY_UNITCODE, rd->ROMunitcode);
	s.setNum(rd->ROMcrc32);
	xml->writeTextElement(TRANSFER_XML_ROMLIST_ENTRY_CRC32, s);
	s.setNum(rd->ROMcapacity);
	xml->writeTextElement(TRANSFER_XML_ROMLIST_ENTRY_CAPACITY, s);
	xml->writeTextElement(TRANSFER_XML_ROMLIST_ENTRY_COMMENT, rd->ROMcomment);
	// Languages
	xml->writeStartElement(TRANSFER_XML_ROMLIST_ENTRY_LANGUAGE);
	for (i=0; i<EOLanguage; i++)
	{
		s.setNum(i);
		xml->writeTextElement(TRANSFER_XML_ROMLIST_LANGUAGE_ID, s);
		xml->writeTextElement(TRANSFER_XML_ROMLIST_LANGUAGE_NAME, rd->ROMlanguage[i].Name);
		xml->writeTextElement(TRANSFER_XML_ROMLIST_LANGUAGE_SUBNAME, rd->ROMlanguage[i].SubName);
		xml->writeTextElement(TRANSFER_XML_ROMLIST_LANGUAGE_PUBLISHER, rd->ROMlanguage[i].Publisher);
	}
	xml->writeEndElement();
	// Icon
	xml->writeTextElement(TRANSFER_XML_ROMLIST_ENTRY_ICON, rd->getROMiconBase64());

	xml->writeEndElement();

	return (1);
}

/***************************************************************************
 * importROMlistV1
 ***************************************************************************/
int CNDStransfer::importROMlistV1(QXmlStreamReader * xml, QList<CNDSromData> * list, uint * invalid, QList<CNDSromData> * invlist)
{
	int	import_count;

	import_count = 0;

	if (xml == NULL)
		return (TRANSFER_ERROR);
	if (list == NULL)
		return (TRANSFER_ERROR);

	while (!xml->atEnd()) 
	{
		xml->readNext();

		DBG("importROMlistV1:" << xml->qualifiedName().toString());
		if (xml->isStartElement())
		{
			if (xml->qualifiedName().toString() == TRANSFER_XML_HEADER_ROMLIST_ENTRY)
			{
				CNDSromData	rd;
				int		res;

				res = this->importROMlistEntryV1(xml, &rd);
				if (res)
				{
					// Set isROM
					rd.isROM = true;

					if (!this->m_DBIfc->existROM(&rd))
					{
						// Insert into DB
						if (this->m_DBIfc->writeROM(&rd))
						{
							import_count += res;
							list->append(rd);
						}
						else
						{
							rd.ROMstate = STATE_NONE;
							if ((invalid != NULL) && (invlist != NULL))
							{
								(*invalid)++;
								rd.ROMid = -(*invalid);
								invlist->append(rd);
							}
						}
					}
					else
					{
						rd.ROMstate = STATE_CRC32;
						if ((invalid != NULL) && (invlist != NULL))
						{
							(*invalid)++;
							rd.ROMid = -(*invalid);
							invlist->append(rd);
						}
					}
				}
				else
				{
					rd.ROMstate = STATE_NONE;
					if ((invalid != NULL) && (invlist != NULL))
					{
						(*invalid)++;
						rd.ROMid = -(*invalid);
						invlist->append(rd);
					}
				}
			}
		}
		if (xml->isEndElement())
		{
			if (xml->qualifiedName().toString() == TRANSFER_XML_HEADER_ROMLIST)
			{
				DBG("importROMlistV1:EO TRANSFER_XML_HEADER_ROMLIST");
				break;
			}
		}
	}

	if (xml->hasError())
	{
		emit Status("XML Error:" + xml->errorString(), 2000);
	}

	return (import_count);
}

/***************************************************************************
 * importROMlistEntryV1
 ***************************************************************************/
int CNDStransfer::importROMlistEntryV1(QXmlStreamReader * xml, CNDSromData * rd)
{
	QString	s;

	if (xml == NULL)
		return (0);
	if (rd == NULL)
		return (0);

	// Set ROM is Data only
	rd->ROMstate = STATE_ONLY_DATA;

	while (!xml->atEnd()) 
	{
		xml->readNext();

		DBG("importROMlistEntryV1:" << xml->qualifiedName().toString());
		if (xml->isStartElement())
		{
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_ENTRY_DISPLNAME)
			{
				rd->ROMdisplname = xml->readElementText();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_ENTRY_NAME)
			{
				rd->ROMname = xml->readElementText();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_ENTRY_VERSION)
			{
				s = xml->readElementText();
				rd->ROMversion = s.toUInt();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_ENTRY_SERIAL)
			{
				rd->ROMserial = xml->readElementText();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_ENTRY_CODE)
			{
				rd->ROMcode = xml->readElementText();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_ENTRY_PUBLISHER)
			{
				rd->ROMpublisher = xml->readElementText();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_ENTRY_FILESIZE)
			{
				s = xml->readElementText();
				rd->ROMfilesize = s.toUInt();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_ENTRY_UNITCODE)
			{
				rd->ROMunitcode = xml->readElementText();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_ENTRY_CRC32)
			{
				s = xml->readElementText();
				rd->ROMcrc32 = s.toUInt();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_ENTRY_CAPACITY)
			{
				s = xml->readElementText();
				rd->ROMcapacity = s.toUInt();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_ENTRY_COMMENT)
			{
				rd->ROMcomment = xml->readElementText();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_ENTRY_LANGUAGE)
			{
				importROMlistEntryV1lang(xml, rd);
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_ENTRY_ICON)
			{
				s = xml->readElementText();
				rd->setROMiconBase64(&s);
			}
		}
		if (xml->isEndElement())
		{
			if (xml->qualifiedName().toString() == TRANSFER_XML_HEADER_ROMLIST_ENTRY)
			{
				DBG("importROMlistEntryV1: EO TRANSFER_XML_HEADER_ROMLIST_ENTRY");
				break;
			}
		}
	}

	return (1);
}

/***************************************************************************
 * importROMlistEntryV1lang
 ***************************************************************************/
int CNDStransfer::importROMlistEntryV1lang(QXmlStreamReader * xml, CNDSromData * rd)
{
	QString	s;
	int	id;

	id = 0;

	if (xml == NULL)
		return (0);
	if (rd == NULL)
		return (0);

	while (!xml->atEnd()) 
	{
		xml->readNext();

		DBG("importROMlistEntryV1lang:" << xml->qualifiedName().toString());
		if (xml->isStartElement())
		{
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_LANGUAGE_ID)
			{
				s = xml->readElementText();
				id = s.toInt();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_LANGUAGE_NAME)
			{
				rd->ROMlanguage[id].Name = xml->readElementText();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_LANGUAGE_SUBNAME)
			{
				rd->ROMlanguage[id].SubName = xml->readElementText();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_LANGUAGE_PUBLISHER)
			{
				rd->ROMlanguage[id].Publisher = xml->readElementText();
			}
		}
		if (xml->isEndElement())
		{
			if (xml->qualifiedName().toString() == TRANSFER_XML_ROMLIST_ENTRY_LANGUAGE)
			{
				DBG("importROMlistEntryV1lang: EO TRANSFER_XML_ROMLIST_ENTRY_LANGUAGE");
				break;
			}
		}
	}

	return (1);
}

/***************************************************************************
 * importIMGlistV1
 ***************************************************************************/
int CNDStransfer::importIMGlistV1(QXmlStreamReader * xml, uint * invalid)
{
	int	import_count;

	import_count = 0;

	if (xml == NULL)
		return (TRANSFER_ERROR);

	while (!xml->atEnd()) 
	{
		xml->readNext();

		DBG("importIMGlistV1:" << xml->qualifiedName().toString());
		if (xml->isStartElement())
		{
			if (xml->qualifiedName().toString() == TRANSFER_XML_HEADER_IMGLIST_ENTRY)
			{
				SNDSromPicture	rp;
				QByteArray	bArray;
				int		res;

				res = this->importIMGlistEntryV1(xml, &rp, &bArray);
				if (res)
				{
					if (!this->m_DBIfc->existIMAGE(&rp))
					{
						// Insert into DB
						if (this->m_DBIfc->writeIMAGE(&rp, &bArray))
						{
							import_count++;
						}
						else
						{
							if (invalid != NULL)
							{
								(*invalid)++;
							}
						}
					}
					else
					{
						if (invalid != NULL)
						{
							(*invalid)++;
						}
					}
				}
				else
				{
					if (invalid != NULL)
					{
						(*invalid)++;
					}
				}
			}
		}
		if (xml->isEndElement())
		{
			if (xml->qualifiedName().toString() == TRANSFER_XML_HEADER_IMGLIST)
			{
				DBG("importIMGlistV1:EO TRANSFER_XML_HEADER_IMGLIST");
				break;
			}
		}
	}

	if (xml->hasError())
	{
		emit Status("XML Error:" + xml->errorString(), 2000);
	}

	return (import_count);
}

/***************************************************************************
 * importIMGlistEntryV1
 ***************************************************************************/
int CNDStransfer::importIMGlistEntryV1(QXmlStreamReader * xml, SNDSromPicture * rp, QByteArray * bArray)
{
	QString	s;

	if (xml == NULL)
		return (0);
	if (rp == NULL)
		return (0);
	if (bArray == NULL)
		return (0);

	while (!xml->atEnd()) 
	{
		xml->readNext();

		DBG("importIMGlistEntryV1:" << xml->qualifiedName().toString());
		if (xml->isStartElement())
		{
			if (xml->qualifiedName().toString() == TRANSFER_XML_IMGLIST_ENTRY_CODE)
			{
				rp->ROMcode = xml->readElementText();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_IMGLIST_ENTRY_NO)
			{
				s = xml->readElementText();
				rp->No = s.toUInt();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_IMGLIST_ENTRY_CRC32)
			{
				s = xml->readElementText();
				rp->crc32 = s.toUInt();
			}
			if (xml->qualifiedName().toString() == TRANSFER_XML_IMGLIST_ENTRY_PIXMAP)
			{
				*bArray = QByteArray::fromBase64(xml->readElementText().toAscii());
			}
		}
		if (xml->isEndElement())
		{
			if (xml->qualifiedName().toString() == TRANSFER_XML_HEADER_IMGLIST_ENTRY)
			{
				DBG("importIMGlistEntryV1: EO TRANSFER_XML_HEADER_IMGLIST_ENTRY");
				break;
			}
		}
	}

	return (1);
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
 * 
 ***************************************************************************/
