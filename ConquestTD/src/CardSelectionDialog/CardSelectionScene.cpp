#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QList>

#include "CardSelectionScene.h"
#include "src/Controller/CardFactory.h"
#include "src/Controller/ResourceManager.h"
#include "src/Assests/Cards/AbstractCard.h"

CardSelectionScene::CardSelectionScene(QList<AbstractCard*> *cards, QObject *parent)
	:QGraphicsScene(parent), _cards(cards)
{
	int height = (ResourceManager::CardEnd / 4 + 1) * (322 + 10) + 10;
	int width = (230 + 10) * 4 + 10;
	setSceneRect(0, 0, width, height);

	setupLayout();

	_view = new QGraphicsView;
	_view->setScene(this);
	
	_view->setFixedSize(width + 20, 502);

}

CardSelectionScene::~CardSelectionScene()
{
}

void CardSelectionScene::reset()
{
	clear();
	setupLayout();
	update();
}

QGraphicsView* CardSelectionScene::view()
{
	return _view;
}

void CardSelectionScene::setupLayout()
{

	for (int index = 0; index < _cards->size(); index++) {
		AbstractCard *card = _cards->at(index);
		if (index < 8) {
			card->setSelected(true);
		}
		int x = (index % 4) * (230 + 10) + 10;
		int y = (index / 4) * (322 + 10) + 10;
		card->setPos(x, y);
		card->setIconSize(230, 322);
		addItem(card);
	}
}

void CardSelectionScene::drawBackground(QPainter *painter, const QRectF &rect)
{
	painter->setPen(QPen(QBrush(QColor(Qt::darkBlue).lighter()), 5));
	painter->setBrush((QColor(Qt::blue)).darker(500));
	painter->drawRect(sceneRect());
}

void CardSelectionScene::setSelectionLock(bool value)
{
	for (int index = 0; index < _cards->size(); index++) {
		AbstractCard * card = _cards->at(index);
		card->setSelectable(value);
	}
}

void CardSelectionScene::update()
{
	emit updated();
}
