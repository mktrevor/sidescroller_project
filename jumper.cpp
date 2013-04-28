#include <iostream>
#include <cmath>
#include "jumper.h"

Jumper::Jumper(bool side) {
	pic = new QPixmap("sprites/jumper1.png");
	altPic = new QPixmap("sprites/jumper2.png");
	
	dead = 0;
	checkKnife = 0;
	
	if(side == 0) {
		x = -200;
		y = 200;
		setPixmap(*pic);
	} else {
		x = 1100;
		y = 200;
		setPixmap(*altPic);
	}
	
	setPos(x, y);
	
	if(side == 0) {
		vx = 5;
		vy = 5;
	} else {
		vx = -5;
		vy = 5;
	}
	
	health = 4;
}

Knife* Jumper::throwKnife() { return NULL; }

Jumper::~Jumper() {
	delete pic;
	delete altPic;
}

void Jumper::move() {
	if(health == 0) {
		dead = 1;
	}

	if(x > 1100) {
		vx *= -1;
		setPixmap(*altPic);
	}
	else if(x < -200) {
		vx *= -1;
		setPixmap(*pic);
	}
	if(y < 200 || y > 450) {
		vy *= -1;
	}
	x += vx;
	y += vy;
	
	setPos(x, y);
}
