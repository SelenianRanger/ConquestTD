#pragma once
#include "AbstractUnit.h"

class QObject;

class Springer : public AbstractUnit
{
public:
	Springer(QObject *parent = 0);
	~Springer();
};

