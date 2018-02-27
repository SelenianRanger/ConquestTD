#pragma once
#include "AbstractBuilding.h"

class QObject;

class TeslaTower : public AbstractBuilding
{
public:
	TeslaTower(QObject *parent = 0);
	~TeslaTower();
};

