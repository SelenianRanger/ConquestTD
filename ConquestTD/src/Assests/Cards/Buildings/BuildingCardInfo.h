#pragma once
#include "src/Assests/Cards/CardInfo.h"

class BuildingCardInfo : public CardInfo
{
public:
	BuildingCardInfo(int hp, int damage, int lifetime, double range, int cost);
	~BuildingCardInfo();

	int hp();

	int damage();

	int lifetime();

	double range();

private:
	int _hp;

	int _damage;

	int _lifetime;

	double _range;

};

