/** A QWidget to hold the puzzle tiles and handle their movement

	@author Trevor Reed
*/
#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QErrorMessage>

class GraphicsWindow : public QWidget {
    Q_OBJECT
    
public:		
    GraphicsWindow();
    ~GraphicsWindow();
    
    QGraphicsView* getView();

    void show();
    
private:
    
    //Error message
    //QErrorMessage *error;
    
    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif
