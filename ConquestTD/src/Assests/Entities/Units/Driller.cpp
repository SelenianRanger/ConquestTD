#include <QString>
#include <QObject>

#include "Driller.h"
#include "AbstractUnit.h"
#include "UnitInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

Driller::Driller(QObject *parent)
	:AbstractUnit(parent, new QString("Driller"), 0,
		new UnitInfo(AbstractEntity::Ground, 2700, 0, 1.2, 8.5, 1, 
			AbstractEntity::Building, 400, 0, 0, 1200))
{
}


Driller::~Driller()
{
}
