/*
 * Unite.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */
#include "Unite.hpp"
using namespace Unite;
bool Unite::deplacer(Case cible){
	bool ret = false;
 if((isCaseAtteignable(cible))and(DeplacementExecute==false)){
	 //modifier contenu de la case d'origine
	 //modifier position
	 position = cible;
	 //modifier contenu de la case d'arrivée
 }
 ret = true;
 return ret;
}
bool Unite::attaquer(const Case cible){
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
	void Unite::setPosition(const Case c){
		position = c;
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

