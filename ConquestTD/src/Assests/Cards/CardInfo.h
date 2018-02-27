#pragma once
class CardInfo
{
public:
	CardInfo(int cost);
	~CardInfo();

	int cost();

private:
	int _cost;

};

