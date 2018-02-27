#pragma once
#include <QDialog>

class Controller;
class QGridLayout;
class QPushButton;
class QLineEdit;
class QLabel;
class QCheckBox;

class ServerDialog : public QDialog
{
	Q_OBJECT

public:
	ServerDialog(QWidget *parent = 0, Controller *controller = 0);
	~ServerDialog();

private:
	Controller *_controller;

	QPushButton *_server_run_btn;
	QPushButton *_server_connect_btn;
	QPushButton *_done_btn;
	QLineEdit *_ip_lineedit;
	QLineEdit *_port_lineedit;
	QLineEdit *_name_lineedit;
	QLabel *_server_info_label;
	QLabel *_connection_info_label;
	QCheckBox *_auto_connect_chkBox;

	void setupLayout(QGridLayout* layout);

private slots:
	void onServerRunBtnClicked();
	void onConnectBtnClicked();
	void hostError();
	void connected();
	void disconnected();
	
};

