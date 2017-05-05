/*
 * Fantassin.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */
#include "Fantassin.hpp"
using namespace Unite;
Fantassin::Fantassin(Case c, Joueur prop){
	position = c;
	joueur = prop;
	vie = VIEFANT;
	attaque = ATTFANT;
	defense = DEFFANT;
	DeplacementExecute = false;
	AttaqueExecutee = false;
}
bool Unite::isCaseAtteignable(Case cible ) {
	//pour le fantassin, on d�place uniquement sur les places adjacente : 4 possibilit�s
	bool ret = false;
	if(((cible.getPosX()==position.getPosX())and(cible.getPosY()==position.getPosY()+1))or((cible.getPosX()==position.getPosX())and(cible.getPosY()==position.getPosY()-1))or((cible.getPosX()==position.getPosX()+1)and(cible.getPosY()==position.getPosY()))or((cible.getPosX()==position.getPosX()-1)and(cible.getPosY()==position.getPosY()))){
		ret=true;
	}
	return ret;
}
bool Unite::isCaseAttaquable(Case cible) {
	bool ret = false;
	if(((cible.getPosX()==position.getPosX())and(cible.getPosY()==position.getPosY()+1))or((cible.getPosX()==position.getPosX())and(cible.getPosY()==position.getPosY-1))or((cible.getPosX()==position.getPosX()+1)and(cible.getPosY()==position.getPosY()))or((cible.getPosX()==position.getPosX()-1)and(cible.getPosY()==position.getPosY()))){
			ret=true;
		}

	return ret;
}

