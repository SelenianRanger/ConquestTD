#pragma once
#include "AbstractUnitCard.h"

class QGraphicsObject;
class GameController;
class ResourceManager;

class MagnetankCard : public AbstractUnitCard
{
public:
	MagnetankCard(ResourceManager *resources, QGraphicsObject *parent = 0);
	~MagnetankCard();

	virtual void activate(GameController *game_controller) override;

};

