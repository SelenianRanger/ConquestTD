#include "UnitInfo.h"
#include "src/Assests/Entities/EntityInfo.h"

UnitInfo::UnitInfo(int type, int hp, int shield,
	double hit_speed, double movement_speed,
	double range, int targets,
	int melee_damage, int area_damage, int special_damage,
	int cost)
	: EntityInfo(type, hp, hit_speed, range, targets, melee_damage, area_damage, special_damage, cost), _shield(shield), _movement_speed(movement_speed)
{

}

UnitInfo::~UnitInfo()
{
}

int UnitInfo::shield()
{
	return _shield;
}

double UnitInfo::movementSpeed()
{
	return _movement_speed;
}