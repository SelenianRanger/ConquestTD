#pragma once
#include <QGraphicsScene>

class QObject;
class QGraphicsView;
class QTimer;
class CardInfo;

class CreditBar : public QGraphicsScene
{
	Q_OBJECT

public:
	CreditBar(QObject *parent = 0);
	~CreditBar();

	int credits();

	QGraphicsView* view();

private:
	QTimer *_timer;

	bool _preview;
	CardInfo *_preview_info;
	int _credits;
	const int UPPER_LIMIT = 5000;

	QGraphicsView *_view;

signals:
	void updated(int value);

public slots:
	void setCredits(int credits);
	void addCredits(int credits);
	void setPreview(CardInfo *info);
	void stopPreview();
	void start();
	void stop();

private slots:
	void timedout();

protected:
	virtual void drawForeground(QPainter *painter, const QRectF &rect) override;
	virtual void drawBackground(QPainter *painter, const QRectF &rect) override;

};

