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

#include "NDSbgr555.h"
#include "NDSdebug.h"
#include <QPixmap>
#include <QFile>

/***************************************************************************
 * CTor
 ***************************************************************************/
CNDSbgr555::CNDSbgr555()
{
}

/***************************************************************************
 * DTor
 ***************************************************************************/
CNDSbgr555::~CNDSbgr555()
{
}

/***************************************************************************
 * 
 * PUBLIC
 * 
 ***************************************************************************/

/***************************************************************************
 * createIcon
 ***************************************************************************/
QString CNDSbgr555::createIcon(nds_rom_icon_title_t * icon)
{
	uint8_t *	pBMP;
	uint16_t *	pPALETTE;
	QStringList	XPM;

	pBMP = icon->icn_bmp;
	pPALETTE = (uint16_t *)icon->icn_pal;

	// Make tiles
	readTileimage(pBMP, &raw_img);

	// Make Palette
	readBGR555(pPALETTE, &raw_palette[0]);

	// Create XPM
	writeXPM(&raw_img, &raw_palette[0], &XPM);

	TRACE(XPM.join("\n"));

	return (XPM.join("\n"));
}

/***************************************************************************
 * 
 * PRIVATE
 * 
 ***************************************************************************/

/***************************************************************************
 * readTile
 ***************************************************************************/
void CNDSbgr555::readTile(uint8_t * data, tile * t)
{
	int	i;

	for (i=0; i<4; i++)
	{
		t->row1[i] = data[i];
		t->row2[i] = data[i+4];
		t->row3[i] = data[i+8];
		t->row4[i] = data[i+12];
		t->row5[i] = data[i+16];
		t->row6[i] = data[i+20];
		t->row7[i] = data[i+24];
		t->row8[i] = data[i+28];
	}
}

/***************************************************************************
 * readTileimage
 ***************************************************************************/
void CNDSbgr555::readTileimage(uint8_t * data, tileimage * ti)
{
	int	i;

	for (i=0; i<4;  i++)
	{
		readTile(&data[i*32], &ti->row1[i]);
		readTile(&data[i*32+128], &ti->row2[i]);
		readTile(&data[i*32+256], &ti->row3[i]);
		readTile(&data[i*32+384], &ti->row4[i]);
	}
}

/***************************************************************************
 * readBGR555
 ***************************************************************************/
void CNDSbgr555::readBGR555(uint16_t * data, bgr555 * palette)
{
	int	i;

	for (i=0; i<16; i++)
	{
		palette[i].R = (data[i] & 0x001F) * 0x08;
		palette[i].G = ((data[i] & 0x03E0) >> 5) * 0x08;
		palette[i].B = ((data[i] & 0x7C00) >> 10) * 0x08;
	}
}

/***************************************************************************
 * writeXPM
 ***************************************************************************/
void CNDSbgr555::writeXPM(tileimage * ti, bgr555 * palette, QString *xpm)
{
	writeXPMheader(xpm);
	writeXPMpalette(palette, xpm);
	writeXPMimage(ti, xpm);
	writeXPMfooter(xpm);
}

/***************************************************************************
 * writeXPMheader
 ***************************************************************************/
void CNDSbgr555::writeXPMheader(QString *xpm)
{
	*xpm = "/* XPM */\n";
	*xpm += "static char *editcopy[] = {\n";
	*xpm += "/* columns rows colors chars-per-pixel */\n";
	*xpm += "\"32 32 16 1\",\n";
}

/***************************************************************************
 * writeXPMfooter
 ***************************************************************************/
void CNDSbgr555::writeXPMfooter(QString *xpm)
{
	*xpm += "\"\n};\n";
}

/***************************************************************************
 * writeXPMpalette
 ***************************************************************************/
void CNDSbgr555::writeXPMpalette(bgr555 * palette, QString *xpm)
{
	int	i;
	QString	s;

	for (i=0; i<16; i++)
	{
		
		*xpm += "\"" + QString('a' + i) + " c #";
		s.setNum(palette[i].R, 16);
		*xpm += s.rightJustified(2, '0');
		s.setNum(palette[i].G, 16);
		*xpm += s.rightJustified(2, '0');
		s.setNum(palette[i].B, 16);
		*xpm += s.rightJustified(2, '0');
		*xpm += "\",\n";
	}
	*xpm += "/* pixels */\n\"";
}

/***************************************************************************
 * writeXPMimage
 ***************************************************************************/
void CNDSbgr555::writeXPMimage(tileimage * ti, QString *xpm)
{
	int	i;
	int	u;

	

	for (u=0; u<8; u++)
	{
		for (i=0; i<4; i++)
		{
			writeXPMtile(&ti->row1[i], u, xpm);
			if (i==3)
			{
				*xpm += "\",\n\"";
			}
		}
	}

	for (u=0; u<8; u++)
	{
		for (i=0; i<4; i++)
		{
			writeXPMtile(&ti->row2[i], u, xpm);
			if (i==3)
			{
				*xpm += "\",\n\"";
			}
		}
	}

	for (u=0; u<8; u++)
	{
		for (i=0; i<4; i++)
		{
			writeXPMtile(&ti->row3[i], u, xpm);
			if (i==3)
			{
				*xpm += "\",\n\"";
			}
		}
	}

	for (u=0; u<8; u++)
	{
		for (i=0; i<4; i++)
		{
			writeXPMtile(&ti->row4[i], u, xpm);
			if (i==3)
			{
				*xpm += "\",\n\"";
			}
		}
	}

}

/***************************************************************************
 * writeXPMtile
 ***************************************************************************/
void CNDSbgr555::writeXPMtile(tile * ti, uint row, QString *xpm)
{
	int		i;
	uint8_t	*	rd;

	i = 0;
	rd = NULL;

	// Get Row
	switch(row)
	{
	case 0: rd = &ti->row1[0]; break;
	case 1: rd = &ti->row2[0]; break;
	case 2: rd = &ti->row3[0]; break;
	case 3: rd = &ti->row4[0]; break;
	case 4: rd = &ti->row5[0]; break;
	case 5: rd = &ti->row6[0]; break;
	case 6: rd = &ti->row7[0]; break;
	case 7: rd = &ti->row8[0]; break;
	}

	for (i=0; i<4; i++)
	{
		*xpm += QString('a' + (rd[i] & 0xF));
		*xpm += QString('a' + ((rd[i] & 0xF0) >> 4));
	}
}

/***************************************************************************
 * writeXPM
 ***************************************************************************/
void CNDSbgr555::writeXPM(tileimage * ti, bgr555 * palette, QStringList *xpm)
{
	writeXPMheader(xpm);
	writeXPMpalette(palette, xpm);
	writeXPMimage(ti, xpm);
}

/***************************************************************************
 * writeXPMheader
 ***************************************************************************/
void CNDSbgr555::writeXPMheader(QStringList *xpm)
{
	xpm->append("32 32 16 1");
}

/***************************************************************************
 * writeXPMpalette
 ***************************************************************************/
void CNDSbgr555::writeXPMpalette(bgr555 * palette, QStringList *xpm)
{
	int	i;
	QString	s;
	QString	l;

	for (i=0; i<16; i++)
	{
		l = QString('a' + i) + " c #";
		s.setNum(palette[i].R, 16);
		l += s.rightJustified(2, '0');
		s.setNum(palette[i].G, 16);
		l += s.rightJustified(2, '0');
		s.setNum(palette[i].B, 16);
		l += s.rightJustified(2, '0');
		xpm->append(l);
	}
	
}

/***************************************************************************
 * writeXPMimage
 ***************************************************************************/
void CNDSbgr555::writeXPMimage(tileimage * ti, QStringList *xpm)
{
	int	i;
	int	u;
	QString	s;
	
	s = "";
	for (u=0; u<8; u++)
	{
		for (i=0; i<4; i++)
		{
			writeXPMtile(&ti->row1[i], u, &s);
			if (i==3)
			{
				xpm->append(s);
				s = "";
			}
		}
	}

	s = "";
	for (u=0; u<8; u++)
	{
		for (i=0; i<4; i++)
		{
			writeXPMtile(&ti->row2[i], u, &s);
			if (i==3)
			{
				xpm->append(s);
				s = "";
			}
		}
	}

	s = "";
	for (u=0; u<8; u++)
	{
		for (i=0; i<4; i++)
		{
			writeXPMtile(&ti->row3[i], u, &s);
			if (i==3)
			{
				xpm->append(s);
				s = "";
			}
		}
	}

	s = "";
	for (u=0; u<8; u++)
	{
		for (i=0; i<4; i++)
		{
			writeXPMtile(&ti->row4[i], u, &s);
			if (i==3)
			{
				xpm->append(s);
				s = "";
			}
		}
	}
}

/***************************************************************************
 * 
 ***************************************************************************/

/***************************************************************************
 * 
 ***************************************************************************/

/***************************************************************************
 * 
 ***************************************************************************/
