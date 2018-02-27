#pragma once
#include "src/Assests/Cards/CardInfo.h"

class UnitCardInfo : public CardInfo
{
public:
	UnitCardInfo(int hp, double range, int shield, int special_damage, int melee_damage, int area_damage, int cost);
	~UnitCardInfo();

private:
	int _hp;
	double _range;
	int _shield;
	int _special_damage;

	int _melee_damage;
	int _area_damage;
};

