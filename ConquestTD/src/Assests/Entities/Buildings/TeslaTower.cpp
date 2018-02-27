#include <QObject>

#include "TeslaTower.h"
#include "AbstractBuilding.h"
#include "BuildingInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

TeslaTower::TeslaTower(QObject *parent)
	:AbstractBuilding(parent, new QString("Tesla Tower"), 0,
		new BuildingInfo(2500, 40, 0.5, 40, 
			AbstractEntity::Air|AbstractEntity::Ground, 100, 0, 0, 2700))
{
}


TeslaTower::~TeslaTower()
{
}
