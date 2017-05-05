/*
 * Plateau.h
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */


#ifndef PLATEAU_HPP_
#define PLATEAU_HPP_
#define NBCASES 50
#include "Case.hpp"
#include "Joueur.hpp"
class Plateau {
private:
	Case cases[NBCASES][NBCASES];
	void genererGrilleAleatoire();
	void deployerUnitesInitiales(Joueur)
public:
	Plateau();
	virtual ~Plateau();
};

#endif /* PLATEAU_HPP_ */
