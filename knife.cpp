#include "knife.h"

Knife::Knife(int direction, int xPos, int yPos) {
	
	switch(direction) {
		case 0:
		pic = new QPixmap("sprites/knife1.png");
		setPixmap(*pic);
		x = xPos + 10;
		y = yPos;
		vx = 15;
		vy = 0;
		break;
		
		case 1:
		pic = new QPixmap("sprites/knife2.png");
		setPixmap(*pic);
		x = xPos - 10;
		y = yPos;
		vx = -15;
		vy = 0;
		break;
	}
	
	setPos(x,y);
}

Knife::~Knife() {
	delete pic;
}

QPoint Knife::getPos() {
	QPoint pos(x,y);
	return pos;
}

void Knife::update() {		
	x += vx;
	y += vy;
	setPos(x,y);
}
