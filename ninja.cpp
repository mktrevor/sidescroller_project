#include "ninja.h"

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

Ninja::~Ninja() {
	delete pic;
}

void Ninja::moveRight() {
	vx = 12;
}

void Ninja::moveLeft() {
	vx = -12;
}

void Ninja::jump() {	
	if(y == 500) {
		vy = -50;
	}
}

void Ninja::stop() {
	vx = 0;
}

Fireball* Ninja::shoot(int direction) {
	if(fireballs.size() < 4) {
		fireballs.push_back(new Fireball(direction, x, y));
		return fireballs[fireballs.size() - 1];
	}
	return NULL;
}
		
QVector<Fireball*>* Ninja::getFire() {
	return &fireballs;
}

void Ninja::update() {
	if(y < 500) {
		vy = vy + 6;
	}
	
	if(y > 450 && vy > 0) {
		vy = 0;
		y = 500;
	}
		
	x += vx;
	y += vy;
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
		health = 100;
	}
	if(lives == 0) {
		health = 0;
		dead = 1;
	}
}

void Ninja::hit() {
	health--;
}

bool Ninja::getDead() {
	return dead;
}

int Ninja::getHealth() {
	return health;
}

int Ninja::getLives() {
	return lives;
}
