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

#ifndef NDSRO_CONFIG_H
#define NDSRO_CONFIG_H

/***************************************************************************
 * include
 ***************************************************************************/
#include <QString>

/***************************************************************************
 * define
 ***************************************************************************/
#define NDSRO_APPNAME		"NDSRO"
#define NDSRO_BASEDIR		".NDSRO"
#define NDSRO_DATADIR		"NDSData"
#define NDSRO_ROMDIR		"NDSRoms"
#define NDSRO_CARDDIR		"NDSCard"
#define NDSRO_CFG_FILE		"NDSRO.cfg"
#define NDSRO_XML_TAG		NDSRO_APPNAME
#define NDSRO_XML_VERSION	"1.0"

#define NDSROF_ROMDIR		1
#define NDSROF_DATADIR		2
#define NDSROF_CARDDIR		3

/***************************************************************************
 * CndsroConfig
 ***************************************************************************/
class CndsroConfig
{
public:
	CndsroConfig();
	~CndsroConfig();

	QString NDS_BASE_dir;
	QString	NDS_ROM_dir;
	QString NDSRO_DATA_dir;
	QString NDS_MEM_CARD_dir;

	bool Validate(void);
	bool CreateDirs(int t);
	bool ReadConfig(void);
	bool WriteConfig(void);

private:
};

/***************************************************************************
 * extern
 ***************************************************************************/
extern CndsroConfig *	NDSROconfig;

#endif // NDSRO_CONFIG_H
