/*
 * Joueur.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: emacedegastines
 */

#include <string>

#include "Fenetre.hpp"
#include "Partie.hpp"
#include "Joueur.hpp"



//=====================================================================
// Fonctions
//=====================================================================
/**
 * constructeur de la classe joueur
 * @param unePartie : la partie � laquelle il appartiendra
 * @param unPseudo : le pseudo du joueur
 * @param unNumero : le num�ro du joueur
 * @param uneCouleur : la couleur qui sera utilis�e pour ce joueur
 *
 */
Joueur::Joueur(Partie &unePartie, std::string &unPseudo, int unNumero, char uneCouleur[3]): m_pseudo(unPseudo), m_numero(unNumero), m_couleur(uneCouleur), p_partie(&unePartie), p_fenetre(&p_partie->getFenetre()){

}

/**
 * m�thode permettant d'effectuer la r�g�n�ration de toutes les unit�s du joueur. Normalement appel� � tous les tours
 */
void Joueur::regenererTroupe(){
	for (unsigned int i=0; i<m_unites.size(); ++i){
		m_unites.at(i)->regenerer();
	}

}
/**
 * m�thode g�rant le tour d'un joueur
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
 * m�thode permettant d'effectuer les actions effectu�es syt�matiquement � la fin du tour
 */
void Joueur::terminerTour(){
	Fenetre::affichageFinDeTour();
}
/**
 * m�thode permettant de lancer une attaque
 */
void Joueur::attaquer(){
	CaseJ* caseAttaquant = p_fenetre->demanderCaseAttaquant();
	if (caseAttaquant->getUnite() != NULL){
		CaseJ* caseAttaquee = p_fenetre->demanderCaseAttaquee();
		if(caseAttaquee->getUnite() != NULL){
			caseAttaquant->getUnite()->attaquer(*caseAttaquee);
		}
		else{
			//afficher erreur
		}
	}
	else{
		//afficher erreur
	}
}
/**
 * m�thode permettant d'effectueer un d�placement
 */
void Joueur::deplacer(){
	CaseJ* caseDepart = p_fenetre->demanderCaseDepart();
	if (caseDepart->getUnite() != NULL){
		CaseJ* caseArrivee = p_fenetre->demanderCaseArrivee();
		if (caseArrivee->getUnite() == NULL){
			caseDepart->getUnite()->deplacer(*caseArrivee);
		}
		else{
			//erreur
			std::cout << "déjà une unité" << std::endl;
		}
	}
	else{
		//erreur
		std::cout << "pas d'unité" << std::endl;
	}
	p_fenetre->afficherGrille();

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

char *Joueur::getCouleur(){
	return m_couleur;
}

void Joueur::setCouleur(char uneCouleur[3]){
	m_couleur = uneCouleur;
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


