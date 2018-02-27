#pragma once
#include "AbstractUnitCard.h"

class QGraphicsObject;
class GameController;
class ResourceManager;

class DrillerCard : public AbstractUnitCard
{
public:
	DrillerCard(ResourceManager *resources, QGraphicsObject *parent = 0);
	~DrillerCard();

	virtual void activate(GameController *game_controller) override;

};

