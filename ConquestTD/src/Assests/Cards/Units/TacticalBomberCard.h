#pragma once
#include "AbstractUnitCard.h"

class QGraphicsObject;
class GameController;
class ResourceManager;

class TacticalBomberCard : public AbstractUnitCard
{
public:
	TacticalBomberCard(ResourceManager *Resources, QGraphicsObject *parent = 0);
	~TacticalBomberCard();

	virtual void activate(GameController *game_controller) override;

};

