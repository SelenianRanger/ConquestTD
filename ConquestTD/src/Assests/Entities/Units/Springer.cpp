#include <QString>
#include <QObject>

#include "Springer.h"
#include "AbstractUnit.h"
#include "UnitInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

Springer::Springer(QObject *parent)
	:AbstractUnit(parent, new QString("Springer"), 0,
		new UnitInfo(AbstractEntity::Ground, 1200, 0, 1.3, 9, 1,
			AbstractEntity::Building, 400, 0, 0, 1200))
{
}


Springer::~Springer()
{
}
