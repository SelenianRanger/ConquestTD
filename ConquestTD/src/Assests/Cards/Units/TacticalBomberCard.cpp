#include <QString>
#include <QGraphicsObject>

#include "TacticalBomberCard.h"
#include "AbstractUnitCard.h"
#include "UnitCardInfo.h"
#include "src/Assests/Entities/Units/TacticalBomber.h"
#include "src/Controller/ResourceManager.h"

TacticalBomberCard::TacticalBomberCard(ResourceManager *resources, QGraphicsObject *parent)
	:AbstractUnitCard(parent, new QString("Tactical Bomber"), resources, ResourceManager::TacticalBomber,
		(UnitCardInfo*)(TacticalBomber().getCardInfo()))
{
}


TacticalBomberCard::~TacticalBomberCard()
{
}

void TacticalBomberCard::activate(GameController *game_controller)
{
	
}
