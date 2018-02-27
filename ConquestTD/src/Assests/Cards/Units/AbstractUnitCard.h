#pragma once
#include "src/Assests/Cards/AbstractCard.h"

class QGraphicsObject;
class QPixmap;
class UnitCardInfo;
class GameController;
class ResourceManager;

class AbstractUnitCard : public AbstractCard
{
public:
	AbstractUnitCard(QGraphicsObject *parent, QString *name, ResourceManager *resources, int id, UnitCardInfo *card_info);
	~AbstractUnitCard();

	virtual void activate(GameController *game_controller) = 0;

};
