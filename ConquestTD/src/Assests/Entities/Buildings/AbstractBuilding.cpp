#include <QObject>
#include <QString>
#include <QGraphicsPixmapItem>

#include "AbstractBuilding.h"
#include "BuildingInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"
#include "src/Assests/Cards/CardInfo.h"
#include "src/Assests/Cards/Buildings/BuildingCardInfo.h"
#include "src/Assests/Entities/EntityInfo.h"

AbstractBuilding::AbstractBuilding(QObject *parent, QString *name, QGraphicsPixmapItem *icon, BuildingInfo *building_info)
	:AbstractEntity(parent, name, icon, building_info)
{

}

AbstractBuilding::~AbstractBuilding()
{
}

CardInfo* AbstractBuilding::getCardInfo()
{
	EntityInfo *entityInfo = info();
	BuildingInfo *info = (BuildingInfo*)entityInfo;
	int hp = info->hp();
	int damage = info->meleeDamage();
	int lifetime = info->lifetime();
	double range = info->range();
	int cost = info->cost();

	return new BuildingCardInfo(hp, damage, lifetime, range, cost);
}
