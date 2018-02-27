#include <QString>
#include <QGraphicsObject>

#include "InfantryCard.h"
#include "AbstractUnitCard.h"
#include "UnitCardInfo.h"
#include "src/Assests/Entities/Units/Infantry.h"
#include "src/Controller/ResourceManager.h"

InfantryCard::InfantryCard(ResourceManager *resources, QGraphicsObject *parent)
	:AbstractUnitCard(parent, new QString("Infantry"), resources, ResourceManager::Infantry,
		(UnitCardInfo*)(Infantry().getCardInfo()))
{
}


InfantryCard::~InfantryCard()
{
}

void InfantryCard::activate(GameController *game_controller)
{
	
}
