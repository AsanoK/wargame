/*
 * Partie.cpp
 *
 *  Created on: 5 mai 2017
 *      Author: emacedegastines
 */

#include "Partie.hpp"


/**
 * Constructeur de la partie
 *
 */
Partie::Partie():m_tourDeJeu(0), m_plateau(), m_fenetre(){
	// création du premier joueur
	m_joueurs.reserve(2);
	std::string pseudo1 = m_fenetre.demanderPseudo(1);
	unsigned char couleur1[3] = {COULEUR_J1,COULEUR_J1, COULEUR_J1};
	Joueur *joueur1 = new Joueur(*this, pseudo1, 1, couleur1);
	m_joueurs.push_back(*joueur1);

	// création du deuxième joueur
	std::string pseudo2 = m_fenetre.demanderPseudo(2);
	unsigned char couleur2[3] = {COULEUR_J2, COULEUR_J2, COULEUR_J2};
	Joueur *joueur2 = new Joueur(*this, pseudo2, 2, couleur2);
	m_joueurs.push_back(*joueur2);

	// Initialisation de Plateau
	m_plateau.setPartie(*this);
	m_fenetre.setPlateau(m_plateau);
	return;
}

/**
 * Gestion de la partie
 */
void Partie::lancerPartie(){
	int fin = 0;
	while(fin == 0){
		getJoueur1()->executerTour();
		if (getJoueur1()->getNbrUnite() == 0){
			fin = 1;
			break;
		}
		if (getJoueur2()->getNbrUnite() == 0){
			fin = 2;
			break;
		}
		getJoueur2()->executerTour();
		if (getJoueur1()->getNbrUnite() == 0){
			fin = 1;
			break;
		}
		if (getJoueur2()->getNbrUnite() == 0){
			fin = 2;
			break;
		}

	}
	if (fin==1){
		m_fenetre.afficherVainqueur(getJoueur1()->getPseudo());
	}
	else{
		m_fenetre.afficherVainqueur(getJoueur2()->getPseudo());
	}
}


Plateau *Partie::getPlateau(){
	return &m_plateau;
}
Fenetre *Partie::getFenetre(){
	return &m_fenetre;
}
Joueur* Partie::getJoueur1(){
	return &m_joueurs.at(0);
}
Joueur* Partie::getJoueur2(){
	return &m_joueurs.at(1);
}
int Partie::getTourDeJeu(){
	return m_tourDeJeu;
}

Partie::~Partie(){
	for(int i = 0; i<m_joueurs.size(); i++)
		delete(&m_joueurs.at(i));
}

