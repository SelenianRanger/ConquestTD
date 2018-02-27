#include <QString>
#include <QObject>

#include "Charger.h"
#include "AbstractUnit.h"
#include "UnitInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

Charger::Charger(QObject *parent)
	:AbstractUnit(parent, new QString("Charger"), 0,
		new UnitInfo(AbstractEntity::Ground, 900, 400, 1.5, 6.5, 1, 
			AbstractEntity::Ground|AbstractEntity::Building, 250, 0, 500, 2500))
{
}


Charger::~Charger()
{
}
