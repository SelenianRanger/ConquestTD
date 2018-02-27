#include <QGraphicsObject>
#include <QPixmap>

#include "AbstractWildCard.h"
#include "WildCardInfo.h"
#include "src/Controller/ResourceManager.h"

AbstractWildCard::AbstractWildCard(QGraphicsObject *parent, QString *name, ResourceManager *resources, int id, WildCardInfo *card_info)
	:AbstractCard(parent, name, resources, id, card_info)
{

}

AbstractWildCard::~AbstractWildCard()
{
}