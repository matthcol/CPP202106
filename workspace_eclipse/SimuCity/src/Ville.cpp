/*
 * Ville.cpp
 *
 *  Created on: 9 juin 2021
 *      Author: Matthias
 */

#include "Ville.h"

#include <sstream>

Ville::Ville():m_nom(""),m_departement(0),m_population(0) {
	// nom = ""; default fro class std::string
	// departement = 0;
	// population = 0;
}

Ville::Ville(const std::string &nom, uint16_t departement, uint32_t population):
		m_nom(nom),m_departement(departement), m_population(population)
{
}

Ville& Ville::operator+=(int i) {
	m_population += i;
	return *this;
}

std::string Ville::toString() const {
	std::stringstream buf; // buffer in memory as std::cout
	buf << m_nom << " (" << m_departement << ", pop " << m_population << ")";
	return buf.str();
}

std::ostream& operator<<(std::ostream &os, const Ville &ville) {
	return os << ville.toString();
}
