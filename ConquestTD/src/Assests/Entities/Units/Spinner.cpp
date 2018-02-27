#include <QObject>
#include <QString>

#include "Spinner.h"
#include "AbstractUnit.h"
#include "UnitInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

Spinner::Spinner(QObject *parent)
	:AbstractUnit(parent, new QString("Spinner"), 0,
		new UnitInfo(AbstractEntity::Ground, 800, 200, 1.2, 7, 1,
			AbstractEntity::Ground|AbstractEntity::Building, 0, 150, 0, 1100))
{
}


Spinner::~Spinner()
{
}
