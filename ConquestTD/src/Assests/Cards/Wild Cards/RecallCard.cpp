#include <QString>
#include <QGraphicsObject>

#include "RecallCard.h"
#include "AbstractWildCard.h"
#include "WildCardInfo.h"
#include "src/Controller/ResourceManager.h"

RecallCard::RecallCard(ResourceManager *resources, QGraphicsObject *parent)
	:AbstractWildCard(parent, new QString("Recall"), resources, ResourceManager::Recall,
		new WildCardInfo(200))
{
}


RecallCard::~RecallCard()
{
}

void RecallCard::activate(GameController *game_controller)
{
	
}
