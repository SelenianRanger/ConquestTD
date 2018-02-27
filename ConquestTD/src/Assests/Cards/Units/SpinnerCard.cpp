#include <QString>
#include <QObject>

#include "SpinnerCard.h"
#include "AbstractUnitCard.h"
#include "UnitCardInfo.h"
#include "src/Assests/Entities/Units/Spinner.h"
#include "src/Controller/ResourceManager.h"

SpinnerCard::SpinnerCard(ResourceManager *resources, QGraphicsObject *parent)
	:AbstractUnitCard(parent, new QString("Spinner"), resources, ResourceManager::Spinner,
		(UnitCardInfo*)(Spinner().getCardInfo()))
{
}


SpinnerCard::~SpinnerCard()
{
}

void SpinnerCard::activate(GameController *game_controller)
{

}