/*
 * Fantassin.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */

#ifndef SRC_FANTASSIN_HPP_
#define SRC_FANTASSIN_HPP_

#include "ConstantesUnites.hpp"
#include  "Unite.hpp"

class CaseJ;
class Joueur;

/**
 * l'infanterie, une sous-classe d'unité
 */
class Fantassin : public Unite{
public:
Fantassin(CaseJ &uneCase, Joueur &unJoueur);
bool isCaseAtteignable(const CaseJ &unecase);
bool isCaseAttaquable(const CaseJ &uneCase);
void regenerer();
char toChar();
virtual ~Fantassin();
};




#endif /* FANTASSIN_HPP_ */
