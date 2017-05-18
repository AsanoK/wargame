/*
 * Artillerie.h
 *
 *  Created on: 15 mai 2017
 *      Author: Hugin
 */

#ifndef SRC_ARTILLERIE_H_
#define SRC_ARTILLERIE_H_
#include "Unite.hpp"
/**
 * classe artillerie, repr�sentant une unit� d'attaque � distance, h�rite d'artillerie
 */
class Artillerie : public Unite {
public:
	Artillerie(CaseJ&, Joueur&);
	virtual ~Artillerie();
	bool isCaseAtteignable(const CaseJ& );
	bool isCaseAttaquable(const CaseJ&);
	void regenerer();
	char toChar();

};

#endif /* SRC_ARTILLERIE_H_ */
