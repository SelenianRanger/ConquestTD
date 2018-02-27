#pragma once
#include "AbstractUnitCard.h"

class QGraphicsObject;
class GameController;
class ResourceManager;

class InfantryCard : public AbstractUnitCard
{
public:
	InfantryCard(ResourceManager *resources, QGraphicsObject *parent = 0);
	~InfantryCard();

	virtual void activate(GameController *game_controller) override;

};

