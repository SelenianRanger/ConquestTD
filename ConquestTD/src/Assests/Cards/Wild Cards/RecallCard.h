#pragma once
#include "AbstractWildCard.h"

class QGraphicsObject;
class GameController;
class ResourceManager;

class RecallCard : public AbstractWildCard
{
public:
	RecallCard(ResourceManager *resources, QGraphicsObject *parent = 0);
	~RecallCard();

	virtual void activate(GameController *game_controller) override;

};

