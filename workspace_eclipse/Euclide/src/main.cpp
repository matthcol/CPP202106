/*
 * main.cpp
 *
 *  Created on: 8 juin 2021
 *      Author: Matthias
 */
#include <iostream>
#include "euclide.h"

int main(int argc, char **argv) {
	unsigned int a;
	unsigned int b;

	// Saisie de a et b depuis le clavier
	std::cout << "Entrez 2 nombres a et b: " << std::endl;
	std::cin >> a;
	std::cin >> b;

	auto p = pgcd(a,b);

	std::cout << "Le PGCD est : " << p << std::endl;

	return 0;
}












