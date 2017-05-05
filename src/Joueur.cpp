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

Joueur::Joueur(std::string unPseudo, char uneCouleur[3]): pseudo(unPseudo), couleur(uneCouleur){

}

<<<<<<< HEAD

=======
/**
 * Fonctions
 */
>>>>>>> d5b7ae922acbe2ef2f0aa0a8239eb0f08d22a5c0
void Joueur::regenererTroupe(){
	for (int i=0; i<unites.size(); ++i){
		unites.at(i).setVie( unites.at(i).getVie()*1.3 );
	}

}

void Joueur::executerTour(){
	std::string action = fenetre.demanderAction();
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
	Case caseAttaquant = fenetre.demanderCaseAttaquant();
	Case caseAttaquee = fenetre.demanderCaseAttaquee();
	caseAttaquant.getUnite()->attaquer(caseAttaquee);
	fenetre.afficherGrille();


}

void Joueur::deplacer(){
	Case caseDepart = fenetre.demanderCaseDepart();
	Case caseArrivee = fenetre.demanderCaseArrivee();
	caseDepart.getUnite()->deplacer(caseArrivee);
	fenetre.afficherGrille();

}


//=====================================================================
// Accesseurs
//=====================================================================

std::string Joueur::getPseudo() const{
	return pseudo;
}

void Joueur::setPseudo(std::string unPseudo){
	pseudo = unPseudo;
}

char *Joueur::getCouleur() const{
	return &couleur;
}

void Joueur::setCouleur(char uneCouleur[3]){
	couleur = uneCouleur;
}

Unite *Joueur::getUnite(int unePosition) const{
	return &unites.at(unePosition);
}

void Joueur::supprimerUnite(int unePosition){
	unites.erase(unites.begin()+unePosition);
}

void Joueur::ajouterUnite(Unite uneUnite){
	unites.push_back(uneUnite);
}

int Joueur::getNbrUnite() const{
	return unites.size();
}


