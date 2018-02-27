#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QList>

#include "DeckPreviewScene.h"
#include "src/Assests/Cards/AbstractCard.h"

DeckPreviewScene::DeckPreviewScene(QList<AbstractCard*> *cards, QObject *parent)
	:QGraphicsScene(parent), _cards(cards)
{
	int width = 8 * (135 + 5) + 15;
	setSceneRect(0, 0, width, 200);

	_view = new QGraphicsView;
	_view->setScene(this);

	_view->setFixedSize(802, 220);
}

DeckPreviewScene::~DeckPreviewScene()
{
}

void DeckPreviewScene::reset()
{
	clear();
	update();
}

QGraphicsView* DeckPreviewScene::view()
{
	return _view;
}

void DeckPreviewScene::drawBackground(QPainter *painter, const QRectF &rect)
{
	painter->setBrush((QColor(Qt::magenta)).darker(500));
	painter->drawRect(sceneRect());
}

void DeckPreviewScene::drawForeground(QPainter *painter, const QRectF &rect)
{
	for (int i = 0; i < 8; i++) {
		int x = i * (135 + 5) + 10;
		painter->setPen(Qt::darkYellow);
		painter->setBrush(Qt::black);
		painter->drawRect(x, 5, 135, 190);
	}
	int c = 0;
	for (int i = 0; i < _cards->size(); i++) {
		AbstractCard *card = _cards->at(i);
		if (card->isSelected()) {
			int x = c * (135 + 5) + 10;
			QPixmap *icon = card->icon();

			painter->drawPixmap(QRect(x, 5,135,190), *icon);

			c++;
		}
	}

	if (c == 8)
		emit deckComplete();
	else
		emit deckIncomplete();
}