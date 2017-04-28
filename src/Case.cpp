/*
 * Case.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */

#include "Case.hpp"

Case::Case(int posX,int posY)
{
	positionX=posX;
	positionY=posY;
	unite=nullptr;
}

Case::~Case() {
	// TODO Auto-generated destructor stub
}

int Case::getPosX()
{
	return positionX;
}

int Case::getPosY()
{
	return positionY;
}

Unite* Case::getUnite()
{
	return unite;
}

void Case::setUnite(Unite* unite)
{
	this->unite=unite;
}
