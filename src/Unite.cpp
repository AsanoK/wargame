/*
 * Unite.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */
#include "Unite.hpp"


bool Unite::deplacer(Case& cible){
	bool ret = false;
 if((isCaseAtteignable(cible))and(DeplacementExecute==false)){
	 //modifier contenu de la case d'origine
	 position.setUnite(nullptr);
	 //modifier position
	 position = cible;
	 //modifier contenu de la case d'arriv�e
	 position.setUnite(this);
 }
 ret = true;
 return ret;
}
bool Unite::attaquer(Case& cible){
	bool ret = false;
	if((isCaseAttaquable(cible))and(AttaqueExecutee==false)){
		//r�soudre attaque;
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
	Case Unite::getposition(){
		return vie;
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
	void Unite::setPosition(Case& c){
		position.setUnite(NULL);
		position = c;
		c.setUnite(this);

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

