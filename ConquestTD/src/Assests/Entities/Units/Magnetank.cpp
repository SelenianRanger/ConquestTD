#include <QString>
#include <QObject>

#include "Magnetank.h"
#include "AbstractUnit.h"
#include "UnitInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

Magnetank::Magnetank(QObject *parent)
	:AbstractUnit(parent, new QString("Magnetank"), 0,
		new UnitInfo(AbstractEntity::Ground, 2500, 0, 1.3, 6, 20, 
			AbstractEntity::Air|AbstractEntity::Ground, 0, 80, 0, 1000))
{
}


Magnetank::~Magnetank()
{
}
