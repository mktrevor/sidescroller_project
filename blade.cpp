#include <iostream>
#include "blade.h"

Blade::Blade(int pos) {
	pic = new QPixmap("sprites/blade1.png");
	altPic = new QPixmap("sprites/blade2.png");
	
	dead = 0;
	checkKnife = 0;
	
	switch(pos) {
		case 0:
		x = -200;
		y = 300;
		vx = 4;
		vy = 0;
		setPixmap(*pic);
		break;
		
		case 1:
		x = -200;
		y = 400;
		vx = 4;
		vy = 0;
		setPixmap(*pic);
		break;
		
		case 2:
		x = -200;
		y = 500;
		vx = 4;
		vy = 0;
		setPixmap(*pic);
		break;
		
		case 3:
		x = 1100;
		y = 300;
		vx = -4;
		vy = 0;
		setPixmap(*altPic);
		break;
		
		case 4:
		x = 1100;
		y = 400;
		vx = -4;
		vy = 0;
		setPixmap(*altPic);
		break;
		
		case 5:
		x = 1100;
		y = 500;
		vx = -4;
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
	if(health == 0) {
		dead = 1;
	}
	
	if(checkKnife == 1) {
		checkKnife = 0;
	}

	if(x < 500 && x > -80) {
		vx *= -1;
		checkKnife = 1;
	}
	if(x > 500 && x < 1000) {
		vx *= -1;
		checkKnife = 1;
	}
	
	if(x < -250 || x > 1150) {
		dead = 1;
	}
	
	x += vx;
	y += vy;
	
	setPos(x, y);
	
}

Knife* Blade::throwKnife() {
	int dir;
	if(x < 500) {
		dir = 0;
	} else {
		dir = 1;
	}
	knife = new Knife(dir, x, y + 10);
	
	return knife;
}
