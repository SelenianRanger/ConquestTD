#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QObject>
#include <QMessageBox>
#include <QGraphicsView>

#include "GamePanel.h"
#include "CountDownTimer.h"
#include "CreditBar.h"
#include "DeckScene.h"
#include "src/Controller/GameController.h"
#include "src/Assests/Cards/CardInfo.h"

GamePanel::GamePanel(GameController *game_controller, QWidget *parent)
	:QWidget(parent), _game_controller(game_controller)
{
	_countDown_timer = new CountDownTimer(3);

	_countDown_label = new QLabel("00 : 00");
	_credit_bar = new CreditBar;
	_credits_label = new QLabel("Credits: 0");
	_deck_scene = new DeckScene();
	_pause_label = new QLabel("-Game Paused-");

	_pause_label->setVisible(false);

	QFont font;
	font.setPointSize(20);
	font.setBold(true);
	_countDown_label->setFont(font);

	font.setPointSize(10);
	font.setBold(false);
	font.setItalic(true);
	_pause_label->setFont(font);

	QVBoxLayout *layout = new QVBoxLayout;
	setupLayout(layout);
	setLayout(layout);

	connect(_countDown_timer, SIGNAL(updated()), this, SLOT(timerUpdated()));
	connect(_credit_bar, SIGNAL(updated(int)), this, SLOT(updateCredits(int)));
	connect(_game_controller, SIGNAL(deckSet()), this, SLOT(updateDeck()));
	connect(_deck_scene, SIGNAL(previewStart(CardInfo*)), _credit_bar, SLOT(setPreview(CardInfo*)));
	connect(_deck_scene, SIGNAL(previewStop()), _credit_bar, SLOT(stopPreview()));

}

GamePanel::~GamePanel()
{
}

void GamePanel::reset()
{
	_countDown_timer->stop();
	_credit_bar->stop();
	_countDown_timer->setTimer(3);
	_credit_bar->setCredits(0);
}

void GamePanel::setupLayout(QVBoxLayout *layout)
{
	layout->addWidget(_countDown_label, 0, Qt::AlignTop | Qt::AlignHCenter);
	layout->addWidget(_pause_label, 0, Qt::AlignTop | Qt::AlignHCenter);
	layout->addWidget(_credits_label, 0, Qt::AlignBottom | Qt::AlignHCenter);
	layout->addWidget(_credit_bar->view(), 0, Qt::AlignHCenter);
	layout->addWidget(_deck_scene->view(), 0, Qt::AlignTop | Qt::AlignHCenter);
}

void GamePanel::start()
{
	_countDown_timer->start();
	_credit_bar->start();
	_pause_label->setVisible(false);
}

void GamePanel::stop()
{
	_countDown_timer->stop();
	_credit_bar->stop();
	_pause_label->setVisible(true);
}

void GamePanel::setPaused(bool value)
{
	if (value)
		stop();
	else
		start();
	_deck_scene->setPaused(value);
}

void GamePanel::timerUpdated()
{
	_countDown_label->setText(_countDown_timer->toString());
}

void GamePanel::updateDeck()
{
	_deck_scene->setDeck(_game_controller->deck());
}

void GamePanel::updateCredits(int value)
{
	_credits_label->setText(QString("Credits: ").append(QString::number(_credit_bar->credits())));
}
