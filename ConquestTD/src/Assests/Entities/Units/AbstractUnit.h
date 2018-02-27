#pragma once
#include "src/Assests/Entities/AbstractEntity.h"

class QString;
class QGraphicsPixmapItem;;
class UnitInfo;

class AbstractUnit : public AbstractEntity
{
	Q_OBJECT

public:
	AbstractUnit(QObject *parent, QString *name, QGraphicsPixmapItem *icon, UnitInfo *unit_info);
	~AbstractUnit();


	virtual CardInfo* getCardInfo() override;

};

