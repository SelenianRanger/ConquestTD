#include <QGraphicsObject>
#include <QPixmap>
#include <QPainter>
#include <QSize>
#include <QPen>
#include <QRectF>
#include <QDebug>

#include "AbstractCard.h"
#include "src/Assests/Cards/CardInfo.h"
#include "src/Controller/ResourceManager.h"

AbstractCard::AbstractCard(QGraphicsObject *parent, QString *name, ResourceManager *resources, int id, CardInfo *card_info)
	:QGraphicsObject(parent),  _id(id), _name(name), _card_info(card_info), _selected(false), _selectable(true), _size(new QSize())
{
	connect(resources, SIGNAL(cardIconSent(int, QPixmap*)), this, SLOT(setIcon(int, QPixmap*)));
	resources->getCardIcon(id);

	setAcceptHoverEvents(true);

	connect(this, SIGNAL(clicked()), this, SLOT(toggleSelected()));
}

AbstractCard::~AbstractCard()
{
}

CardInfo* AbstractCard::info()
{
	return _card_info;
}

bool AbstractCard::isSelected()
{
	return _selected;
}

bool AbstractCard::isSelectable()
{
	return _selectable;
}

void AbstractCard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawPixmap(QRect(0, 0, _size->width(), _size->height()), *_icon);
	if (isSelected()) {
		painter->setPen(QPen(Qt::yellow, _size->height() / 100));
		painter->drawRect( 0, 0,_size->width(),  _size->height());
		painter->setPen(QPen());
	}
}

void AbstractCard::setIconSize(int w, int h)
{
	_size->setWidth(w);
	_size->setHeight(h);
	update();
}

void AbstractCard::setIconSize(QSize& size)
{
	_size->setWidth(size.width());
	_size->setHeight(size.height());
	update();
}

QPixmap * AbstractCard::icon()
{
	return _icon;
}

QRectF AbstractCard::boundingRect() const
{
	return QRectF(QPoint(0, 0), QPoint(_size->width(), _size->height()));
}

void AbstractCard::setSelectable(bool value)
{
	_selectable = value;
}

void AbstractCard::toggleSelected()
{
	if (!_selected && _selectable) {
		_selected = true;
		update();
		emit updated();
		emit selected();
	}
	else if (_selected) {
		_selected = false;
		update();
		emit updated();
	}
}

void AbstractCard::setSelected(bool value)
{
	_selected = value;
	update();
}

void AbstractCard::setIcon(int id, QPixmap *icon)
{
	if (id == _id) {
		_icon = icon;
		_size->setWidth(icon->width());
		_size->setHeight(icon->height());
	}
}

void AbstractCard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	emit clicked();
}

void AbstractCard::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	emit hoverPreview(_card_info);
}

void AbstractCard::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	emit stopPreview();
}