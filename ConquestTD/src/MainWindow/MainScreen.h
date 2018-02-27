#pragma once
#include <QWidget>

class Controller;
class StartPage;
class CardSelectionDialog;
class MainGame;
class QStackedLayout;
class GameController;

class MainScreen : public QWidget
{
	Q_OBJECT

public:
	enum PageID {startPage = 0, cardSelection, mainGame};

	MainScreen(Controller *controller, GameController *game_controller, QWidget *parent = 0);
	~MainScreen();

	void reset();

private:
	enum Page {start = 0};

	StartPage *_start_page;
	CardSelectionDialog *_card_selection_dialog;
	MainGame *_mainGame;

	QStackedLayout *_page_layout;

	Controller *_controller;
	GameController *_game_controller;

signals:
	void gameStarted();
	void gameStopped();

public slots:
	void showPage(int id);

private slots:
	void selectCards();
	void waitForPlayers();
	void startGame();
	void stopGame();
	void stopWaitingForPlayers();

};

