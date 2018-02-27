#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>

#include "CreditBar.h"
#include "src/Assests/Cards/CardInfo.h"

CreditBar::CreditBar(QObject *parent)
	:QGraphicsScene(parent), _credits(0), _preview(false)
{
	setSceneRect(0, 0, 200, 30);

	_timer = new QTimer();
	_timer->setInterval(20);

	connect(_timer, SIGNAL(timeout()), this, SLOT(timedout()));

	_view = new QGraphicsView;
	_view->setScene(this);

	_view->setFixedSize(202, 32);

}

CreditBar::~CreditBar()
{
}

int CreditBar::credits()
{
	return _credits;
}

QGraphicsView* CreditBar::view()
{
	return _view;
}

void CreditBar::setCredits(int credits)
{
	_credits = credits;
	if (_credits % 100 == 0) 
		emit updated(_credits);
	update();
}

void CreditBar::addCredits(int credits)
{
	if (_credits + credits > UPPER_LIMIT)
		_credits = UPPER_LIMIT;
	else
		_credits += credits;
	if (_credits % 100 == 0)
		emit updated(_credits);
	update();
}

void CreditBar::setPreview(CardInfo *info)
{
	_preview = true;
	_preview_info = info;
	qDebug() << _preview_info->cost();
}

void CreditBar::stopPreview()
{
	_preview = false;
}

void CreditBar::start()
{
	_timer->start();
}

void CreditBar::stop()
{
	_timer->stop();
}

void CreditBar::timedout()
{
	addCredits(2);
}

void CreditBar::drawForeground(QPainter *painter, const QRectF &rect)
{
	int count = UPPER_LIMIT / 200;
	int gap = 200 / count;
	painter->setPen(Qt::white);
	painter->drawRect(sceneRect());
	for (int i = 0; i < count; i++) {
		int x = i * (gap) + gap;
		painter->drawLine(x, 0, x, 30);
	}
}

void CreditBar::drawBackground(QPainter *painter, const QRectF &rect)
{
	//Background
	painter->setBrush(Qt::black);
	painter->drawRect(sceneRect());

	//Bar
	int width = (double)_credits / UPPER_LIMIT * 200;
	QRect rct(0, 0, width, 30);
	painter->setBrush(Qt::blue);
	painter->drawRect(rct);

	//Preview
	if (_preview) {
		width = (double)_preview_info->cost() / UPPER_LIMIT * 200;
		QRect rct_prv(0, 0, width, 30);
		QColor c(Qt::white);
		c.setAlpha(150);
		painter->setBrush(c);
		painter->drawRect(rct_prv);
	}
}
