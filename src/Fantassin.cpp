/*
 * Fantassin.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */

#include "CaseJ.hpp"
#include "Fantassin.hpp"
#include "Joueur.hpp"
#include <stdio.h>



/**
 * Constructeur de l'infanterie
 * @param c : case sur laquelle on crée l'unité
 * @param prop : propritaire de l'unité
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
 * méthode déterminant si les positions de la case d'origine et de celle d'arrivée permettent le déplacement
 * @param cible : la case vers laquelle on souhaite déplacer l'unité
 * @return : vrai si on peut effectuer le déplacement, faux sinon
 */
bool Fantassin::isCaseAtteignable(const CaseJ& cible ) {

	//pour le fantassin, on déplace uniquement sur les places adjacente : 4 possibilités
	bool ret = false;
	if(((cible.getPositionX()==position->getPositionX())and(cible.getPositionY()==position->getPositionY()+1))or((cible.getPositionX()==position->getPositionX())and(cible.getPositionY()==position->getPositionY()-1))or((cible.getPositionX()==position->getPositionX()+1)and(cible.getPositionY()==position->getPositionY()))or((cible.getPositionX()==position->getPositionX()-1)and(cible.getPositionY()==position->getPositionY()))){
		ret=true;
	}
	return ret;
}
/**
 * méthode déterminant si il est possible d'attaquer une position
 * @param cible : la case visée
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
 * méthode qui devrat être appelée à chaque tour : reset des booléens, et régénération de vie.
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
