#include <QString>
#include <QGraphicsObject>

#include "SpringerCard.h"
#include "AbstractUnitCard.h"
#include "UnitCardInfo.h"
#include "src/Assests/Entities/Units/Springer.h"
#include "src/Controller/ResourceManager.h"

SpringerCard::SpringerCard(ResourceManager *resources, QGraphicsObject *parent)
	:AbstractUnitCard(parent, new QString("Springer"), resources, ResourceManager::Springer,
		(UnitCardInfo*)(Springer().getCardInfo()))
{
}


SpringerCard::~SpringerCard()
{
}

void SpringerCard::activate(GameController *game_controller)
{

}
