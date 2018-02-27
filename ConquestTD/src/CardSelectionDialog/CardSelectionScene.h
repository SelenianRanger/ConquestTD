#pragma once
#include <QGraphicsScene>
#include <QList>

class QGraphicsView;
class AbstractCard;
class ResourceManager;

class CardSelectionScene : public QGraphicsScene
{
	Q_OBJECT

public:
	CardSelectionScene(QList<AbstractCard*> *cards, QObject *parent = 0);
	~CardSelectionScene();

	void reset();

	QGraphicsView* view();

private:
	ResourceManager *_resources;
	QList<AbstractCard*> *_cards;

	QGraphicsView *_view;

	void setupLayout();
protected:
	virtual void drawBackground(QPainter *painter, const QRectF &rect) override;

signals:
	void updated();

public slots:
	void setSelectionLock(bool value);

private slots:
	void update();

};

