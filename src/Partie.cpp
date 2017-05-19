/*
 * Partie.cpp
 *
 *  Created on: 5 mai 2017
 *      Author: emacedegastines
 */

#include "Partie.hpp"



Partie::Partie():m_tourDeJeu(0), m_plateau(), m_fenetre(){
	// cration du premier joueur
	this->m_joueurs.reserve(2);

	std::string pseudo1 = m_fenetre.demanderPseudo(1);
	unsigned char couleur1[3] = {COULEUR_J1,COULEUR_J1, COULEUR_J1};
	Joueur *joueur1 = new Joueur(*this, pseudo1, 1, couleur1);
	this->m_joueurs.push_back(*joueur1);

	// creation du deuxieme joueur
	std::string pseudo2 = m_fenetre.demanderPseudo(2);
	unsigned char couleur2[3] = {COULEUR_J2, COULEUR_J2, COULEUR_J2};
	Joueur *joueur2 = new Joueur(*this, pseudo2, 2, couleur2);
	this->m_joueurs.push_back(*joueur2);

	// Initialisation de Plateau
	m_plateau.setPartie(*this);
	m_fenetre.setPlateau(m_plateau);
	return;
}


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


Plateau &Partie::getPlateau(){
	return m_plateau;
}
Fenetre &Partie::getFenetre(){
	return m_fenetre;
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
	for(int i = 0; i<this->m_joueurs.size(); i++)
		delete(&this->m_joueurs.at(i));
}

