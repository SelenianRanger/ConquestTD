#pragma once
#include "AbstractCommandCard.h"

class QGraphicsObject;
class ResourceManager;

class OverChargeCard : public AbstractCommandCard
{
public:
	OverChargeCard(ResourceManager *resources, QGraphicsObject *parent = 0);
	~OverChargeCard();

	virtual void activate(GameController *game_controller) override;

};

