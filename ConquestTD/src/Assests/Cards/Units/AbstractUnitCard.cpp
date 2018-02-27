#include <QGraphicsObject>
#include <QPixmap>

#include "AbstractUnitCard.h"
#include "UnitCardInfo.h"
#include "src/Controller/ResourceManager.h"

AbstractUnitCard::AbstractUnitCard(QGraphicsObject *parent, QString *name, ResourceManager *resources, int id, UnitCardInfo *card_info)
	:AbstractCard(parent, name, resources, id, card_info)
{

}

AbstractUnitCard::~AbstractUnitCard()
{
}
