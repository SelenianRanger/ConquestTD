#include <time.h>
#include <stdlib.h>

#include <QObject>
#include <QList>

#include "GameController.h"
#include "Controller.h"
#include "src/Assests/Cards/AbstractCard.h"

GameController::GameController()
	:QObject(), _paused(false)
{
	srand(time(0));
}


GameController::~GameController()
{
}

void GameController::setController(Controller *controller)
{
	_controller = controller;
}

void GameController::setDeck(QList<AbstractCard*> *deck)
{
	_deck = deck;
	//shuffle deck
	int n = rand() % 10 + 5;
	for (int c = 0; c < n; c++) {
		int i = rand() % 8;
		int j = rand() % 8;
		deck->swap(i, j);
	}
	emit deckSet();
}

QList<AbstractCard*>* GameController::deck()
{
	return _deck;
}

void GameController::requestPause()
{
	if (_controller->isConnected()) {
		_controller->requestPause();
	}
	else {
		togglePaused();
	}
}

void GameController::togglePaused()
{
	_paused = !_paused;
	emit setPaused(_paused);
}
