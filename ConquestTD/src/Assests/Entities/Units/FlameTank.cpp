#include <QString>
#include <QObject>

#include "FlameTank.h"
#include "AbstractUnit.h"
#include "UnitInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

FlameTank::FlameTank(QObject *parent)
	:AbstractUnit(parent, new QString("Flame Tank"), 0,
		new UnitInfo(AbstractEntity::Ground, 3000, 0, 0.8, 5, 8, 
			AbstractEntity::Building, 0, 200, 0, 2300))
{
}


FlameTank::~FlameTank()
{
}
