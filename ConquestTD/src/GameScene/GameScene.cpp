#include <QGraphicsScene>
#include <QGraphicsView>

#include "GameScene.h"
#include "src/Controller/GameController.h"
#include "src/Assests/Cards/Units/ChargerCard.h"
#include "src/Controller/ResourceManager.h"

GameScene::GameScene(QObject *parent)
	:QGraphicsScene(parent)
{
	setSceneRect(0, 0, 500, 800);
	addRect(sceneRect(), QPen(), QBrush(Qt::black));

	_game_controller = new GameController;
	_resources = new ResourceManager;

	_view = new QGraphicsView;
	_view->setScene(this);

	_view->setFixedSize(502, 802);
}


GameScene::~GameScene()
{
}

QGraphicsView* GameScene::view()
{
	return _view;
}

void GameScene::setPaused(bool value)
{

}
