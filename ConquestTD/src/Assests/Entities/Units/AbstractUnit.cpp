#include <QGraphicsPixmapItem>
#include <QString>
#include <QList>
#include <QPoint>

#include "AbstractUnit.h"
#include "UnitInfo.h"
#include "src/Assests/Cards/CardInfo.h"
#include "src/Assests/Cards/Units/UnitCardInfo.h"
#include "src/Assests/Entities/EntityInfo.h"

AbstractUnit::AbstractUnit(QObject *parent, QString *name, QGraphicsPixmapItem *icon, UnitInfo *unit_info)
	:AbstractEntity(parent, name, icon, unit_info)
{

}

AbstractUnit::~AbstractUnit()
{
}

CardInfo* AbstractUnit::getCardInfo()
{
	EntityInfo *entityInfo = info();
	UnitInfo *info = (UnitInfo*)entityInfo;
	int hp = info->hp();
	double range = info->range();
	int shield = info->shield();
	int melee_damage = info->meleeDamage();
	int area_damage = info->areaDamage();
	int special_damage = info->specialDamage();
	int cost = info->cost();

	return new UnitCardInfo(hp, range, shield, special_damage, melee_damage, area_damage, cost);
}
