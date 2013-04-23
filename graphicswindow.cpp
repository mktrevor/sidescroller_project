#include "graphicswindow.h"

using namespace std;

/** Constructor - creates a new GraphicsWindow with either 9 or 16 tiles 
	@param dimension of board (3 or 4)
*/
GraphicsWindow::GraphicsWindow() {
	error = new QErrorMessage();
  scene = new QGraphicsScene();
  view = new QGraphicsView( scene );
  
  bull1 = new Bulldozer(0);
  bull2 = new Bulldozer(1);
  scene->addItem(bull1);
  scene->addItem(bull2);
  
  creep1 = new Creep(0);
  scene->addItem(creep1);
  
  creep2 = new Creep(2);
  scene->addItem(creep2);
  
  creep3 = new Creep(3);
  scene->addItem(creep3);
  
  creep4 = new Creep(5);
  scene->addItem(creep4);
  
  blade1 = new Blade(1);
  scene->addItem(blade1);
  
  blade2 = new Blade(4);
  scene->addItem(blade2);
  
  boxer1 = new Boxer(0);
  scene->addItem(boxer1);
  
  boxer2 = new Boxer(1);
  scene->addItem(boxer2);
  
  thugs.push_back(bull1);
  thugs.push_back(bull2);
  thugs.push_back(creep1);
  thugs.push_back(creep2);
  thugs.push_back(creep3);
  thugs.push_back(creep4);
  thugs.push_back(blade1);
  thugs.push_back(blade2);
  thugs.push_back(boxer1);
  thugs.push_back(boxer2);
  
  scene->setSceneRect(0,0,1000, 700);
  setMinimumSize(1000, 700);
  setMaximumSize(1000, 700);
  
  QPalette palette;
  palette.setBrush(this->backgroundRole(), QBrush(QPixmap("sprites/background.png")));
  this->setPalette(palette);
  
  timer = new QTimer;
  timer->setInterval(50);
  connect(timer, SIGNAL(timeout()), this, SLOT(moveThugs()));
  timer->start();
}

/** Deconstructor - deletes the messageBox, tiles, scene and view */
GraphicsWindow::~GraphicsWindow() {
	timer->stop();
	delete timer;
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

void GraphicsWindow::moveThugs() {
	for(int i = 0; i < thugs.size(); i++) {
		thugs[i]->move();
	}
}
