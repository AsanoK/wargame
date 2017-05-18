/*
 * Cavalier.cpp
 *
 *  Created on: 14 mai 2017
 *      Author: Hugin
 */

#include "CaseJ.hpp"
#include "Cavalier.hpp"


/**
 * Constructeur de la cavalerie (�curie?)
 * @param c : case sur laquelle on cr�e la cavalerie
 * @param prop : propri�taire de la cavalerie
 */

Cavalier::Cavalier(CaseJ& c, Joueur& prop) : Unite(c,prop) {
	// TODO Auto-generated constructor stub
	position = &c;
		joueur = &prop;
		vie = VIECAV;
		attaque = ATTCAV;
		defense = DEFCAV;
		DeplacementExecute = false;
		AttaqueExecutee = false;
}
/**
 *m�thode d�terminant si une case est attaquable (case adjacente pour la cavalerie)
 *@param cible : la cible de la tentative (une case)
 *@return : vrai si la case est attaquable, faux sinon
 */
bool Cavalier::isCaseAttaquable(const CaseJ& cible){
	//le cavalier peut attaquer devant lui et derri�re lui
	bool res = false;
	if((cible.getPositionY()==position->getPositionY()+1 or cible.getPositionY()==position->getPositionY()-1)and (cible.getPositionY()==position->getPositionY())){
		res = true;
	}
	if(this->AttaqueExecutee){
		res = false;
	}
	return res;
}
/**
 * m�thode d�terminant si il est possible de se d�placer sur une case. Ne prend en compte que les positions des cases
 * @param cible: la case vis�e
 * @return  vrai si il est possible d'aller sur la cible, faux sinon.
 *
 */
bool Cavalier::isCaseAtteignable( const CaseJ& cible){
	//le cavalier peut se d�placer de deux cases en vertical, ou d'une horizontale, ou les deux.
	//xxx
	//xxx
	//xox <----le 'o' est la position d'origine du cavalier
	//xxx
	//xxx
	//repr�sentation graphique de sa zone de d�placement
	int xi = position->getPositionX();
	int yi = position->getPositionY();
	int xo = cible.getPositionX();
	int yo = cible.getPositionY();
	bool res = true;
	if((xi!=xo and xi!=xo+1 and xi!=xo-1)and(yi!=yo and yi!=yo+1 and yi!=yo+2 and yi!=yo-1 and yi!=yo-2)){
		res = false;
	}
	if(this->DeplacementExecute){
		res = false;
	}
	return res;
}
/**
 * la m�thode appel�e � chaqque tour : on reset les bool�ens et on ajoute de la vie.
 */
void Cavalier::regenerer(){
	//on reset les bool�en de d�placement et d'attaque
	DeplacementExecute = false;
	AttaqueExecutee = false;
	//r�gen de vie? 1/4 du total ou de quoi revenir au maximum
	int bvie = 0;
	if(vie<VIECAV){
		bvie = (int)VIECAV/4;
		if(vie+bvie>VIECAV){
			bvie = VIECAV-vie;
		}
	}
	vie=vie+bvie;
}
Cavalier::~Cavalier() {
	// TODO Auto-generated destructor stub
}
char Cavalier::toChar(){
	return CHARCAV;
}
