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
	Case pos;
	bool isAttaqueExecutee,isDeplacementExecute;
	public:
bool isCaseAtteignable(Case ) = 0;
bool isCaseAttaquable(Case) = 0;
bool deplacer(Case);
bool attaquer(Case);
void regenerer() = 0;
}

#endif /* UNITE_HPP_ */
