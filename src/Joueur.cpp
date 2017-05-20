/*
 * Joueur.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: emacedegastines
 */

#include <string>
#include <stdio.h>

#include "Fenetre.hpp"
#include "Partie.hpp"
#include "Joueur.hpp"



//=====================================================================
// Fonctions
//=====================================================================

/**
 * constructeur de la classe joueur
 * @param unePartie : la partie à laquelle il appartiendra
 * @param unPseudo : le pseudo du joueur
 * @param unNumero : le numéro du joueur
 * @param uneCouleur : la couleur qui sera utilisée pour ce joueur
 *
 */
Joueur::Joueur(Partie &unePartie, std::string &unPseudo, int unNumero, unsigned char uneCouleur[3]): m_pseudo(unPseudo), m_numero(unNumero), p_partie(&unePartie), p_fenetre(p_partie->getFenetre()){
	m_couleur = new unsigned char[3];
	for(int i = 0; i<3; i++)
		m_couleur[i] = uneCouleur[i];
#if COULEUR
	char buffer[3];
	sprintf(buffer, "%d", m_couleur[0] + 1);
	m_pseudo = "\e[38;5;" + (std::string)buffer + "m" + m_pseudo + "\e[39m";
#endif
}

/**
 * méthode permettant d'effectuer la régénération de toutes les unités du joueur. Normalement appelée à tous les tours
 */
void Joueur::regenererTroupe(){
	for (unsigned int i=0; i<m_unites.size(); ++i){
		m_unites.at(i)->regenerer();
	}

}
/**
 * méthode gérant le tour d'un joueur
 */
void Joueur::executerTour(){
	regenererTroupe();
	p_fenetre->afficherTour(this->m_pseudo);
	p_fenetre->afficherGrille();
	std::string action = p_fenetre->demanderAction();
	p_fenetre->afficherGrille();
	while ( action != "q"){
		if (action == "a"){
			attaquer();
		}
		else if(action == "d"){
			deplacer();
		}
		p_fenetre->afficherGrille();
		action = p_fenetre->demanderAction();
	}
	terminerTour();
}
/**
 * méthode permettant d'effectuer les actions effectuées sytématiquement à la fin du tour
 */
void Joueur::terminerTour(){
	Fenetre::affichageFinDeTour();
}
/**
 * méthode permettant de lancer une attaque
 */
void Joueur::attaquer(){
	CaseJ* caseAttaquant = p_fenetre->demanderCaseAttaquant();
	if (caseAttaquant->getUnite() != NULL){
		if (caseAttaquant->getUnite()->getJoueur()==this)
		{
			CaseJ* caseAttaquee = p_fenetre->demanderCaseAttaquee();
			if(caseAttaquee->getUnite() != NULL){
				caseAttaquant->getUnite()->attaquer(*caseAttaquee);
			}
			else{
				//erreur
				std::cout << "Pas d'unité à attaquer" << std::endl;
			}
		}
		else
		{
			//erreur
			std::cout << "Cette unité ne vous appartient pas" << std::endl;
		}
	}
	else{
		//erreur
		std::cout << "Pas d'unité pour attaquer" << std::endl;
	}
}
/**
 * méthode permettant d'effectuer un déplacement
 */
void Joueur::deplacer(){
	CaseJ* caseDepart = p_fenetre->demanderCaseDepart();
	if (caseDepart->getUnite() != NULL){
		if (caseDepart->getUnite()->getJoueur()==this)
		{
			CaseJ* caseArrivee = p_fenetre->demanderCaseArrivee();
			if (caseArrivee->getUnite() == NULL){
				caseDepart->getUnite()->deplacer(*caseArrivee);
			}
			else{
				//erreur
				std::cout << "La case visée est déjà occupée" << std::endl;
			}
		}
		else
		{
			std::cout << "Cette unité ne vous appartient pas" << std::endl;
		}
	}
	else{
		//erreur
		std::cout << "Pas d'unité à déplacer" << std::endl;
	}
}


//=====================================================================
// Accesseurs
//=====================================================================

std::string &Joueur::getPseudo(){
	return m_pseudo;
}

void Joueur::setPseudo(const std::string &unPseudo){
	m_pseudo = unPseudo;
}

int Joueur::getNumero() const{
	return m_numero;
}

unsigned char *Joueur::getCouleur(){
	return m_couleur;
}

void Joueur::setCouleur(unsigned char uneCouleur[3]){
	for(int i = 0; i<3; i++)
		m_couleur[i] = uneCouleur[i];
}

Unite *Joueur::getUnite(int unePosition) const{
	return m_unites.at(unePosition);
}

void Joueur::supprimerUnite(Unite &uneUnite){
	int i=0;
	while(m_unites.at(i) != &uneUnite){
		i=i+1;
	}
	m_unites.erase(m_unites.begin()+i);
}

void Joueur::ajouterUnite(Unite &uneUnite){
	m_unites.push_back(&uneUnite);
}

int Joueur::getNbrUnite() const{
	return m_unites.size();
}

Joueur::~Joueur(){
	delete m_couleur;
}

