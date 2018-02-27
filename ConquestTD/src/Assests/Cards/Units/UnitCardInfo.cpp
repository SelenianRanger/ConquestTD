#include "UnitCardInfo.h"
#include "src/Assests/Cards/CardInfo.h"

UnitCardInfo::UnitCardInfo(int hp, double range, int shield, int special_damage,
	int melee_damage, int area_damage, int cost)
	:CardInfo(cost), _hp(hp), _range(range), _shield(shield), _special_damage(special_damage),
	_melee_damage(melee_damage), _area_damage(area_damage)
{

}

UnitCardInfo::~UnitCardInfo()
{

}
