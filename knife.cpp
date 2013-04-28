#include "knife.h"

/** Constructor
	@param direction
	@param x position
	@param y position
*/
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

/** Deconstructor */
Knife::~Knife() {
	delete pic;
}

/** Returns the knife's position */
QPoint Knife::getPos() {
	QPoint pos(x,y);
	return pos;
}

/** Updates the knife's location */
void Knife::update() {		
	x += vx;
	y += vy;
	setPos(x,y);
}
