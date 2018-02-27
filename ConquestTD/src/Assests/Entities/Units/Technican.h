#pragma once
#include "AbstractUnit.h"

class QObject;

class Technican : public AbstractUnit
{
public:
	Technican(QObject *parent = 0);
	~Technican();
};

