#include <QString>
#include <QGraphicsObject>

#include "FlameTankCard.h"
#include "AbstractUnitCard.h"
#include "UnitCardInfo.h"
#include "src/Assests/Entities/Units/FlameTank.h"
#include "src/Controller/ResourceManager.h"

FlameTankCard::FlameTankCard(ResourceManager *resources, QGraphicsObject *parent)
	:AbstractUnitCard(parent, new QString("Flame Tank"), resources, ResourceManager::FlameTank,
		(UnitCardInfo*)(FlameTank().getCardInfo()))
{

}

FlameTankCard::~FlameTankCard()
{
}

void FlameTankCard::activate(GameController *game_controller)
{
	
}
