#include <iostream>
#include "boxer.h"

Boxer::Boxer(bool side) {
	pic = new QPixmap("sprites/boxer1.png");
	altPic = new QPixmap("sprites/boxer2.png");
	
	if(side == 0) {
		x = -200;
		y = 600;
		setPixmap(*pic);
	} else {
		x = 1100;
		y = 600;
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
