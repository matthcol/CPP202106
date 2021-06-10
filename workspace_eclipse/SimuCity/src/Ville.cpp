/*
 * Ville.cpp
 *
 *  Created on: 9 juin 2021
 *      Author: Matthias
 */

#include "Ville.h"

#include <sstream>

Ville::Ville():nom(""),departement(0),population(0) {
	// nom = ""; default fro class std::string
	// departement = 0;
	// population = 0;
}

Ville::Ville(const std::string &nom, uint16_t departement, uint32_t population):
		nom(nom),departement(departement), population(population)
{
}

Ville& Ville::operator+=(int i) {
	population += i;
	return *this;
}

std::string Ville::toString() const {
	std::stringstream buf; // buffer in memory as std::cout
	buf << nom << " (" << departement << ", pop " << population << ")";
	return buf.str();
}

std::ostream& operator<<(std::ostream &os, const Ville &ville) {
	return os << ville.toString();
}
