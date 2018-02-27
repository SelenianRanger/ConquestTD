#include <QGraphicsObject>
#include <QString>

#include "TeslaTowerCard.h"
#include "AbstractBuildingCard.h"
#include "BuildingCardInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"
#include "src/Assests/Entities/Buildings/TeslaTower.h"
#include "src/Controller/ResourceManager.h"

TeslaTowerCard::TeslaTowerCard(ResourceManager *resources, QGraphicsObject *parent)
	:AbstractBuildingCard(parent, new QString("Tesla Tower"), resources, ResourceManager::TeslaTower,
		(BuildingCardInfo*)(TeslaTower().getCardInfo()))
{
}


TeslaTowerCard::~TeslaTowerCard()
{
}

void TeslaTowerCard::activate(GameController *game_controller)
{
	
}
