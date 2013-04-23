#ifndef BOXER_H
#define BOXER_H

#include "thug.h"

class Boxer : public Thug {
	private:
		QPixmap *altPic;
		
	public:
		Boxer(bool side);
		~Boxer();
		void move();
};
		
#endif
