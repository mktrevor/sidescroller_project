#include "graphicswindow.h"

using namespace std;

/** Constructor - creates a new GraphicsWindow with either 9 or 16 tiles 
	@param dimension of board (3 or 4)
*/
GraphicsWindow::GraphicsWindow() {
	error = new QErrorMessage;
  scene = new QGraphicsScene();
  setScene(scene);

  counter = 0;
  score = 0;
  
  scene->setSceneRect(0,0,1000,600);
  setMinimumSize(1200, 600);
  setMaximumSize(1200, 600);
  
  setBackgroundBrush(QImage("sprites/background1.png"));
  //setCacheMode(QGraphicsView::CacheBackground);
  timer = new QTimer;
  timer->setInterval(70);
  interval = 70;
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  
  ninja = new Ninja();
  scene->addItem(ninja);
}

/** Deconstructor - deletes the messageBox, tiles, scene and view */
GraphicsWindow::~GraphicsWindow() {
	timer->stop();
	delete timer;
	for(int i = 0; i < thugs.size(); i++) {
		delete thugs[i];
	}
	for(int i = 0; i < knives.size(); i++) {
		delete knives[i];
	}
	delete ninja;
	delete error;
	delete scene;
}

Ninja* GraphicsWindow::getNinja() {
	return ninja;
}

void GraphicsWindow::fireball(int direction) {
	if(!timer->isActive()) {
		return;
	}
	Fireball* fire;
	fire = ninja->shoot(direction);
	if(fire != NULL) {
		scene->addItem(fire);
	}
}

int GraphicsWindow::getScore() {
	return score;
}

void GraphicsWindow::start() {
  timer->start();
}

QTimer* GraphicsWindow::getTimer() {
	return timer;
}

void GraphicsWindow::moveThugs() {
	for(int i = 0; i < thugs.size(); i++) {
		thugs[i]->move();
		if(thugs[i]->getKnifeCheck()) {
			knives.push_back(thugs[i]->throwKnife());
			scene->addItem(knives[knives.size() - 1]);
		}
	}
	for(int i = 0; i < knives.size(); i++) {
		knives[i]->update();
	}
}

void GraphicsWindow::checkDead() {
	int numThugs = thugs.size();
	for(int i = 0; i < numThugs; i++) {
		if(thugs[i]->isDead() == 1) {
			delete thugs[i];
			thugs.remove(i);
			score += 100;
		}
	}
}

bool GraphicsWindow::gameOver() {
	return ninja->getDead();
}

void GraphicsWindow::update() {
	
	checkDead();
	moveThugs();
	
	ninja->update();
	
	counter += 1;
	score++;
	
	if(counter > 4000/interval && interval > 15) {
		interval -= 1;
		timer->setInterval(interval);
		counter = 0;
	}
	
	for(int i = 0; i < thugs.size(); i++) {
		for(int j = 0; j < ninja->getFire()->size(); j++) {
			if(thugs[i]->collidesWithItem(ninja->getFire()->at(j))) {
				thugs[i]->hit();
				delete ninja->getFire()->at(j);
				ninja->getFire()->remove(j);
			}
		}
	}
	
	for(int i = 0; i < thugs.size(); i++) {
		if(thugs[i]->collidesWithItem(ninja)) {
			ninja->hit();
		}
	}
	
	for(int i = 0; i < knives.size(); i++) {
		if(knives[i]->collidesWithItem(ninja)) {
			ninja->hit();
			ninja->hit();
			ninja->hit();
			delete knives[i];
			knives.remove(i);
		}
		if(knives[i]->getPos().x() < -200 || knives[i]->getPos().y() > 1200) {
			delete knives[i];
			knives.remove(i);
		}
	}
	
	srand(rand() * counter);
	int num = rand() % 1200;
	switch(num) {
		case 0:
		thugs.push_back(new Creep(0));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 1:
		thugs.push_back(new Creep(1));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 2:
		thugs.push_back(new Creep(2));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 3:
		thugs.push_back(new Creep(3));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 4:
		thugs.push_back(new Creep(4));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 5:
		thugs.push_back(new Creep(5));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 6:
		case 7:
		thugs.push_back(new Jumper(0));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 9:
		case 10:
		thugs.push_back(new Jumper(1));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 12:
		case 13:
		case 14:
		thugs.push_back(new Bulldozer(0));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 15:
		case 16:
		case 17:
		thugs.push_back(new Bulldozer(1));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 18:
		case 19:
		case 20:
		thugs.push_back(new Boxer(0, rand() + counter));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 21:
		case 22:
		case 23:
		thugs.push_back(new Boxer(1, rand() + counter));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 24:
		thugs.push_back(new Blade(0));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 25:
		thugs.push_back(new Blade(1));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 26:
		thugs.push_back(new Blade(2));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 27:
		thugs.push_back(new Blade(3));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 28:
		thugs.push_back(new Blade(4));
		scene->addItem(thugs[thugs.size()-1]);
		break;
		
		case 29:
		thugs.push_back(new Blade(5));
		scene->addItem(thugs[thugs.size()-1]);
		break;
	}
	
	if(ninja->lifeLost()) {
		for(int i = thugs.size() - 1; i >= 0; i--) {
			delete thugs[i];
			thugs.remove(i);
		}
		for(int i = knives.size() - 1; i >= 0; i--) {
			delete knives[i];
			knives.remove(i);
		}
		error->showMessage("You lost a life!");
		error->exec();
	}
}
