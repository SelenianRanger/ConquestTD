#pragma once
#include "AbstractUnit.h"

class QObject;

class TacticalBomber : public AbstractUnit
{
public:
	TacticalBomber(QObject *parent = 0);
	~TacticalBomber();
};

