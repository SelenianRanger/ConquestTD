#pragma once
#include "src/Assests/Cards/AbstractCard.h"

class QGraphicsObject;
class QPixmap;
class WildCardInfo;
class GameController;
class ResourceManager;

class AbstractWildCard : public AbstractCard
{
public:
	AbstractWildCard(QGraphicsObject *parent, QString *name, ResourceManager *resources, int id, WildCardInfo *_card_info);
	~AbstractWildCard();

	virtual void activate(GameController *game_controller) = 0;

};

