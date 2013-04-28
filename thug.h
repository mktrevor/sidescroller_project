/** A super class for all of the enemies to inherit from */
#ifndef THUG_H
#define THUG_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "knife.h"

class Thug : public QGraphicsPixmapItem {
	protected:
		int x, y; //X and Y position
		int vx, vy; //X and Y velocity
		int health;
		QPixmap *pic;
		bool dead;
		bool checkKnife;
		Knife* knife;
		
	public:
		/** Virtual function for movement */
		virtual void move() = 0;
		/** Virtual function for throwing knives */
		virtual Knife* throwKnife() = 0;
		/** Returns 1 if the enemy is dead */
		bool isDead() {	return dead; }
		/** Health reduces if enemy is hit */
		void hit() { health--; }
		/** Checks if a knife has been thrown */
		bool getKnifeCheck() { return checkKnife; }
};
		
#endif
