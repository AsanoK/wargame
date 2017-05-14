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

#include "Plateau.hpp"
#include "Joueur.hpp"
#include "Fenetre.hpp"

class Partie {

private:
	std::vector<Joueur> m_joueurs;
	Fenetre m_fenetre;
	Plateau m_plateau;
	int m_tourDeJeu;

public:
	Partie();

private:
	void lancerPartie();

public:
	Plateau &getPlateau() const;
	Fenetre &getFenetre() const;
	Joueur &getJoueur1() const;
	Joueur &getJoueur2() const;
	int getTourDeJeu() const;
};


#endif /* PARTIE_HPP_ */
