/*
 * Unite.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */

#ifndef UNITE_HPP_
#define UNITE_HPP_
class Unite{
	private :
	int attaque, defense, vie;
	Joueur joueur;
	Case position;
	bool AttaqueExecutee,DeplacementExecute;
	public:
	Unite(Case, Joueur);
	int getAttaque();
	int getdefense();
	int getVie();
	Case getposition();
	Joueur getJoueur();
	bool isAttaqueExecutee();
	bool isdeplacementExecute();
	void setPosition(const Case);
	void setVie(const int);
	void setDeplacementExecute(const bool);
	void setAttaqueExecutee(const bool);
	bool isCaseAtteignable(const Case ) = 0;
	bool isCaseAttaquable(const Case) = 0;
	bool deplacer(Case);
	bool attaquer(const Case);
	void regenerer() = 0;

};

#endif /* UNITE_HPP_ */
