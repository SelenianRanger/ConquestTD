#pragma once
#include <QGraphicsScene>
#include <QList>

class QObject;
class QGraphicsView;
class AbstractCard;
class CardInfo;

class DeckScene : public QGraphicsScene
{
	Q_OBJECT

public:
	DeckScene(QObject *parent = 0);
	~DeckScene();

	void setDeck(QList<AbstractCard*> *deck);

	QGraphicsView* view();

private:
	QList<AbstractCard*> *_deck;
	int _selected_index;

	QGraphicsView *_view;

	void setupLayout();

protected:
	virtual void drawBackground(QPainter *painter, const QRectF &rect) override;

signals:
	void previewStart(CardInfo *info);
	void previewStop();

public slots:
	void cardUsed();
	void cardClicked();
	void preview(CardInfo *info);
	void stopPreview();
	void setPaused(bool value);

};

