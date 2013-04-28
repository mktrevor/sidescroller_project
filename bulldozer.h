/** A class to hold "Bulldozer" enemies which move fast and inflict damage 
	@author Trevor Reed
*/
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
		Knife* throwKnife();
};
		
#endif
