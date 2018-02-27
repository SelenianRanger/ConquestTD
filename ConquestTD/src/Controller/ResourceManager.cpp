#include <QObject>
#include <QPixmap>

#include "ResourceManager.h"

ResourceManager::ResourceManager()
	:QObject()
{
	_card_icon_list = new QList<QPixmap*>;
	_card_icon_list->append(new QPixmap(":Resources/Cards/Charger.png"));
	_card_icon_list->append(new QPixmap(":Resources/Cards/Discharge.png"));
	_card_icon_list->append(new QPixmap(":Resources/Cards/Driller.png"));
	_card_icon_list->append(new QPixmap(":Resources/Cards/Flame Tank.png"));
	_card_icon_list->append(new QPixmap(":Resources/Cards/Infantry.png"));
	_card_icon_list->append(new QPixmap(":Resources/Cards/Magnetank.png"));
	_card_icon_list->append(new QPixmap(":Resources/Cards/Missile Factory.png"));
	_card_icon_list->append(new QPixmap(":Resources/Cards/Mobile Artillery.png"));
	_card_icon_list->append(new QPixmap(":Resources/Cards/Mobile Factory.png"));
	_card_icon_list->append(new QPixmap(":Resources/Cards/OverCharge.png"));
	_card_icon_list->append(new QPixmap(":Resources/Cards/Recall.png"));
	_card_icon_list->append(new QPixmap(":Resources/Cards/Spinner.png"));
	_card_icon_list->append(new QPixmap(":Resources/Cards/Springer.png"));
	_card_icon_list->append(new QPixmap(":Resources/Cards/Tactical Bomber.png"));
	_card_icon_list->append(new QPixmap(":Resources/Cards/Tesla Tower.png"));

}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::getCardIcon(int id)
{
	emit cardIconSent(id, _card_icon_list->at(id));
}
