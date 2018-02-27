#pragma once
#include "AbstractUnit.h"

class QObject;

class Spinner : public AbstractUnit
{
public:
	Spinner(QObject *parent = 0);
	~Spinner();
};

