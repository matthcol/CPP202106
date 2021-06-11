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
// visibility: public, private, protected, friend
private:
	// 3 attributes
	std::string m_nom;
	uint16_t m_departement;
	uint32_t m_population;

public:
	// constructors
	Ville();
	Ville(const std::string & nom, uint16_t departement, uint32_t population);

	// operators
	Ville & operator+=(int i);

	// methods
	std::string toString() const; // const: methode en lecture seule

	constexpr uint16_t departement() const {
		return m_departement;
	}

	constexpr void setDepartement(uint16_t mDepartement) {
		m_departement = mDepartement;
	}

	constexpr const std::string& nom() const {
		return m_nom;
	}

	void setNom(const std::string &mNom) {
		m_nom = mNom;
	}

	constexpr uint32_t population() const {
		return m_population;
	}

	constexpr void setPopulation(uint32_t mPopulation) {
		m_population = mPopulation;
	}
};

std::ostream & operator<<(std::ostream& os, const Ville & ville);

#endif /* VILLE_H_ */
