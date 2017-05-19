/*
 * Artillerie.cpp
 *
 *  Created on: 15 mai 2017
 *      Author: Hugin
 */


#include "CaseJ.hpp"
#include "Artillerie.hpp"

/**
 * constructeur de l'artillerie (ingï¿½nieur de siï¿½ge)
 * @param pos : position de l'unitï¿½ crï¿½ï¿½e
 * @param prop : propriï¿½taire de l'unitï¿½
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
 * mï¿½thode dï¿½terminant si une case est attaquable ou non. Dans le cas de l'artillerie, toute cible ï¿½ deux cases de distance dans toute les direction (donc un carrï¿½)
 *schéma des cases atteignables : x case possible, o pour l'origine et _ pour vide
 *     xxxxx
	 * x___x
	 * x_o_x
	 * x___x
	 * xxxxx
 * @param cible : case dont l'on souhaite savoir si elle est attaquable
 * @return vrai si la case est attaquable, faux sinon.
 */
bool Artillerie::isCaseAttaquable(const CaseJ& cible){
	//l'artilerie peut attaquer ï¿½ toute case situï¿½e ï¿½ deux cases de distance:
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
 * mï¿½thode permettant de savoir si une case est atteignable en un mouvement (les cases adjacentes pour l'artillerie
 * @param cible : la case visï¿½e
 * @return vrai si la case est atteignable, faux sinon
 */
bool Artillerie::isCaseAtteignable(const CaseJ& cible){

	//pour l'artillerie, on dï¿½place uniquement sur les places adjacente : 4 possibilitï¿½s
	bool ret = false;
	if(((cible.getPositionX()==position->getPositionX())and(cible.getPositionY()==position->getPositionY()+1))or((cible.getPositionX()==position->getPositionX())and(cible.getPositionY()==position->getPositionY()-1))or((cible.getPositionX()==position->getPositionX()+1)and(cible.getPositionY()==position->getPositionY()))or((cible.getPositionX()==position->getPositionX()-1)and(cible.getPositionY()==position->getPositionY()))){
		ret=true;
	}
	return ret;
}
/**
 * mï¿½thode appelï¿½e normalement ï¿½ chaque tour, et resettant certains paramï¿½tres, mais aussi en faisant rï¿½cupï¿½rer un peu de vie.
 */
void Artillerie::regenerer(){
	//on reset les boolï¿½en de dï¿½placement et d'attaque
	DeplacementExecute = false;
	AttaqueExecutee = false;
	//rï¿½gen de vie? 1/4 du total ou de quoi revenir au maximum
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
