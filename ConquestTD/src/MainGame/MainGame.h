#pragma once
#include <QWidget>

class GamePanel;
class GameScene;
class GameController;

class MainGame : public QWidget
{
	Q_OBJECT

public:
	MainGame(GameController *game_controller, QWidget *parent = 0);
	~MainGame();

	void reset();

private:
	GameController *_game_controller;

	GamePanel *_panel;
	GameScene *_game_scene;

public slots:
	void start();
	void setPaused(bool value);

protected:
	virtual void keyPressEvent(QKeyEvent *event) override;

};

