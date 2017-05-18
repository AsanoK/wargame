/*
 * Partie.h
 *
 *  Created on: 5 mai 2017
 *      Author: emacedegastines
 */

#ifndef PARTIE_HPP_
#define PARTIE_HPP_

#include <vector>
#include <iostream>

#include "Joueur.hpp"

class Plateau;
class Fenetre;

class Partie {

private:
	std::vector<Joueur> m_joueurs;
	Fenetre *m_fenetre;
	Plateau *m_plateau;
	int m_tourDeJeu;

public:
	Partie();
	void lancerPartie();
	Plateau &getPlateau();
	Fenetre &getFenetre();
	Joueur &getJoueur1();
	Joueur &getJoueur2();
	int getTourDeJeu();
};

#endif /* PARTIE_HPP_ */

