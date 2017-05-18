/*
 * Artillerie.cpp
 *
 *  Created on: 15 mai 2017
 *      Author: Hugin
 */

#include "Artillerie.h"

Artillerie::Artillerie(CaseJ& pos, Joueur& prop) {
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
bool Artillerie::isCaseAtteignable(const CaseJ& cible){

	//pour l'artillerie, on dï¿½place uniquement sur les places adjacente : 4 possibilitï¿½s
	bool ret = false;
	if(((cible.getPositionX()==position->getPositionX())and(cible.getPositionY()==position->getPositionY()+1))or((cible.getPositionX()==position->getPositionX())and(cible.getPositionY()==position->getPositionY()-1))or((cible.getPositionX()==position->getPositionX()+1)and(cible.getPositionY()==position->getPositionY()))or((cible.getPositionX()==position->getPositionX()-1)and(cible.getPositionY()==position->getPositionY()))){
		ret=true;
	}
	return ret;
}
void Artillerie::regenerer(){
	//on reset les booléen de déplacement et d'attaque
	DeplacementExecute = false;
	AttaqueExecutee = false;
	//régen de vie? 1/4 du total ou de quoi revenir au maximum
	int bvie = 0;
	if(vie<VIEART){
		bvie = (int)VIEART/4;
		if(vie+bvie>VIEART){
			bvie = VIEART-vie;
		}
	}
	vie=vie+bvie;
}
char Artillerie::toChar(){
	return 'CHARART';
}
