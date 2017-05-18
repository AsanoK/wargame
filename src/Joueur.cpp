/*
 * Joueur.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: emacedegastines
 */

#include <string>

#include "Joueur.hpp"



//=====================================================================
// Fonctions
//=====================================================================

Joueur::Joueur(const Partie &unePartie, const std::string &unPseudo, const char *uneCouleur): m_pseudo(unPseudo), this.m_couleur(uneCouleur), p_partie(&unePartie), p_fenetre(p_partie->getFenetre()){

}


void Joueur::regenererTroupe(){
	for (int i=0; i<m_unites.size(); ++i){
		m_unites.at(i).setVie( m_unites.at(i).getVie()*1.3 );
	}

}

void Joueur::executerTour(){
	std::string action = p_fenetre->demanderAction();
	while ( action != "q"){
		if (action == "a"){
			attaquer();
		}
		else if(action == "d"){
			deplacer();
		}
	}
	terminerTour();
}

void Joueur::terminerTour(){

}

void Joueur::attaquer(){
	CaseJ caseAttaquant = p_fenetre->demanderCaseAttaquant();
	CaseJ caseAttaquee = p_fenetre->demanderCaseAttaquee();
	caseAttaquant.getUnite().attaquer(caseAttaquee);
	p_fenetre->afficherGrille();


}

void Joueur::deplacer(){
	CaseJ caseDepart = p_fenetre->demanderCaseDepart();
	CaseJ caseArrivee = p_fenetre->demanderCaseArrivee();
	caseDepart.getUnite().deplacer(caseArrivee);
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

char &Joueur::getCouleur(){
	return m_couleur;
}

void Joueur::setCouleur(char *uneCouleur){
	m_couleur = uneCouleur;
}

Unite &Joueur::getUnite(int unePosition){
	return m_unites.at(unePosition);
}

void Joueur::supprimerUnite(int unePosition){
	m_unites.erase(m_unites.begin()+unePosition);
}

void Joueur::ajouterUnite(const Unite &uneUnite){
	m_unites.push_back(uneUnite);
}

int Joueur::getNbrUnite() const{
	return m_unites.size();
}


