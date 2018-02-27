#pragma once
#include "src\Assests\Entities\EntityInfo.h"

class BuildingInfo : public EntityInfo
{
public:
	BuildingInfo(int hp, int lifetime,
		double hit_speed,
		double range, int targets,
		int melee_damage, int area_damage, int special_damage,
		int cost);
	~BuildingInfo();

	int lifetime();

private:
	int _lifetime;
};

