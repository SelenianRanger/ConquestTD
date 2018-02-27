#pragma once
#include <QDialog>
#include <QList>

class QVBoxLayout;
class QPushButton;
class CardSelectionScene;
class DeckPreviewScene;
class AbstractCard;
class ResourceManager;
class GameController;

class CardSelectionDialog : public QDialog
{
	Q_OBJECT

public:
	CardSelectionDialog(GameController *game_controller, QWidget *parent = 0);
	~CardSelectionDialog();

	void reset();

private:
	GameController *_game_controller;
	ResourceManager *_resources;
	QList<AbstractCard*> *_cards;

	CardSelectionScene  *_selection_scene;
	DeckPreviewScene *_deck_preview_scene;
	QPushButton *_ready_btn;

	void setupLayout(QVBoxLayout *layout);

private slots:
	void onReadyBtnClicked();
	void update();
	void deckComplete();
	void deckIncomplete();

};

