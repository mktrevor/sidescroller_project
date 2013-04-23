#ifndef CREEP_H
#define CREEP_H

#include "thug.h"

class Creep : public Thug {
	private:
		QPixmap *altPic;
		
	public:
		Creep(int pos);
		~Creep();
		void move();
};
		
#endif
