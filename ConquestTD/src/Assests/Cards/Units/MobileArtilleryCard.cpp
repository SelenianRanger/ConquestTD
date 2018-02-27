#include <QString>
#include <QGraphicsObject>

#include "MobileArtilleryCard.h"
#include "AbstractUnitCard.h"
#include "UnitCardInfo.h"
#include "src/Assests/Entities/Units/MobileArtillery.h"
#include "src/Controller/ResourceManager.h"

MobileArtilleryCard::MobileArtilleryCard(ResourceManager *resources, QGraphicsObject *parent)
	:AbstractUnitCard(parent, new QString("Mobile Artillery"), resources, ResourceManager::MobileArtillery,
		(UnitCardInfo*)(MobileArtillery().getCardInfo()))
{
}


MobileArtilleryCard::~MobileArtilleryCard()
{
}

void MobileArtilleryCard::activate(GameController *game_controller)
{
	
}
