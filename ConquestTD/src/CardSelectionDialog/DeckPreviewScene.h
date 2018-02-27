#pragma once
#include <QGraphicsScene>
#include <QList>

class QObject;
class QGraphicsView;
class ResourceManager;
class AbstractCard;

class DeckPreviewScene : public QGraphicsScene
{
	Q_OBJECT

public:
	DeckPreviewScene(QList<AbstractCard*> *cards, QObject *parent = 0);
	~DeckPreviewScene();

	void reset();

	QGraphicsView* view();

private:
	ResourceManager *_resources;
	QList<AbstractCard*> *_cards;

	QGraphicsView *_view;

protected:
	virtual void drawBackground(QPainter *painter, const QRectF &rect) override;

	virtual void drawForeground(QPainter *painter, const QRectF &rect) override;

signals:
	void deckComplete();
	void deckIncomplete();

};

