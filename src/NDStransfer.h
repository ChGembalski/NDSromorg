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

#ifndef NDS_TRANSFER_H
#define NDS_TRANSFER_H

/***************************************************************************
 * include
 ***************************************************************************/
#include "NDSdbIfc.h"
#include <QObject>
#include <QString>
#include <QList>
#include "NDSromData.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

/***************************************************************************
 * define
 ***************************************************************************/
#define TRANSFER_ERROR				-1

#define TRANSFER_XML_VERSION			"1.0"

#define TRANSFER_XML_HEADER_ROMLIST		"ROM-List-V1"
#define TRANSFER_XML_HEADER_ROMFILES		"ROM-Dump-V1"
#define TRANSFER_XML_HEADER_IMGLIST		"IMG-List-V1"

#define TRANSFER_XML_HEADER_ROMLIST_ENTRY	"ROM-Data-V1"
#define TRANSFER_XML_HEADER_ROMFILE_ENTRY	"ROM-File-V1"
#define TRANSFER_XML_HEADER_IMGLIST_ENTRY	"IMG-Data-V1"

#define TRANSFER_XML_ROMLIST_ENTRY_DISPLNAME	"ROMdisplname"
#define TRANSFER_XML_ROMLIST_ENTRY_NAME		"ROMname"
#define TRANSFER_XML_ROMLIST_ENTRY_VERSION	"ROMversion"
#define TRANSFER_XML_ROMLIST_ENTRY_SERIAL	"ROMserial"
#define TRANSFER_XML_ROMLIST_ENTRY_CODE		"ROMcode"
#define TRANSFER_XML_ROMLIST_ENTRY_PUBLISHER	"ROMpublisher"
#define TRANSFER_XML_ROMLIST_ENTRY_FILESIZE	"ROMfilesize"
#define TRANSFER_XML_ROMLIST_ENTRY_UNITCODE	"ROMunitcode"
#define TRANSFER_XML_ROMLIST_ENTRY_CRC32	"ROMcrc32"
#define TRANSFER_XML_ROMLIST_ENTRY_CAPACITY	"ROMcapacity"
#define TRANSFER_XML_ROMLIST_ENTRY_COMMENT	"ROMcomment"
#define TRANSFER_XML_ROMLIST_ENTRY_LANGUAGE	"ROMlanguage"
#define TRANSFER_XML_ROMLIST_ENTRY_ICON		"ROMicon"

#define TRANSFER_XML_ROMLIST_LANGUAGE_ID	"Id"
#define TRANSFER_XML_ROMLIST_LANGUAGE_NAME	"Name"
#define TRANSFER_XML_ROMLIST_LANGUAGE_SUBNAME	"SubName"
#define TRANSFER_XML_ROMLIST_LANGUAGE_PUBLISHER	"Publisher"

#define TRANSFER_XML_IMGLIST_ENTRY_CODE		"ROMcode"
#define TRANSFER_XML_IMGLIST_ENTRY_NO		"No"
#define TRANSFER_XML_IMGLIST_ENTRY_CRC32	"crc32"
#define TRANSFER_XML_IMGLIST_ENTRY_PIXMAP	"ROMpixmap"

/***************************************************************************
 * CNDStransfer
 ***************************************************************************/
class CNDStransfer : public QObject
{
	Q_OBJECT

public:
	CNDStransfer(CNDSdbIfc * dbifc);
	~CNDStransfer();

	int exportROMlist(QString fname, QList<CNDSromData> * list);
	int exportROMfiles(QString fname, QList<CNDSromData> * list, uint * invalid = NULL);
	int exportIMGlist(QString fname);

	int importROMlist(QString fname, QList<CNDSromData> * list, uint * invalid = NULL, QList<CNDSromData> * invlist = NULL);
	int importROMfiles(QString fname, QList<CNDSromData> * list, uint * invalid = NULL, QList<CNDSromData> * invlist = NULL);
	int importIMGlist(QString fname, uint * invalid = NULL);
	
public slots:

protected:

protected slots:

private:
	CNDSdbIfc *		m_DBIfc;

	int exportROMlistEntry(QXmlStreamWriter * xml, CNDSromData * rd);

	int importROMlistV1(QXmlStreamReader * xml, QList<CNDSromData> * list, uint * invalid = NULL, QList<CNDSromData> * invlist = NULL);
	int importROMlistEntryV1(QXmlStreamReader * xml, CNDSromData * rd);
	int importROMlistEntryV1lang(QXmlStreamReader * xml, CNDSromData * rd);

	int importIMGlistV1(QXmlStreamReader * xml, uint * invalid = NULL);
	int importIMGlistEntryV1(QXmlStreamReader * xml, SNDSromPicture * rp, QByteArray * bArray);

private slots:

signals:
	void Status(QString s, uint delay = 0);

};

/***************************************************************************
 * 
 ***************************************************************************/

#endif // NDS_TRANSFER_H
