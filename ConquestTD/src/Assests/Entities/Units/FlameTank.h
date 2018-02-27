#pragma once
#include "AbstractUnit.h"

class QObject;

class FlameTank : public AbstractUnit
{
public:
	FlameTank(QObject *parent = 0);
	~FlameTank();
};

