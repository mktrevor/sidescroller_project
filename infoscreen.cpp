#include "infoscreen.h"

/** Constructor - Can create a title screen or game over screen 
	@param type of screen
*/
InfoScreen::InfoScreen(int type) {

  scene = new QGraphicsScene();
  setScene(scene);
  scene->setSceneRect(0,0,1200,600);
	
	switch(type) {
		case 0:
  	background = new QImage("sprites/titlescreen.png");
  	break;
  	
		case 1:
  	background = new QImage("sprites/gameover.png");
  	break;
  }
	
	setBackgroundBrush(*background);
	
  setMinimumSize(1200, 600);
  setMaximumSize(1200, 600);
}

/** Deconstructor */
InfoScreen::~InfoScreen() {
	delete background;
	delete scene;
} 
