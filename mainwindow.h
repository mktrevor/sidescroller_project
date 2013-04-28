/** A MainWindow class to hold the game window, menus, and text boxes of the Magic Ninja game

	@author Trevor Reed
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QToolBar>
#include <QDockWidget>
#include <QErrorMessage>
#include <QLabel>
#include <QLineEdit>
#include <QKeyEvent>
#include <QHBoxLayout>
#include <QInputDialog>
#include <cstdlib>
#include "displaywidget.h"
#include "graphicswindow.h"
#include "infoscreen.h"
#include "questionbox.h"
#include "ninja.h"

class MainWindow : public QMainWindow {
	Q_OBJECT
  
	public:
		explicit MainWindow();
		~MainWindow();

		void show();
  
	private:	
		QString name;
		
		//Menu Bar components
		QMenuBar *mb;
		QMenu *file;
		QAction *start;
		QAction *quit;
		
		//Tool bar components
		QToolBar *toolBar;
		QPushButton *startButton;
		QPushButton *quitButton;
		QPushButton *pauseButton;
		bool paused;
		
		//Central widget components
		GraphicsWindow *game;
		bool gameInProgress;
		//Extra screens
		InfoScreen *title;
		InfoScreen *gameOver;
		
		//Top dock widget (for showing score, name, health, etc.)
		QDockWidget *display;
		DisplayWidget *displayWidget;
		
		//Message for errors, etc.
		QErrorMessage *error;
		QuestionBox *question;
		QInputDialog *inputName;
    
    //Keyboard commands
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);

	public slots:
		void startSlot();
		void pause();
		void quitGame();
		
		void update();
};

#endif
