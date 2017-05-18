/*
 * Fenetre.cpp
 *
 *  Created on: 12 mai 2017
 *      Author: emacedegastines
 */

#include "Fenetre.hpp"

Fenetre::Fenetre() : p_plateau(0){
	// TODO Auto-generated constructor stub

}

Fenetre::~Fenetre() {
	// TODO Auto-generated destructor stub
}

void Fenetre::afficherGrille(){
	std::cout << "  A B C D E F G H I J K L M N O P Q R S  " << std::endl;
	CaseJ caseAffichee;
	for (int i=0; i<Plateau::NBCASES; ++i){
		if (i < 10){
		std::cout << " ";
		}
		std::cout << i << " " ;

		for (int j=0; j<Plateau::NBCASES; ++i){
			caseAffichee = p_plateau->getCase(i,j);
			if ( caseAffichee.getUnite() == 0 ){
				std::cout << ".";
			}
			else{
				std::cout << caseAffichee.getUnite()->toChar();
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}

}

void Fenetre::afficherVainqueur(std::string &vainqueur){
	std::cout << "bravo, le vainqueur est le joueur "<< vainqueur << std::endl;
}

std::string Fenetre::demanderAction(){
	std::cout << "quelle action souhaitez vous faire? (q : arret, a a: attaquer, d : deplacer)" << std::endl;
	std::string action;
	std::cin >> action;
	while (action != "a" && action !="q" && action != "d"){
		std::cout << "quelle action souhaitez vous faire? (q : arret, a a: attaquer, d : deplacer)" << std::endl;
		std::cin >> action;
	}
	return action;
}

std::string Fenetre::demanderPseudo(int joueur){
	std::cout << "Joueur " << joueur << ", entrez votre pseudo:" << std::endl;
	std::string pseudo;
	std::cin >> pseudo;
	return pseudo;
}

Case Fenetre::demanderCaseAttaquant(){
	std::cout << "entrez la position de l'attaquant (7S):" << std::endl;
    std::string s;
    std::cin >> s;
    while ( (int)s[0] <= 48 || (int)s[0] >=55 || (int)s[1] <= 65 || (int)s[1] >= 83){
    	std::cout << "entrez la position de l'attaquant (7S):" << std::endl;
        std::cin >> s;
    }
    return p_plateau->getCase((int)s[0] - 48, (int)s[1]);
}

Case Fenetre::demanderCaseAttaquee(){
	std::cout << "entrez la case à attaquer (7S):" << std::endl;
    std::string s;
    std::cin >> s;
    while ( (int)s[0] <= 48 || (int)s[0] >=55 || (int)s[1] <= 65 || (int)s[1] >= 83){
    	std::cout << "entrez la case à attaquer (7S):" << std::endl;
        std::cin >> s;
    }
    return p_plateau->getCase((int)s[0] - 48, (int)s[1]);
}

Case Fenetre::demanderCaseDepart(){
	std::cout << "entrez la position de l'unité à déplacer (7S):" << std::endl;
    std::string s;
    std::cin >> s;
    while ( (int)s[0] <= 48 || (int)s[0] >=55 || (int)s[1] <= 65 || (int)s[1] >= 83){
    	std::cout << "entrez la position de l'unité à déplacer (7S):" << std::endl;
        std::cin >> s;
    }
    return p_plateau->getCase((int)s[0] - 48, (int)s[1]);
}

Case Fenetre::demanderCaseArrivee(){
	std::cout << "entrez la position d'arrivée (7S):" << std::endl;
    std::string s;
    std::cin >> s;
    while ( (int)s[0] <= 48 || (int)s[0] >=55 || (int)s[1] <= 65 || (int)s[1] >= 83){
    	std::cout << "entrez la position d'arrivée (7S):" << std::endl;
        std::cin >> s;
    }
    return p_plateau->getCase((int)s[0] - 48, (int)s[1]);
}

void Fenetre::setPlateau(const Plateau &unPlateau){
	p_plateau = &unPlateau;
}

