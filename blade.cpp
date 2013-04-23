#include <iostream>
#include "blade.h"

Blade::Blade(int pos) {
	pic = new QPixmap("sprites/blade1.png");
	altPic = new QPixmap("sprites/blade2.png");
	
	switch(pos) {
		case 0:
		x = -200;
		y = 500;
		vx = 3;
		vy = 0;
		setPixmap(*pic);
		break;
		
		case 1:
		x = -200;
		y = 550;
		vx = 3;
		vy = 0;
		setPixmap(*pic);
		break;
		
		case 2:
		x = -200;
		y = 600;
		vx = 3;
		vy = 0;
		setPixmap(*pic);
		break;
		
		case 3:
		x = 1100;
		y = 500;
		vx = -3;
		vy = 0;
		setPixmap(*altPic);
		break;
		
		case 4:
		x = 1100;
		y = 550;
		vx = -3;
		vy = 0;
		setPixmap(*altPic);
		break;
		
		case 5:
		x = 1100;
		y = 600;
		vx = -3;
		vy = 0;
		setPixmap(*altPic);
		break;
	}
	
	setPos(x, y);
	
	health = 2;
}

Blade::~Blade() {
	delete pic;
	delete altPic;
}

void Blade::move() {

	if(x < 500 && x > -100) {
		vx = 0;
	}
	if(x > 500 && x < 1000) {
		vx = 0;
	}
	
	x += vx;
	y += vy;
	
	setPos(x, y);
	
}
