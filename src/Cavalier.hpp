/*
 * Cavalier.h
 *
 *  Created on: 14 mai 2017
 *      Author: Hugin
 */

#ifndef SRC_CAVALIER_HPP_
#define SRC_CAVALIER_HPP_

#include "ConstantesUnites.hpp"
#include  "Unite.hpp"

class CaseJ;
class Joueur;


/**
 * Classe de cavalerie, qui est un type d'unité (et donc hérite de la classe unité)
 */
class Cavalier : public Unite {
public:
	Cavalier(CaseJ&, Joueur&);
	virtual ~Cavalier();
	bool isCaseAtteignable(const CaseJ& );
	bool isCaseAttaquable(const CaseJ&);
	void regenerer();
	char toChar();

};

#endif /* SRC_CAVALIER_HPP_ */
