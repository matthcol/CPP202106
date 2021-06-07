/*
 * main.cpp
 *
 *  Created on: 7 juin 2021
 *      Author: Matthias
 */

#include <iostream>
#include <limits>
//using namespace std;  // std::cout => cout

int main() {
	// variable de type int (signed)
	// initialisée avec la valeur 2
	int nombrePersonne = 2;
	std::cout << "Nombre de personnes dans la réunion : " << nombrePersonne << std::endl;
	// modification de variable
	nombrePersonne = 2000000000;
	std::cout << "Nombre de personnes dans la réunion : " << nombrePersonne << std::endl;
//	nombrePersonne = 3000000000; // too much => -1294967296
//	std::cout << "Nombre de personnes dans la réunion : " << nombrePersonne << std::endl;
	unsigned int nombreOeil = 3000000000;
	std::cout << "Yeux : " << nombreOeil << std::endl;
	// afficher les limites d'un type entiers
	std::cout << "Limites du type int : " << std::numeric_limits<int>::min()
			<< " to " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "Limites du type unsigned int : " << std::numeric_limits<unsigned int>::min()
				<< " to " << std::numeric_limits<unsigned int>::max() << std::endl;
	std::cout << "Limites du type long : " << std::numeric_limits<long>::min()
				<< " to " << std::numeric_limits<long>::max() << std::endl;
	std::cout << "Limites du type long long : " << std::numeric_limits<long long>::min()
				<< " to " << std::numeric_limits<long long>::max() << std::endl;
	// calculs : * / + - %
	nombrePersonne = 3;
	int sizeGroup = (nombrePersonne * 3) + 5;
	std::cout << "Size of the group: " << sizeGroup << std::endl;
	int sizeSubGroup = sizeGroup / 3;  // 14 / 3 = 4 avec un reste de 2
	std::cout << "Size of the sub group: " << sizeSubGroup << std::endl;
	int restGroup =  sizeGroup % 3;  // reste division 14 par 3
	std::cout << "Remains: " << restGroup << std::endl;

}





