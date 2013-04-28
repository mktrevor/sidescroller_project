/** A QWidget to handle the game display, managing the character and enemy objects and all other gameplay

	@author Trevor Reed
*/
#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsItemAnimation>
#include <QErrorMessage>
#include <ctime>
#include "thug.h"
#include "bulldozer.h"
#include "creep.h"
#include "blade.h"
#include "boxer.h"
#include "jumper.h"
#include "ninja.h"

class GraphicsWindow : public QGraphicsView {
    Q_OBJECT
    
	public:		
    GraphicsWindow();
    ~GraphicsWindow();
    
    Ninja* getNinja();
    void fireball(int direction);

    void show();
    
    int getScore();
    
    bool gameOver();
    
    void start();
    QTimer* getTimer();
    
	private:
		int counter;
		int interval;
		int score;
		
		Ninja *ninja;
		
		QVector<Thug*> thugs;
		QVector<Knife*> knives;
		
		//Error message
		QErrorMessage *error;
		
		QTimer *timer;    
    QGraphicsScene *scene;
    
    //Functions to run in the update SLOT
    void moveThugs();
    void checkDead();
    
	public slots:
		void update();
};

#endif
