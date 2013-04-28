#include "questionbox.h"

QuestionBox::QuestionBox(QString text, QString title) {
	setText(text);
	setWindowTitle(title);
	addButton(QMessageBox::Yes);
	addButton(QMessageBox::No);
	
}

QuestionBox::~QuestionBox() { }	
