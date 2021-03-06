/*
 * Plateau.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: cdecultot
 */
#include <iostream>
#include "Partie.hpp"
#include "Plateau.hpp"

Plateau::Plateau():partie(0){

}

void Plateau::setPartie(Partie &p) {
	partie=&p;
	genererGrilleAleatoire();
	deployerUnitesInitiales();
}
/**
 * méthode permettant d'obtenir une grille aléatoire
 */
void Plateau::genererGrilleAleatoire()
{
	for (int i=0;i<NBCASES;i++){
		for (int j=0;j<NBCASES;j++){
			cases[i][j]=CaseJ(i,j);
		}
	}
}
/**
 * méthode permettant de placer les unités de départ des joueurs.
 */
void Plateau::deployerUnitesInitiales()
{
	Joueur* p1 = partie->getJoueur1();
	Joueur* p2 = partie->getJoueur2();

	// Creation et déploiement des unités initiales du premier joueur
	for(int i = NBCASES/2-NB_TROUPES_DEPART/2;i<NBCASES/2-NB_TROUPES_DEPART/2+NBCASES;i++)
	{
		Fantassin *f=new Fantassin(cases[1][i],*p1);
		p1->ajouterUnite(*f);
		cases[1][i].setUnite(f);
	}
	Cavalier *c1=new Cavalier(cases[0][NBCASES/2-2],*p1);
	p1->ajouterUnite(*c1);
	cases[0][NBCASES/2-2].setUnite(c1);
	Cavalier *c2=new Cavalier(cases[0][NBCASES/2+2],*p1);
	p1->ajouterUnite(*c2);
	cases[0][NBCASES/2+2].setUnite(c2);

	Artillerie *a1=new Artillerie(cases[0][NBCASES/2-1],*p1);
	p1->ajouterUnite(*a1);
	cases[0][NBCASES/2-1].setUnite(a1);
	Artillerie *a2=new Artillerie(cases[0][NBCASES/2+1],*p1);
	p1->ajouterUnite(*a2);
	cases[0][NBCASES/2+1].setUnite(a2);

	// Creation et déploiement des unités initiales du deuxième joueur

	for (int i=NBCASES/2-NB_TROUPES_DEPART/2;i<NBCASES/2+NB_TROUPES_DEPART/2;i++)
	{
		Fantassin *f=new Fantassin(cases[NBCASES-2][i],*p2);
		p2->ajouterUnite(*f);
		cases[NBCASES-2][i].setUnite(f);
	}
	Cavalier *c3=new Cavalier(cases[NBCASES-1][NBCASES/2-2],*p2);
	p2->ajouterUnite(*c3);
	cases[NBCASES-1][NBCASES/2-2].setUnite(c3);
	Cavalier *c4=new Cavalier(cases[NBCASES-1][NBCASES/2+2],*p2);
	p2->ajouterUnite(*c4);
	cases[NBCASES-1][NBCASES/2+2].setUnite(c4);
	Artillerie *a3=new Artillerie(cases[NBCASES-1][NBCASES/2-1],*p2);
	p2->ajouterUnite(*a3);
	cases[NBCASES-1][NBCASES/2-1].setUnite(a3);
	Artillerie *a4=new Artillerie(cases[NBCASES-1][NBCASES/2+1],*p2);
	p2->ajouterUnite(*a4);
	cases[NBCASES-1][NBCASES/2+1].setUnite(a4);
}

CaseJ *Plateau::getCase(int i, int j){
	return (&cases[i][j]);
}



Plateau::~Plateau() {
	std::cout << 1 << std::endl;
	for (int i=0;i<Plateau::NBCASES;i++)
	{
		for (int j=0;j<Plateau::NBCASES;j++)
		{
			Unite* u=cases[i][j].getUnite();
			if (u!=NULL)
				u->getJoueur()->supprimerUnite(*u);
			delete(&cases[i][j]);
		}
	}
}

