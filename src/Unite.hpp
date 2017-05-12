/*
 * Unite.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */

#ifndef UNITE_HPP_
#define UNITE_HPP_
#include "CaseJ.hpp"
#include "ConstantesUnites.hpp"

#include "Joueur.hpp"

class Unite{
	private :
	int attaque, defense, vie;
	Joueur joueur;
	CaseJ* position;
	bool AttaqueExecutee,DeplacementExecute;
	public:
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

	bool  virtual isCaseAtteignable(const CaseJ ) = 0;
	bool virtual isCaseAttaquable(const CaseJ) = 0;
	bool deplacer(CaseJ&);
	bool attaquer(CaseJ&);
	bool virtual isCaseAtteignable(const CaseJ ) = 0;
	bool virtual isCaseAttaquable(const CaseJ) = 0;
	bool deplacer(CaseJ&);
	bool attaquer(CaseJ&);
	void virtual regenerer() = 0;

};

#endif /* UNITE_HPP_ */
