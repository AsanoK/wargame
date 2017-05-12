/*
 * Fantassin.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */
#include "Fantassin.hpp"

using namespace Unite;
Fantassin::Fantassin(CaseJ c, Joueur prop){
	position = c;
	joueur = prop;
	vie = VIEFANT;
	attaque = ATTFANT;
	defense = DEFFANT;
	DeplacementExecute = false;
	AttaqueExecutee = false;
}
bool Unite::isCaseAtteignable(CaseJ cible ) {
<<<<<<< HEAD
	//pour le fantassin, on d�place uniquement sur les places adjacente : 4 possibilit�s
=======
	//pour le fantassin, on d�place uniquement sur les places adjacente : 4 Positionsibilit�s
>>>>>>> be064f78d486b2c5f929e70fabe152d5ba5ed0a6

	bool ret = false;
	if(((cible.getPositionX()==position.getPositionX())and(cible.getPositionY()==position.getPositionY()+1))or((cible.getPositionX()==position.getPositionX())and(cible.getPositionY()==Position.getPositionY()-1))or((cible.getPositionX()==position.getPositionX()+1)and(cible.getPositionY()==position.getPositionY()))or((cible.getPositionX()==position.getPositionX()-1)and(cible.getPositionY()==position.getPositionY()))){
		ret=true;
	}
	return ret;
}
bool Unite::isCaseAttaquable(CaseJ cible) {
	bool ret = false;
	if(((cible.getPositionX()==position.getPositionX())and(cible.getPositionY()==position.getPositionY()+1))or((cible.getPositionX()==position.getPositionX())and(cible.getPositionY()==Position.getPositionY()-1))or((cible.getPositionX()==position.getPositionX()+1)and(cible.getPositionY()==position.getPositionY()))or((cible.getPositionX()==position.getPositionX()-1)and(cible.getPositionY()==position.getPositionY()))){
			ret=true;
		}

	return ret;
}

