/*
 * Fenetre.cpp
 *
 *  Created on: 12 mai 2017
 *      Author: emacedegastines
 */

#include <cstdlib>
#include <stdio.h>
#include <string>
#include <iostream>

#include "Plateau.hpp"
#include "Fenetre.hpp"


Fenetre::Fenetre() : p_plateau(NULL){
	// TODO Auto-generated constructor stub

}

Fenetre::~Fenetre() {
	// TODO Auto-generated destructor stub
}
/**
 * m�thode g�rant la totalit� de l'afficahge du plateau, couleurs et unit�s inclues
 */
void Fenetre::afficherGrille(){
#if !COULEUR
	std::cout << "   A B C D E F G H I J K L M N O P Q R S T " << std::endl;
	CaseJ *caseAffichee = NULL;
	for (int i=0; i<Plateau::NBCASES; ++i){
		if (i < 9){
			std::cout << " ";
		}
		std::cout << i + 1 << " " ;

		for (int j=0; j<Plateau::NBCASES; ++j){
			caseAffichee = p_plateau->getCase(i,j);
			Unite* unite = caseAffichee->getUnite();
			if ( unite == NULL){
				std::cout << ".";
			}
			else{
				std::cout << unite->toChar();
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
#else
	std::string couleurBack;
	std::string couleurFront = "\e[39m";
	std::cout << "   ";
	for(char lettre = 'A'; lettre < 'A' + Plateau::NBCASES; lettre++)
	{
		if((lettre-'A')%2 == 1)
			couleurBack = "\e[40m";
		else
			couleurBack = "\e[44m";
		std::cout << couleurFront << couleurBack << lettre << " ";
	}
	couleurBack = "\e[40m";
	std::cout << couleurFront << couleurBack << std::endl;

	CaseJ *caseAffichee = NULL;
	for (int i=0; i<Plateau::NBCASES; ++i){
		if(i%2==0)
			couleurBack = "\e[100m";
		else
			couleurBack = "\e[40m";
		if (i < 9){
			std::cout << couleurFront << couleurBack << " ";
		}
		else
			std::cout << couleurFront << couleurBack;
		std::cout << i + 1 << " " ;

		for (int j=0; j<Plateau::NBCASES; ++j){
			if(i%2==0)
			{
				if(j%2 == 0)
					couleurBack = "\e[104m";
				else
					couleurBack = "\e[100m";
			}
			else
			{
				if(j%2 == 0)
					couleurBack = "\e[44m";
				else
					couleurBack = "\e[40m";
			}
			caseAffichee = p_plateau->getCase(i,j);
			Unite* unite = caseAffichee->getUnite();
			if ( unite == NULL){
				couleurFront = "\e[39m";
				std::cout << couleurFront << couleurBack << ".";
			}
			else{
				char buffer[3];
				sprintf(buffer, "%d", unite->getJoueur()->getCouleur()[0] + 1);
				couleurFront = "\e[38;5;" + (std::string)buffer;
				couleurFront += "m";
				std::cout << couleurFront << couleurBack << unite->toChar();
			}
			std::cout << " ";
		}
		couleurFront = "\e[39m";
		couleurBack = "\e[49m";
		std::cout << couleurFront << couleurBack << std::endl;
	}
#endif
}
/**
 * m�thode g�rant l'affichage du vainqueur
 * @param vainqueur : pseudo du joueur gagnant
 */
void Fenetre::afficherVainqueur(std::string &vainqueur) const{
	std::cout << "bravo, le vainqueur est le joueur "<< vainqueur << std::endl;
}
/**
 * m�thode permettant d'afficher le joueur dont c'est le tour.
 * @param pseudo : le pseudo du joueur dont c'est le tour.
 */
void Fenetre::afficherTour(std::string pseudo) const{
	std::cout << "C'est au tour du joueur " << pseudo << std::endl;
}
/**
 * m�thode permettant de demander au joueur quel sera son action
 * @return une chaine de caract�re qui pourra �tre interpr�t�e en tant que commande
 */
std::string Fenetre::demanderAction() const{
	std::cout << "quelle action souhaitez vous faire? (q : arret, a: attaquer, d : deplacer)" << std::endl;
	std::string action;
	std::cin >> action;
	while (action != "a" && action !="q" && action != "d"){
		std::cout << "quelle action souhaitez vous faire? (q : arret, a: attaquer, d : deplacer)" << std::endl;
		std::cin >> action;
	}
	return action;
}
/**
 * m�thode demandant � l'utilisateur le pseudonyme d'un joueur donn�
 * @param : le joueur dont on souhaite r�cup�rer le pseudo
 * @return : la chaine de caract�re repr�sentant ce pseudo
 */
std::string Fenetre::demanderPseudo(int joueur) const{
	std::cout << "Joueur " << joueur << ", entrez votre pseudo:" << std::endl;
	std::string pseudo;
	std::cin >> pseudo;
	return pseudo;
}
/**
 * m�thode demandant quelle est la case d'une unit� attaquante
 * @return la case s�lectionn�e
 */
CaseJ *Fenetre::demanderCaseAttaquant() const{
	std::cout << "entrez la ligne de l'attaquant:" << std::endl;
    std::string s;
    std::cin >> s;

    while ( atoi(s.c_str()) <= 0 || atoi(s.c_str()) > Plateau::NBCASES){
    	std::cout << "entrez la ligne de l'attaquant:" << std::endl;
        std::cin >> s;
    }
    int position1 = atoi(s.c_str());

	std::cout << "entrez la colonne de l'attaquant:" << std::endl;
    std::cin >> s;
    while ( (int)s[0] - 64 <= 0|| (int)s[0] -64 > Plateau::NBCASES){
    	std::cout << "entrez la colonne de l'attaquant:" << std::endl;
        std::cin >> s;
    }
    int position2 = (int)s[0] - 64;

    return p_plateau->getCase(position1-1, position2-1);
}
/**
 * m�thode demandant quelle est la case qui sera cible d'une attaque
 * @return la case � viser
 */
CaseJ *Fenetre::demanderCaseAttaquee() const{
	std::cout << "entrez la ligne de la case à attaquer:" << std::endl;
    std::string s;
    std::cin >> s;

    while ( atoi(s.c_str()) <= 0 || atoi(s.c_str()) > Plateau::NBCASES){
    	std::cout << "entrez la ligne de la case à attaquer:" << std::endl;
        std::cin >> s;
    }
    int position1 = atoi(s.c_str());

	std::cout << "entrez la colonne de la case à attaquer:" << std::endl;
    std::cin >> s;
    while ( (int)s[0] - 64 <= 0|| (int)s[0] -64 > Plateau::NBCASES){
    	std::cout << "entrez la colonne de la case à attaquer:" << std::endl;
        std::cin >> s;
    }
    int position2 = (int)s[0] - 64;
    //std::cout << position1 << position2 << std::endl;
    return p_plateau->getCase(position1-1, position2-1);
}
/**
 * m�thode permettant d'obtenir la case d'o� va partir une unit�
 * @return : la case de d�part
 */
CaseJ *Fenetre::demanderCaseDepart() const{
	std::cout << "entrez la ligne de l'unite à déplacer:" << std::endl;
    std::string s;
    std::cin >> s;

    while ( atoi(s.c_str()) <= 0 || atoi(s.c_str()) > Plateau::NBCASES){
    	std::cout << "entrez la ligne de l'unite à déplacer:" << std::endl;
        std::cin >> s;
    }
    int position1 = atoi(s.c_str());

	std::cout << "entrez la colonne de l'unite à déplacer:" << std::endl;
    std::cin >> s;
    while ( (int)s[0] - 64 <= 0|| (int)s[0] -64 > Plateau::NBCASES){
    	std::cout << "entrez la colonne de l'unite à déplacer:" << std::endl;
        std::cin >> s;
    }
    int position2 = (int)s[0] - 64;

    return p_plateau->getCase(position1-1, position2-1);
}
/**
 * m�thode permettant d'obtenir la case vers laquelle se d�place une unit�
 * @return la case vis�e par le d�placement
 */
CaseJ *Fenetre::demanderCaseArrivee() const{
	std::cout << "entrez la ligne de la position d'arrivée:" << std::endl;
    std::string s;
    std::cin >> s;

    while ( atoi(s.c_str()) <= 0 || atoi(s.c_str()) > Plateau::NBCASES){
    	std::cout << "entrez la ligne de la position d'arrivée:" << std::endl;
        std::cin >> s;
    }
    int position1 = atoi(s.c_str());

	std::cout << "entrez la colonne de la position d'arrivée:" << std::endl;
    std::cin >> s;
    while ( (int)s[0] - 64 <= 0|| (int)s[0] -64 > Plateau::NBCASES){
    	std::cout << "entrez la colonne de la position d'arrivée:" << std::endl;
        std::cin >> s;
    }
    int position2 = (int)s[0] - 64;

    return p_plateau->getCase(position1-1, position2-1);
}

void Fenetre::setPlateau(Plateau &unPlateau) {
	p_plateau = &unPlateau;
}

void  Fenetre::affichageAttaqueRealisee(){
	std::cout<<"l'assaut est terminé"<<std::endl;
}
void  Fenetre::affichageDeplacementRealise(){
	std::cout<<"déplacement effectué"<<std::endl;
}
void Fenetre::affichageCibleEnVie(){
	std::cout<<"Les troupes ennemies ont tenues malgré vos assauts"<<std::endl;
}
void Fenetre::affichageCibleDetruite(){
	std::cout<<"Vos troupes ont prévalu, l'assaut est une réussite!"<<std::endl;
}
void Fenetre::affichageAttaqueLancee(){
	std::cout<<'vos troupes se lancent au combat'<<std::endl;
}
void Fenetre::affichageDeplacementLance(){
	std::cout<<'vos troupes se mettent en marche'<<std::endl;
}
void Fenetre::affichageFinDeTour(){
	std::cout<<'fin du tour'<<std::endl;
}
