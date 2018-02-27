#pragma once
#include <QObject>

class QGraphicsPixmapItem;
class QString;
class QPoint;
class EntityInfo;
class CardInfo;

class AbstractEntity : public QObject
{
	Q_OBJECT

public:
	enum UnitType { Ground = 1, Air = 2, Building = 4 };

	AbstractEntity(QObject *parent, QString *name, QGraphicsPixmapItem *icon, EntityInfo *info);
	~AbstractEntity();

	double distance(AbstractEntity* unit);
	bool attacks(AbstractEntity *unit);

	QString* name();
	QPoint* position();
	QGraphicsPixmapItem* icon();

	EntityInfo* info();
	virtual CardInfo* getCardInfo() = 0;

private:
	QString *_name;
	QPoint *_position;
	QGraphicsPixmapItem *_icon;

	EntityInfo* _info;

signals:
	void updated();
	void died();
	
};
