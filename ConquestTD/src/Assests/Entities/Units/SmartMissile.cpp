#include <QString>
#include <QObject>

#include "SmartMissile.h"
#include "AbstractUnit.h"
#include "UnitInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

SmartMissile::SmartMissile(QObject *parent)
	:AbstractUnit(parent, new QString("Smart Missile"), 0,
		new UnitInfo(AbstractUnit::Air, 400, 0, 1, 9.5, 20,
			AbstractEntity::Ground, 0, 120, 100, 0))
{
}


SmartMissile::~SmartMissile()
{
}
