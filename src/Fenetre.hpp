/*
 * Fenetre.h
 *
 *  Created on: 12 mai 2017
 *      Author: emacedegastines
 */

#ifndef SRC_FENETRE_HPP_
#define SRC_FENETRE_HPP_

#include <string>
class Case;
class Joueur;

class Fenetre {
public:
	Fenetre();
	virtual ~Fenetre();

	void afficherGrille();
	void afficherVainqueur(int vainqueur);
	std::string demanderAction();
	std::string demanderPseudo(int Joueur);
	Case demanderCaseAttaquant();
	Case demanderCaseAttaquee();
	Case demanderCaseDepart();
	Case demanderCaseArrivee();
};

#endif /* SRC_FENETRE_HPP_ */
