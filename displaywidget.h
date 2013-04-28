#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>

class DisplayWidget : public QWidget {
	Q_OBJECT

	private:
		QHBoxLayout *displayLayout;
		QLabel *scoreLabel;
		QLabel *nameLabel;
		QLabel *healthLabel;
		QLabel *livesLabel;
		QLineEdit *score;
		QLineEdit *name;
		QLineEdit *health;
		QLineEdit *lives;
   
  public:
		DisplayWidget();
		~DisplayWidget();
		void setScore(QString score);
		void setName(QString name);
		void setLives(QString lives);
		void setHealth(QString health);
};

#endif
