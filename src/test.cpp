/*
 * test.cpp
 *
 *  Created on: 5 mai 2017
 *      Author: gdamay
 */

#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include "Joueur.cpp"
#include "Fantassin.hpp"

BOOST_AUTO_TEST_CASE(test_Case)
{
	Case pos1 = new Case(3, 2);
	BOOST_CHECK(pos1.getPositionX() == 3);
	BOOST_CHECK(pos1.getPositionY() == 2);
	try{

	}catch(std::exception & e){

	}


}

BOOST_AUTO_TEST_CASE(test_fantassin)
{
	Fantassin fant1 = new Fantassin();

}
