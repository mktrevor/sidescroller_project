/** Class to represent Creep enemies which drop from the top of the game window
	@author Trevor Reed
*/
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
		Knife* throwKnife();
};
		
#endif
