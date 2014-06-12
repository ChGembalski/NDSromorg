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

#ifndef NDS_BGR555_H
#define NDS_BGR555_H

/***************************************************************************
 * include
 ***************************************************************************/
#include <stdint.h>
#include "NDSrominfo.h"
#include <QString>
#include <QStringList>

/***************************************************************************
 * define
 ***************************************************************************/
#if __BYTE_ORDER == __LITTLE_ENDIAN
#  define pixel_16(a) ((((uint16_t)(a) & 0xff00) >> 8) | \
                        (((uint16_t)(a) & 0x00ff) << 8))
#else // __BYTE_ORDER == __BIG_ENDIAN
#  define pixel_16(a) a
#endif

/***************************************************************************
 * SNDSbgr555
 ***************************************************************************/
struct tile
{
	uint8_t		row1[4];
	uint8_t		row2[4];
	uint8_t		row3[4];
	uint8_t		row4[4];
	uint8_t		row5[4];
	uint8_t		row6[4];
	uint8_t		row7[4];
	uint8_t		row8[4];
};

struct tileimage
{
	tile		row1[4];	
	tile		row2[4];	
	tile		row3[4];	
	tile		row4[4];	
};

struct bgr555
{
	uint8_t		B;
	uint8_t		G;
	uint8_t		R;
};

/***************************************************************************
 * CNDSbgr555
 ***************************************************************************/
class CNDSbgr555
{
public:
	CNDSbgr555();
	~CNDSbgr555();

	QString createIcon(nds_rom_icon_title_t * icon);

private:
	//SNDSbgr555	raw[0x100];
	
	tileimage	raw_img;
	bgr555		raw_palette[16];

	void readTile(uint8_t * data, tile * t);
	void readTileimage(uint8_t * data, tileimage * ti);
	void readBGR555(uint16_t * data, bgr555 * palette);
	void writeXPM(tileimage * ti, bgr555 * palette, QString *xpm);
	void writeXPMheader(QString *xpm);
	void writeXPMfooter(QString *xpm);
	void writeXPMpalette(bgr555 * palette, QString *xpm);
	void writeXPMimage(tileimage * ti, QString *xpm);
	void writeXPMtile(tile * ti, uint row, QString *xpm);
	void writeXPM(tileimage * ti, bgr555 * palette, QStringList *xpm);
	void writeXPMheader(QStringList *xpm);
	void writeXPMpalette(bgr555 * palette, QStringList *xpm);
	void writeXPMimage(tileimage * ti, QStringList *xpm);
};

/***************************************************************************
 * 
 ***************************************************************************/

#endif // NDS_BGR555_H
