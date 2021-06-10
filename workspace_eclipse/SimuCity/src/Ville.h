/*
 * Ville.h
 *
 *  Created on: 9 juin 2021
 *      Author: Matthias
 */

#ifndef VILLE_H_
#define VILLE_H_

#include <string>
#include <cstdint>
#include <iostream>

class Ville {
public:
	// 3 attributes
	std::string nom;
	uint16_t departement;
	uint32_t population;

	// constructors
	Ville();
	Ville(const std::string & nom, uint16_t departement, uint32_t population);

	// operators
	Ville & operator+=(int i);

	// methods
	std::string toString() const; // const: methode en lecture seule

};

std::ostream & operator<<(std::ostream& os, const Ville & ville);

#endif /* VILLE_H_ */
