/** A class to represent the randomly moving "Boxer" enemies
	@author Trevor Reed
*/
#ifndef BOXER_H
#define BOXER_H

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
