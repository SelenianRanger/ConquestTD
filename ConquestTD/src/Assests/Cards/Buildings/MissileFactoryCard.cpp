#include <QGraphicsObject>

#include "MissileFactoryCard.h"
#include "AbstractBuildingCard.h"
#include "BuildingCardInfo.h"
#include "src/Assests/Entities/Buildings/MissileFactory.h"
#include "src/Controller/ResourceManager.h"

MissileFactoryCard::MissileFactoryCard( ResourceManager *resources, QGraphicsObject *parent)
	:AbstractBuildingCard(parent, new QString("Missile Factory"), resources, ResourceManager::MissileFactory,
		(BuildingCardInfo*)(MissileFactory().getCardInfo()))
{

}


MissileFactoryCard::~MissileFactoryCard()
{
}

void MissileFactoryCard::activate(GameController *game_controller)
{
	
}
