#include "graphicswindow.h"

using namespace std;

/** Constructor - creates a new GraphicsWindow with either 9 or 16 tiles 
	@param dimension of board (3 or 4)
*/
GraphicsWindow::GraphicsWindow(int dim) {
	error = new QErrorMessage();
  scene = new QGraphicsScene();
  view = new QGraphicsView( scene );
  dimension = dim;
      
}

/** Deconstructor - deletes the messageBox, tiles, scene and view */
GraphicsWindow::~GraphicsWindow() {
	delete error;
	delete scene;
	delete view;
}

/** Displays the GraphicsWindow */
void GraphicsWindow::show() {
	view->show();
}

/** Returns pointer to the view 
	@return pointer to view
*/
QGraphicsView* GraphicsWindow::getView() {
	return view;
}
