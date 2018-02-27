#pragma once
#include "src/Assests/Entities/EntityInfo.h"

class UnitInfo : public EntityInfo
{
public:
	UnitInfo(int type, int hp, int shield,
		double hit_speed, double movement_speed,
		double range, int targets,
		int melee_damage, int area_damage, int special_damage,
		int cost);
	~UnitInfo();

	int shield();

	double movementSpeed();

private:
	int _shield;

	double _movement_speed;

};