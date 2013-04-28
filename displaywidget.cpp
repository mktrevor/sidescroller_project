#include "displaywidget.h"

/** Constructor - creates a new widget with display text boxes and buttons */
DisplayWidget::DisplayWidget() {
	
  displayLayout = new QHBoxLayout;
  
  scoreLabel = new QLabel("SCORE: ");
  nameLabel = new QLabel("NAME: ");
  healthLabel = new QLabel("HEALTH: ");
  livesLabel = new QLabel("LIVES: ");
  
  score = new QLineEdit;
  score->setReadOnly(TRUE);
  name = new QLineEdit;
  name->setReadOnly(TRUE);
  health = new QLineEdit;
  health->setReadOnly(TRUE);
  lives = new QLineEdit;
  lives->setReadOnly(TRUE);
  
  displayLayout = new QHBoxLayout();
  displayLayout->addWidget(nameLabel);
  displayLayout->addWidget(name);
  displayLayout->addWidget(livesLabel);
  displayLayout->addWidget(lives);
  displayLayout->addWidget(healthLabel);
  displayLayout->addWidget(health);
  displayLayout->addWidget(scoreLabel);
  displayLayout->addWidget(score);

	setLayout(displayLayout);
}

/** Deconstructor */
DisplayWidget::~DisplayWidget() {
	delete scoreLabel;
	delete nameLabel;
	delete healthLabel;
	delete livesLabel;
	delete score;
	delete name;
	delete health;
	delete lives;
	delete displayLayout;
}


void DisplayWidget::setScore(QString newScore) {
	score->setText(newScore);
}

void DisplayWidget::setName(QString newName) {
	name->setText(newName);
}

void DisplayWidget::setLives(QString newLives) {
	lives->setText(newLives);
}
	
void DisplayWidget::setHealth(QString newHealth) {
	health->setText(newHealth);
}
