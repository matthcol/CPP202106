/*
 * main.cpp
 *
 *  Created on: 7 juin 2021
 *      Author: Matthias
 */

#include <iostream>
#include <iomanip>
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

	// nombres à virgule flottante
	float prixBonbon = 0.10; // 10 centimes
	std::cout  << std::fixed << std::setprecision(10)
			<< "- un bonbon: "  << prixBonbon << std::endl
			<< "- deux bonbons: " << (2*prixBonbon) << std::endl
			<< "- trois bonbons: " << (3*prixBonbon) << std::endl;
	double sizeSubGroupF = sizeGroup / 3.0;
	std::cout << "Size of the sub group: " << sizeSubGroupF << std::endl;

	// booleans and logic
	bool isExpensive;
	isExpensive = prixBonbon > 100;
	std::cout << std::boolalpha << "Prix cher ? " << isExpensive << std::endl;
	// comparaisons ordre: <  <=  >  >=   <=>
	// comparaison d'égalité, différence: == !=
	std::cout << "Y a-t-il 3 personnes dans l'avion ? "  << (nombrePersonne==3) << std::endl;
	// combinaison: && (and)    || (or)   ! (not)
	bool allConditionsAreGood;
	allConditionsAreGood = isExpensive && ((nombrePersonne < 10) || (sizeSubGroup < 5));
	std::cout << "All is OK ? " << allConditionsAreGood << std::endl;
	std::cout << "Is anything wrong ? " << !allConditionsAreGood << std::endl;

	// conditionnelles: ex1
	std::cout << "Séquenche Achat #1" << std::endl;
	prixBonbon = 4;
	if (prixBonbon < 1) {
		int total = prixBonbon * 10000;
		std::cout << "Prix du bonbon raisonnable" << std::endl;
		std::cout << "J'en achète pour: " << total << std::endl;
	} else {
		std::cout << "Un peu trop cher pour un achat de groupe :(" << std::endl;
	}

	// exemple 2
	std::cout << "Séquenche Achat #2" << std::endl;
	prixBonbon = 20; // 0.1  4  20
	if (prixBonbon < 1) {
		int total = prixBonbon * 10000;
		std::cout << "Prix du bonbon raisonnable" << std::endl;
		std::cout << "J'en achète pour: " << total << std::endl;
	} else if (prixBonbon < 10) {
		int total = prixBonbon * 100;
		std::cout << "Prix du bonbon 1 peu cher mais j'y vais" << std::endl;
		std::cout << "J'en achète pour: " << total << std::endl;
	} else {
		std::cout << "Un peu trop cher pour un achat de groupe :(" << std::endl;
	}

}





