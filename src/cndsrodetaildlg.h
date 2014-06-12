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

#ifndef CNDSRODETAILDLG_H
#define CNDSRODETAILDLG_H

/***************************************************************************
 * include
 ***************************************************************************/
#include <QDialog>
#include "ui_NDSROdetailDlg.h"
#include "NDSromData.h"
#include <QLabel>
#include "QClickableLabel.h"
#include <QList>
#include "NDSdbIfc.h"
#include <QPixmap>
#include <QImage>

/***************************************************************************
 * 
 ***************************************************************************/

/***************************************************************************
 * CNDSROdetailDlg
 ***************************************************************************/
class CNDSROdetailDlg : public QDialog, public Ui::Dialog
{
	Q_OBJECT

public:
	CNDSROdetailDlg(CNDSdbIfc * dbifc, QWidget* parent = 0, Qt::WFlags fl = 0);
	~CNDSROdetailDlg();
	/*$PUBLIC_FUNCTIONS$*/

	void showROM(CNDSromData * rd, bool enableSave);

public slots:
	/*$PUBLIC_SLOTS$*/

protected:
	/*$PROTECTED_FUNCTIONS$*/
	bool event(QEvent *event);

protected slots:
	/*$PROTECTED_SLOTS$*/

private:
	bool				m_InitDone;
	QList<QClickableLabel *>	m_THUMBlist;
	CNDSdbIfc *			m_DBIfc;
	CNDSromData *			m_ROM;
	QGridLayout *			m_THUMBgrid;
	int				m_THUMBpos;
	bool				m_EnableSave;

	void Init();
	void connectActions();
	void romDataToGui(CNDSromData * rd);
	void romDataFromGui(CNDSromData * rd);
	void showIMG(const QPixmap * pixmap);
	void showIMG(const QImage * tmpIMG);
	bool checkIMGloading(CNDSromData * rd);

private slots:
	void THUMB_clicked(QClickableLabel * item);
	void CMD_clicked (QAbstractButton * button);
	void CreateNextTHUMB();
	void CMD_THUMB_LEFT_clicked();
	void CMD_THUMB_RIGHT_clicked();
	void CMDcode_clicked();
};

/***************************************************************************
 * 
 ***************************************************************************/

#endif

