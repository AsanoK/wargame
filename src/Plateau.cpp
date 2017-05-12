/*
 * Plateau.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */

#include "Plateau.hpp"


Plateau::Plateau(Partie* p) {
	this->partie=p;
	Plateau::genererGrilleAleatoire();
	Plateau::deployerUnitesInitiales();
}

void Plateau::genererGrilleAleatoire()
{
	for (int i;i<NBCASES;i++)
		for (int j;j<NBCASES;j++)
			this->cases[i][j]=CaseJ(i,j);
}

void Plateau::deployerUnitesInitiales()
{
	Joueur p1=this->partie->getJoueur1();
	Joueur p2=this->partie->getJoueur2();

	for (int i=NBCASES/2-NB_TROUPES_DEPART/2;i<NB_TROUPES_DEPART;i++)
		this->cases[0][i].CaseJ::setUnite(p1->Joueur::getUnite(i));

	for (int i=NBCASES/2-NB_TROUPES_DEPART/2;i<NB_TROUPES_DEPART;i++)
		this->cases[NBCASES-1][i].CaseJ::setUnite(p2->Joueur::getUnite(i));
}

Plateau::~Plateau() {
	// TODO Auto-generated destructor stub
}


