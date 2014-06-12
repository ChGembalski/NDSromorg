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

#include "QClickableLabel.h"
#include "NDSdebug.h"
#include <QRect>
#include <QMimeData>
#include <QUrl>
#include <QNetworkRequest>

/***************************************************************************
 * CTor
 ***************************************************************************/
QClickableLabel::QClickableLabel(const QString& text, QWidget * parent)
: QLabel(parent)
{
	this->setText(text);
	connect(&m_WebCtrl, SIGNAL(finished(QNetworkReply*)), SLOT(fileDownloaded(QNetworkReply*)));
}



/***************************************************************************
 * DTor
 ***************************************************************************/
QClickableLabel::~QClickableLabel()
{
}

/***************************************************************************
 * 
 * PUBLIC
 * 
 ***************************************************************************/

/***************************************************************************
 * createIMAGE
 ***************************************************************************/
void QClickableLabel::createIMAGE(QPixmap * pixmap, uint X, uint Y)
{
	QRect	r;

	this->setMinimumSize(64, 64);
	this->setMaximumSize(64, 64);
	this->setFrameShape(QFrame::Box);
	this->setFrameShadow(QFrame::Sunken);
	this->setScaledContents(true);
	if (pixmap != NULL)
	{
		this->setPixmap(*pixmap);
		this->setAcceptDrops(false);
		emit pixmapset();
	}
	else
	{
		this->setAcceptDrops(true);
	}

	r = this->geometry();
	r.setLeft(X);
	r.setTop(Y);
	this->setGeometry(r);
}

/***************************************************************************
 * createIMAGE
 ***************************************************************************/
void QClickableLabel::createIMAGE(QImage * img, uint X, uint Y)
{
	QPixmap	pixmap;

	pixmap = QPixmap::fromImage(*img);
	this->createIMAGE(&pixmap, X, Y);
}

/***************************************************************************
 * setPixmapEx
 ***************************************************************************/
void QClickableLabel::setPixmapEx(const QPixmap & pixmap)
{
	this->setPixmap(pixmap);
	if (this->pixmap() != NULL)
	{
		this->setAcceptDrops(false);
		emit pixmapset();
	}
	else
	{
		this->setAcceptDrops(true);
	}
}

/***************************************************************************
 * 
 * PROTECTED
 * 
 ***************************************************************************/

/***************************************************************************
 * mousePressEvent
 ***************************************************************************/
void QClickableLabel::mousePressEvent(QMouseEvent * event)
{
	emit clicked(this);
}

/***************************************************************************
 * dragEnterEvent
 ***************************************************************************/
void QClickableLabel::dragEnterEvent(QDragEnterEvent *event)
{
	event->acceptProposedAction();
	emit changed(event->mimeData());
}

/***************************************************************************
 * dragMoveEvent
 ***************************************************************************/
void QClickableLabel::dragMoveEvent(QDragMoveEvent *event)
{
	event->acceptProposedAction();
}

/***************************************************************************
 * dragLeaveEvent
 ***************************************************************************/
void QClickableLabel::dragLeaveEvent(QDragLeaveEvent *event)
{
	clear();
	event->accept();
}

/***************************************************************************
 * dropEvent
 ***************************************************************************/
void QClickableLabel::dropEvent(QDropEvent *event)
{
    const QMimeData *	mimeData;

	mimeData = event->mimeData();

	DBG("Formats:" << mimeData->formats());

	if (mimeData->hasImage()) 
	{
		DBG("found Image");
		this->setPixmap(qvariant_cast<QPixmap>(mimeData->imageData()));
	}
	else if (mimeData->hasUrls())
	{
		QList<QUrl>	urlList;
		QString		fname;

		DBG("found Urls");

		urlList = mimeData->urls();
		foreach(QUrl u, urlList)
		{
			fname = u.toLocalFile();
			DBG("fname:" << fname);
			if (!fname.isEmpty())
			{
				// treat as image
				this->setPixmap(QPixmap(fname));
			}
			else
			{
				// Download?
				this->download(u);
			}
		}
	}
	else
	{
		DBG("Unsupported format.");
	}

	if (this->pixmap() != NULL)
	{
		this->setAcceptDrops(false);
		emit pixmapset();
	}

	event->acceptProposedAction();
}

/***************************************************************************
 * 
 * PRIVATE
 * 
 ***************************************************************************/

/***************************************************************************
 * download
 ***************************************************************************/
void QClickableLabel::download(QUrl imageUrl)
{
	QNetworkRequest request(imageUrl);
    	this->m_WebCtrl.get(request);
}

/***************************************************************************
 * 
 * SLOTS
 * 
 ***************************************************************************/

/***************************************************************************
 * clear
 ***************************************************************************/
void QClickableLabel::clear()
{
	emit changed();
}

/***************************************************************************
 * fileDownloaded
 ***************************************************************************/
void QClickableLabel::fileDownloaded(QNetworkReply* pReply)
{
	QPixmap	pixmap;

	this->m_DownloadedData = pReply->readAll();
	pReply->deleteLater();

	pixmap.loadFromData(this->m_DownloadedData);
	this->setPixmap(pixmap);

	if (this->pixmap() != NULL)
	{
		this->setAcceptDrops(false);
		emit pixmapset();
	}
}

/***************************************************************************
 * 
 ***************************************************************************/
