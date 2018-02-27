#pragma once
#include "qwidget.h"

class QPushButton;
class QButtonGroup;
class QRadioButton;
class QLabel;
class QString;
class Controller;

class StartPanel : public QWidget
{
	Q_OBJECT

public:
	StartPanel(Controller *controller, QWidget *parent = 0);
	~StartPanel();

private:
	Controller *_controller;

	QPushButton *_player_top1_btn;
	QPushButton *_player_top2_btn;
	QPushButton *_player_bottom1_btn;
	QPushButton *_player_bottom2_btn;
	QPushButton *_play_btn;
	QButtonGroup *_gametype_btnGroup;
	QRadioButton *_2Player_radioBtn;
	QRadioButton *_4Player_radioBtn;
	QLabel *_waiting_label;

	bool _waiting;

	void setupLayout();

signals:
	void readyPlay();
	void stopWaiting();

public slots:
	void setWaitingForPlayers(bool value);
	void reset();

private slots:
	void gamemodeChanged(int id);
	void requestGamemode(int id);
	void playClicked();

	void requestTopLeft();
	void requestTopRight();
	void requestBottomLeft();
	void requestBottomRight();
	void setPosition(QString *name, int position, bool me = false);
};

