#include <QWidget>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QMessageBox>
#include <QKeyEvent>

#include "MainGame.h"
#include "GamePanel.h"
#include "src/GameScene/GameScene.h"
#include "src/Controller/GameController.h"

MainGame::MainGame(GameController *game_controller, QWidget *parent)
	:QWidget(parent), _game_controller(game_controller)
{
	_panel = new GamePanel(game_controller);
	_game_scene = new GameScene;

	QHBoxLayout *layout = new QHBoxLayout;

	connect(_game_controller, SIGNAL(setPaused(bool)), this, SLOT(setPaused(bool)));

	layout->addWidget(_game_scene->view());
	layout->addWidget(_panel);

	setLayout(layout);
}

MainGame::~MainGame()
{

}

void MainGame::reset()
{
	_panel->reset();
}

void MainGame::start()
{
	_panel->start();
}

void MainGame::setPaused(bool value)
{
	_panel->setPaused(value);
	_game_scene->setPaused(value);

}

void MainGame::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_P)
		_game_controller->requestPause();

}
