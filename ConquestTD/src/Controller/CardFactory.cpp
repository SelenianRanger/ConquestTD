#include <QGraphicsObject>

#include "CardFactory.h"
#include "src/Assests/Cards/AbstractCard.h"
#include "ResourceManager.h"

#include "src/Assests/Cards/Buildings/MissileFactoryCard.h"
#include "src/Assests/Cards/Buildings/TeslaTowerCard.h"
#include "src/Assests/Cards/Commands/DischargeCard.h"
#include "src/Assests/Cards/Commands/OverChargeCard.h"
#include "src/Assests/Cards/Units/ChargerCard.h"
#include "src/Assests/Cards/Units/DrillerCard.h"
#include "src/Assests/Cards/Units/FlameTankCard.h"
#include "src/Assests/Cards/Units/InfantryCard.h"
#include "src/Assests/Cards/Units/MagnetankCard.h"
#include "src/Assests/Cards/Units/MobileArtilleryCard.h"
#include "src/Assests/Cards/Units/MobileFactoryCard.h"
#include "src/Assests/Cards/Units/SpinnerCard.h"
#include "src/Assests/Cards/Units/SpringerCard.h"
#include "src/Assests/Cards/Units/TacticalBomberCard.h"
#include "src/Assests/Cards/Wild Cards/RecallCard.h"


CardFactory::CardFactory()
{
}


CardFactory::~CardFactory()
{
}

AbstractCard* CardFactory::getCard(int id, ResourceManager *resources, QGraphicsObject *parent)
{
	switch (id)
	{
	case ResourceManager::Charger:
		return new ChargerCard(resources, parent);
	case ResourceManager::Discharge:
		return new DischargeCard(resources, parent);
	case ResourceManager::Driller:
		return new DrillerCard(resources, parent);
	case ResourceManager::FlameTank:
		return new FlameTankCard(resources, parent);
	case ResourceManager::Infantry:
		return new InfantryCard(resources, parent);
	case ResourceManager::Magnetank:
		return new MagnetankCard(resources, parent);
	case ResourceManager::MissileFactory:
		return new MissileFactoryCard(resources, parent);
	case ResourceManager::MobileArtillery:
		return new MobileArtilleryCard(resources, parent);
	case ResourceManager::MobileFactory:
		return new MobileFactoryCard(resources, parent);
	case ResourceManager::OverCharge:
		return new OverChargeCard(resources, parent);
	case ResourceManager::Recall:
		return new RecallCard(resources, parent);
	case ResourceManager::Spinner:
		return new SpinnerCard(resources, parent);
	case ResourceManager::Springer:
		return new SpringerCard(resources, parent);
	case ResourceManager::TacticalBomber:
		return new TacticalBomberCard(resources, parent);
	case ResourceManager::TeslaTower:
		return new TeslaTowerCard(resources, parent);
	default:
		return new ChargerCard(resources, parent);
	}
}
