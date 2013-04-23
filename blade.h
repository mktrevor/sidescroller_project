#ifndef BLADE_H
#define BLADE_H

#include "thug.h"

class Blade : public Thug {
	private:
		QPixmap *altPic;
		
	public:
		Blade(int pos);
		~Blade();
		void move();
};
		
#endif
