#pragma once
#include "AbstractUnitCard.h"

class QGraphicsObject;
class GameController;
class ResourceManager;

class MobileFactoryCard : public AbstractUnitCard
{
public:
	MobileFactoryCard(ResourceManager *resources, QGraphicsObject *parent = 0);
	~MobileFactoryCard();

	virtual void activate(GameController *game_controller) override;

};

