/*
 * Plateau.h
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */


#ifndef PLATEAU_HPP_
#define PLATEAU_HPP_



#include "ConstantesUnites.hpp"
#include "CaseJ.hpp"

class Partie;
class Joueur;

class Plateau {
public:
	static const int NBCASES = 20;
private:
	CaseJ cases[NBCASES][NBCASES];
	Partie* partie;
	void genererGrilleAleatoire();
	void deployerUnitesInitiales();
public:
	Plateau(Partie* p);
	virtual ~Plateau();

	CaseJ getCase(int i, int j) const;
};

#endif /* PLATEAU_HPP_ */

