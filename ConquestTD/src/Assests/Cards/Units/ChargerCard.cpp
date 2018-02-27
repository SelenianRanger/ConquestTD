#include <QString>
#include <QGraphicsObject>

#include "ChargerCard.h"
#include "AbstractUnitCard.h"
#include "UnitCardInfo.h"
#include "src/Assests/Entities/Units/Charger.h"
#include "src/Controller/ResourceManager.h"

ChargerCard::ChargerCard(ResourceManager *resources, QGraphicsObject *parent)
	:AbstractUnitCard(parent, new QString("Charger"), resources, ResourceManager::Charger,
		(UnitCardInfo*)(Charger().getCardInfo()))
{
}


ChargerCard::~ChargerCard()
{
}

void ChargerCard::activate(GameController *game_controller)
{
	
}
