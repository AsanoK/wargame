/*
 * Plateau.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */

#include "Plateau.hpp"
#include "ConstantesUnites.hpp"

Plateau::Plateau() {
	Plateau::genererGrilleAleatoire();

}

void Plateau::genererGrilleAleatoire()
{
	for (int i;i<NBCASES;i++)
		for (int j;j<NBCASES;j++)
			this->cases[i][j]=Case(i,j);
}

void Plateau::deployerUnitesInitiales(Joueur j)
{
	for (int i=0;i<NB_TROUPES_DEPART;i++)
		this->cases[i][i].setUnite(j->getUnite(i));
}

Plateau::~Plateau() {
	// TODO Auto-generated destructor stub
}


