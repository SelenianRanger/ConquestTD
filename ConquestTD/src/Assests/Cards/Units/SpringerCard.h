#pragma once
#include "AbstractUnitCard.h"

class QGraphicsObject;
class GameController;
class ResourceManager;

class SpringerCard : public AbstractUnitCard
{
public:
	SpringerCard(ResourceManager *resources, QGraphicsObject *parent = 0);
	~SpringerCard();

	virtual void activate(GameController *game_controller) override;

};

