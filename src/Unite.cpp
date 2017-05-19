/*
 * Unite.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */

#include "Joueur.hpp"
#include "CaseJ.hpp"
#include "Unite.hpp"
#include "Fenetre.hpp"

#include <stdio.h>

/**
 * constructeur de base de la classe unit�
 * @param c : case sur laquelle on cr�e l'unit�
 * @pram prop : joueur propri�taire de l'unit�
 */
Unite::Unite(CaseJ& c, Joueur& prop) {
	// TODO Auto-generated constructor stub
	position = &c;
		joueur = &prop;
		vie = 1;
		attaque = 1;
		defense = 1;
		DeplacementExecute = false;
		AttaqueExecutee = false;
}
/**
 * m�thode effectuant le d�placement de l'unit�, y compris les changements de contenu des cases
 * @param cible : la case vis�e par le d�placement
 * @return : vrai si le d�placement a �t� r�solue, faux sinon.
 */
bool Unite::deplacer(CaseJ& cible){
	bool ret = false;
 if((isCaseAtteignable(cible))and(DeplacementExecute==false)and(cible.getUnite()==NULL)){
	 this->setPosition(cible);
	 Fenetre::affichageDeplacementRealise();
	 ret = true;
 }

 DeplacementExecute = true;
 return ret;
}
/**
 * m�thode permettant de g�rer l'attaque d'une case
 * @param cible : case vis�e par l'attaque
 * @return : vrai si l'attaque a �t� r�solue, faux sinon
 */
bool Unite::attaquer(CaseJ& cible){
	bool ret = false;
	if((isCaseAttaquable(cible))and(isAttaqueExecutee()==false)and(cible.getUnite()!=NULL)and(cible.getUnite()->getJoueur()!=this->getJoueur())){
		attaquer(cible.getUnite());
		Fenetre::affichageAttaqueRealisee();
		ret = true;
	}

	AttaqueExecutee = true;
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
CaseJ* Unite::getposition(){
	return position;
}
Joueur* Unite::getJoueur(){
	return joueur;
}
bool Unite::isAttaqueExecutee(){
	return AttaqueExecutee;
}
bool Unite::isdeplacementExecute(){
	return DeplacementExecute;
}
/**
 * m�thode pour changer la position
 */
void Unite::setPosition(CaseJ& c){
	position->setUnite(NULL);
	position = &c;
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
/**
 * m�thode de r�solution des attaques (on suppose que celle-ci est possible)
 * @param : l'unit� contre laquelle on est engag�
 *
 */
void Unite::attaquer(Unite* cible){
int modvie = attaque-cible->getdefense();
if(modvie>0){
	int resteVieCible = cible->getVie()-modvie;
	if(resteVieCible>cible->getVie()){
		//on ne fait rien
	}else if(resteVieCible>0){
		cible->setVie(resteVieCible);
		Fenetre::affichageCibleEnVie();
	}else {
		delete cible;
		Fenetre::affichageCibleDetruite();
		}
	}
}
Unite::~Unite(){
	position->setUnite(NULL);
	joueur->supprimerUnite(*this);
}
