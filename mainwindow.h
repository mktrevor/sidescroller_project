/** A MainWindow class to hold the game board, menus, and text boxes of a sliding tile puzzle

	@author Trevor Reed
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
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
#include <QKeyEvent>
#include <cmath>
#include <cstdlib>

#include "graphicswindow.h"
#include "ninja.h"

class MainWindow : public QMainWindow {
	Q_OBJECT
  
	public:
		explicit MainWindow();
		~MainWindow();

		void show();
  
	private:	
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
		QPushButton *optionButton;
		
		//Central widget components
		GraphicsWindow *game;
		
		//Message for errors, etc.
		QErrorMessage *error;
    
    //Keyboard commands
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);

	public slots:
		void startSlot();
		void pause();
		void options();
};

#endif
