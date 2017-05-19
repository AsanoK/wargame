/*
 * Fantassin.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */

#include "CaseJ.hpp"
#include "Fantassin.hpp"


/**
 * Constructeur de l'infanterie
 * @param c : case sur laquelle on cr�e l'unit�
 * @param prop : propritaire de l'unit�
 */

Fantassin::Fantassin(CaseJ& c, Joueur& prop): Unite(c,prop) {
	position = &c;
	joueur = &prop;
	vie = VIEFANT;
	attaque = ATTFANT;
	defense = DEFFANT;
	DeplacementExecute = false;
	AttaqueExecutee = false;
}
/**
 * m�thode d�terminant si les positions de la case d'origine et de celle d'arriv�e permettent le d�placement
 * @param cible : la case vers laquelle on souhaite d�placer l'unit�
 * @return : vrai si on peut effectuer le d�placement, faux sinon
 */
bool Fantassin::isCaseAtteignable(const CaseJ& cible ) {

	//pour le fantassin, on d�place uniquement sur les places adjacente : 4 possibilit�s
	bool ret = false;
	if(((cible.getPositionX()==position->getPositionX())and(cible.getPositionY()==position->getPositionY()+1))or((cible.getPositionX()==position->getPositionX())and(cible.getPositionY()==position->getPositionY()-1))or((cible.getPositionX()==position->getPositionX()+1)and(cible.getPositionY()==position->getPositionY()))or((cible.getPositionX()==position->getPositionX()-1)and(cible.getPositionY()==position->getPositionY()))){
		ret=true;
	}
	return ret;
}
/**
 * m�thode d�terminant si il est possible d'attaquer une position
 * @param cible : la case vis�e
 * @return vrai si la case est attaquable, faux sinon
 */
bool Fantassin::isCaseAttaquable(const CaseJ& cible) {
	bool ret = false;
	if(((cible.getPositionX()==position->getPositionX())and(cible.getPositionY()==position->getPositionY()+1))or((cible.getPositionX()==position->getPositionX())and(cible.getPositionY()==position->getPositionY()-1))or((cible.getPositionX()==position->getPositionX()+1)and(cible.getPositionY()==position->getPositionY()))or((cible.getPositionX()==position->getPositionX()-1)and(cible.getPositionY()==position->getPositionY()))){
			ret=true;
		}

	return ret;
}
/**
 * m�thode qui devrait �tre appel�e � chaque tour : reset des bool�ns, et r�g�n�ration de vie.
 */
void Fantassin::regenerer(){
	DeplacementExecute = false;
	AttaqueExecutee = false;
	int bvie = 0;
	if(vie<VIEFANT){
		bvie = (int)VIEFANT*REGEN;
		if(vie+bvie>VIEFANT){
			bvie = VIEFANT-vie;
		}
	}
	vie=vie+bvie;
}
char Fantassin::toChar(){
	return CHARFANT;
}

Fantassin::~Fantassin()
{
	position->setUnite(NULL);
		joueur->supprimerUnite(*this);
}
