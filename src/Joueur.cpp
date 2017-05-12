/*
 * Joueur.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: emacedegastines
 */

#include "Joueur.hpp"



//=====================================================================
// Fonctions
//=====================================================================

Joueur::Joueur(const Partie &unePartie, const std::string &unPseudo, const char &uneCouleur[3]): m_pseudo(unPseudo), m_couleur(uneCouleur), p_partie(&unePartie), p_fenetre(p_partie->getFenetre()){

}


void Joueur::regenererTroupe(){
	for (int i=0; i<unites.size(); ++i){
		unites.at(i).setVie( unites.at(i).getVie()*1.3 );
	}

}

void Joueur::executerTour(){
	std::string action = p_fenetre.demanderAction();
	while ( action != "arret"){
		if (action == "attaque"){
			attaquer();
		}
		else if(action == "deplacer"){
			deplacer();
		}
	}
	terminerTour();
}

void Joueur::terminerTour(){

}

void Joueur::attaquer(){
	Case caseAttaquant = p_fenetre.demanderCaseAttaquant();
	Case caseAttaquee = p_fenetre.demanderCaseAttaquee();
	caseAttaquant.getUnite()->attaquer(caseAttaquee);
	p_fenetre.afficherGrille();


}

void Joueur::deplacer(){
	Case caseDepart = p_fenetre.demanderCaseDepart();
	Case caseArrivee = p_fenetre.demanderCaseArrivee();
	caseDepart.getUnite()->deplacer(caseArrivee);
	p_fenetre.afficherGrille();

}


//=====================================================================
// Accesseurs
//=====================================================================

std::string Joueur::getPseudo() const{
	return m_pseudo;
}

void Joueur::setPseudo(std::string &unPseudo){
	m_pseudo = unPseudo;
}

char &Joueur::getCouleur() const{
	return m_couleur;
}

void Joueur::setCouleur(char &uneCouleur[3]){
	m_couleur = uneCouleur;
}

Unite &Joueur::getUnite(int unePosition) const{
	return unites.at(unePosition);
}

void Joueur::supprimerUnite(int unePosition){
	unites.erase(unites.begin()+unePosition);
}

void Joueur::ajouterUnite(Unite &uneUnite){
	unites.push_back(uneUnite);
}

int Joueur::getNbrUnite() const{
	return unites.size();
}


