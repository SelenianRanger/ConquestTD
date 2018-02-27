#include <QGraphicsObject>
#include <QPixmap>

#include "AbstractBuildingCard.h"
#include "BuildingCardInfo.h"
#include "src/Controller/ResourceManager.h"

AbstractBuildingCard::AbstractBuildingCard(QGraphicsObject *parent, QString *name, ResourceManager *resources, int id, BuildingCardInfo *card_info)
	:AbstractCard(parent, name, resources, id, card_info)
{

}

AbstractBuildingCard::~AbstractBuildingCard()
{
}