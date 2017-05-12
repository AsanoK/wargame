/*
 * Case.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */
#include <iostream>
#include <string>

#include "CaseJ.hpp"

CaseJ::CaseJ(int posX,int posY)
{
	if ((posX<0) || (posY<0))
			throw std::string("Position non valable.");
	positionX=posX;
	positionY=posY;
	unite=NULL;
}

CaseJ::~CaseJ() {
	// TODO Auto-generated destructor stub
}

int CaseJ::getPosX()
{
	return positionX;
}

int CaseJ::getPosY()
{
	return positionY;
}

Unite* CaseJ::getUnite()
{
	return unite;
}

void CaseJ::setUnite(Unite* u)
{
	this->unite=u;
}


