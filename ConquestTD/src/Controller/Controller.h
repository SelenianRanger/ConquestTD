#pragma once
#include <QObject>
#include <QTcpSocket>
#include <QList>

class QTcpServer;
class QHostAddress;
class Client;
class QString;
class GameController;

class Controller : public QObject
{
	Q_OBJECT

public:
	Controller();
	~Controller();

	enum DataType { Init = 0, OpenPositionRequest, PositionRequest, NotReadyToPlay, ReadyToPlay, GamemodeChanged, PositionSet, StartGame, PauseToggle, StopGame };
	enum Position { None = 0, BottomLeft, TopLeft, BottomRight, TopRight };
	enum GameMode { twoPlayer, fourPLayer };

	void setGameController(GameController *controller);

	int gamemode();
	void setGamemode(int mode);
	int nextOpenPosition();

	//server side
	bool serverRunning();

	//client side
	void setName(QString name);

	bool isConnected();

private:
	GameController *_game_controller;

	int _gamemode;

	//server side
	int _id_counter;
	int _server_gamemode;

	QTcpServer *_server;
	QList<Client*> *_client_list;
	QList<Client*> *_player_list;

	bool isReadyToStart();

	//client side
	Client *_me;

	bool _connected;

public slots:
	//server side
	void startServer();
	void stopServer();
	void requestGamemode(int id);

	//client side
	void connectToServer(QHostAddress &ip, int &port);
	void requestPosition(int position);
	void requestNextOpenPosition();
	void setReadyPlay(bool value);
	void disconnect();

	void requestPause();

private slots:
	//server side
	void newConnection();
	void serverReadyRead();
	void clientDisconnected();

	//client side
	void serverConnected();
	void serverDisconnected();
	void serverHostError();
	void clientReadyRead();

signals:
	//server side
	void connected();
	void disconnected();
	void hostError();

	//client side
	void init();
	void readyToStart();
	void stopGame();
	void positionSet(QString *name, int position, bool lock = true);
	void gamemodeChanged(int mode);

};

class Client
{
public:
	Client(QTcpSocket * sok);
	~Client();

	int id();
	QString name();
	bool isReady();
	int position();

	void setPosition(int position);
	void setName(QString name);
	void setID(int id);
	void setReady(bool value);

	QTcpSocket *socket();
	void setSocket(QTcpSocket *sok);

private:
	int _id;
	QString _name;
	int _position;

	bool _ready;
	QTcpSocket *_sok;

};

