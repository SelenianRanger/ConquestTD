#include <QHBoxLayout>
#include <QGraphicsView>
#include <QMessageBox>

#include "StartPage.h"
#include "StartPanel.h"
#include "src/GameScene/GameScene.h"
#include "src/Controller/Controller.h"

StartPage::StartPage(Controller *controller, QWidget *parent)
	:QWidget(parent)
{
	setFixedSize(825, 825);

	_str_panel = new StartPanel(controller);
	_gameScene = new GameScene;

	//Layout
	QHBoxLayout *hlayout = new QHBoxLayout;
	hlayout->setSpacing(0);

	hlayout->addWidget(_gameScene->view(), 0);
	hlayout->addWidget(_str_panel, 0);

	setLayout(hlayout);

	connect(_str_panel, SIGNAL(readyPlay()), this, SLOT(readyPlay()));
	connect(_str_panel, SIGNAL(stopWaiting()), this, SLOT(stopWaiting()));


}

StartPage::~StartPage()
{
}

void StartPage::setWaitingForPlayers(bool value)
{
	_str_panel->setWaitingForPlayers(value);
}

void StartPage::readyPlay()
{
	emit readyToPlay();
}

void StartPage::stopWaiting()
{
	emit stopWaitingForPlayers();
}
