#include <QString>
#include <QObject>

#include "Technican.h"
#include "AbstractUnit.h"
#include "UnitInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

Technican::Technican(QObject *parent)
	:AbstractUnit(parent, new QString("Technician"), 0,
		new UnitInfo(AbstractEntity::Ground, 200, 0, 1, 7, 1,
			AbstractEntity::Ground|AbstractEntity::Building, 100, 0, 0, 0))
{
}


Technican::~Technican()
{
}
