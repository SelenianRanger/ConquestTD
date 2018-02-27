#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QMessageBox>
#include <QStringList>
#include <QAbstractSocket>

#include "Controller.h"
#include "GameController.h"

//Controller class
Controller::Controller()
	:QObject(), _connected(false), _gamemode(twoPlayer), _server_gamemode(twoPlayer)
{
	//server side
	_server = new QTcpServer;
	_client_list = new QList<Client*>;
	_player_list = new QList<Client*>;

	_id_counter = 0;
	
	connect(_server, SIGNAL(newConnection()), this, SLOT(newConnection()));

	//client side
	_me = new Client(new QTcpSocket);

	connect(_me->socket(), SIGNAL(connected()), this, SLOT(serverConnected()));
	connect(_me->socket(), SIGNAL(disconnected()), this, SLOT(serverDisconnected()));
	connect(_me->socket(), SIGNAL(error()), this, SLOT(serverHostError()));
	connect(_me->socket(), SIGNAL(readyRead()), this, SLOT(clientReadyRead()));

}


Controller::~Controller()
{
}

void Controller::setGameController(GameController *controller)
{
	_game_controller = controller;
}

int Controller::gamemode()
{
	return _gamemode;
}

void Controller::setGamemode(int mode)
{
		_gamemode = mode;
}

int Controller::nextOpenPosition()
{
	int position = None;
	if (isConnected()) {
		bool f = false;
		int pos;
		int limit = (_server_gamemode == twoPlayer) ? TopLeft : TopRight;
		for (pos = BottomLeft; pos <= limit && !f; pos++) {
			f = true;
			for (int i = 0; i < _player_list->size() && f; i++) {
				Client *c = _player_list->at(i);
				if (c->position() == pos) {
					f = false;
				}
			}
		}
		if (f) {
			return pos - 1;
		}
		else {
			return None;
		}
	}
	else {
		return BottomLeft;
	}	
}

//server side
bool Controller::serverRunning()
{
	return _server->isListening();
}

bool Controller::isReadyToStart()
{
	for (int i = 0; i < _player_list->size(); i++) {
		Client *client = _player_list->at(i);
		if (!client->isReady())
			return false;
	}
	return true;
}

void Controller::startServer()
{
	_server->listen(QHostAddress::Any, 25000);
}

void Controller::stopServer()
{
	_server->close();
}

void Controller::requestGamemode(int id)
{
	if (isConnected()) {
		QString str(QString::number(GamemodeChanged));
		str.append("|").append(QString::number(id))
			.append("|");
		_me->socket()->write(str.toUtf8());
	}
	else {
		setGamemode(id);
	}
}

void Controller::newConnection()
{
	QTcpSocket *sok = _server->nextPendingConnection();
	Client *client = new Client(sok);
	client->setID(_id_counter);
	_client_list->append(client);

	connect(client->socket(), SIGNAL(readyRead()), this, SLOT(serverReadyRead()));
	connect(client->socket(), SIGNAL(disconnected()), this, SLOT(clientDisconnected()));

}

void Controller::serverReadyRead()
{
	//check each client for data
	for (int index = 0; index < _client_list->size(); index++) {
		Client *client = _client_list->at(index);
		QTcpSocket *sok = client->socket();
		if (sok->bytesAvailable() > 0) {
			QByteArray data(sok->readAll());
			QString data_str(data);
			QStringList data_tokens = data_str.split("|");

			//decode data
			QString *str;
			int id;
			int mode;
			int position;
			bool available;
			int i = 0;
			while (data_tokens.at(i) != 0) {
			int subject = data_tokens.at(i).toInt();		
				switch ((DataType)subject) {
				case Init:
					client->setName(data_tokens.at(++i));
					str = new QString;
					str->append(QString::number(Init));
					str->append("|").append(QString::number(_id_counter)).append("|").append(QString::number(_server_gamemode)).append("|");
					for (int j = 0; j < _player_list->size(); j++) {
						Client *c = _player_list->at(j);
						str->append(QString::number(c->position())).append("|").append(c->name()).append("|");
					}
					str->append("|");
					sok->write(str->toUtf8());

					_id_counter++;
					break;
				case OpenPositionRequest:
					position = nextOpenPosition();
					if (position != None) {
						str = new QString;
						str->append(QString::number(PositionSet))
							.append("|").append(QString::number(client->id()))
							.append("|").append(client->name())
							.append("|").append(QString::number(position)).append("|");

						for (int j = 0; j < _client_list->size(); j++) {
							Client *c = _client_list->at(j);
							c->socket()->write(str->toUtf8());
						}
						client->setPosition(position);
						_player_list->append(client);
					}
					break;
				case PositionRequest:
					id = data_tokens.at(++i).toInt();
					position = data_tokens.at(++i).toInt();
					available = true;
					for (int j = 0; j < _player_list->size() && available; j++) {
						Client *c = _player_list->at(j);
						if (c->position() == position)
							available = false;
					}
					if (available) {
						//set new position
						str = new QString;
						str->append(QString::number(PositionSet))
							.append("|").append(QString::number(id))
							.append("|").append(client->name())
							.append("|").append(QString::number(position)).append("|");

						for (int j = 0; j < _client_list->size(); j++) {
							Client *c = _client_list->at(j);
							c->socket()->write(str->toUtf8());
						}
						//empty last position
						int lastpos = client->position();
						if (lastpos != None) {
							str = new QString;
							str->append(QString::number(PositionSet))
								.append("|").append(QString::number(-1))
								.append("|").append(client->name())
								.append("|").append(QString::number(lastpos)).append("|");
							for (int j = 0; j < _client_list->size(); j++) {
								Client *c = _client_list->at(j);
								c->socket()->write(str->toUtf8());
							}
						}
						else {
							_player_list->append(client);
						}

						client->setPosition(position);
					}

					else {
						Client *who;
						for (int j = 0; j < _player_list->size(); j++) {
							Client *c = _player_list->at(j);
							if (c->position() == position) {
								who = c;
								_player_list->removeAt(j);
								break;
							}
						}
						str = new QString;
						str->append(QString::number(PositionSet))
							.append("|").append(QString::number(-1))
							.append("|").append(who->name())
							.append("|").append(QString::number(position)).append("|");
						for (int j = 0; j < _client_list->size(); j++) {
							Client *c = _client_list->at(j);
							c->socket()->write(str->toUtf8());
						}
						who->setPosition(None);
					}

					break;
				case GamemodeChanged:
					mode = data_tokens.at(++i).toInt();
					_server_gamemode = mode;
					str = new QString(QString::number(GamemodeChanged));
					str->append("|").append(QString::number(mode))
						.append("|");
					for (int i = 0; i < _client_list->size(); i++) {
						Client *c = _client_list->at(i);
						c->socket()->write(str->toUtf8());
					}

					break;
				case ReadyToPlay:
					client->setReady(true);
					if (isReadyToStart()) {
						str = new QString;
						str->append(QString::number(StartGame)).append("|");
						for (int j = 0; j < _player_list->size(); j++) {
							Client *c = _player_list->at(j);
							c->socket()->write(str->toUtf8());
						}
					}

					break;
				case NotReadyToPlay:
					client->setReady(false);
					str = new QString(QString::number(StopGame));
					str->append("|");
					for (int j = 0; j < _player_list->size(); j++) {
						Client *c = _player_list->at(j);
						c->socket()->write(str->toUtf8());
					}
					break;
				//Game Controller Data
				case PauseToggle:
					str = new QString(QString::number(PauseToggle));
					str->append("|");
					for (int j = 0; j < _player_list->size(); j++) {
						Client *c = _player_list->at(j);
						c->socket()->write(str->toUtf8());
					}

					break;
				default:
					break;
				}
				i++;
			}
		}
	}
}

void Controller::clientDisconnected()
{
	for (int i = 0; i < _client_list->size(); i++) {
		Client *client = _client_list->at(i);
		QString str;
		if (client->socket()->state() == QAbstractSocket::UnconnectedState) {
			_client_list->removeAt(i);
			str.append(QString::number(PositionSet))
				.append("|").append(QString::number(-1))
				.append("|").append(client->name())
				.append("|").append(QString::number(client->position())).append("|");
			for (int j = 0; j < _client_list->size(); j++) {
				Client *c = _client_list->at(j);
				c->socket()->write(str.toUtf8());
			}
		}
	}
	for (int i = 0; i < _player_list->size(); i++) {
		Client *client = _player_list->at(i);
		if (client->socket()->state() == QAbstractSocket::UnconnectedState) {
			_player_list->removeAt(i);
		}
	}
}

//client side
void Controller::setName(QString name)
{
	_me->setName(name);
}

bool Controller::isConnected()
{
	return _connected;
}

void Controller::connectToServer(QHostAddress &ip, int &port)
{
	_me->socket()->connectToHost(ip, port);
}

void Controller::requestPosition(int position)
{
	if (isConnected()) {
		QString str(QString::number(PositionRequest));
		str.append("|").append(QString::number(_me->id()))
			.append("|").append(QString::number(position)).append("|");

		_me->socket()->write(str.toUtf8());
	}
	else {
		int lastpos = _me->position();
		_me->setPosition(position);
		emit positionSet(new QString("You"), position);
		if(lastpos != None && lastpos != position)
			emit positionSet(0, lastpos);
	}
}

void Controller::requestNextOpenPosition()
{
	if (isConnected()) {
		QString str(QString::number(OpenPositionRequest));
		str.append("|");
		_me->socket()->write(str.toUtf8());
	}
	else {
		requestPosition(nextOpenPosition());
	}
}

void Controller::setReadyPlay(bool value)
{
	if (value) {
		QString str(QString::number(ReadyToPlay));
		str.append("|");
		_me->socket()->write(str.toUtf8());
	}
	else {
		QString str(QString::number(NotReadyToPlay));
		str.append("|");
		_me->socket()->write(str.toUtf8());
	}
	_me->setReady(value);
}

void Controller::disconnect()
{
	_me->socket()->disconnectFromHost();
}

void Controller::requestPause()
{
	QString str(QString::number(PauseToggle));
	str.append("|");

	_me->socket()->write(str.toUtf8());
}

void Controller::serverConnected()
{
	//initialize client on server
	QString str(QString::number(Init));
	str.append("|").append(_me->name()).append("|");
	_me->socket()->write(str.toUtf8());

	_connected = true;
	emit connected();
}

void Controller::serverDisconnected()
{
	_connected = false;
	emit disconnected();
	requestNextOpenPosition();
}

void Controller::serverHostError()
{
	emit hostError();
}

void Controller::clientReadyRead()
{
	//tokenize message
	QByteArray data = _me->socket()->readAll();
	QString data_str(data);
	QStringList data_tokens = data_str.split("|");

	//decode data
	int id;
	int mode;
	QString *name;
	int position;
	int i = 0;
	while (data_tokens.at(i) != 0) {
		int subject = data_tokens.at(i).toInt();
		switch ((DataType)subject) {
		case Init:
			_me->setID(data_tokens.at(++i).toInt());
			mode = data_tokens.at(++i).toInt();
			emit init();
			emit gamemodeChanged(mode);
			while (data_tokens.at(++i) != 0) {
				position = data_tokens.at(i).toInt();
				name = new QString(data_tokens.at(++i));
				emit positionSet(name, position);
			}

			requestNextOpenPosition();

			break;
		case GamemodeChanged:
			mode = data_tokens.at(++i).toInt();
			emit gamemodeChanged(mode);

			break;
		case PositionSet:
			id = data_tokens.at(++i).toInt();
			name = new QString(data_tokens.at(++i));
			position = data_tokens.at(++i).toInt();
			if (id == -1) {
				emit positionSet(0, position);
				if (position == _me->position())
					_me->setPosition(None);
			}
			else if (id == _me->id()) {
				_me->setPosition(position);
				emit positionSet(new QString("You"), position, false);
			}
			else {
				emit positionSet(name, position);
			}

			break;
		case StartGame:
			emit readyToStart();
			break;
		case StopGame:
			emit stopGame();
			break;
		//Game Controller data
		case PauseToggle:
			_game_controller->togglePaused();
		default:
			break;
		}
		i++;
	}

}

//Controller class end---------------------------------------------------------------------------------------------------------

//Client class
Client::Client(QTcpSocket * sok)
	:_sok(sok), _id(-1), _ready(false), _position(Controller::None)
{

}

Client::~Client()
{

}

QString Client::name()
{
	return _name;
}

bool Client::isReady()
{
	return _ready;
}

int Client::position()
{
	return _position;
}

void Client::setPosition(int position)
{
	_position = position;
}

int Client::id()
{
	return _id;
}

void Client::setName(QString name)
{
	_name = name;
}

void Client::setID(int id)
{
	_id = id;
}

void Client::setReady(bool value)
{
	_ready = value;
}

QTcpSocket * Client::socket()
{
	return _sok;
}

void Client::setSocket(QTcpSocket *sok)
{
	_sok = sok;
}

//Client class end-------------------------------------------------------------------------------------------------------------
