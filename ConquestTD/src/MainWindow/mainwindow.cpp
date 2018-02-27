#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QMessageBox>

#include "mainwindow.h"
#include "MainScreen.h"
#include "ServerDialog.h"
#include "src/Controller/Controller.h"
#include "src/Controller/GameController.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowTitle("Sina Kamali [610394126]");
	setFixedSize(810, 850);

	_controller = new Controller;
	_game_controller = new GameController;
	_controller->setGameController(_game_controller);
	_game_controller->setController(_controller);

	_mainScreen = new MainScreen(_controller, _game_controller, this);

	//Menu Setup
	_game_menu = menuBar()->addMenu("Game");
	_server_action = _game_menu->addAction("Server Options...");
	_back_action = _game_menu->addAction("Exit to Mainmenu");
	_back_action->setEnabled(false);

	connect(_back_action, SIGNAL(triggered()), this, SLOT(backToStart()));
	connect(_mainScreen, SIGNAL(gameStarted()), this, SLOT(gameStarted()));
	connect(_mainScreen, SIGNAL(gameStopped()), this, SLOT(gameStopped()));

	//server dialog setup
	ServerDialog *serverDialog = new ServerDialog(this, _controller);
	connect(_server_action, SIGNAL(triggered()), serverDialog, SLOT(open()));

	
	setCentralWidget(_mainScreen);
}

MainWindow::~MainWindow()
{

}

void MainWindow::backToStart()
{
	_mainScreen->reset();
}

void MainWindow::gameStarted()
{
	_back_action->setEnabled(true);
}

void MainWindow::gameStopped()
{
	_back_action->setEnabled(false);
}
