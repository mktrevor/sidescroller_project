#ifndef BULLDOZER_H
#define BULLDOZER_H

#include "thug.h"

class Bulldozer : public Thug {
	private:
		QPixmap *altPic;
		
	public:
		Bulldozer(bool side);
		~Bulldozer();
		void move();
};
		
#endif
