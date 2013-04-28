#include "questionbox.h"

/** Constructor */
QuestionBox::QuestionBox(QString text, QString title) {
	setText(text);
	setWindowTitle(title);
	addButton(QMessageBox::Yes);
	addButton(QMessageBox::No);
	
}

/** Deconstructor */
QuestionBox::~QuestionBox() { }	
