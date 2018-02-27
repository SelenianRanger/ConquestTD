#include <QObject>
#include <QString>

#include "MobileFactory.h"
#include "AbstractUnit.h"
#include "UnitInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

MobileFactory::MobileFactory(QObject *parent)
	:AbstractUnit(parent, new QString("Mobile Factory"), 0,
		new UnitInfo(AbstractEntity::Ground, 950, 200, 0.6, 5, 40,
			AbstractEntity::Air|AbstractEntity::Ground, 0, 90, 0, 2700))
{
}


MobileFactory::~MobileFactory()
{
}
