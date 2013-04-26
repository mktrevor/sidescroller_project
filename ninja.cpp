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

void Ninja::jump() { }

void Ninja::stop() {
	vx = 0;
	vy = 0;
}

void Ninja::update() {
	x += vx;
	y += vy;
	setPos(x,y);
}
