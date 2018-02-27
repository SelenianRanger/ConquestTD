#include <QObject>
#include <QString>

#include "MobileArtillery.h"
#include "AbstractUnit.h"
#include "UnitInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

MobileArtillery::MobileArtillery(QObject *parent)
	:AbstractUnit(parent, new QString("Mobile Artillery"), 0,
		new UnitInfo(AbstractEntity::Ground, 3000, 200, 0.3, 4, 60,
			AbstractEntity::Building, 100, 0, 0, 3000))
{
}


MobileArtillery::~MobileArtillery()
{
}
