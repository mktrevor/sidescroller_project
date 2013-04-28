#ifndef BOXER_H
#define BOXER_H

#include <ctime>
#include "thug.h"

class Boxer : public Thug {
	private:
		QPixmap *altPic;
		int randNum;
		
	public:
		Boxer(bool side, int num);
		~Boxer();
		void move();
		Knife* throwKnife();
};
		
#endif
