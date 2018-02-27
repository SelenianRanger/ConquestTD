#pragma once
#include <QWidget>

class CountDownTimer;
class QLabel;
class QVBoxLayout;
class CreditBar;
class DeckScene;
class GameController;

class GamePanel : public QWidget
{
	Q_OBJECT

public:
	GamePanel(GameController *game_controller, QWidget *parent = 0);
	~GamePanel();

	void reset();

private:
	GameController *_game_controller;

	CountDownTimer *_countDown_timer;

	QLabel *_countDown_label;
	CreditBar *_credit_bar;
	QLabel *_credits_label;
	DeckScene *_deck_scene;
	QLabel *_pause_label;

	void setupLayout(QVBoxLayout *layout);

public slots:
	void start();
	void stop();
	void setPaused(bool value);
	
private slots:
	void timerUpdated();
	void updateDeck();
	void updateCredits(int value);

};

