/*
 * Fantassin.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */
#include "Fantassin.hpp"

Fantassin::Fantassin(CaseJ& c, Joueur& prop){
	position = c;
	joueur = prop;
	vie = VIEFANT;
	attaque = ATTFANT;
	defense = DEFFANT;
	DeplacementExecute = false;
	AttaqueExecutee = false;
}
bool Fantassin::isCaseAtteignable(const CaseJ& cible ) {

	//pour le fantassin, on d�place uniquement sur les places adjacente : 4 possibilit�s
	bool ret = false;
	if(((cible.getPositionX()==position->getPositionX())and(cible.getPositionY()==position->getPositionY()+1))or((cible.getPositionX()==position->getPositionX())and(cible.getPositionY()==position->getPositionY()-1))or((cible.getPositionX()==position->getPositionX()+1)and(cible.getPositionY()==position->getPositionY()))or((cible.getPositionX()==position->getPositionX()-1)and(cible.getPositionY()==position->getPositionY()))){
		ret=true;
	}
	return ret;
}
bool Fantassin::isCaseAttaquable(const CaseJ& cible) {
	bool ret = false;
	if(((cible.getPositionX()==position->getPositionX())and(cible.getPositionY()==position->getPositionY()+1))or((cible.getPositionX()==position->getPositionX())and(cible.getPositionY()==position->getPositionY()-1))or((cible.getPositionX()==position->getPositionX()+1)and(cible.getPositionY()==position->getPositionY()))or((cible.getPositionX()==position->getPositionX()-1)and(cible.getPositionY()==position->getPositionY()))){
			ret=true;
		}

	return ret;
}
void Fantassin::regenerer(){
	DeplacementExecute = false;
	AttaqueExecutee = false;
	int bvie = 0;
	if(vie<VIEFANT){
		bvie = (int)VIEFANT/4;
		if(vie+bvie>VIEFANT){
			bvie = VIEFANT-vie;
		}
	}
	vie=vie+bvie;
}
char Fantassin::toChar(){
	return 'CHARFANT';
}
