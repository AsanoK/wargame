/*
 * Case.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */

#ifndef CASE_HPP_
#define CASE_HPP_

class Case {
private:
	int positionX;
	int positionY;
	Unite* unite;
public:
	Case(int posX, int posY);
	virtual ~Case();
	int getPosX();
	int getPosY();
	Unite* getUnite();
	void setUnite(Unite* u);
};

#endif /* CASE_HPP_ */


