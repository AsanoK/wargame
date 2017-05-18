/*
 * Fantassin.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Hugin
 */

#ifndef FANTASSIN_HPP_
#define FANTASSIN_HPP_
#include "ConstantesUnites.hpp"
#include "Unite.hpp"
class Unite;
class CaseJ;
/**
 * l'infanterie, une sous-classe d'unité
 */
class Fantassin : public Unite{
public:
Fantassin(CaseJ&, Joueur&);
bool isCaseAtteignable(const CaseJ& );
bool isCaseAttaquable(const CaseJ&);
void regenerer();
char toChar();
virtual ~Fantassin();
};




#endif /* FANTASSIN_HPP_ */
