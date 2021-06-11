/*
 * main.cpp
 *
 *  Created on: 9 juin 2021
 *      Author: Matthias
 */

#include <iostream>
#include <vector>
#include <set>
#include "Ville.h"
#include "backup.h"
#include <regex>

void scenario1() {
	// construire 1 objet de type Ville
	// classe Ville => creer 1 instance
	// utilise le constructeur par défaut de la classe Ville
	Ville villePau; // 1 objet de type Ville dans stack (pile)

	// affichage de l'objet Ville
	std::cout << "@: " << &villePau
			<< " ; nom : " << villePau.nom()
			<< " ; departement : " << villePau.departement()
			<< " ; population : " << villePau.population()
			<<  std::endl;

	// remplir les attributs de l'objet
	villePau.setNom("Pau");
	villePau.setDepartement(64);
	villePau.setPopulation(77000);

	// affichage de l'objet Ville
	std::cout << "@: " << &villePau
			<< " ; nom : " << villePau.nom()
			<< " ; departement : " << villePau.departement()
			<< " ; population : " << villePau.population()
			<<  std::endl;

}

void scenario2() {
	// appelle le constructeur Ville(const & string, uint16_t, uint32_t)
	Ville pau("Pau", 64, 77000);
	Ville toulouse("Toulouse", 31, 471941);
	Ville brive = Ville("Brive-la-Gaillarde", 19, 50000);

	// rassembler les villes dans un vecteur (NB: copies)
	std::vector<Ville> villes {pau, toulouse, brive};

	// preuve ville copiée dans vecteur
	//pau.population +=1;
	pau += 3; // += sur la population
	// pau = pau + 1;
	std::cout << pau << std::endl;

	std::cout << std::endl << "Liste de villes (vecteur)" << std::endl;
	// for (auto v: villes) { // foreach par copie
	 for (auto & v: villes) { // foreach par reference modifiable
	// for (const auto & v: villes) { // foreach par reference en lecture seule
		// v.population *= 2; // interdit en const &
		v += 3; // interdit en const &
		std::cout << "\t* " << v << std::endl;
	}

}

void scenario3() {
	// appelle le constructeur Ville(const & string, uint16_t, uint32_t)
	Ville pau("Pau", 64, 77000);	// stack
	Ville toulouse("Toulouse", 31, 471941);  // stack
	Ville* brive_ptr = new Ville("Brive-la-Gaillarde", 19, 50000); // heap

	// rassembler les villes dans un vecteur (partagée)
	std::vector<Ville *> villes {&pau, &toulouse, brive_ptr};

	auto ville_ptr = villes[2];
	std::cout << ville_ptr->nom() << std::endl;
	std::cout << (*ville_ptr).nom() << std::endl;
	std:: cout << ville_ptr << std::endl;
	std:: cout << *ville_ptr << std::endl;

	delete brive_ptr;
}

//void scenario4_set() {
//	Ville villeP("Pau",64, 77000);
//	std::set<Ville>  villes {villeP};
//}

void scenario5_ecriture() {
	Ville ville("Pau",64,77001);
	save("ville.txt", ville);
	std::cout << "Ville sauvegardée !" << std::endl;
}

void scenario6_ecriture_csv() {
	Ville ville1("Pau",64,77001);
	Ville ville2("Brive",19,50000);
	Ville ville3("Toulouse",31,470000);
	std::vector<Ville> villes { ville1, ville2, ville3 };

	save_csv("villes.csv", villes.begin(), villes.end());

	std::cout << "Villes sauvegardées !" << std::endl;
}

void scenario7_lecture() {
	std::vector<Ville> villes; // non optimisé
	read_csv("villes.csv", villes);

	for (const auto & v : villes) {
		std::cout << "Ville vecteur: " << v << std::endl;
	}
}

int main(int argc, char **argv) {
	std::cout << "Welcome in Simu City ! " << std::endl;
	// scenario1();
	// scenario2();
	// scenario3();
	// scenario4_set(); // manque operator< pour le type Ville ou equivalent
	// scenario5_ecriture();
	// scenario6_ecriture_csv();
	scenario7_lecture();
	// std::cerr << "Ceci est un message d'erreur ! " << std::endl;
	// std::clog << "Ceci est un message de log ! " << std::endl;
	std::cout << "That's all folks !" << std::endl;
	return 0;
}






