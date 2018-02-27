#include <QString>
#include <QObject>

#include "TacticalBomber.h"
#include "AbstractUnit.h"
#include "UnitInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

TacticalBomber::TacticalBomber(QObject *parent)
	:AbstractUnit(parent, new QString("Tactical Bomber"), 0,
		new UnitInfo(AbstractEntity::Air, 2700, 0, 4, 6, 5, 
			AbstractEntity::Building, 1200, 0, 900, 4000))
{
}


TacticalBomber::~TacticalBomber()
{
}
