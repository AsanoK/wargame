/*
 * Artillerie.cpp
 *
 *  Created on: 15 mai 2017
 *      Author: Hugin
 */


#include "CaseJ.hpp"
#include "Artillerie.hpp"

/**
 * constructeur de l'artillerie (ingénieur de siège)
 * @param pos : position de l'unité créée
 * @param prop : propriétaire de l'unité
 */
Artillerie::Artillerie(CaseJ& pos, Joueur& prop): Unite(pos,prop) {
	position = &pos;
	joueur = &prop;
	vie = VIEART;
	attaque = ATTART;
	defense = DEFART;
	DeplacementExecute = false;
	AttaqueExecutee = false;

}

Artillerie::~Artillerie() {
	// TODO Auto-generated destructor stub
}
/**
 * méthode déterminant si une case est attaquable ou non. Dans le cas de l'artillerie, toute cible à deux cases de distance dans toute les direction (donc un carré)
 *sch�ma des cases atteignables : x case possible, o pour l'origine et _ pour vide
 *     xxxxx
	 * x___x
	 * x_o_x
	 * x___x
	 * xxxxx
 * @param cible : case dont l'on souhaite savoir si elle est attaquable
 * @return vrai si la case est attaquable, faux sinon.
 */
bool Artillerie::isCaseAttaquable(const CaseJ& cible){
	//l'artilerie peut attaquer à toute case située à deux cases de distance:
	/*
	 * xxxxx
	 * x   x
	 * x o x
	 * x   x
	 * xxxxx
	 */
	bool res = false;
	int xa = position->getPositionX();
	int ya = position->getPositionY();
	int xc = cible.getPositionX();
	int yc = cible.getPositionY();

	if((((xa==xc-2)or(xa==xc+2))or((ya==yc+2)or(ya==yc-2)))and (xa-xc<=2 and ya-yc<=2)){
		res = true;
	}
	return res;
}
/**
 * méthode permettant de savoir si une case est atteignable en un mouvement (les cases adjacentes pour l'artillerie)
 * @param cible : la case visée
 * @return vrai si la case est atteignable, faux sinon
 */
bool Artillerie::isCaseAtteignable(const CaseJ& cible){

	//pour l'artillerie, on déplace uniquement sur les places adjacente : 4 possibilités
	bool ret =true;
		int xf = this->getposition()->getPositionX();
		int yf = this->getposition()->getPositionY();
		int xc = cible.getPositionX();
		int yc = cible.getPositionY();
		if((xc<xf-1)or(xc>xf+1)or(yc>yf+1)or(yc<yf-1)){
			ret= false;
		}
		return ret;

}
/**
 * méthode appelée normalement à chaque tour, et resettant certains paramètres, mais aussi en faisant récupérer un peu de vie.
 */
void Artillerie::regenerer(){
	//on reset les booléen de déplacement et d'attaque
	DeplacementExecute = false;
	AttaqueExecutee = false;
	//régen de vie? 1/4 du total ou de quoi revenir au maximum
	int bvie = 0;
	if(vie<VIEART){
		bvie = (int)VIEART*REGEN;
		if(vie+bvie>VIEART){
			bvie = VIEART-vie;
		}
	}
	vie=vie+bvie;
}
char Artillerie::toChar(){
	return CHARART;
}
