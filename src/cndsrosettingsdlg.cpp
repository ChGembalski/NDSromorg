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


#include "cndsrosettingsdlg.h"
#include "NDSROconfig.h"


/***************************************************************************
 * CTor
 ***************************************************************************/
CndsroSettingsDlg::CndsroSettingsDlg(QWidget* parent, Qt::WFlags fl)
: QDialog( parent, fl ), Ui::NDSROsettingsDlg()
{
	setupUi(this);

	// Fill in config Data
	m_nds_rom_dir->setText(NDSROconfig->NDS_ROM_dir);
	m_ndsro_data_dir->setText(NDSROconfig->NDSRO_DATA_dir);
	m_nds_memcard_dir->setText(NDSROconfig->NDS_MEM_CARD_dir);
}

/***************************************************************************
 * DTor
 ***************************************************************************/
CndsroSettingsDlg::~CndsroSettingsDlg()
{
}

/***************************************************************************
 * 
 * SLOTS
 * 
 ***************************************************************************/

/***************************************************************************
 * CMD_CANCEL_clicked
 ***************************************************************************/
void CndsroSettingsDlg::CMD_CANCEL_clicked()
{
	this->close();
}

/***************************************************************************
 * CMD_HELP_clicked
 ***************************************************************************/
void CndsroSettingsDlg::CMD_HELP_clicked()
{
}

/***************************************************************************
 * CMD_OK_clicked
 ***************************************************************************/
void CndsroSettingsDlg::CMD_OK_clicked()
{
	QString	RD;
	QString	DD;
	QString	MCD;

	// Backup old Values
	RD = NDSROconfig->NDS_ROM_dir;
	DD = NDSROconfig->NDSRO_DATA_dir;
	MCD = NDSROconfig->NDS_MEM_CARD_dir;
	// Set new Values
	NDSROconfig->NDS_ROM_dir = m_nds_rom_dir->text();
	NDSROconfig->NDSRO_DATA_dir = m_ndsro_data_dir->text();
	NDSROconfig->NDS_MEM_CARD_dir = m_nds_memcard_dir->text();
	// Validate
	if (!NDSROconfig->Validate())
	{
		NDSROconfig->NDS_ROM_dir = RD;
		NDSROconfig->NDSRO_DATA_dir = DD;
		NDSROconfig->NDS_MEM_CARD_dir = MCD;
		return;
	}

	// Save
	if(!NDSROconfig->WriteConfig())
	{
		NDSROconfig->NDS_ROM_dir = RD;
		NDSROconfig->NDSRO_DATA_dir = DD;
		NDSROconfig->NDS_MEM_CARD_dir = MCD;
		return;
	}

	this->close();
}

/***************************************************************************
 * 
 ***************************************************************************/
