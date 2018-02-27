#pragma once
#include "AbstractBuilding.h"

class QObject;

class MissileFactory : public AbstractBuilding
{
public:
	MissileFactory(QObject *parent = 0);
	~MissileFactory();
};

