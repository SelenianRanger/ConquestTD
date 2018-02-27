#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QSpacerItem>
#include <QString>
#include <QHostAddress>
#include <QMessageBox>
#include <QCheckBox>

#include "src/Controller/Controller.h"
#include "ServerDialog.h"

ServerDialog::ServerDialog(QWidget *parent, Controller *controller)
	:QDialog(parent), _controller(controller)
{
	setWindowTitle("Server Options");
	setFixedSize(400, 150);

	_server_run_btn = new QPushButton("Start Server");
	_server_connect_btn = new QPushButton("connect");
	_done_btn = new QPushButton("Done");
	_ip_lineedit = new QLineEdit;
	_port_lineedit = new QLineEdit;
	_name_lineedit = new QLineEdit("Player");
	_server_info_label = new QLabel("server running on port 25000");
	_connection_info_label = new QLabel;
	_auto_connect_chkBox = new QCheckBox("Auto-Connect");

	_ip_lineedit->setPlaceholderText("Server IP");
	_ip_lineedit->setFixedWidth(120);
	_port_lineedit->setPlaceholderText("Server Port");
	_port_lineedit->setFixedWidth(70);
	_name_lineedit->setPlaceholderText("Display Name");
	_name_lineedit->setFixedWidth(200);
	_server_info_label->setVisible(false);
	_connection_info_label->setVisible(false);

	QGridLayout *layout = new QGridLayout(this);
	setupLayout(layout);
	setLayout(layout);

	connect(_controller, SIGNAL(connected()), this, SLOT(connected()));
	connect(_controller, SIGNAL(disconnected()), this, SLOT(disconnected()));
	connect(_controller, SIGNAL(hostError()), this, SLOT(hostError()));

	connect(_server_run_btn, SIGNAL(clicked()), this, SLOT(onServerRunBtnClicked()));
	connect(_server_connect_btn, SIGNAL(clicked()), this, SLOT(onConnectBtnClicked()));
	connect(_done_btn, SIGNAL(clicked()), this, SLOT(accept()));
}

ServerDialog::~ServerDialog()
{
}

void ServerDialog::setupLayout(QGridLayout* layout)
{
	int row = 0;
	//first row
	layout->addWidget(new QLabel("Name:"), row, 0);
	layout->addWidget(_name_lineedit, row, 1);
	layout->addWidget(_server_run_btn, row, 2);

	//next row
	row++;
	layout->addWidget(_server_info_label, row, 1);
	layout->addWidget(_auto_connect_chkBox, row, 2);

	//next row
	row++;
	layout->addWidget(new QLabel("IP:"), row, 0);
	layout->addWidget(_ip_lineedit, row, 1);

	//next row
	row++;
	layout->addWidget(new QLabel("Port:"), row, 0);
	layout->addWidget(_port_lineedit, row, 1);
	layout->addWidget(_server_connect_btn, row, 2);

	//last row
	row++;
	layout->addWidget(_connection_info_label, row, 1);
	layout->addWidget(_done_btn, row, 2);
}

void ServerDialog::onServerRunBtnClicked()
{
	if (_controller->serverRunning()) {
		_controller->stopServer();

		_server_run_btn->setText("Start Server");
		_server_info_label->setVisible(false);
		if(!_controller->isConnected())
			_auto_connect_chkBox->setEnabled(true);
	}
	else {
		_controller->startServer();

		_server_run_btn->setText("Stop Server");
		_server_info_label->setVisible(true);
		_auto_connect_chkBox->setEnabled(false);

		if (!_controller->isConnected() && _auto_connect_chkBox->isChecked()) {
			_ip_lineedit->setText("127.0.0.1");
			_port_lineedit->setText("25000");
			_server_connect_btn->click();
		}
	}

}

void ServerDialog::onConnectBtnClicked()
{
	if (_controller->isConnected()) {
		_controller->disconnect();
	}
	else {
		_controller->setName(_name_lineedit->text());

		QString ip_str = _ip_lineedit->text();
		QString port_str = _port_lineedit->text();
		QHostAddress ip(ip_str);
		int port = port_str.toInt();

		_controller->connectToServer(ip, port);
		_connection_info_label->setVisible(true);
		_connection_info_label->setText("connecting...");
	}
}

void ServerDialog::hostError()
{
	QMessageBox::critical(this, "Server Not Found", "could not connect to server");
	_connection_info_label->setVisible(true);
	_connection_info_label->setText("connection failed.");
}

void ServerDialog::connected()
{
	_server_connect_btn->setText("Disconnect");
	_name_lineedit->setEnabled(false);

	_ip_lineedit->setEnabled(false);
	_port_lineedit->setEnabled(false);

	_auto_connect_chkBox->setEnabled(false);

	_connection_info_label->setVisible(true);
	_connection_info_label->setText("connection successful.");

}

void ServerDialog::disconnected()
{
	_server_connect_btn->setText("Connect");
	_name_lineedit->setEnabled(true);

	_ip_lineedit->setEnabled(true);
	_port_lineedit->setEnabled(true);

	if(!_controller->serverRunning())
		_auto_connect_chkBox->setEnabled(true);
	
	_connection_info_label->setVisible(true);
	_connection_info_label->setText("disconnected.");
}
