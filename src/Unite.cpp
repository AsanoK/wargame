/*
 * Unite.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */
#include "Unite.hpp"
using namespace Unite;

bool Unite::deplacer(CaseJ& cible){
	bool ret = false;
 if((isCaseAtteignable(cible))and(DeplacementExecute==false)){
	 //modifier contenu de la case d'origine
	 position->setUnite(NULL);
	 //modifier position
	 position = &cible;
	 //modifier contenu de la case d'arrivée
	 position->setUnite(this);
 }
 ret = true;
 return ret;
}
bool Unite::attaquer(CaseJ& cible){
	bool ret = false;
	if((isCaseAttaquable(cible))and(AttaqueExecutee==false)){
		//résoudre attaque;
		position = cible;
	}
	ret = true;
	return ret;
}

int Unite::getAttaque(){
	return attaque;
}
	int Unite::getdefense(){
		return defense;
	}
	int Unite::getVie(){
		return vie;
	}
	CaseJ Unite::getposition(){
		return position;
	}
	Joueur Unite::getJoueur(){
		return joueur;
	}
	bool Unite::isAttaqueExecutee(){
		return AttaqueExecutee;
	}
	bool Unite::isdeplacementExecute(){
		return DeplacementExecute;
	}
	void Unite::setPosition(CaseJ& c){
		position->setUnite(NULL);
		position = c;
		c->setUnite(this);

	}
	void Unite::setVie( const int v){
		vie = v;
	}
	void Unite::setDeplacementExecute( const bool b){
		DeplacementExecute = b;
	}
	void Unite::setAttaqueExecutee( const bool b){
		AttaqueExecutee = b;
	}

