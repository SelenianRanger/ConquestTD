#pragma once
#include "AbstractUnitCard.h"

class QGraphicsObject;
class GameController;
class ResourceManager;

class SpinnerCard : public AbstractUnitCard
{
public:
	SpinnerCard(ResourceManager *resources, QGraphicsObject *parent = 0);
	~SpinnerCard();

	virtual void activate(GameController *game_controller) override;

};

