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
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QToolBar>
#include <QRadioButton>
#include <QDockWidget>
#include <QErrorMessage>
#include <QListWidget>
#include <QComboBox>
#include <QLabel>
#include <cmath>
#include <cstdlib>

class MainWindow : public QMainWindow {
	Q_OBJECT
  
	public:
		explicit MainWindow();
		~MainWindow();

		void show();
  
	private:	
		//Menu Bar components
		/*QMenuBar *mb;
		QMenu *file;
		QAction *start;
		QAction *quit;*/
		
		//Tool bar components
		//QToolBar *toolBar;
		
		//Central widget components
		GraphicsWindow *game;
		
		//Message for errors, etc.
		QErrorMessage *error;
		
		//Bottom dock widget components - Text box to display errors
		/*QDockWidget *outputs;
		QPlainTextEdit *textBox;*/

	public slots:
		//Starts a new puzzle
		void pressStart();
};

#endif
