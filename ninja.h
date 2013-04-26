#ifndef NINJA_H
#define NINJA_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Ninja : public QGraphicsPixmapItem {
	private:
		QPixmap *pic;
		
	public:
		Ninja();
		~Ninja();
		
		int health;
		int x, y;
		int vx, vy;
		
		void moveRight();
		void moveLeft();
		void jump();
		void stop();
		
		void update();
		
};

#endif
