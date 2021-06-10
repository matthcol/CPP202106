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
	// initialis�e avec la valeur 2
	int nombrePersonne = 2;
	std::cout << "Nombre de personnes dans la r�union : " << nombrePersonne << std::endl;
	// modification de variable
	nombrePersonne = 2000000000;
	std::cout << "Nombre de personnes dans la r�union : " << nombrePersonne << std::endl;
//	nombrePersonne = 3000000000; // too much => -1294967296
//	std::cout << "Nombre de personnes dans la r�union : " << nombrePersonne << std::endl;
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

	// nombres � virgule flottante
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
	// comparaison d'�galit�, diff�rence: == !=
	std::cout << "Y a-t-il 3 personnes dans l'avion ? "  << (nombrePersonne==3) << std::endl;
	// combinaison: && (and)    || (or)   ! (not)
	bool allConditionsAreGood;
	allConditionsAreGood = isExpensive && ((nombrePersonne < 10) || (sizeSubGroup < 5));
	std::cout << "All is OK ? " << allConditionsAreGood << std::endl;
	std::cout << "Is anything wrong ? " << !allConditionsAreGood << std::endl;

	// conditionnelles: ex1
	std::cout << "S�quenche Achat #1" << std::endl;
	prixBonbon = 4;
	if (prixBonbon < 1) {
		int total = prixBonbon * 10000;
		std::cout << "Prix du bonbon raisonnable" << std::endl;
		std::cout << "J'en ach�te pour: " << total << std::endl;
	} else {
		std::cout << "Un peu trop cher pour un achat de groupe :(" << std::endl;
	}

	// exemple 2
	std::cout << "S�quenche Achat #2" << std::endl;
	prixBonbon = 20; // 0.1  4  20
	if (prixBonbon < 1) {
		int total = prixBonbon * 10000;
		std::cout << "Prix du bonbon raisonnable" << std::endl;
		std::cout << "J'en ach�te pour: " << total << std::endl;
	} else if (prixBonbon < 10) {
		int total = prixBonbon * 100;
		std::cout << "Prix du bonbon 1 peu cher mais j'y vais" << std::endl;
		std::cout << "J'en ach�te pour: " << total << std::endl;
	} else {
		std::cout << "Un peu trop cher pour un achat de groupe :(" << std::endl;
	}

	// conditionnelle switch case
	std::cout << "S�quenche Achat #3" << std::endl;
	int typeBonbon = 1;
	// type 1 : Fraise tagada
	// type 2 : Malabar
	// type 3 : Carambar
	// type 4 : roudoudou
	// type 5 : r�glisse
	int total = 0;
	switch (typeBonbon) {
	case 1:
		total = 100;
		std::cout << "Fraise tagada, j'adore" << std::endl;
		break;
	case 2:
		total = prixBonbon * 100;
		std::cout << "Malabar. J'en ach�te pour: " << total << std::endl;
		break;
	default:  // type 3, 4 et 5
		std::cout << "Autre produit: je note pour une autre fois" << std::endl;
	}

	// boucles
	int cpt=1;
	while (cpt < 10) {
		int prixTotal = prixBonbon * cpt;
		std::cout << "Prix total pour " << cpt << " bonbons : " << prixTotal << std::endl;
		cpt += 1; // ++cpt;  // cpt++; //cpt = cpt + 1;
	}
	// operateurs contract�s:
	//	++cpt, cpt++, cpt--, --cpt, cpt += 4, cpt -= 10
	//  cpt *= 2,  cpt /= 5, ...

	// operator bitwise
	unsigned char octet = 255;  // 11111111
	unsigned char res = ~octet; // 00000000
	std::cout << "Octet: " << static_cast<unsigned int>(octet) << std::endl;
	std::cout << "not octet: " << static_cast<unsigned int>(res) << std::endl;
	octet = 1; // 00000001
	res = octet << 2; // 00000100
	std::cout << "not octet: " << static_cast<unsigned int>(res) << std::endl;

	for (int i=1; i<10; i++) {
		std::cout << "Compteur i= " << i << std::endl;
	}

}





