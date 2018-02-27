#include <QGraphicsObject>
#include <QString>

#include "DischargeCard.h"
#include "AbstractCommandCard.h"
#include "CommandCardInfo.h"
#include "src/Controller/ResourceManager.h"

DischargeCard::DischargeCard(ResourceManager *resources, QGraphicsObject *parent)
	:AbstractCommandCard(parent, new QString("Discharge"), resources, ResourceManager::Discharge,
		new CommandCardInfo(20, 0, 500))
{
}


DischargeCard::~DischargeCard()
{
}

void DischargeCard::activate(GameController *game_controller)
{
	
}
