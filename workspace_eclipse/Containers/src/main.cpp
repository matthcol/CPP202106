/*
 * main.cpp
 *
 *  Created on: 8 juin 2021
 *      Author: Matthias
 */

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <cmath>
#include <iterator>
#include <utility>
#include <cstdint>
#include <algorithm>

#include "display.h"

using namespace std;

void scenario1() {
	// std::vector<double> temperatures;
	vector<double> temperatures;  // initialisation à un vecteur vide

	// pas possible d'afficher entier
	// std::cout << temperatures << std::endl;

	cout << "Taille du vecteur: " << temperatures.size() << endl;

	temperatures.push_back(12.3);
	cout << "Taille du vecteur: " << temperatures.size() << endl;
	cout << "Case #0 : " << temperatures[0] << endl;
	cout << "Case #0 : " << temperatures.at(0) << endl;

	// accès en dehors du vecteur : donnée random ou accès interdit (pgme plante)
	// NB: accès non protégé avec []
	// cout << "Case #1 : " << temperatures[1] << endl;
	// cout << "Case #très loin : " << temperatures[1000000000] << endl;
	// NB: accès protégé avec at()
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
	// ajout à posteriori
	villes.push_back("Lourdes");
	// villes.push_back(12.3); // impossible d'ajouter un double dans un vector<string>

	//for (string ville : villes) {
	for (auto ville : villes) {
		cout << "\t. " << ville << " -> " << ville.substr(0, 3) << endl;
	}

	// 1 texte
	string texte ="Mardi on fait du C++ ensemble. C++ est un peu compliqué.";
	cout << "Longueur du texte : " << texte.length() << " ou " << texte.size() << endl;
	// 1ère recherche
	int pos = texte.find("C++");
	cout << "C++ trouvé à la position : " << pos << endl;
	cout << "Check 1 : " << texte[pos] << endl;
	cout << "Check 2 : " << texte.substr(pos, 7) << endl;
	// 2eme recherche
	pos = texte.find("C++", pos+3);
	cout << "C++ trouvé à la position : " << pos << endl;
	cout << "Check 1 : " << texte[pos] << endl;
	cout << "Check 2 : " << texte.substr(pos, 7) << endl;
	// 3e recherche
	pos = texte.find("C++", pos+3);
	cout << "C++ trouvé (ou pas) à la position : " << pos << endl;

	// boucle sur string
	for (auto lettre : texte) {		// auto vaut char
		cout << lettre << " ";
	}
	cout << endl;

	// appel d'une fonction sur tous les éléments d'un vecteur
	double tempNormalisee;
	for (auto t : temperaturesTuesday) {
		tempNormalisee = sqrt(pow(t,2) + 1);
		cout << "Temp normalisée de " << t << " -> " << tempNormalisee << endl;
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

	std::cout << " --- liste de voitures (parcours partiel) --- " << std::endl;
	auto it = voitures.begin();
	// it += 2;
	std::advance(it, 2);
	auto fin = voitures.end();
	//--fin; // fin -= 2;
	std::advance(fin, -1);

	for ( ; it != fin; ++it) {
		std::cout << "\t# " << *it << std::endl;
	}

	// reversement
	std::cout << " --- selection de voitures (2e vecteur) --- " << std::endl;
	vector<string> selectionVoiture (
			std::next(voitures.begin(),2),	// position départ dans la source
			voitures.end()-1);	// position de fin (exclus) dans la source
	for (const auto & v : selectionVoiture) {
		std::cout << "\t^ " << v << std::endl;
	}

	displayVector(voitures); // template T=std::string
	displayIterable(voitures.begin(), voitures.end(), "-- toutes les voitures --");
	displayIterable(voitures.begin()+2, voitures.end()-1, "-- extrait voitures --");

	displayIterable(voitures.rbegin(), voitures.rend(), "-- toutes les voitures (r) --");
}

void scenario3_kilometrages() {
	vector<unsigned int> kilometrages {0, 50000, 250000};
	displayVector(kilometrages); // template T=unsigned int
	displayVector(kilometrages, "-- kilometrages --");
	displayVector(kilometrages, "-- kilometrages (2) --", "\t* ");
}

void scenario4_empty_container() {
	vector<double> emptyVector;
	displayIterable(emptyVector.begin(), emptyVector.end(), "--- empty vector ---");
}

void scenario5_list() {
	list<string> voitures {"Peugeot 206", "Peugeot 106", "Renault Traffic", "Renault Clio RS", "Fiat"};
	displayIterable(voitures.begin(), voitures.end(), " --- liste de voitures ---");

	// cout << "1er element : " << voitures[0] << endl; // random access interdit
	cout << "1er element : " << voitures.front() << endl;
	cout << "dernier element : " << voitures.back() << endl;
	cout << "3e element de la liste : " << *(std::next(voitures.begin(), 2)) << endl;

	vector<string> nouveautes {"Ferrari F40", "Renault Twingo", "Jaguar"};
	displayIterable(nouveautes.begin(), nouveautes.end(), "--- nouveautés ---");

	//auto itInsert = std::next(voitures.begin(), 1); // 2e position
	//auto itInsert = voitures.begin();  // begin
	auto itInsert = voitures.end();  // end
	voitures.insert(
			itInsert,  // point d'insertion
			nouveautes.begin(), // debut de la source à insérer
			nouveautes.end()); // fin (exclus) de la source à insérer

	displayIterable(voitures.begin(), voitures.end(), " --- liste de voitures MAJ ---");


}

void scenario6_set() {
	// pas doublon (==), trié suivant un ordre (naturel du type de donnée < )
	set<string> voitures {"Peugeot 206", "Peugeot 106", "Renault Traffic", "Renault Clio RS", "Fiat"};
	displayIterable(voitures.begin(), voitures.end(), "-- ensemble de voitures --");

	voitures.insert("Peugeot 106");  // doublon
	voitures.insert("Renault Megane");
	voitures.insert("Sunny");

	displayIterable(voitures.begin(), voitures.end(), "-- ensemble de voitures (U) --");

	// std::greater<string> désigne operateur > du type string
	set<string, std::greater<string>> voituresZA (voitures.begin(), voitures.end());
	displayIterable(voituresZA.begin(),voituresZA.end(), "-- ensemble de voitures (Z-A) ---");

	displayIterable(voitures.lower_bound("Renault"), voitures.end(), "--- voitures Renault et+ ---");

	displayIterable(
			voitures.lower_bound("Renault"),
			voitures.upper_bound("Renault ZZZZZZZZZ"),
			"--- voitures Renault ---");
}

void scenario7_pair(){
	pair<string,uint16_t> ville1 {"Pau", 64};
	pair<string,uint16_t> ville2 ("Brive", 19);
	pair<string,uint16_t> ville3 = make_pair("Toulouse", 31);

	vector<pair<string,uint16_t>> villes {ville1, ville2, ville3};

	std::cout << ville1.first << ", " << ville2.second << endl;

	displayIterable(villes.begin(), villes.end(), "-- villes (pair) --");

	for (auto & v: villes) {
		v.second +=1;
	}

	displayIterable(villes.begin(), villes.end(), "-- villes (pair, dep+1) --");

}

bool filter_startby_peugeot(const string & voiture){
	return voiture.find("Peugeot") == 0;
}

bool filter_contains_peugeot(const string & voiture){
	return voiture.find("Peugeot") != string::npos;
}

bool filter_startby(const string & voiture, const string & valFind){
	return voiture.find(valFind) == 0;
}

void scenario8_algorithms() {
	list<string> voitures {"    Peugeot 206", "Peugeot 106", "Renault Traffic", "Renault Clio RS", "Fiat"};

	auto itFind = find(voitures.begin(), voitures.end(), "Peugeot 106");

	if (itFind != voitures.end()) {
		cout << "Trouvé : " << *itFind << endl;
	} else {
		cout << "404 Not Found" << endl;
	}

	// auto ifFind2 = find_if(voitures.begin(), voitures.end(), filter_startby_peugeot);
	// auto ifFind2 = find_if(voitures.begin(), voitures.end(), filter_contains_peugeot);
//	auto ifFind2 = find_if(voitures.begin(), voitures.end(),
//			[](auto & v) { return filter_startby(v, "Renault");});
	auto ifFind2 = find_if(voitures.begin(), voitures.end(),
				[](auto & v) { return v == "Fiat"; });
	if (ifFind2 != voitures.end()) {
		cout << "Trouvé (2) : " << *ifFind2 << endl;
	} else {
		cout << "404 Not Found" << endl;
	}

	auto nb = count_if(voitures.begin(), voitures.end(), filter_contains_peugeot);
	cout << "Nb peugeot : " << nb << endl;

}

int main(int argc, char **argv) {
	// scenario1();
	// scenario2_it_vector();
	// scenario3_kilometrages();
	// scenario4_empty_container();
	// scenario5_list();
	// scenario6_set();
	// scenario7_pair();
	scenario8_algorithms();
	std::cout << "That's all Folks" << std::endl;
}













