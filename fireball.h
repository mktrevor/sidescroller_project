#ifndef FIREBALL_H
#define FIREBALL_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Fireball : public QGraphicsPixmapItem {
	private:
		QPixmap *pic;
		
		int x, y;
		int vx, vy;
		
	public:
		Fireball(int direction, int xPos, int yPos);
		~Fireball();
		
		void update();
		
		QPoint getPos();
		
};

#endif
