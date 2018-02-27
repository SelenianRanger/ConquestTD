#pragma once
#include "AbstractUnit.h"

class QObject;

class MobileFactory : public AbstractUnit
{
public:
	MobileFactory(QObject *parent = 0);
	~MobileFactory();
};

