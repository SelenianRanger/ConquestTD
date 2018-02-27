#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Controller;
class GameController;
class MainScreen;
class QMenu;
class QAction;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Controller *_controller;
	GameController *_game_controller;

	QMenu *_game_menu;
	QAction *_server_action;
	QAction *_back_action;

	MainScreen *_mainScreen;

private slots:
	void backToStart();
	void gameStarted();
	void gameStopped();

};

#endif // MAINWINDOW_H
