#pragma once
#include "AbstractBuildingCard.h"

class QGraphicsObject;
class ResourceManager;

class TeslaTowerCard : public AbstractBuildingCard
{
public:
	TeslaTowerCard(ResourceManager *resources ,QGraphicsObject *parent = 0);
	~TeslaTowerCard();

	virtual void activate(GameController *game_controller) override;

};

