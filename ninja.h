#ifndef NINJA_H
#define NINJA_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "fireball.h"

class Ninja : public QGraphicsPixmapItem {
	private:
		QPixmap *pic;
		QVector<Fireball*> fireballs;
		
		bool dead;
		
		int health;
		int lives;
		int x, y;
		int vx, vy;
		
	public:
		Ninja();
		~Ninja();
		
		void moveRight();
		void moveLeft();
		void jump();
		void stop();
		
		QVector<Fireball*>* getFire();
		
		void hit();
		void update();
		bool getDead();
		int getHealth();
		int getLives();
		
		Fireball* shoot(int direction);
		
};

#endif
