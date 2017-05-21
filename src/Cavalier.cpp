/*
 * Cavalier.cpp
 *
 *  Created on: 14 mai 2017
 *      Author: Hugin
 */

#include "CaseJ.hpp"
#include "Cavalier.hpp"
#include "Joueur.hpp"
#include <stdio.h>


/**
 * Constructeur de la cavalerie (écurie)
 * @param c : case sur laquelle on crée la cavalerie
 * @param prop : propriétaire de la cavalerie
 */

Cavalier::Cavalier(CaseJ& c, Joueur& prop) : Unite(c,prop) {
	position = &c;
	joueur = &prop;
	vie = VIECAV;
	attaque = ATTCAV;
	defense = DEFCAV;
	DeplacementExecute = false;
	AttaqueExecutee = false;
}
/**
 *méthode déterminant si une case est attaquable (case adjacente pour la cavalerie)
 *@param cible : la cible de la tentative (une case)
 *@return : vrai si la case est attaquable, faux sinon
 */
bool Cavalier::isCaseAttaquable(const CaseJ& cible){
	//le cavalier peut attaquer devant lui et derrière lui
	int xf = this->getposition()->getPositionX();
			int yf = this->getposition()->getPositionY();
			int xc = cible.getPositionX();
			int yc = cible.getPositionY();
			if((xc<xf-1)or(xc>xf+1)or(yc>yf+1)or(yc<yf-1)){
				return false;
						}else{
							return true;
					}
}
/**
 * méthode déterminant si il est possible de se déplacer sur une case. Ne prend en compte que les positions des cases
 * @param cible: la case visée
 * @return  vrai si il est possible d'aller sur la cible, faux sinon.
 *
 */
bool Cavalier::isCaseAtteignable( const CaseJ& cible){
	//le cavalier peut se déplacer de deux cases en vertical, ou d'une horizontale, ou les deux.
	//xxx
	//xxx
	//xox <----le 'o' est la position d'origine du cavalier
	//xxx
	//xxx
	int xf = this->getposition()->getPositionX();
	int yf = this->getposition()->getPositionY();
	int xc = cible.getPositionX();
	int yc = cible.getPositionY();
	if((xc<xf-2)or(xc>xf+2)or(yc>yf+1)or(yc<yf-1)){
		return false;
	}else{
		return true;
	}
}
/**
 * la méthode appelée à chaque tour : on reset les booléens et on ajoute de la vie.
 */
void Cavalier::regenerer(){
	//on reset les booléen de déplacement et d'attaque
	DeplacementExecute = false;
	AttaqueExecutee = false;
	//régen de vie? 1/4 du total ou de quoi revenir au maximum
	int bvie = 0;
	if(vie<VIECAV){
		bvie = (int)VIECAV*REGEN;
		if(vie+bvie>VIECAV){
			bvie = VIECAV-vie;
		}
	}
	vie=vie+bvie;
}
Cavalier::~Cavalier() {
	position->setUnite(NULL);
	joueur->supprimerUnite(*this);
}
char Cavalier::toChar(){
	return CHARCAV;
}
