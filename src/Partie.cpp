/*
 * Partie.cpp
 *
 *  Created on: 5 mai 2017
 *      Author: emacedegastines
 */

#include "Partie.hpp"

#include "Fenetre.hpp"
#include <string>

Partie::Partie():m_tourDeJeu(0), m_fenetre(){
	// cration du premier joueur
	std::string pseudo1 m_plateau.getFenetre().demanderPseudo();
	char couleur1[3] = {255,255,0};
	Joueur joueur1(pseudo1, couleur1);

	// creation du deuxieme joueur
	std::string pseudo2 m_plateau.getFenetre().demanderPseudo();
	char couleur2[3] = {0,255,255};
	Joueur joueur2(pseudo2, couleur2);

	m_plateau(this);
}


void Partie::lancerPartie(){
	int fin = 0;
	while(fin == 0){
		getJoueur1().executerTour();
		if (getJoueur1().getNbrUnites == 0){
			fin = 1;
			break;
		}
		if (getJoueur2().getNbrUnites == 0){
			fin = 2;
			break;
		}
		getJoueur2().executerTour();
		if (getJoueur1().getNbrUnites == 0){
			fin = 1;
			break;
		}
		if (getJoueur2().getNbrUnites == 0){
			fin = 2;
			break;
		}

	}

	m_fenetre.afficherVainqueur(fin);

}


Plateau *Partie::getPlateau() const{
	return *m_plateau;
}
Joueur *Partie::getJoueur1() const{
	return m_joueurs.at(0);
}
Joueur *Partie::getJoueur2() const{
	return m_joueurs.at(1);
}
int Partie::getTourDeJeu() const{
	return m_tourDeJeu;
}
