/*
 * main.cpp
 *
 *  Created on: 8 juin 2021
 *      Author: Matthias
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>

using namespace std;

void scenario1() {
	// std::vector<double> temperatures;
	vector<double> temperatures;  // initialisation � un vecteur vide

	// pas possible d'afficher entier
	// std::cout << temperatures << std::endl;

	cout << "Taille du vecteur: " << temperatures.size() << endl;

	temperatures.push_back(12.3);
	cout << "Taille du vecteur: " << temperatures.size() << endl;
	cout << "Case #0 : " << temperatures[0] << endl;
	cout << "Case #0 : " << temperatures.at(0) << endl;

	// acc�s en dehors du vecteur : donn�e random ou acc�s interdit (pgme plante)
	// NB: acc�s non prot�g� avec []
	// cout << "Case #1 : " << temperatures[1] << endl;
	// cout << "Case #tr�s loin : " << temperatures[1000000000] << endl;
	// NB: acc�s prot�g� avec at()
	// cout << "Case #1 : " << temperatures.at(1) << endl; // throw exception std::out_of_range

	cout << "----------- Data of tuesday -------------" << endl;
	vector<double> temperaturesTuesday {12.3, 34.2, 14.5, 18.6, 17.98};
	cout << "Taille du vecteur: " << temperaturesTuesday.size() << endl;
	cout << "Case #0 : " << temperaturesTuesday[0] << endl;
	cout << "Case #1 : " << temperaturesTuesday[1] << endl;

	cout << "valeurs avec for i" << endl;
	for (vector<double>::size_type i = 0; i < temperaturesTuesday.size(); i++) {
		cout << "\t- case #" << i << " : " << temperaturesTuesday[i] << endl;
	}

	// modern for : foreach C+11
	cout << "valeurs avec foreach" << endl;
	//for (double t : temperaturesTuesday) {
	for (auto t : temperaturesTuesday) {
		cout << "\t* case : " << t << endl;
	}

	// vecteurs de villes : Toulouse, Brives, Pau
	cout << "--- Villes du Sud-Ouest ---" << endl;
	vector<string> villes {"Toulouse", "Brives", "Pau"};
	// ajout � posteriori
	villes.push_back("Lourdes");
	// villes.push_back(12.3); // impossible d'ajouter un double dans un vector<string>

	//for (string ville : villes) {
	for (auto ville : villes) {
		cout << "\t. " << ville << " -> " << ville.substr(0, 3) << endl;
	}

	// 1 texte
	string texte ="Mardi on fait du C++ ensemble. C++ est un peu compliqu�.";
	cout << "Longueur du texte : " << texte.length() << " ou " << texte.size() << endl;
	// 1�re recherche
	int pos = texte.find("C++");
	cout << "C++ trouv� � la position : " << pos << endl;
	cout << "Check 1 : " << texte[pos] << endl;
	cout << "Check 2 : " << texte.substr(pos, 7) << endl;
	// 2eme recherche
	pos = texte.find("C++", pos+3);
	cout << "C++ trouv� � la position : " << pos << endl;
	cout << "Check 1 : " << texte[pos] << endl;
	cout << "Check 2 : " << texte.substr(pos, 7) << endl;
	// 3e recherche
	pos = texte.find("C++", pos+3);
	cout << "C++ trouv� (ou pas) � la position : " << pos << endl;

	// boucle sur string
	for (auto lettre : texte) {		// auto vaut char
		cout << lettre << " ";
	}
	cout << endl;

	// appel d'une fonction sur tous les �l�ments d'un vecteur
	double tempNormalisee;
	for (auto t : temperaturesTuesday) {
		tempNormalisee = sqrt(pow(t,2) + 1);
		cout << "Temp normalis�e de " << t << " -> " << tempNormalisee << endl;
	}

	cout << "That's all Folks" << endl;
}

void scenario2_it_vector() {
	vector<string> voitures {"Peugeot 206", "Peugeot 106", "Renault Traffic", "Renault Clio RS", "Fiat"};

	std::cout << "--- Liste de voitures (foreach) ---" << std::endl;
	for (const auto & v	: voitures) {
		std::cout << "\t* " << v << std::endl;
	}

	std::cout << " ---liste de voitures (iterator)--- " << std::endl;
	for (auto it = voitures.begin() ; it != voitures.end() ; ++it) {
		const auto & v = *it;
		std::cout << "\t-" << v << std::endl;
	}

	std::cout << " ---liste de voitures (parcours partiel)--- " << std::endl;
	auto it = voitures.begin();
	// it += 2;
	std::advance(it, 2);
	auto fin = voitures.end();
	//--fin; // fin -= 2;
	std::advance(fin, -1);

	for ( ; it != fin; ++it) {
		std::cout << "\t# " << *it << std::endl;
	}

}

int main(int argc, char **argv) {
	// scenario1();
	scenario2_it_vector();
}













