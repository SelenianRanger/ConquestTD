#pragma once
#include "AbstractUnit.h"

class QObject;

class SmartMissile : public AbstractUnit
{
public:
	SmartMissile(QObject *parent = 0);
	~SmartMissile();
};

