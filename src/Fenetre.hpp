/*
 * Fenetre.h
 *
 *  Created on: 12 mai 2017
 *      Author: emacedegastines
 */

#ifndef SRC_FENETRE_HPP_
#define SRC_FENETRE_HPP_

#include <string>


class Fenetre {
public:
	Fenetre();
	virtual ~Fenetre();
	std::string demanderAction();
	std::string demanderCaseAttaquant();
	std::string demanderCaseAttaquee();
	std::string demanderCaseDepart();
	std::string demanderCaseArrivee();
};

#endif /* SRC_FENETRE_HPP_ */
