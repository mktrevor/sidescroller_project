#ifndef KNIFE_H
#define KNIFE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Knife : public QGraphicsPixmapItem {
	private:
		QPixmap *pic;
		
		int x, y;
		int vx, vy;
		
	public:
		Knife(int direction, int xPos, int yPos);
		~Knife();
		
		void update();
		
		QPoint getPos();
		
};

#endif
