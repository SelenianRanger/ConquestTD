#include "CardInfo.h"

CardInfo::CardInfo(int cost)
	:_cost(cost)
{

}

CardInfo::~CardInfo()
{
}

int CardInfo::cost()
{
	return _cost;
}
