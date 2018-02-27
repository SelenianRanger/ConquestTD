#include <QString>
#include <QGraphicsObject>

#include "MagnetankCard.h"
#include "AbstractUnitCard.h"
#include "UnitCardInfo.h"
#include "src/Assests/Entities/Units/Magnetank.h"
#include "src/Controller/ResourceManager.h"

MagnetankCard::MagnetankCard(ResourceManager *resources, QGraphicsObject *parent)
	:AbstractUnitCard(parent, new QString("Magnetank"), resources, ResourceManager::Magnetank,
		(UnitCardInfo*)(Magnetank().getCardInfo()))
{
}


MagnetankCard::~MagnetankCard()
{
}

void MagnetankCard::activate(GameController *game_controller)
{
	
}
