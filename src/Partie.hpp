/*
 * Partie.h
 *
 *  Created on: 5 mai 2017
 *      Author: emacedegastines
 */

#ifndef SRC_PARTIE_HPP_
#define SRC_PARTIE_HPP_

#include <vector>
#include <iostream>

#include "Joueur.hpp"
#include "Plateau.hpp"
#include "Fenetre.hpp"
/**
 * classe gérant la totalité de la partie, notamment l'alternance des tours de jeu
 */
class Partie {

private:
	std::vector<Joueur> m_joueurs;
	Fenetre m_fenetre;
	Plateau m_plateau;
	int m_tourDeJeu;

public:
	Partie();
	void lancerPartie();
	Plateau *getPlateau();
	Fenetre *getFenetre();
	Joueur* getJoueur1();
	Joueur* getJoueur2();
	int getTourDeJeu();
};

#endif /* PARTIE_HPP_ */

