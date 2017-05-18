/*
 * Cavalier.h
 *
 *  Created on: 14 mai 2017
 *      Author: Hugin
 */

#ifndef SRC_CAVALIER_H_
#define SRC_CAVALIER_H_
#include "Unite.hpp"
#include "ConstantesUnites.hpp"
class Cavalier : Unite {
public:
	Cavalier(CaseJ&, Joueur&);
	virtual ~Cavalier();
	bool isCaseAtteignable(const CaseJ& );
	bool isCaseAttaquable(const CaseJ&);
	void regenerer();
	char toChar();

};

#endif /* SRC_CAVALIER_H_ */
