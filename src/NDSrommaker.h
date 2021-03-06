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

#ifndef NDS_ROM_MAKER_H
#define NDS_ROM_MAKER_H

#include <stdint.h>

struct mctbl {
	uint8_t		C0;
	uint8_t		C1;
	const char *	Name;
};

static mctbl maker_table [] = {
	{ '0', '1', "Nintendo" },
	{ '0', '2', "Rocket Games, Ajinomoto" },
	{ '0', '3', "Imagineer-Zoom" },
	{ '0', '5', "Zamuse" },
	{ '0', '6', "Falcom" },
	{ '0', '8', "Capcom" },
	{ '0', '9', "Hot B Co." },
	{ '0', 'A', "Jaleco" },
	{ '0', 'B', "Coconuts Japan" },
	{ '0', 'C', "Coconuts Japan/G.X.Media" },
	{ '0', 'E', "Technos" },
	{ '0', 'F', "Mebio Software" },
	{ '0', 'G', "Shouei System" },
	{ '0', 'H', "Starfish" },
	{ '0', 'J', "Mitsui Fudosan/Dentsu" },
	{ '0', 'L', "Warashi Inc." },
	{ '0', 'N', "Nowpro" },
	{ '0', 'P', "Game Village" },
	{ '1', '2', "Infocom" },
	{ '1', '3', "Electronic Arts Japan" },
	{ '1', '5', "Cobra Team" },
	{ '1', '6', "Human/Field" },
	{ '1', '7', "KOEI" },
	{ '1', '8', "Hudson Soft" },
	{ '1', '9', "S.C.P." },
	{ '1', 'A', "Yanoman" },
	{ '1', 'C', "Tecmo Products" },
	{ '1', 'D', "Japan Glary Business" },
	{ '1', 'E', "Forum/OpenSystem" },
	{ '1', 'F', "Virgin Games" },
	{ '1', 'G', "SMDE" },
	{ '1', 'J', "Daikokudenki" },
	{ '1', 'P', "Creatures Inc." },
	{ '1', 'Q', "TDK Deep Impresion" },
	{ '2', '0', "Destination Software, KSS" },
	{ '2', '1', "Sunsoft/Tokai Engineering??" },
	{ '2', '2', "POW, VR 1 Japan??" },
	{ '2', '3', "Micro World" },
	{ '2', '5', "San-X" },
	{ '2', '6', "Enix" },
	{ '2', '7', "Loriciel/Electro Brain" },
	{ '2', '8', "Kemco Japan" },
	{ '2', '9', "Seta" },
	{ '2', 'A', "Culture Brain" },
	{ '2', 'C', "Palsoft" },
	{ '2', 'D', "Visit Co.,Ltd." },
	{ '2', 'E', "Intec" },
	{ '2', 'F', "System Sacom" },
	{ '2', 'G', "Poppo" },
	{ '2', 'H', "Ubisoft Japan" },
	{ '2', 'J', "Media Works" },
	{ '2', 'K', "NEC InterChannel" },
	{ '2', 'L', "Tam" },
	{ '2', 'M', "Jordan" },
	{ '2', 'Q', "Mediakite" },
	{ '3', '0', "Viacom" },
	{ '3', '1', "Carrozzeria" },
	{ '3', '2', "Dynamic" },
	{ '3', '4', "Magifact" },
	{ '3', '5', "Hect" },
	{ '3', '6', "Codemasters" },
	{ '3', '7', "Taito/GAGA Communications" },
	{ '3', '8', "Laguna" },
	{ '3', '9', "Telstar Fun & Games, Event/Taito" },
	{ '3', 'B', "Arcade Zone Ltd" },
	{ '3', 'C', "Entertainment International/Empire Software?" },
	{ '3', 'D', "Loriciel" },
	{ '3', 'E', "Gremlin Graphics" },
	{ '3', 'F', "K.Amusement Leasing Co." },
	{ '4', '0', "Seika Corp." },
	{ '4', '1', "Ubi Soft Entertainment" },
	{ '4', '4', "Life Fitness" },
	{ '4', '6', "System 3" },
	{ '4', '7', "Spectrum Holobyte" },
	{ '4', '9', "IREM" },
	{ '4', 'B', "Raya Systems" },
	{ '4', 'C', "Renovation Products" },
	{ '4', 'D', "Malibu Games" },
	{ '4', 'F', "Eidos (was U.S. Gold <=1995)" },
	{ '4', 'G', "Playmates Interactive?" },
	{ '4', 'J', "Fox Interactive" },
	{ '4', 'K', "Time Warner Interactive" },
	{ '4', 'Q', "Disney Interactive" },
	{ '4', 'S', "Black Pearl" },
	{ '4', 'U', "Advanced Productions" },
	{ '4', 'X', "GT Interactive" },
	{ '4', 'Z', "Crave Entertainment" },
	{ '5', '0', "Absolute Entertainment" },
	{ '5', '1', "Acclaim" },
	{ '5', '2', "Activision" },
	{ '5', '3', "American Sammy" },
	{ '5', '4', "Take 2 Interactive (before it was GameTek)" },
	{ '5', '5', "Hi Tech" },
	{ '5', '6', "LJN LTD." },
	{ '5', '8', "Mattel" },
	{ '5', 'B', "Romstar" },
	{ '5', 'C', "Taxan" },
	{ '5', 'D', "Midway (before it was Tradewest)" },
	{ '5', 'F', "American Softworks" },
	{ '5', 'G', "Majesco Sales Inc" },
	{ '5', 'H', "3DO" },
	{ '5', 'K', "Hasbro" },
	{ '5', 'L', "NewKidCo" },
	{ '5', 'M', "Telegames" },
	{ '5', 'N', "Metro3D" },
	{ '5', 'P', "Vatical Entertainment" },
	{ '5', 'Q', "LEGO Media" },
	{ '5', 'S', "Xicat Interactive" },
	{ '5', 'T', "Cryo Interactive" },
	{ '5', 'W', "Red Storm Entertainment" },
	{ '5', 'X', "Microids" },
	{ '5', 'Z', "Conspiracy/Swing" },
	{ '6', '0', "Titus" },
	{ '6', '1', "Virgin Interactive" },
	{ '6', '2', "Maxis" },
	{ '6', '4', "LucasArts Entertainment" },
	{ '6', '7', "Ocean" },
	{ '6', '9', "Electronic Arts" },
	{ '6', 'B', "Laser Beam" },
	{ '6', 'E', "Elite Systems" },
	{ '6', 'F', "Electro Brain" },
	{ '6', 'G', "The Learning Company" },
	{ '6', 'H', "BBC" },
	{ '6', 'J', "Software 2000" },
	{ '6', 'L', "BAM! Entertainment" },
	{ '6', 'M', "Studio 3" },
	{ '6', 'Q', "Classified Games" },
	{ '6', 'S', "TDK Mediactive" },
	{ '6', 'U', "DreamCatcher" },
	{ '6', 'V', "JoWood Produtions" },
	{ '6', 'W', "SEGA" },
	{ '6', 'X', "Wannado Edition" },
	{ '6', 'Y', "LSP" },
	{ '6', 'Z', "ITE Media" },
	{ '7', '0', "Infogrames" },
	{ '7', '1', "Interplay" },
	{ '7', '2', "JVC" },
	{ '7', '3', "Parker Brothers" },
	{ '7', '5', "Sales Curve" },
	{ '7', '8', "THQ" },
	{ '7', '9', "Accolade" },
	{ '7', 'A', "Triffix Entertainment" },
	{ '7', 'C', "Microprose Software" },
	{ '7', 'D', "Universal Interactive, Sierra, Simon & Schuster?" },
	{ '7', 'F', "Kemco" },
	{ '7', 'G', "Rage Software" },
	{ '7', 'H', "Encore" },
	{ '7', 'J', "Zoo Digital Publishing" },
	{ '7', 'K', "BVM" },
	{ '7', 'L', "Simon & Schuster Interactive" },
	{ '7', 'M', "Asmik Ace Entertainment Inc./AIA" },
	{ '7', 'Q', "Jester Interactive" },
	{ '7', 'T', "Scholastic" },
	{ '7', 'U', "Ignition Entertainment" },
	{ '7', 'W', "Stadlbauer" },
	{ '8', '0', "Misawa" },
	{ '8', '1', "Teichiku" },
	{ '8', '2', "Namco Ltd." },
	{ '8', '3', "LOZC" },
	{ '8', '4', "KOEI" },
	{ '8', '6', "Tokuma Shoten Intermedia" },
	{ '8', '7', "Tsukuda Original" },
	{ '8', '8', "DATAM-Polystar" },
	{ '8', 'B', "Bulletproof Software" },
	{ '8', 'C', "Vic Tokai Inc." },
	{ '8', 'E', "Character Soft" },
	{ '8', 'F', "I'Max" },
	{ '8', 'G', "Saurus" },
	{ '8', 'J', "General Entertainment" },
	{ '8', 'N', "Success" },
	{ '8', 'P', "SEGA Japan" },
	{ '9', '0', "Takara Amusement" },
	{ '9', '1', "Chun Soft" },
	{ '9', '3', "BEC" },
	{ '9', '5', "Varie" },
	{ '9', '6', "Yonezawa/S'pal" },
	{ '9', '7', "Kaneko" },
	{ '9', '9', "Victor Interactive Software, Pack in Video" },
	{ '9', 'A', "Nichibutsu/Nihon Bussan" },
	{ '9', 'B', "Tecmo" },
	{ '9', 'C', "Imagineer" },
	{ '9', 'F', "Nova" },
	{ '9', 'G', "Den'Z" },
	{ '9', 'H', "Bottom Up" },
	{ '9', 'J', "TGL" },
	{ '9', 'N', "Marvelous Entertainment" },
	{ '9', 'P', "Keynet Inc." },
	{ '9', 'Q', "Hands-On Entertainment" },
	{ 'A', '0', "Telenet" },
	{ 'A', '1', "Hori" },
	{ 'A', '4', "Konami" },
	{ 'A', '5', "K.Amusement Leasing Co." },
	{ 'A', '6', "Kawada" },
	{ 'A', '7', "Takara" },
	{ 'A', '9', "Technos Japan Corp." },
	{ 'A', 'A', "JVC, Victor Musical Indutries" },
	{ 'A', 'C', "Toei Animation" },
	{ 'A', 'D', "Toho" },
	{ 'A', 'F', "Namco" },
	{ 'A', 'G', "Media Rings Corporation" },
	{ 'A', 'H', "J-Wing" },
	{ 'A', 'J', "Pioneer LDC" },
	{ 'A', 'K', "KID" },
	{ 'A', 'L', "Mediafactory" },
	{ 'A', 'P', "Infogrames Hudson" },
	{ 'A', 'Q', "Kiratto. Ludic Inc" },
	{ 'B', '0', "Acclaim Japan" },
	{ 'B', '1', "ASCII" },
	{ 'B', '2', "Bandai" },
	{ 'B', '4', "Enix" },
	{ 'B', '6', "HAL Laboratory" },
	{ 'B', '7', "SNK" },
	{ 'B', '9', "Pony Canyon" },
	{ 'B', 'A', "Culture Brain" },
	{ 'B', 'B', "Sunsoft" },
	{ 'B', 'C', "Toshiba EMI" },
	{ 'B', 'D', "Sony Imagesoft" },
	{ 'B', 'F', "Sammy" },
	{ 'B', 'G', "Magical" },
	{ 'B', 'H', "Visco" },
	{ 'B', 'J', "Compile " },
	{ 'B', 'L', "MTO Inc." },
	{ 'B', 'N', "Sunrise Interactive" },
	{ 'B', 'P', "Global A Entertainment" },
	{ 'B', 'Q', "Fuuki" },
	{ 'C', '0', "Taito" },
	{ 'C', '2', "Kemco" },
	{ 'C', '3', "Square" },
	{ 'C', '4', "Tokuma Shoten" },
	{ 'C', '5', "Data East" },
	{ 'C', '6', "Tonkin House (was Tokyo Shoseki)" },
	{ 'C', '8', "Koei" },
	{ 'C', 'A', "Konami/Ultra/Palcom" },
	{ 'C', 'B', "NTVIC/VAP" },
	{ 'C', 'C', "Use Co.,Ltd." },
	{ 'C', 'D', "Meldac" },
	{ 'C', 'E', "Pony Canyon" },
	{ 'C', 'F', "Angel, Sotsu Agency/Sunrise" },
	{ 'C', 'J', "Boss" },
	{ 'C', 'G', "Yumedia/Aroma Co., Ltd" },
	{ 'C', 'K', "Axela/Crea-Tech?" },
	{ 'C', 'M', "Konami Computer Entertainment Osaka" },
	{ 'C', 'P', "Enterbrain" },
	{ 'D', '0', "Taito/Disco" },
	{ 'D', '1', "Sofel" },
	{ 'D', '2', "Quest, Bothtec" },
	{ 'D', '4', "Ask Kodansha" },
	{ 'D', '6', "Naxat" },
	{ 'D', '7', "Copya System" },
	{ 'D', '8', "Capcom Co., Ltd." },
	{ 'D', '9', "Banpresto" },
	{ 'D', 'A', "TOMY" },
	{ 'D', 'B', "LJN Japan" },
	{ 'D', 'D', "NCS" },
	{ 'D', 'E', "Human Entertainment" },
	{ 'D', 'F', "Altron" },
	{ 'D', 'H', "Gaps Inc." },
	{ 'D', 'N', "Elf" },
	{ 'E', '0', "Jaleco" },
	{ 'E', '2', "Yutaka" },
	{ 'E', '3', "Varie" },
	{ 'E', '4', "T&ESoft" },
	{ 'E', '5', "Epoch" },
	{ 'E', '7', "Athena" },
	{ 'E', '8', "Asmik" },
	{ 'E', '9', "Natsume" },
	{ 'E', 'A', "King Records" },
	{ 'E', 'B', "Atlus" },
	{ 'E', 'C', "Epic/Sony Records" },
	{ 'E', 'E', "IGS" },
	{ 'E', 'G', "Chatnoir" },
	{ 'E', 'H', "Right Stuff" },
	{ 'E', 'L', "Spike" },
	{ 'E', 'M', "Konami Computer Entertainment Tokyo" },
	{ 'E', 'N', "Alphadream Corporation" },
	{ 'F', '0', "A Wave" },
	{ 'F', '1', "Motown Software" },
	{ 'F', '2', "Left Field Entertainment" },
	{ 'F', '3', "Extreme Ent. Grp." },
	{ 'F', '4', "TecMagik" },
	{ 'F', '9', "Cybersoft" },
	{ 'F', 'B', "Psygnosis" },
	{ 'F', 'E', "Davidson/Western Tech." },
	{ 'G', '1', "PCCW Japan" },
	{ 'G', '4', "KiKi Co Ltd" },
	{ 'G', '6', "Sims" },
	{ 'G', '7', "Broccoli" },
	{ 'G', '8', "Avex" },
	{ 'G', '9', "D3 Publisher" },
	{ 'G', 'B', "Konami Computer Entertainment Japan" },
	{ 'G', 'D', "Square-Enix" },
	{ 'I', 'H', "Yojigen" },
//	{'', '', ""},
	{0, 0, NULL}
};

#endif // NDS_ROM_MAKER_H
