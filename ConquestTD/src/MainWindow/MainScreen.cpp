#include <QWidget>
#include <QStackedLayout>
#include <QMessageBox>

#include "MainScreen.h"
#include "src/Controller/Controller.h"
#include "src/Controller/GameController.h"
#include "src/StartPage/StartPage.h"
#include "src/CardSelectionDialog/CardSelectionDialog.h"
#include "src/MainGame/MainGame.h"

MainScreen::MainScreen(Controller *controller, GameController *game_controller, QWidget *parent)
	:QWidget(parent), _controller(controller), _game_controller(game_controller)
{
	//page setup
	_start_page = new StartPage(_controller);
	_card_selection_dialog = new CardSelectionDialog(game_controller);
	_mainGame = new MainGame(game_controller);

	_page_layout = new QStackedLayout;

	_page_layout->addWidget(_start_page);
	_page_layout->addWidget(_mainGame);

	setLayout(_page_layout);

	connect(_start_page, SIGNAL(readyToPlay()), this, SLOT(selectCards()));
	connect(_card_selection_dialog, SIGNAL(accepted()), this, SLOT(waitForPlayers()));
	connect(_controller, SIGNAL(readyToStart()), this, SLOT(startGame()));
	connect(_controller, SIGNAL(stopGame()), this, SLOT(stopGame()));
	connect(_start_page, SIGNAL(stopWaitingForPlayers()), this, SLOT(stopWaitingForPlayers()));

}

MainScreen::~MainScreen()
{
}

void MainScreen::reset()
{
	stopWaitingForPlayers();
}

void MainScreen::showPage(int id)
{
	switch (id)
	{
	case startPage:
		_page_layout->setCurrentWidget(_start_page);
		break;
	case cardSelection:
		_card_selection_dialog->open();
		break;
	case mainGame:
		_page_layout->setCurrentWidget(_mainGame);
		break;
	}
}

void MainScreen::selectCards()
{
	showPage(cardSelection);
}

void MainScreen::waitForPlayers()
{
	_start_page->setWaitingForPlayers(true);
	if (_controller->isConnected())
		_controller->setReadyPlay(true);
	else
		startGame();
}

void MainScreen::startGame()
{
	_start_page->setWaitingForPlayers(false);
	showPage(mainGame);
	_mainGame->start();
	emit gameStarted();
}

void MainScreen::stopGame()
{
	_card_selection_dialog->reset();
	_start_page->setWaitingForPlayers(false);
	showPage(startPage);
	_mainGame->reset();
	emit gameStopped();
}

void MainScreen::stopWaitingForPlayers()
{
	_controller->setReadyPlay(false);
}
