/*
 * Fenetre.h
 *
 *  Created on: 12 mai 2017
 *      Author: emacedegastines
 */

#ifndef SRC_FENETRE_HPP_
#define SRC_FENETRE_HPP_

#include <string>
#include <iostream>

class Plateau;
class CaseJ;
/**
 * classe g�rant la totalit� de l'affichage du programme
 */
class Fenetre {

private:
	Plateau *p_plateau;

public:
	Fenetre();
	virtual ~Fenetre();

	void afficherGrille();
	void afficherTour(std::string pseudo) const;
	void afficherVainqueur(std::string &vainqueur) const;
	std::string demanderAction() const;
	std::string demanderPseudo(int joueur) const;

	CaseJ *demanderCaseAttaquant() const;
	CaseJ *demanderCaseAttaquee() const;
	CaseJ *demanderCaseDepart() const;
	CaseJ *demanderCaseArrivee() const;
	void static affichageAttaqueRealisee();
	void static affichageDeplacementRealise();
	void static affichageCibleEnVie();
	void static affichageCibleDetruite();
	void static affichageAttaqueLancee();
	void static affichageDeplacementLance();
	void static affichageFinDeTour();
	void setPlateau(Plateau &unPlateau);
};

#endif /* SRC_FENETRE_HPP_ */
