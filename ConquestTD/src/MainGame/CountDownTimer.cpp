#include <QTimer>
#include <QTime>
#include <QMessageBox>

#include "CountDownTimer.h"

CountDownTimer::CountDownTimer(int minutes, int seconds, QObject *parent)
	:QObject(parent)
{
	_second_timer = new QTimer;
	_time = new QTime(0, minutes, seconds);
	_second_timer->setInterval(1000);

	connect(_second_timer, SIGNAL(timeout()), this, SLOT(secondPassed()));
}

CountDownTimer::~CountDownTimer()
{
}

QString CountDownTimer::toString()
{
	return _time->toString("mm : ss");
}

void CountDownTimer::start()
{
	_second_timer->start();
	emit updated();
}

void CountDownTimer::stop()
{
	_second_timer->stop();
}

void CountDownTimer::setTimer(int minutes, int seconds)
{
	_time->setHMS(0, minutes, seconds);
	emit updated();
}

void CountDownTimer::secondPassed()
{
	if (_time->minute() == 0 && _time->second() == 0) {
		stop();
		emit finished();
	}
	else {
		setTimer(_time->addSecs(-1).minute(), _time->addSecs(-1).second());
	}
	
}
