/*
 * Plateau.h
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */


#ifndef PLATEAU_HPP_
#define PLATEAU_HPP_

#define NBCASES 50
#include "CaseJ.hpp"
#include "Partie.hpp"
#include "Joueur.hpp"
class Plateau {
private:
	CaseJ cases[NBCASES][NBCASES];
	Partie* partie;
	void genererGrilleAleatoire();
	void deployerUnitesInitiales();
public:
	Plateau(Partie* p);
	virtual ~Plateau();
};

#endif /* PLATEAU_HPP_ */

