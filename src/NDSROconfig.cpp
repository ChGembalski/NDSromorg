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

#include "NDSROconfig.h"
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

/***************************************************************************
 * global
 ***************************************************************************/
CndsroConfig *	NDSROconfig;

/***************************************************************************
 * CTor
 ***************************************************************************/
CndsroConfig::CndsroConfig()
{
	this->NDS_BASE_dir = QDir::homePath() + QDir::separator() + NDSRO_BASEDIR;
	this->NDS_BASE_dir = QDir::toNativeSeparators(this->NDS_BASE_dir);
	this->NDS_ROM_dir = this->NDS_BASE_dir + QDir::separator() + NDSRO_ROMDIR;
	this->NDSRO_DATA_dir = this->NDS_BASE_dir + QDir::separator() + NDSRO_DATADIR;
	this->NDS_MEM_CARD_dir = this->NDS_BASE_dir + QDir::separator() + NDSRO_CARDDIR;
}

/***************************************************************************
 * DTor
 ***************************************************************************/
CndsroConfig::~CndsroConfig()
{
}

/***************************************************************************
 * 
 * PUBLIC
 * 
 ***************************************************************************/

/***************************************************************************
 * Validate
 ***************************************************************************/
bool CndsroConfig::Validate(void)
{
	QDir d;

	if (this->NDS_ROM_dir != "")
	{
		if (this->CreateDirs(1 << NDSROF_ROMDIR))
		{
			if (!d.exists(this->NDS_ROM_dir))
			{
				return (false);
			}
		}
		else
		{
			return (false);
		}
	}

	if (this->NDSRO_DATA_dir != "")
	{
		if (this->CreateDirs(1 << NDSROF_DATADIR))
		{
			if (!d.exists(this->NDSRO_DATA_dir))
			{
				return (false);
			}
		}
		else
		{
			return (false);
		}
	}

	if (this->NDS_MEM_CARD_dir != "")
	{
		if (this->CreateDirs(1 << NDSROF_CARDDIR))
		{
			if (!d.exists(this->NDS_MEM_CARD_dir))
			{
				return (false);
			}
		}
		else
		{
			return (false);
		}
	}

	return (true);
}

/***************************************************************************
 * CreateDirs
 ***************************************************************************/
bool CndsroConfig::CreateDirs(int t)
{
	QDir	d;
	bool	res;

	res = true;

	// Base Dir create allways
	if (!d.exists(this->NDS_BASE_dir))
	{
		res = d.mkpath(this->NDS_BASE_dir);
		if (!res) 
		{
			QMessageBox::critical(NULL, NDSRO_APPNAME, "Error create:" + this->NDS_BASE_dir);
			return (res);
		}
	}

	if ((t & (1 << NDSROF_ROMDIR)) == (1 << NDSROF_ROMDIR))
	{
		if (!d.exists(this->NDS_ROM_dir))
		{
			res = d.mkpath(this->NDS_ROM_dir);
			if (!res) 
			{
				QMessageBox::critical(NULL, NDSRO_APPNAME, "Error create:" + this->NDS_ROM_dir);
				return (res);
			}
		}
	}

	if ((t & (1 << NDSROF_DATADIR)) == (1 << NDSROF_DATADIR))
	{
		if (!d.exists(this->NDSRO_DATA_dir))
		{
			res = d.mkpath(this->NDSRO_DATA_dir);
			if (!res) 
			{
				QMessageBox::critical(NULL, NDSRO_APPNAME, "Error create:" + this->NDSRO_DATA_dir);
				return (res);
			}
		}
	}

	if ((t & (1 << NDSROF_CARDDIR)) == (1 << NDSROF_CARDDIR))
	{
		if (!d.exists(this->NDS_MEM_CARD_dir))
		{
			res = d.mkpath(this->NDS_MEM_CARD_dir);
			if (!res) 
			{
				QMessageBox::critical(NULL, NDSRO_APPNAME, "Error create:" + this->NDS_MEM_CARD_dir);
				return (res);
			}
		}
	}

	return (res);
}

/***************************************************************************
 * ReadConfig
 ***************************************************************************/
bool CndsroConfig::ReadConfig(void)
{
	QFile			cfgfile;
	bool			res;
	QXmlStreamReader *	xmlr;

	res = true;

	// Have config?
	cfgfile.setFileName(this->NDS_BASE_dir + QDir::separator() + NDSRO_CFG_FILE);
	if (!cfgfile.exists())
	{
		return (false);
	}

	// read Config data
	if (!cfgfile.open(QIODevice::ReadOnly))
	{
		return (false);
	}

	xmlr = new QXmlStreamReader(&cfgfile);
	while (!xmlr->atEnd()) 
	{
		xmlr->readNext();

		if (xmlr->isStartElement())
		{
			if (xmlr->qualifiedName().toString() == NDSRO_DATADIR)
			{
				this->NDSRO_DATA_dir = xmlr->readElementText();
			}
			if (xmlr->qualifiedName().toString() == NDSRO_ROMDIR)
			{
				this->NDS_ROM_dir = xmlr->readElementText();
			}
			if (xmlr->qualifiedName().toString() == NDSRO_CARDDIR)
			{
				this->NDS_MEM_CARD_dir = xmlr->readElementText();
			}
		}
	}
	if (xmlr->hasError())
	{
		QMessageBox::critical(NULL, NDSRO_APPNAME, "XML Error:" + xmlr->errorString());
	}
	
	cfgfile.close();

	delete xmlr;
	xmlr = NULL;

	return (res);
}

/***************************************************************************
 * WriteConfig
 ***************************************************************************/
bool CndsroConfig::WriteConfig(void)
{
	QFile *			cfgfile;
	QXmlStreamWriter *	xmlw;

	// First create base dir
	if (!this->CreateDirs(0))
	{
		return (false);
	}

	// Write Config data

	cfgfile = new QFile(this->NDS_BASE_dir + QDir::separator() + NDSRO_CFG_FILE);
	if (!cfgfile->open(QIODevice::WriteOnly))
	{
		delete cfgfile;
		cfgfile = NULL;
		return (false);
	}

	xmlw = new QXmlStreamWriter(cfgfile);
	xmlw->setCodec("UTF-8");
	xmlw->setAutoFormatting(true);

	xmlw->writeStartDocument(NDSRO_XML_VERSION);
	xmlw->writeStartElement(NDSRO_XML_TAG);
	xmlw->writeTextElement(NDSRO_DATADIR, this->NDSRO_DATA_dir);
	xmlw->writeTextElement(NDSRO_ROMDIR, this->NDS_ROM_dir);
	xmlw->writeTextElement(NDSRO_CARDDIR, this->NDS_MEM_CARD_dir);
	xmlw->writeEndElement();
	xmlw->writeEndDocument();

	delete xmlw;
	xmlw = NULL;

	cfgfile->flush();
	cfgfile->close();

	delete cfgfile;
	cfgfile = NULL;

	return (true);
}

/***************************************************************************
 * 
 ***************************************************************************/
