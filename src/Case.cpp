/*
 * Case.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */
#include <iostream>
#include <string>
#include "Case.hpp"

Case::Case(int posX,int posY)
{
	if ((posX<0) || (posY<0))
			throw std::string("Position non valable.");
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

void Case::setUnite(Unite* u)
{
	this->unite=u;
}


