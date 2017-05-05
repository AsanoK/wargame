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
/**
 * attributs
 */
private:
	std::string pseudo;
	char couleur[3];
	std::vector<Unite> unites;

/**
 * fonctions
 */
public:
	Joueur(std::string unPseudo, char uneCouleur[3]);
	~Joueur();
	void regenererTroupe();
	void executerTour();
	void demanderCommande();
private:
	void terminerTour();

/**
 * accesseurs
 */
public:
	std::string getPseudo();
	void setPseudo(std::string unPseudo);
	char* getCouleur();
	void setCouleur(char uneCouleur[3]);
	Unite getUnite(int unePosition);
	void supprimerUnite(int unePosition);
	void ajouterUnite(Unite uneUnite);
	int getNbrUnite();


};




#endif /* JOUEUR_HPP_ */
