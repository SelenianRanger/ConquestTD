#pragma once
#include "AbstractUnit.h"

class QObject;

class MiniTank : public AbstractUnit
{
public:
	MiniTank(QObject *parent = 0);
	~MiniTank();
};

