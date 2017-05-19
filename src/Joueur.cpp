/*
 * Joueur.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: emacedegastines
 */

#include <string>
#include <cstring>

#include "Fenetre.hpp"
#include "Partie.hpp"
#include "Joueur.hpp"



//=====================================================================
// Fonctions
//=====================================================================

Joueur::Joueur(Partie &unePartie, std::string &unPseudo, int unNumero, unsigned char uneCouleur[3]): m_pseudo(unPseudo), m_numero(unNumero), p_partie(&unePartie), p_fenetre(&p_partie->getFenetre()){
	std::memcpy(m_couleur, uneCouleur, sizeof(unsigned char) * 3);
}


void Joueur::regenererTroupe(){
	for (unsigned int i=0; i<m_unites.size(); ++i){
		m_unites.at(i)->regenerer();
	}

}

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

void Joueur::terminerTour(){

}

void Joueur::attaquer(){
	CaseJ* caseAttaquant = p_fenetre->demanderCaseAttaquant();
	if (caseAttaquant->getUnite() != NULL){
		CaseJ* caseAttaquee = p_fenetre->demanderCaseAttaquee();
		if(caseAttaquee->getUnite() != NULL){
			CaseJ* caseAttaquee = p_fenetre->demanderCaseAttaquee();
		}
		else{
			//afficher erreur
		}
	}
	else{
		//afficher erreur
	}
}

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

unsigned char *Joueur::getCouleur(){
	return m_couleur;
}

void Joueur::setCouleur(unsigned char uneCouleur[3]){
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


