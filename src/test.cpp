/*
 * test.cpp
 *
 *  Created on: 5 mai 2017
 *      Author: gdamay
 */
/*
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include "Joueur.cpp"
#include "Fantassin.hpp"

BOOST_AUTO_TEST_CASE(test_CaseJ)
{
	CaseJ pos1 = new CaseJ(3, 2);
	BOOST_CHECK(pos1.getPositionX() == 3);
	BOOST_CHECK(pos1.getPositionY() == 2);
	try{
		CaseJ pos2 = new CaseJ(-3, 2);
		BOOST_CHECK(false);
	}catch(std::exception & e){
		BOOST_CHECK(true);
	}
	try{
		CaseJ pos2 = new CaseJ(3, -2);
		BOOST_CHECK(false);
	}catch(std::exception & e){
		BOOST_CHECK(true);
	}
	try{
		CaseJ pos2 = new CaseJ(-3, -2);
		BOOST_CHECK(false);
	}catch(std::exception & e){
		BOOST_CHECK(true);
	}
	BOOST_CHECK(pos1.getUnite() == NULL);

	Joueur joueur = new Joueur;
	Fantassin fant1 = new Fantassin(pos1, joueur);
	pos1.setUnite(&fant1);
	BOOST_CHECK(pos1.getUnite() == &fant1);
	pos1.setUnite(NULL);


}

BOOST_AUTO_TEST_CASE(test_fantassin)
{
	Fantassin fant1 = new Fantassin();

}
*/
