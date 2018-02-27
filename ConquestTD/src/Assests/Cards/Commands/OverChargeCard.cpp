#include <QGraphicsObject>
#include <QString>

#include "OverChargeCard.h"
#include "AbstractCommandCard.h"
#include "CommandCardInfo.h"
#include "src/Controller/ResourceManager.h"

OverChargeCard::OverChargeCard(ResourceManager *resources, QGraphicsObject *parent)
	:AbstractCommandCard(parent, new QString("OverCharge"), resources, ResourceManager::OverCharge,
		new CommandCardInfo(30, 8, 1000))
{
}


OverChargeCard::~OverChargeCard()
{
}

void OverChargeCard::activate(GameController *game_controller)
{
	
}
