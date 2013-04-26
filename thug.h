#ifndef THUG_H
#define THUG_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Thug : public QGraphicsPixmapItem {
	protected:
		int x, y; //X and Y position
		int vx, vy; //X and Y velocity
		int health;
		QPixmap *pic;
		bool dead;
		
	public:
		virtual void move() = 0;
		bool isDead() {	return dead; }
		void hit() { health--; }
};
		
#endif
