#pragma once
#include "src/Assests/Cards/AbstractCard.h"

class QGraphicsObject;
class QPixmap;
class BuildingCardInfo;
class GameController;
class ResourceManager;

class AbstractBuildingCard : public AbstractCard
{
public:
	AbstractBuildingCard(QGraphicsObject *parent, QString *name, ResourceManager *resources, int id, BuildingCardInfo *card_info);
	~AbstractBuildingCard();

	virtual void activate(GameController *game_controller) = 0;

};

