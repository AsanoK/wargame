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
 * constructeur de base de la classe unité
 * @param c : case sur laquelle on crée l'unité
 * @pram prop : joueur propriétaire de l'unité
 */
Unite::Unite(CaseJ& c, Joueur& prop) {
	position = &c;
		joueur = &prop;
		vie = 1;
		attaque = 1;
		defense = 1;
		DeplacementExecute = false;
		AttaqueExecutee = false;
}
/**
 * méthode effectuant le déplacement de l'unité, y compris les changements de contenu des cases
 * @param cible : la case visée par le déplacement
 * @return : vrai si le déplacement a été résolue, faux sinon.
 */
bool Unite::deplacer(CaseJ& cible){
	bool ret = false;
	Fenetre::affichageDeplacementLance();
	 if((isCaseAtteignable(cible))and(DeplacementExecute==false)and(cible.getUnite()==NULL)){
		 this->setPosition(cible);
		 Fenetre::affichageDeplacementRealise();
		 ret = true;
	 }

 DeplacementExecute = true;
 return ret;
}
/**
 * méthode permettant de gérer l'attaque d'une case
 * @param cible : case visée par l'attaque
 * @return : vrai si l'attaque a été résolue, faux sinon
 */
bool Unite::attaquer(CaseJ& cible){
	bool ret = false;
	Fenetre::affichageAttaqueLancee();
	if((isCaseAttaquable(cible))and(isAttaqueExecutee()==false)and(cible.getUnite()!=NULL)and(cible.getUnite()->getJoueur()!=this->getJoueur())){
		attaquer(cible.getUnite());
		Fenetre::affichageAttaqueRealisee();
		ret = true;
	}else{
		Fenetre::affichageAttaqueInterdite();
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
 * méthode pour changer la position
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
 * méthode de résolution des attaques (on suppose que celle-ci est possible)
 * @param : l'unité contre laquelle on est engagé
 *
 */
void Unite::attaquer(Unite* cible){
int modvie = attaque-cible->getdefense();
if(modvie>0){
	int resteVieCible = cible->getVie()-modvie;
	if(resteVieCible>cible->getVie()){
		Fenetre::affichageAttaqueInutile();

	}else if(resteVieCible>0){
		cible->setVie(resteVieCible);
		Fenetre::affichageDegats();
		Fenetre::affichageCibleEnVie();
	}else {
		delete cible;
		Fenetre::affichageDegats();
		Fenetre::affichageCibleDetruite();
		}
	}
}
Unite::~Unite(){
	position->setUnite(NULL);
	joueur->supprimerUnite(*this);
}
