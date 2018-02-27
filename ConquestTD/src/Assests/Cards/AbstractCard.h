#pragma once
#include <QGraphicsObject>

class QSize;
class QPixmap;
class GameController;
class CardInfo;
class ResourceManager;

class AbstractCard : public QGraphicsObject
{
	Q_OBJECT

public:
	AbstractCard(QGraphicsObject *parent, QString *name, ResourceManager *resources, int id, CardInfo* card_info);
	~AbstractCard();

	virtual void activate(GameController *game_controller) = 0;

	CardInfo* info();

	bool isSelected();
	bool isSelectable();

	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

	void setIconSize(int w, int h);
	void setIconSize(QSize& size);
	QPixmap *icon();


	virtual QRectF boundingRect() const override;

private:
	int _id;
	QString *_name;
	QPixmap *_icon;
	QSize *_size;

	CardInfo *_card_info;

	bool _selected;
	bool _selectable;

protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
	virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
	virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

signals:
	void clicked();
	void selected();
	void updated();
	void hoverPreview(CardInfo *info);
	void stopPreview();

public slots:
	void setSelectable(bool value);
	void toggleSelected();
	void setSelected(bool value);
	void setIcon(int id, QPixmap *icon);


};

