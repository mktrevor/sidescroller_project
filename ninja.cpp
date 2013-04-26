#include "ninja.h"

Ninja::Ninja() {
	pic = new QPixmap("sprites/ninja1.png");
	setPixmap(*pic);
	
	health = 100;
	
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
	vx = 9;
}

void Ninja::moveLeft() {
	vx = -9;
}

void Ninja::jump() {	
	vy = -25;
}

void Ninja::stop() {
	vx = 0;
	vy = 0;
}

void Ninja::update() {
	/*if(vy >= 0) {
		if(vy < 15) {
			vy = 15;
		} else {
			vy++;
		}
	}
	if(y <= 350 && vy < 0) {
		vy += 5;
	} else if (vy < 0) {
		vy++;
	}*/
	if(y < 500) {
		vy = vy + 2;
	}
	
	if(y > 475 && vy > 0) {
		vy = 0;
		y = 500;
	}
		
	x += vx;
	y += vy;
	setPos(x,y);
}
