#pragma once
#include <QGraphicsScene>

class QGraphicsView;
class GameController;
class ResourceManager;

class GameScene : public QGraphicsScene
{
	Q_OBJECT

public:
	GameScene(QObject *parent = 0);
	~GameScene();

	QGraphicsView* view();

private:
	GameController *_game_controller;
	ResourceManager *_resources;

	QGraphicsView *_view;

public slots:
	void setPaused(bool value);

};

