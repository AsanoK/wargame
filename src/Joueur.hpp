/*
 * Joueur.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */

#ifndef JOUEUR_HPP_
#define JOUEUR_HPP_

#include <string>
#include <vector>

#include "Unite.hpp"


class Joueur{

	//=====================================================================
	// Attributs
	//=====================================================================

private:
	std::string pseudo;
	char couleur[3];
	std::vector<Unite> unites;
	Fenetre fenetre;

	//=====================================================================
	// Fonctions
	//=====================================================================

public:
	Joueur(std::string unPseudo, char uneCouleur[3]);
	void regenererTroupe();
	void executerTour();
private:
	void terminerTour();
	void attaquer();
	void deplacer();

	//=====================================================================
	// Accesseurs
	//=====================================================================

public:
	std::string getPseudo() const;
	void setPseudo(std::string unPseudo);
	char *getCouleur() const;
	void setCouleur(char uneCouleur[3]);
	Unite *getUnite(int unePosition) const;
	void supprimerUnite(int unePosition);
	void ajouterUnite(Unite uneUnite);
	int getNbrUnite() const;


};




#endif /* JOUEUR_HPP_ */
