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

class Fantassin : Unite{
public:
Fantassin(CaseJ, Joueur);
virtual ~Fantassin();
};




#endif /* FANTASSIN_HPP_ */
