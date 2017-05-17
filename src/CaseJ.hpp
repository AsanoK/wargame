/*
 * Case.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */

#ifndef CASE_HPP_
#define CASE_HPP_

class Unite;

class CaseJ {
private:
	int positionX;
	int positionY;
	Unite* unite;
public:
	CaseJ(int posX, int posY);
	virtual ~CaseJ();
	int getPositionX()const;
	int getPositionY()const;
	Unite* getUnite();
	void setUnite(Unite* u);
};

#endif /* CASE_HPP_ */


