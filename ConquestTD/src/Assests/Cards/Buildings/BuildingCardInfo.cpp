#include "BuildingCardInfo.h"

BuildingCardInfo::BuildingCardInfo(int hp, int damage, int lifetime, double range, int cost)
	:CardInfo(cost), _hp(hp), _damage(damage), _lifetime(lifetime), _range(range)
{

}

BuildingCardInfo::~BuildingCardInfo()
{
}

int BuildingCardInfo::hp()
{
	return _hp;
}


int BuildingCardInfo::damage()
{
	return _damage;
}

int BuildingCardInfo::lifetime()
{
	return _lifetime;
}

double BuildingCardInfo::range()
{
	return _range;
}