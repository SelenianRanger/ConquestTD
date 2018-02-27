#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QMessageBox>
#include <QDebug>

#include "DeckScene.h"
#include "src/Assests/Cards/AbstractCard.h"
#include "src/Assests/Cards/CardInfo.h"

DeckScene::DeckScene(QObject *parent)
	:QGraphicsScene(parent), _selected_index(-1)
{
	int height = 4 * (280 + 5) + 5;
	setSceneRect(0, 0, 210, height);

	_view = new QGraphicsView;
	_view->setScene(this);

	_view->setFixedSize(230, 602);
}

DeckScene::~DeckScene()
{
}

void DeckScene::setDeck(QList<AbstractCard*> *deck)
{
	_deck = deck;
	for (int i = 0; i < _deck->size(); i++) {
		AbstractCard *card = _deck->at(i);
		connect(card, SIGNAL(clicked()), this, SLOT(cardClicked()));
		connect(card, SIGNAL(hoverPreview(CardInfo*)), this, SLOT(preview(CardInfo*)));
		connect(card, SIGNAL(stopPreview()), this, SLOT(stopPreview()));
	}

	setupLayout();
}

QGraphicsView* DeckScene::view()
{
	return _view;
}

void DeckScene::setupLayout()
{
	clear();
	for (int i = 0; i < 4; i++) {
		AbstractCard *card = _deck->at(i);
		card->setIconSize(200, 280);
		int y = i * (280 + 5) + 5;
		card->setPos(5, y);
		addItem(card);
	}
}

void DeckScene::drawBackground(QPainter *painter, const QRectF &rect)
{
	painter->setPen(QPen(QBrush(QColor(Qt::darkBlue).lighter(100)), 5));
	painter->setBrush((QColor(Qt::magenta)).darker(500));
	painter->drawRect(sceneRect());
}

void DeckScene::cardUsed()
{
	for (int i = 0; i < 4; i++) {
		AbstractCard *card = _deck->at(i);
		if (card->isSelected()) {
			_deck->removeAt(i);
			_deck->push_back(card);
			card->setSelected(false);
		}
	}
	setupLayout();
}

void DeckScene::cardClicked()
{
	int tmp = -1;
	for (int i = 0; i < 4; i++) {
		AbstractCard *card = _deck->at(i);
		if (_selected_index != i && card->isSelected()) {
			tmp = i;
		}
		else {
			card->setSelected(false);
		}
	}
	_selected_index = tmp;
}

void DeckScene::preview(CardInfo *info)
{
	emit previewStart(info);
}

void DeckScene::stopPreview()
{
	emit previewStop();
}

void DeckScene::setPaused(bool value)
{
	for (int i = 0; i < _deck->size(); i++) {
		AbstractCard *card = _deck->at(i);
		card->setEnabled(!value);
	}
}
