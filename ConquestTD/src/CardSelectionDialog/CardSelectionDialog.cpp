#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QList>

#include "CardSelectionDialog.h"
#include "CardSelectionScene.h"
#include "DeckPreviewScene.h"
#include "src/Assests/Cards/AbstractCard.h"
#include "src/Controller/CardFactory.h"
#include "src/Controller/ResourceManager.h"
#include "src/Controller/GameController.h"

CardSelectionDialog::CardSelectionDialog(GameController *game_controller, QWidget *parent)
	:QDialog(parent), _game_controller(game_controller)
{
	setWindowTitle("Card Selection");
	setFixedSize(1050, 850);

	//cards initialization
	_cards = new QList<AbstractCard *>;

	CardFactory cards;
	_resources = new ResourceManager;

	for (int id = 0; id < ResourceManager::CardEnd; id++) {
		AbstractCard *card = cards.getCard(id, _resources);
		_cards->append(card);
		connect(card, SIGNAL(updated()), this, SLOT(update()));
	}
	//------------------------------------------------------------

	_selection_scene = new CardSelectionScene(_cards);
	_deck_preview_scene = new DeckPreviewScene(_cards);
	_ready_btn = new QPushButton("Ready");
	_ready_btn->setFixedSize(120, 120);
	QFont btnFont;
	btnFont.setPointSize(12);
	_ready_btn->setFont(btnFont);

	QVBoxLayout *layout = new QVBoxLayout;
	setupLayout(layout);
	setLayout(layout);

	connect(_ready_btn, SIGNAL(clicked()), this, SLOT(onReadyBtnClicked()));
	connect(_deck_preview_scene, SIGNAL(deckComplete()), this, SLOT(deckComplete()));
	connect(_deck_preview_scene, SIGNAL(deckIncomplete()), this, SLOT(deckIncomplete()));

}

CardSelectionDialog::~CardSelectionDialog()
{
}

void CardSelectionDialog::reset()
{
	_cards->clear();

	CardFactory cards;

	for (int id = 0; id < ResourceManager::CardEnd; id++) {
		AbstractCard *card = cards.getCard(id, _resources);
		_cards->append(card);
		connect(card, SIGNAL(updated()), this, SLOT(update()));
	}

	_deck_preview_scene->reset();
	_selection_scene->reset();
}

void CardSelectionDialog::setupLayout(QVBoxLayout *layout)
{
	//top label
	QLabel *top_label = new QLabel("Choose 8 Cards");
	QFont font;
	QPalette palette;
	palette.setColor(QPalette::WindowText, QColor(20, 1, 107));
	font.setPointSize(30);
	top_label->setFont(font);
	top_label->setPalette(palette);
	layout->addWidget(top_label, 0, Qt::AlignHCenter|Qt::AlignTop);

	//selection scene
	layout->addWidget(_selection_scene->view(), 0, Qt::AlignHCenter|Qt::AlignTop);

	//bottom layout
	QGroupBox *bottom_grpBox = new QGroupBox("Deck Preview");
	QHBoxLayout *bottom_layout = new QHBoxLayout;

	bottom_layout->addWidget(_deck_preview_scene->view(), Qt::AlignCenter);
	bottom_layout->addWidget(_ready_btn, 0,Qt::AlignCenter);

	bottom_grpBox->setLayout(bottom_layout);

	layout->addWidget(bottom_grpBox);

}

void CardSelectionDialog::onReadyBtnClicked()
{
	//initialize the deck
	QList<AbstractCard*> *deck = new QList<AbstractCard*>;
	for (int i = 0; i < _cards->size(); i++) {
		AbstractCard *card = _cards->at(i);
		if (card->isSelected()) {
			card->setSelected(false);
			card->setSelectable(true);
			deck->append(card);
		}
	}
	
	_game_controller->setDeck(deck);
	accept();
}

void CardSelectionDialog::update()
{
	_deck_preview_scene->update();
}

void CardSelectionDialog::deckComplete()
{
	_ready_btn->setEnabled(true);
	for (int i = 0;i < _cards->size();i++) {
		AbstractCard *card = _cards->at(i);
		card->setSelectable(false);
	}
}

void CardSelectionDialog::deckIncomplete()
{
	_ready_btn->setEnabled(false);
	for (int i = 0;i < _cards->size();i++) {
		AbstractCard *card = _cards->at(i);
		card->setSelectable(true);
	}
}
