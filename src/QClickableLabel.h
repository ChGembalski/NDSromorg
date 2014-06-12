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

#ifndef Q_CLICKABLE_LABEL_H
#define Q_CLICKABLE_LABEL_H

/***************************************************************************
 * include
 ***************************************************************************/
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QMouseEvent>
#include <QMimeData>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QString>
#include <QNetworkAccessManager>
#include <QByteArray>
#include <QNetworkReply>

/***************************************************************************
 * define
 ***************************************************************************/

/***************************************************************************
 * QClickableLabel
 ***************************************************************************/
class QClickableLabel : public QLabel
{
	Q_OBJECT

public:
	explicit QClickableLabel(const QString& text = "", QWidget * parent = 0);
	~QClickableLabel();

	void createIMAGE(QPixmap * pixmap, uint X = 0, uint Y = 0);
	void createIMAGE(QImage * img, uint X = 0, uint Y = 0);
	void setPixmapEx(const QPixmap & pixmap);

public slots:
	void clear();

protected:
	void mousePressEvent(QMouseEvent * event) ;
	void dragEnterEvent(QDragEnterEvent * event);
	void dragMoveEvent(QDragMoveEvent * event);
	void dragLeaveEvent(QDragLeaveEvent * event);
	void dropEvent(QDropEvent * event);

private:
	QNetworkAccessManager	m_WebCtrl;
	QByteArray		m_DownloadedData;

	void download(QUrl imageUrl);

private slots:
	void fileDownloaded(QNetworkReply * pReply);

signals:
	void clicked(QClickableLabel * item);
	void changed(const QMimeData * mimeData = 0);
	void pixmapset();

};

/***************************************************************************
 * 
 ***************************************************************************/

#endif // Q_CLICKABLE_LABEL_H
