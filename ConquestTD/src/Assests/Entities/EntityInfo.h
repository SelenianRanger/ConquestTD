#pragma once
class EntityInfo
{
public:
	EntityInfo(int type, int hp,
		double hit_speed,
		double range, int targets,
		int melee_damage, int area_damage, int special_damage,
		int cost);
	~EntityInfo();

	int type();

	int hp();

	double hitSpeed();

	double range();
	int targets();

	int meleeDamage();
	int areaDamage();
	int specialDamage();

	int cost();

private:
	int _type;

	int _hp;

	double _hit_speed;

	double _range;
	int _targets;

	int _melee_damage;
	int _area_damage;
	int _special_damage;

	int _cost;

};

