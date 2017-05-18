/*
 * Unite.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */

#ifndef UNITE_HPP_
#define UNITE_HPP_

#include "ConstantesUnites.hpp"
#include "CaseJ.hpp"
class CaseJ;
class Joueur;
/**
 * classe mère des différents types d'unité
 */
class Unite{
	protected :
	int attaque, defense, vie;
	Joueur* joueur;
	CaseJ* position;
	bool AttaqueExecutee,DeplacementExecute;
	public:
	Unite();
	Unite(CaseJ&, Joueur&);
	int getAttaque();
	int getdefense();
	int getVie();
	CaseJ getposition();
	Joueur getJoueur();
	bool isAttaqueExecutee();
	bool isdeplacementExecute();
	void setPosition(CaseJ&);
	void setVie(const int);
	void setDeplacementExecute(const bool);
	void setAttaqueExecutee(const bool);

	bool virtual  isCaseAtteignable(const CaseJ&) = 0;
	bool virtual isCaseAttaquable(const CaseJ&) = 0;
	bool deplacer(CaseJ&);
	bool attaquer(CaseJ&);
	virtual ~Unite();
	void virtual regenerer() = 0;
	char virtual toChar() = 0;

};

#endif /* UNITE_HPP_ */
