/*
 * Joueur.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */

#ifndef SRC_JOUEUR_HPP_
#define SRC_JOUEUR_HPP_

#include <string>
#include <vector>

#include "Unite.hpp"

class Fenetre;
class Partie;
/**
 * classe représentant un des joueurs
 */
class Joueur{

	//=====================================================================
	// Attributs
	//=====================================================================

private:
	std::string m_pseudo;
	int m_numero;
	unsigned char *m_couleur;
	std::vector<Unite*> m_unites;
	Partie *p_partie;
	Fenetre *p_fenetre;

	//=====================================================================
	// Fonctions
	//=====================================================================

public:
	Joueur(Partie& unePartie, std::string &unPseudo, int unNumero, unsigned char *uneCouleur);
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
	int getNumero() const;
	unsigned char *getCouleur();
	void setCouleur(unsigned char uneCouleur[3]);
	Unite *getUnite(int unePosition) const;
	void supprimerUnite(Unite &uneUnite);
	void ajouterUnite(Unite &uneUnite);
	int getNbrUnite() const;
	~Joueur();


};




#endif /* JOUEUR_HPP_ */
