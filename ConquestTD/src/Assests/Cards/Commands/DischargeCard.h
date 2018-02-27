#pragma once
#include "AbstractCommandCard.h"

class QGraphicsObject;
class ResourceManager;

class DischargeCard : public AbstractCommandCard
{
public:
	DischargeCard( ResourceManager *resources, QGraphicsObject *parent = 0);
	~DischargeCard();

	virtual void activate(GameController *game_controller) override;

};

