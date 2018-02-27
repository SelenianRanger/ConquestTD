#pragma once
#include "AbstractBuildingCard.h"

class QGraphicsObject;
class ResourceManager;

class MissileFactoryCard : public AbstractBuildingCard
{
public:
	MissileFactoryCard(ResourceManager *resources, QGraphicsObject *parent = 0);
	~MissileFactoryCard();

	virtual void activate(GameController *game_controller) override;

};

