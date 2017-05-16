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

private:
	Plateau *p_plateau;

public:
	Fenetre();
	virtual ~Fenetre();

	void afficherGrille();
	void afficherVainqueur(std::string &vainqueur);
	std::string demanderAction();
	std::string demanderPseudo(int joueur);
	Case demanderCaseAttaquant();
	Case demanderCaseAttaquee();
	Case demanderCaseDepart();
	Case demanderCaseArrivee();

	void setPlateau(const Plateau &unPlateau);
};

#endif /* SRC_FENETRE_HPP_ */
