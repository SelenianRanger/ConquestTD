#include <QString>
#include <QGraphicsObject>

#include "MobileFactoryCard.h"
#include "AbstractUnitCard.h"
#include "UnitCardInfo.h"
#include "src/Assests/Entities/Units/MobileFactory.h"
#include "src/Controller/ResourceManager.h"

MobileFactoryCard::MobileFactoryCard(ResourceManager *resources, QGraphicsObject *parent)
	:AbstractUnitCard(parent, new QString("Mobile Factory"), resources, ResourceManager::MobileFactory,
		(UnitCardInfo*)(MobileFactory().getCardInfo()))
{
}


MobileFactoryCard::~MobileFactoryCard()
{
}

void MobileFactoryCard::activate(GameController *game_controller)
{

}
