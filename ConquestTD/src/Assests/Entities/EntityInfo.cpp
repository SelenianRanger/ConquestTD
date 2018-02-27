#include "EntityInfo.h"


EntityInfo::EntityInfo(int type, int hp,
	double hit_speed,
	double range, int targets,
	int melee_damage, int area_damage, int special_damage,
	int cost)
	:_type(type), _hp(hp),
	_hit_speed(hit_speed),
	_range(range), _targets(targets),
	_melee_damage(melee_damage), _area_damage(area_damage), _special_damage(special_damage),
	_cost(cost)
{

}

EntityInfo::~EntityInfo()
{
}

int EntityInfo::type()
{
	return _type;
}

int EntityInfo::hp()
{
	return _hp;
}

double EntityInfo::hitSpeed()
{
	return _hit_speed;
}

double EntityInfo::range()
{
	return _range;
}

int EntityInfo::targets()
{
	return _targets;
}

int EntityInfo::meleeDamage()
{
	return _melee_damage;
}

int EntityInfo::areaDamage()
{
	return _area_damage;
}

int EntityInfo::specialDamage()
{
	return _special_damage;
}

int EntityInfo::cost()
{
	return _cost;
}