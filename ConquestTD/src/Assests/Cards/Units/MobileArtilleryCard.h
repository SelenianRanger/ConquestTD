#pragma once
#include "AbstractUnitCard.h"

class QGraphicsObject;
class GameController;
class ResourceManager;

class MobileArtilleryCard : public AbstractUnitCard
{
public:
	MobileArtilleryCard(ResourceManager *resources, QGraphicsObject *parent = 0);
	~MobileArtilleryCard();

	virtual void activate(GameController *game_controller) override;

};

