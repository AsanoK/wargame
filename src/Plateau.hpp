/*
 * Plateau.h
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */


#ifndef SRC_PLATEAU_HPP_
#define SRC_PLATEAU_HPP_



#include "CaseJ.hpp"
#include "Fantassin.hpp"
#include "Cavalier.hpp"
#include "Artillerie.hpp"
#include "ConstantesUnites.hpp"

class Partie;
class Joueur;
/**
 * classe représentant le plateau de jeu, avec l'ensemble des cases
 */
class Plateau {

public:
	static const int NBCASES = 20;

private:
	CaseJ cases[NBCASES][NBCASES];
	Partie* partie;
	void genererGrilleAleatoire();
	void deployerUnitesInitiales();

public:
	Plateau();
	void setPartie(Partie &unePartie);
	virtual ~Plateau();

	CaseJ *getCase(int i, int j);
};

#endif /* PLATEAU_HPP_ */
