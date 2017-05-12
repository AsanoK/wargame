/*
 * Joueur.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */

#ifndef JOUEUR_HPP_
#define JOUEUR_HPP_

#include "Unite.hpp"
class Partie;
class Fenetre;


class Joueur{

	//=====================================================================
	// Attributs
	//=====================================================================

private:
	std::string m_pseudo;
	char m_couleur[3];
	std::vector<Unite> m_unites;
	Partie *p_partie;
	Fenetre *p_fenetre;

	//=====================================================================
	// Fonctions
	//=====================================================================

public:
	Joueur(const Partie &unePartie, const std::string &unPseudo, const char &uneCouleur[3]);
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
	void setPseudo(const std::string &unPseudo);
	char &getCouleur() const;
	void setCouleur(const char &uneCouleur[3]);
	Unite &getUnite(int unePosition) const;
	void supprimerUnite(int unePosition);
	void ajouterUnite(const Unite &uneUnite);
	int getNbrUnite() const;


};




#endif /* JOUEUR_HPP_ */
