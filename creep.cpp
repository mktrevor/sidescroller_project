#include <iostream>
#include "creep.h"

Creep::Creep(int pos) {
	pic = new QPixmap("sprites/creep1.png");
	altPic = new QPixmap("sprites/creep2.png");
	
	dead = 0;
	
	switch(pos) {
		case 0:
		x = 100;
		y = -100;
		setPixmap(*pic);
		break;
		
		case 1:
		x = 250;
		y = -100;
		setPixmap(*pic);
		break;
		
		case 2:
		x = 400;
		y = -100;
		setPixmap(*pic);
		break;
		
		case 3:
		x = 600;
		y = -100;
		setPixmap(*altPic);
		break;
		
		case 4:
		x = 750;
		y = -100;
		setPixmap(*altPic);
		break;
		
		case 5:
		x = 900;
		y = -100;
		setPixmap(*altPic);
		break;
	}
	
	setPos(x, y);
	
	vx = 0;
	vy = 20;
	
	health = 3;
}

Creep::~Creep() {
	delete pic;
	delete altPic;
}

void Creep::move() {
	if(health == 0) {
		dead = 1;
	}

	if(y > 480 && vx == 0) {
		vy = 0;
		if(x < 500) {
			vx = 5;
		} else {
			vx = -5;
		}
	}
	
	if(x < -250 || x > 1150) {
		dead = 1;
	}
	
	x += vx;
	y += vy;
	
	setPos(x, y);
}
