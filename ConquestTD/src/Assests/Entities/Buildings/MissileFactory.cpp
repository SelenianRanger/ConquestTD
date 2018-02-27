#include <QString>
#include <QObject>

#include "MissileFactory.h"
#include "AbstractBuilding.h"
#include "BuildingInfo.h"

MissileFactory::MissileFactory(QObject *parent)
	:AbstractBuilding(parent, new QString("Missile Factory"), 0,
		new BuildingInfo(2700, 50, 0, 0, 0, 0, 0, 0, 1200))
{
}


MissileFactory::~MissileFactory()
{
}
