//============================================================================
// Name        : wargame.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Partie.hpp"
using namespace std;

#if !TEST
/**
 * main du programme
 */
int main( int argc, const char* argv[] )
{
	Partie p=Partie();
	p.lancerPartie();
	return 0;
}
#endif
