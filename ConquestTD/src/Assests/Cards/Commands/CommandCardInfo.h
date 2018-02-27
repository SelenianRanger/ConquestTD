#pragma once
#include "src/Assests/Cards/CardInfo.h"

class CommandCardInfo : public CardInfo
{
public:
	CommandCardInfo(double radius, int duration, int cost);
	~CommandCardInfo();

	double radius();
	int duration();

private:
	double _radius;
	int _duration;

};

