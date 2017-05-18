/*
 * Artillerie.h
 *
 *  Created on: 15 mai 2017
 *      Author: Hugin
 */

#ifndef SRC_ARTILLERIE_H_
#define SRC_ARTILLERIE_H_
#include "unite.hpp"

class Artillerie : Unite {
public:
	Artillerie(CaseJ&, Joueur&);
	virtual ~Artillerie();
	bool isCaseAtteignable(const CaseJ& );
	bool isCaseAttaquable(const CaseJ&);
	void regenerer();
	char toChar();
};

#endif /* SRC_ARTILLERIE_H_ */
