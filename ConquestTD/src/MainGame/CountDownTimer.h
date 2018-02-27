#pragma once
#include <QObject>

class QTimer;
class QTime;
class QString;

class CountDownTimer : public QObject
{
	Q_OBJECT

public:
	CountDownTimer(int minutes = 0, int seconds = 0, QObject *parent = 0);
	~CountDownTimer();

	QString toString();

private:
	QTimer *_second_timer;
	QTime *_time;

signals:
	void finished();
	void updated();

public slots :
	void start();
	void stop();
	void setTimer(int minutes, int seconds = 0);

private slots :
	void secondPassed();

};

