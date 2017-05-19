/*
 * Unite.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */

#ifndef UNITE_HPP_
#define UNITE_HPP_

class CaseJ;
class Joueur;

/**
 * classe mère des différents types d'unité
 */


class Unite{
private:
	void attaquer(Unite*);
protected :
	int attaque, defense, vie;
	Joueur* joueur;
	CaseJ* position;
	bool AttaqueExecutee,DeplacementExecute;
public:
	Unite();
	Unite(CaseJ& uneCase, Joueur& unJoueur);
	int getAttaque();
	int getdefense();
	int getVie();
	CaseJ *getposition();
	Joueur *getJoueur();
	bool isAttaqueExecutee();
	bool isdeplacementExecute();
	void setPosition(CaseJ&);
	void setVie(const int);
	void setDeplacementExecute(const bool);
	void setAttaqueExecutee(const bool);

	bool virtual  isCaseAtteignable(const CaseJ& uneCase) = 0;
	bool virtual isCaseAttaquable(const CaseJ& uneCase) = 0;
	bool deplacer(CaseJ& uneCase);
	bool attaquer(CaseJ& uneCase);
	virtual ~Unite();
	void virtual regenerer() = 0;
	char virtual toChar() = 0;

};

#endif /* UNITE_HPP_ */
