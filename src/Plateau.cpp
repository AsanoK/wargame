/*
 * Plateau.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */

#include "Plateau.hpp"


Plateau::Plateau(Partie* p) {
	partie=p;
	Plateau::genererGrilleAleatoire();
	Plateau::deployerUnitesInitiales();
}

void Plateau::genererGrilleAleatoire()
{
	for (int i;i<NBCASES;i++)
		for (int j;j<NBCASES;j++)
			cases[i][j]=CaseJ(i,j);
}

void Plateau::deployerUnitesInitiales()
{
	Joueur p1 = partie->getJoueur1();
	Joueur p2 = partie->getJoueur2();

	for (int i=NBCASES/2-NB_TROUPES_DEPART/2;i<NB_TROUPES_DEPART;i++)
		cases[0][i].setUnite(p1.getUnite(i));

	for (int i=NBCASES/2-NB_TROUPES_DEPART/2;i<NB_TROUPES_DEPART;i++)
		cases[NBCASES-1][i].setUnite(p2.getUnite(i));
}

Plateau::~Plateau() {
	// TODO Auto-generated destructor stub
}


