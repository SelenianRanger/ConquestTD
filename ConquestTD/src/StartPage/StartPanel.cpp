#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QLabel>
#include <QMessageBox>

#include "StartPanel.h"
#include "src/Controller/Controller.h"

StartPanel::StartPanel(Controller *controller, QWidget *parent)
	:QWidget(parent), _controller(controller), _waiting(false)
{
	setFixedSize(300, 800);

	_player_top1_btn = new QPushButton("bot");
	_player_top1_btn->setFixedSize(80, 80);
	_player_top2_btn = new QPushButton("bot");
	_player_top2_btn->setFixedSize(80, 80);
	_player_bottom1_btn = new QPushButton("bot");
	_player_bottom1_btn->setFixedSize(80, 80);
	_player_bottom2_btn = new QPushButton("bot");
	_player_bottom2_btn->setFixedSize(80, 80);
	_play_btn = new QPushButton("Play");
	_play_btn->setFixedSize(120, 30);
	_2Player_radioBtn = new QRadioButton("2 Players");
	_4Player_radioBtn = new QRadioButton("4 Players");
	_gametype_btnGroup = new QButtonGroup;
	_waiting_label = new QLabel("waiting for players...");
	_waiting_label->setVisible(false);

	_gametype_btnGroup->addButton(_2Player_radioBtn, Controller::twoPlayer);
	_gametype_btnGroup->addButton(_4Player_radioBtn, Controller::fourPLayer);
	_2Player_radioBtn->setChecked(true);

	_player_top2_btn->setVisible(false);
	_player_bottom2_btn->setVisible(false);

	connect(_gametype_btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(requestGamemode(int)));
	connect(_play_btn, SIGNAL(clicked()), this, SLOT(playClicked()));

	connect(_player_top1_btn, SIGNAL(clicked()), this, SLOT(requestTopLeft()));
	connect(_player_top2_btn, SIGNAL(clicked()), this, SLOT(requestTopRight()));
	connect(_player_bottom1_btn, SIGNAL(clicked()), this, SLOT(requestBottomLeft()));
	connect(_player_bottom2_btn, SIGNAL(clicked()), this, SLOT(requestBottomRight()));
	connect(_controller, SIGNAL(positionSet(QString*, int, bool)), this, SLOT(setPosition(QString*, int, bool)));
	connect(_controller, SIGNAL(gamemodeChanged(int)), this, SLOT(gamemodeChanged(int)));
	connect(_controller, SIGNAL(disconnected()), this, SLOT(reset()));
	connect(_controller, SIGNAL(init()), this, SLOT(reset()));

	_controller->requestPosition(_controller->nextOpenPosition());

	setupLayout();
}

StartPanel::~StartPanel()
{
}

void StartPanel::setupLayout()
{
	//radio button group
	QWidget *btnGrp = new QWidget;
	QHBoxLayout *btnGrp_layout = new QHBoxLayout;

	btnGrp_layout->addWidget(_2Player_radioBtn);
	btnGrp_layout->addWidget(_4Player_radioBtn);

	btnGrp->setLayout(btnGrp_layout);
	//---------------------------------------------------------------------------
	
	//player setup box
	QGroupBox *setup_grpBox = new QGroupBox("Player Setup");
	QGridLayout *setup_grpBox_layout = new QGridLayout;

	setup_grpBox_layout->addWidget(_player_top1_btn, 0, 0);
	setup_grpBox_layout->addWidget(_player_top2_btn, 0, 1);
	setup_grpBox_layout->addWidget(_player_bottom1_btn, 1, 0);
	setup_grpBox_layout->addWidget(_player_bottom2_btn, 1, 1);

	setup_grpBox->setLayout(setup_grpBox_layout);
	//---------------------------------------------------------------------------

	//panel layout
	QGroupBox *grpBox = new QGroupBox;
	QVBoxLayout *vlayout = new QVBoxLayout;

	QLabel *label = new QLabel("ConquestTD");
	QFont font;
	QPalette palette;
	palette.setColor(QPalette::WindowText, QColor("red"));
	font.setBold(true);
	font.setPointSize(30);
	label->setFont(font);
	label->setPalette(palette);
	
	vlayout->addWidget(label, 1, Qt::AlignCenter);
	vlayout->addSpacing(100);
	vlayout->addWidget(btnGrp, 1, Qt::AlignCenter);
	vlayout->addWidget(setup_grpBox, 1);
	vlayout->addSpacing(400);
	vlayout->addWidget(_play_btn, 1, Qt::AlignCenter);
	vlayout->addWidget(_waiting_label, 1, Qt::AlignTop | Qt::AlignHCenter);

	grpBox->setLayout(vlayout);
	//---------------------------------------------------------------------------

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(grpBox);
	setLayout(layout);
}

void StartPanel::setWaitingForPlayers(bool value)
{
	_waiting = value;
	_waiting_label->setVisible(value);
	if (value) {
		_play_btn->setText("Stop");
	}
	else {
		_play_btn->setText("Play");
	}
}

void StartPanel::reset()
{
	_2Player_radioBtn->setChecked(true);
	_player_top2_btn->setVisible(false);
	_player_bottom2_btn->setVisible(false);
	_player_bottom1_btn->setText("bot");
	_player_bottom2_btn->setText("bot");
	_player_top1_btn->setText("bot");
	_player_top2_btn->setText("bot");
	_player_bottom1_btn->setEnabled(true);
	_player_bottom2_btn->setEnabled(true);
	_player_top1_btn->setEnabled(true);
	_player_top2_btn->setEnabled(true);
}

void StartPanel::gamemodeChanged(int id)
{
	switch (id) {
	case Controller::twoPlayer:
		_2Player_radioBtn->setChecked(true);
		_player_top2_btn->setVisible(false);
		_player_bottom2_btn->setVisible(false);
		break;

	case Controller::fourPLayer:
		_4Player_radioBtn->setChecked(true);
		_player_top2_btn->setVisible(true);
		_player_bottom2_btn->setVisible(true);
		break;
	}
}

void StartPanel::requestGamemode(int id)
{
	_controller->requestGamemode(id);
}

void StartPanel::playClicked()
{
	if (_waiting) {
		emit stopWaiting();
	}
	else {
		emit readyPlay();
	}
}

void StartPanel::requestTopLeft()
{
	_controller->requestPosition(Controller::TopLeft);
}

void StartPanel::requestTopRight()
{
	_controller->requestPosition(Controller::TopRight);
}

void StartPanel::requestBottomLeft()
{
	_controller->requestPosition(Controller::BottomLeft);
}

void StartPanel::requestBottomRight()
{
	_controller->requestPosition(Controller::BottomRight);
}

void StartPanel::setPosition(QString *name, int position, bool lock)
{
	switch (position)
	{
	case Controller::TopLeft:
		if (name == 0) {
			_player_top1_btn->setText("bot");
			_player_top1_btn->setEnabled(true);
		}
		else {
			_player_top1_btn->setText(*name);
			if(lock)
				_player_top1_btn->setEnabled(false);
		}
		break;
	case Controller::TopRight:
		if (name == 0) {
			_player_top2_btn->setText("bot");
			_player_top2_btn->setEnabled(true);
		}
		else {
			_player_top2_btn->setText(*name);
			if (lock)
				_player_top2_btn->setEnabled(false);
		}
		break;
	case Controller::BottomLeft:
		if (name == 0) {
			_player_bottom1_btn->setText("bot");
			_player_bottom1_btn->setEnabled(true);
		}
		else {
			_player_bottom1_btn->setText(*name);
			if (lock)
				_player_bottom1_btn->setEnabled(false);
		}
		break;
	case Controller::BottomRight:
		if (name == 0) {
			_player_bottom2_btn->setText("bot");
			_player_bottom2_btn->setEnabled(true);
		}
		else {
			_player_bottom2_btn->setText(*name);
			if (lock)
				_player_bottom2_btn->setEnabled(false);
		}
		break;
	}
}
