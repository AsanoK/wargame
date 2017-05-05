/*
 * Joueur.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: emacedegastines
 */

#include "Joueur.hpp"

/**
 * Constructeur
 */
Joueur::Joueur(std::string unPseudo, char uneCouleur[3]): pseudo(unPseudo), couleur(uneCouleur){

}

/**
 * Destructeur
 */
Joueur::~Joueur(){

}

/**
 * Fonctions
 */
void Joueur::regenererTroupe(){
	for (int i=0; i<unites.size(); ++i){
		unites.at(i).setVie( unites.at(i).getVie()*1.3 );
	}

}

void Joueur::executerTour(){

}

void Joueur::demanderCommande(){

}

void Joueur::terminerTour(){

}












/**
 * Accesseurs
 */

std::string Joueur::getPseudo(){
	return pseudo;
}

void Joueur::setPseudo(std::string unPseudo){
	pseudo = unPseudo;
}

char* Joueur::getCouleur(){
	return &couleur;
}

void Joueur::setCouleur(char uneCouleur[3]){
	couleur = uneCouleur;
}

Unite Joueur::getUnite(int unePosition){
	return unites.at(unePosition);
}

void Joueur::supprimerUnite(int unePosition){
	unites.erase(unites.begin()+unePosition);
}

void Joueur::ajouterUnite(Unite uneUnite){
	unites.push_back(uneUnite);
}

int Joueur::getNbrUnite(){
	return unites.size();
}


