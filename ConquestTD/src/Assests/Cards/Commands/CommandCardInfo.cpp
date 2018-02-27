#include "CommandCardInfo.h"
#include "src/Assests/Cards/CardInfo.h"

CommandCardInfo::CommandCardInfo(double radius, int duration, int cost)
	:CardInfo(cost), _radius(radius), _duration(duration)
{

}

CommandCardInfo::~CommandCardInfo()
{
}


double CommandCardInfo::radius()
{
	return _radius;
}

int CommandCardInfo::duration()
{
	return _duration;
}