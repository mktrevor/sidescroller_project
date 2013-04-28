#ifndef JUMPER_H
#define JUMPER_H

#include "thug.h"

class Jumper : public Thug {
	private:
		QPixmap *altPic;
		
	public:
		Jumper(bool side);
		~Jumper();
		void move();
		Knife* throwKnife();
};
		
#endif
