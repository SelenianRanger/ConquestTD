#include <QObject>
#include <QString>
#include <QGraphicsPixmapItem>

#include "AbstractEntity.h"
#include "EntityInfo.h"

AbstractEntity::AbstractEntity(QObject *parent, QString *name, QGraphicsPixmapItem *icon, EntityInfo *info)
	:QObject(parent), _name(name), _icon(icon), _info(info)
{

}

AbstractEntity::~AbstractEntity()
{

}

bool AbstractEntity::attacks(AbstractEntity *entity)
{
	int result = entity->info()->type()&info()->targets();
	return result != 0;
}


double AbstractEntity::distance(AbstractEntity* unit)
{
	QPoint distance = *unit->position() - *_position;
	return std::sqrt(std::pow(distance.x(), 2) + std::pow(distance.y(), 2));
}

QString* AbstractEntity::name()
{
	return _name;
}

QPoint* AbstractEntity::position()
{
	return _position;
}

QGraphicsPixmapItem* AbstractEntity::icon()
{
	return _icon;
}

EntityInfo* AbstractEntity::info()
{
	return _info;
}