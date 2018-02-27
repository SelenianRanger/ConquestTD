#pragma once
#include <QWidget>

class StartPanel;
class GameScene;
class Controller;

class StartPage : public QWidget
{
	Q_OBJECT

public:
	StartPage(Controller *controller, QWidget *parent = 0);
	~StartPage();

private:
	StartPanel *_str_panel;
	GameScene *_gameScene;

signals:
	void readyToPlay();
	void stopWaitingForPlayers();

public slots:
	void setWaitingForPlayers(bool value);

private slots:
	void readyPlay();
	void stopWaiting();

};

