#pragma once
#include <QObject>
#include <QList>

class AbstractCard;
class Controller;
class QStringList;

class GameController : public QObject
{
	Q_OBJECT

public:
	GameController();
	~GameController();

	void setController(Controller *controller);

	void setDeck(QList<AbstractCard*> *deck);
	QList<AbstractCard*>* deck();

private:
	Controller *_controller;

	bool _paused;

	QList<AbstractCard*> *_deck;

signals:
	void setPaused(bool value);

	void deckSet();

public slots:
	void requestPause();
	void togglePaused();

};

