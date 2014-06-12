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

#include "NDSromCRC32.h"
#include "NDSdebug.h"

/***************************************************************************
 * CTor
 ***************************************************************************/
CNDSromCRC32::CNDSromCRC32()
{
}

/***************************************************************************
 * DTor
 ***************************************************************************/
CNDSromCRC32::~CNDSromCRC32()
{
}

/***************************************************************************
 * CNDSromCRC32
 ***************************************************************************/
uint32_t CNDSromCRC32::crc32(uint32_t crc, const void *buf, size_t size)
{
	const uint8_t *p;

	p = (const uint8_t *)buf;
	crc = crc ^ ~0U;

	while (size--)
		crc = crc32_tab[(crc ^ *p++) & 0xFF] ^ (crc >> 8);

	return (crc ^ ~0U);
}

/***************************************************************************
 * crc32fromFile
 ***************************************************************************/
int CNDSromCRC32::crc32fromFile(FILE *rom_file, uint32_t *outcrc32)
{
#define CRC_BUFFER_SIZE  8192

    unsigned char buf[CRC_BUFFER_SIZE];
    size_t bufLen;

    /** accumulate crc32 from file **/
    *outcrc32 = 0;
    while (1) {
        bufLen = fread( buf, 1, CRC_BUFFER_SIZE, rom_file );
        if (bufLen == 0) {
            if (ferror(rom_file)) {
                goto ERR_EXIT;
            }
            break;
        }
        *outcrc32 = CNDSromCRC32::crc32( *outcrc32, buf, bufLen );
    }
    return (0);

    /** error exit **/
ERR_EXIT:
    return (-1);
}

/***************************************************************************
 * 
 ***************************************************************************/
