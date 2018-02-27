#include <QString>
#include <QGraphicsObject>

#include "DrillerCard.h"
#include "AbstractUnitCard.h"
#include "UnitCardInfo.h"
#include "src/Assests/Entities/Units/Driller.h"
#include "src/Controller/ResourceManager.h"

DrillerCard::DrillerCard(ResourceManager *resources, QGraphicsObject *parent)
	:AbstractUnitCard(parent, new QString("Driller"), resources, ResourceManager::Driller,
		(UnitCardInfo*)(Driller().getCardInfo()))
{
}


DrillerCard::~DrillerCard()
{
}

void DrillerCard::activate(GameController *game_controller)
{
	
}
