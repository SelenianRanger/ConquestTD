#pragma once
#include "AbstractUnit.h"

class QObject;

class Charger : public AbstractUnit
{
public:
	Charger(QObject *parent = 0);
	~Charger();
};

