#pragma once
#include "AbstractUnit.h"

class QObject;

class MobileArtillery : public AbstractUnit
{
public:
	MobileArtillery(QObject *parent = 0);
	~MobileArtillery();
};

