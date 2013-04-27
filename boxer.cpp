#include <iostream>
#include "boxer.h"

Boxer::Boxer(bool side) {
	pic = new QPixmap("sprites/boxer1.png");
	altPic = new QPixmap("sprites/boxer2.png");
	
	dead = 0;
	randNum = 481516;
	
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
		vx = 3;
		vy = 0;
	} else {
		vx = -3;
		vy = 0;
	}
	
	health = 5;
}

Boxer::~Boxer() {
	delete pic;
	delete altPic;
}

void Boxer::move() {
	if(health == 0) {
		dead = 1;
	}
	
	srand(randNum);
	randNum = rand() % 100000;
	if(randNum > 97500 && vx < 0) {
		vx *= -1;
		setPixmap(*pic);
	}
	if(randNum > 97500 && vx > 0) {
		vx *= -1;
		setPixmap(*altPic);
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
