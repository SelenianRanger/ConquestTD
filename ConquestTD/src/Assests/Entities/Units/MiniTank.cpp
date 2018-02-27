#include <QString>
#include <QObject>

#include "MiniTank.h"
#include "AbstractUnit.h"
#include "UnitInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

MiniTank::MiniTank(QObject *parent)
	:AbstractUnit(parent, new QString("Mini-Tank"), 0,
		new UnitInfo(AbstractEntity::Ground, 300, 100, 0.9, 7, 1,
			AbstractEntity::Ground|AbstractEntity::Building, 140, 0, 0, 0))
{
}


MiniTank::~MiniTank()
{
}
