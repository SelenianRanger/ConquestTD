#pragma once

class AbstractCard;
class ResourceManager;
class QGraphicsObject;

class CardFactory
{
public:
	CardFactory();
	~CardFactory();

	AbstractCard* getCard(int id, ResourceManager *resources, QGraphicsObject *parent = 0);
};

