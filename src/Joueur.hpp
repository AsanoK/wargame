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
#include "Fenetre.hpp"
#include "Partie.hpp"


class Joueur{

	//=====================================================================
	// Attributs
	//=====================================================================

private:
	std::string m_pseudo;
	char m_couleur[3];
	std::vector<Unite*> m_unites;
	Partie *p_partie;
	Fenetre *p_fenetre;

	//=====================================================================
	// Fonctions
	//=====================================================================

public:
	Joueur(Partie& unePartie, std::string &unPseudo, char *uneCouleur);
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
	std::string &getPseudo();
	void setPseudo(const std::string &unPseudo);
	char *getCouleur();
	void setCouleur(char uneCouleur[3]);
	Unite *getUnite(int unePosition);
	void supprimerUnite(int unePosition);
	void ajouterUnite(Unite &uneUnite);
	int getNbrUnite() const;


};




#endif /* JOUEUR_HPP_ */
