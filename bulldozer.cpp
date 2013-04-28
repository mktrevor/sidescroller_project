#include <iostream>
#include "bulldozer.h"

Bulldozer::Bulldozer(bool side) {
	pic = new QPixmap("sprites/bulldozer1.png");
	altPic = new QPixmap("sprites/bulldozer2.png");
	
	dead = 0;
	checkKnife = 0;
	
	if(side == 0) {
		x = -200;
		y = 500;
		setPixmap(*pic);
	} else {
		x = 1100;
		y = 500;
		setPixmap(*altPic);
	}
	
	setPos(x, y);
	
	if(side == 0) {
		vx = 10;
		vy = 0;
	} else {
		vx = -10;
		vy = 0;
	}
	
	health = 4;
}

Bulldozer::~Bulldozer() {
	delete pic;
	delete altPic;
}

void Bulldozer::move() {
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
	x += vx;
	y += vy;
	
	setPos(x, y);
}

Knife* Bulldozer::throwKnife() { return NULL; }
