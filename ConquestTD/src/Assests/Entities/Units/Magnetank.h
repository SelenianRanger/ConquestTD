#pragma once
#include "AbstractUnit.h"

class QObject;

class Magnetank : public AbstractUnit
{
public:
	Magnetank(QObject *parent = 0);
	~Magnetank();
};

