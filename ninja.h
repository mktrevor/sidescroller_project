/** A class to hold the game's hero, the Magic Ninja!
	@author Trevor Reed
*/
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
		bool lostLife;
		
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
		bool lifeLost();
		
		Fireball* shoot(int direction);
		
};

#endif
