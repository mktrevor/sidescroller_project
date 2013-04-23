/** A QWidget to hold the puzzle tiles and handle their movement

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
#include <QPalette>
#include "thug.h"
#include "bulldozer.h"
#include "creep.h"
#include "blade.h"
#include "boxer.h"

class GraphicsWindow : public QWidget {
    Q_OBJECT
    
	public:		
    GraphicsWindow();
    ~GraphicsWindow();
    
    QGraphicsView* getView();

    void show();
    
	private:
		QPixmap *bullPic;
		QVector<Thug*> thugs;
		Bulldozer *bull1;
		Bulldozer *bull2;
		
		Creep *creep1;
		Creep *creep2;
		Creep *creep3;
		Creep *creep4;
		
		Blade *blade1;
		Blade *blade2;
		
		Boxer *boxer1;
		Boxer *boxer2;
		
		QTimer *timer;
    
    //Error message
    QErrorMessage *error;
    
    QGraphicsScene *scene;
    QGraphicsView *view;
    
	public slots:
		void moveThugs();
};

#endif
