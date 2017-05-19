/*
 * Case.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */

#ifndef SRC_CASE_HPP_
#define SRC_CASE_HPP_

#include "Unite.hpp"
/**
 * Classe représentant une case du plateau de jeu, avec un lien vers son contenu
 */
class CaseJ {

private:
	int positionX;
	int positionY;
	Unite* unite;
public:
	CaseJ();
	CaseJ(int posX, int posY);
	virtual ~CaseJ();
	int getPositionX()const;
	int getPositionY()const;
	Unite *getUnite();
	void setUnite(Unite *u);

};

#endif /* CASE_HPP_ */


