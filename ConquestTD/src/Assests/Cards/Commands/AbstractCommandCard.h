#pragma once
#include "src/Assests/Cards/AbstractCard.h"

class QGraphicsObject;
class QPixmap;
class CommandCardInfo;
class GameController;
class ResourceManager;

class AbstractCommandCard : public AbstractCard
{
public:
	AbstractCommandCard(QGraphicsObject *parent, QString *name, ResourceManager *resources, int id, CommandCardInfo *card_info);
	~AbstractCommandCard();

	virtual void activate(GameController *game_controller) = 0;

};

