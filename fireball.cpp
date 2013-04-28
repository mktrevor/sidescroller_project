#include "fireball.h"

Fireball::Fireball(int direction, int xPos, int yPos) {
	
	switch(direction) {
		case 0:
		pic = new QPixmap("sprites/fireball2.png");
		setPixmap(*pic);
		x = xPos + 10;
		y = yPos;
		vx = 20;
		vy = 0;
		break;
		
		case 1:
		pic = new QPixmap("sprites/fireball1.png");
		setPixmap(*pic);
		x = xPos - 10;
		y = yPos;
		vx = -20;
		vy = 0;
		break;
		
		case 2:
		pic = new QPixmap("sprites/fireball3.png");
		setPixmap(*pic);
		x = xPos;
		y = yPos - 10;
		vx = 0;
		vy = -20;
		break;
		
		case 3:
		pic = new QPixmap("sprites/fireball4.png");
		setPixmap(*pic);
		x = xPos;
		y = yPos + 10;
		vx = 0;
		vy = 20;
		break;
	}
	
	setPos(x,y);
}

Fireball::~Fireball() {
	delete pic;
}

QPoint Fireball::getPos() {
	QPoint pos(x,y);
	return pos;
}

void Fireball::update() {		
	x += vx;
	y += vy;
	setPos(x,y);
}
