#include <QGraphicsObject>
#include <QPixmap>

#include "AbstractCommandCard.h"
#include "CommandCardInfo.h"
#include "src/Controller/ResourceManager.h"

AbstractCommandCard::AbstractCommandCard(QGraphicsObject *parent, QString *name, ResourceManager *resources, int id, CommandCardInfo *card_info)
	:AbstractCard(parent, name, resources, id, card_info)
{

}

AbstractCommandCard::~AbstractCommandCard()
{
}