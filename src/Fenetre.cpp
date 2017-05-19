/*
 * Fenetre.cpp
 *
 *  Created on: 12 mai 2017
 *      Author: emacedegastines
 */

#include <cstdlib>

#include "Plateau.hpp"
#include "Fenetre.hpp"


Fenetre::Fenetre() : p_plateau(NULL){
	// TODO Auto-generated constructor stub

}

Fenetre::~Fenetre() {
	// TODO Auto-generated destructor stub
}
/**
 * méthode gérant la totalité de l'afficahge du plateau, couleurs et unités inclues
 */
void Fenetre::afficherGrille(){
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

}
/**
 * méthode gérant l'affichage du vainqueur
 * @param vainqueur : pseudo du joueur gagnant
 */
void Fenetre::afficherVainqueur(std::string &vainqueur) const{
	std::cout << "bravo, le vainqueur est le joueur "<< vainqueur << std::endl;
}
/**
 * méthode permettant d'afficher le joueur dont c'est le tour.
 * @param pseudo : le pseudo du joueur dont c'est le tour.
 */
void Fenetre::afficherTour(std::string pseudo) const{
	std::cout << "C'est au tour du joueur " << pseudo << std::endl;
}
/**
 * méthode permettant de demander au joueur quel sera son action
 * @return une chaine de caractère qui pourra être interprétée en tant que commande
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
 * méthode demandant à l'utilisateur le pseudonyme d'un joueur donné
 * @param : le joueur dont on souhaite récupérer le pseudo
 * @return : la chaine de caractère représentant ce pseudo
 */
std::string Fenetre::demanderPseudo(int joueur) const{
	std::cout << "Joueur " << joueur << ", entrez votre pseudo:" << std::endl;
	std::string pseudo;
	std::cin >> pseudo;
	return pseudo;
}
/**
 * méthode demandant quelle est la case d'une unité attaquante
 * @return la case sélectionnée
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
 * méthode demandant quelle est la case qui sera cible d'une attaque
 * @return la case à viser
 */
CaseJ *Fenetre::demanderCaseAttaquee() const{
	std::cout << "entrez la ligne de la case Ã  attaquer:" << std::endl;
    std::string s;
    std::cin >> s;

    while ( atoi(s.c_str()) <= 0 || atoi(s.c_str()) > Plateau::NBCASES){
    	std::cout << "entrez la ligne de la case Ã  attaquer:" << std::endl;
        std::cin >> s;
    }
    int position1 = atoi(s.c_str());

	std::cout << "entrez la colonne de la case Ã  attaquer:" << std::endl;
    std::cin >> s;
    while ( (int)s[0] - 64 <= 0|| (int)s[0] -64 > Plateau::NBCASES){
    	std::cout << "entrez la colonne de la case Ã  attaquer:" << std::endl;
        std::cin >> s;
    }
    int position2 = (int)s[0] - 64;
    std::cout << position1 << position2 << std::endl;
    return p_plateau->getCase(position1-1, position2-1);
}
/**
 * méthode permettant d'obtenir la case d'où va partir une unité
 * @return : la case de départ
 */
CaseJ *Fenetre::demanderCaseDepart() const{
	std::cout << "entrez la ligne de l'unite Ã  dÃ©placer:" << std::endl;
    std::string s;
    std::cin >> s;

    while ( atoi(s.c_str()) <= 0 || atoi(s.c_str()) > Plateau::NBCASES){
    	std::cout << "entrez la ligne de l'unite Ã  dÃ©placer:" << std::endl;
        std::cin >> s;
    }
    int position1 = atoi(s.c_str());

	std::cout << "entrez la colonne de l'unite Ã  dÃ©placer:" << std::endl;
    std::cin >> s;
    while ( (int)s[0] - 64 <= 0|| (int)s[0] -64 > Plateau::NBCASES){
    	std::cout << "entrez la colonne de l'unite Ã  dÃ©placer:" << std::endl;
        std::cin >> s;
    }
    int position2 = (int)s[0] - 64;

    return p_plateau->getCase(position1-1, position2-1);
}
/**
 * méthode permettant d'obtenir la case vers laquelle se déplace une unité
 * @return la case visée par le déplacement
 */
CaseJ *Fenetre::demanderCaseArrivee() const{
	std::cout << "entrez la ligne de la position d'arrivÃ©e:" << std::endl;
    std::string s;
    std::cin >> s;

    while ( atoi(s.c_str()) <= 0 || atoi(s.c_str()) > Plateau::NBCASES){
    	std::cout << "entrez la ligne de la position d'arrivÃ©e:" << std::endl;
        std::cin >> s;
    }
    int position1 = atoi(s.c_str());

	std::cout << "entrez la colonne de la position d'arrivÃ©e:" << std::endl;
    std::cin >> s;
    while ( (int)s[0] - 64 <= 0|| (int)s[0] -64 > Plateau::NBCASES){
    	std::cout << "entrez la colonne de la position d'arrivÃ©e:" << std::endl;
        std::cin >> s;
    }
    int position2 = (int)s[0] - 64;

    return p_plateau->getCase(position1-1, position2-1);
}

void Fenetre::setPlateau(Plateau &unPlateau) {
	p_plateau = &unPlateau;
}

void  Fenetre::affichageAttaqueRealisee(){
	std::cout<<"l'assaut est terminÃ©"<<std::endl;
}
void  Fenetre::affichageDeplacementRealise(){
	std::cout<<"dï¿½placement effectuï¿½"<<std::endl;
}
void Fenetre::affichageCibleEnVie(){
	std::cout<<"Les troupes ennemies ont tenues malgrï¿½ vos assauts"<<std::endl;
}
void Fenetre::affichageCibleDetruite(){
	std::cout<<"Vos troupes ont prï¿½valu, l'assaut est une rï¿½ussite!"<<std::endl;
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
