#pragma once
#include "AbstractUnitCard.h"

class QGraphicsObject;
class GameController;
class ResourceManager;

class ChargerCard : public AbstractUnitCard
{
public:
	ChargerCard(ResourceManager *resources, QGraphicsObject *parent = 0);
	~ChargerCard();

	virtual void activate(GameController *game_controller) override;

};

