#include "ninja.h"

/** Default constructor - Creates a new ninja in the middle of the screen with full health and 3 lives */
Ninja::Ninja() {
	pic = new QPixmap("sprites/ninja1.png");
	setPixmap(*pic);
	
	health = 100;
	lives = 3;
	dead = 0;
	
	x = 500;
	y = 500;
	
	vx = 0;
	vy = 0;
	
	setPos(x,y);
}

/** Deconstructor */
Ninja::~Ninja() {
	delete pic;
}

/** Method for moving right */
void Ninja::moveRight() {
	vx = 12;
}

/** Method for moving left */
void Ninja::moveLeft() {
	vx = -12;
}

/** Method for jumping. Only single jumping is allowed */
void Ninja::jump() {	
	if(y == 500) {
		vy = -50;
	}
}

/** Method to stop the ninja's movement */
void Ninja::stop() {
	vx = 0;
}

/** Method to create a shoot a new fireball
	@return pointer to fireball 
*/
Fireball* Ninja::shoot(int direction) {
	if(fireballs.size() < 4) {
		fireballs.push_back(new Fireball(direction, x, y));
		return fireballs[fireballs.size() - 1];
	}
	return NULL;
}

/** Returns list of fireballs */
QVector<Fireball*>* Ninja::getFire() {
	return &fireballs;
}

/** Returns 1 for a single game cycle if the ninja loses a life */
bool Ninja::lifeLost() {
	return lostLife;
}

/** Method to update the ninja's position, health, lives, and fireballs */
void Ninja::update() {
	if(lostLife == 1) {
		lostLife = 0;
	}
	
	if(y < 500) {
		vy = vy + 6;
	}
	
	if(y > 450 && vy > 0) {
		vy = 0;
		y = 500;
	}
		
	x += vx;
	y += vy;
	if(x < -100) {
		x = -100;
	} else if(x > 1025) {
		x = 1025;
	}
	setPos(x,y);
	
	for(int i = 0; i < fireballs.size(); i++) {
		fireballs[i]->update();
		QPoint point = fireballs[i]->getPos();
		if(point.x() > 1100 || point.x() < -100 || point.y() < 0 || point.y() > 600) {
			delete fireballs[i];
			fireballs.remove(i);
		}
	}
	if(health <= 0) {
		lives--;
		if(lives > 0) {
			lostLife = 1;
		}
		health = 100;
	}
	if(lives == 0) {
		health = 0;
		dead = 1;
	}
}

/** Decreases health when hit */
void Ninja::hit() {
	health--;
}

/** Returns 1 if ninja is dead */
bool Ninja::getDead() {
	return dead;
}

/** Returns health */
int Ninja::getHealth() {
	return health;
}

/** Returns lives */
int Ninja::getLives() {
	return lives;
}
