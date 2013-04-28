#ifndef QUESTIONBOX_H
#define QUESTIONBOX_H

#include <QMessageBox>

class QuestionBox : public QMessageBox {
	public:
		QuestionBox(QString text, QString title);
		~QuestionBox();
	
	private:
};

#endif
