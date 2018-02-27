#pragma once
#include "src/Assests/Entities/AbstractEntity.h"

class QString;
class QGraphicsPixmapItem;;
class BuildingInfo;

class AbstractBuilding : public AbstractEntity
{
public:
	AbstractBuilding(QObject *parent, QString *name, QGraphicsPixmapItem *icon, BuildingInfo *building_info);
	~AbstractBuilding();


	virtual CardInfo* getCardInfo() override;

};

