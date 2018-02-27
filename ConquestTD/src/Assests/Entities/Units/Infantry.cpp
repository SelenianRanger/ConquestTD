#include <QString>
#include <QObject>

#include "Infantry.h"
#include "AbstractUnit.h"
#include "UnitInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

Infantry::Infantry(QObject *parent)
	:AbstractUnit(parent, new QString("Infantry"), 0,
		new UnitInfo(AbstractEntity::Ground, 400, 0, 1, 8, 10, 
			AbstractEntity::Air|AbstractEntity::Ground, 120, 0, 0, 400))
{
}


Infantry::~Infantry()
{
}
