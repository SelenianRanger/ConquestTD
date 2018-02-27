#pragma once
#include "AbstractUnit.h"

class QObject;

class Infantry : public AbstractUnit
{
public:
	Infantry(QObject *parent = 0);
	~Infantry();
};

