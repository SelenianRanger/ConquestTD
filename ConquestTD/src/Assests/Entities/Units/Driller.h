#pragma once
#include "AbstractUnit.h"

class QObject;

class Driller : public AbstractUnit
{
public:
	Driller(QObject *parent = 0);
	~Driller();
};

