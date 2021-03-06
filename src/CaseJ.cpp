/*
 * Case.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */

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

CaseJ::CaseJ(){
	positionX=0;
	positionY=0;
	unite=NULL;
}

CaseJ::~CaseJ() {
	// TODO Auto-generated destructor stub
}

int CaseJ::getPositionX()const
{
	return positionX;
}

int CaseJ::getPositionY()const
{
	return positionY;
}

Unite* CaseJ::getUnite()
{
	return unite;
}

void CaseJ::setUnite(Unite* u)
{
	unite=u;
}


