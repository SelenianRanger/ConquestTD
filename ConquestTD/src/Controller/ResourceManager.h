#pragma once
#include <QObject>
#include <QList>

class QPixmap;

class ResourceManager : public QObject
{
	Q_OBJECT

public:
	enum CardID { Charger = 0, Discharge, Driller, FlameTank, Infantry, Magnetank, MissileFactory, MobileArtillery, MobileFactory, OverCharge, Recall, Spinner, Springer, TacticalBomber, TeslaTower, CardEnd };

	ResourceManager();
	~ResourceManager();

private:
	QList<QPixmap*> *_card_icon_list;

signals:
	void cardIconSent( int id, QPixmap* icon);

public slots:
	void getCardIcon(int id);

};

