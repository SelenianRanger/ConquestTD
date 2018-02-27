#include "BuildingInfo.h"
#include "src/Assests/Entities/EntityInfo.h"
#include "src/Assests/Entities/AbstractEntity.h"

BuildingInfo::BuildingInfo(int hp, int lifetime, double hit_speed, double range, int targets, int melee_damage, int area_damage, int special_damage, int cost)
	:EntityInfo(AbstractEntity::Building, hp, hit_speed, range, targets, melee_damage, area_damage, special_damage, cost), _lifetime(lifetime)
{

}

BuildingInfo::~BuildingInfo()
{
}

int BuildingInfo::lifetime()
{
	return _lifetime;
}
