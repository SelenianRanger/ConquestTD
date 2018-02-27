#pragma once
#include "AbstractUnitCard.h"

class QGraphicsObject;
class GameController;
class ResourceManager;

class FlameTankCard : public AbstractUnitCard
{
public:
	FlameTankCard(ResourceManager *resources, QGraphicsObject *parent = 0);
	~FlameTankCard();

	virtual void activate(GameController *game_controller) override;

};

