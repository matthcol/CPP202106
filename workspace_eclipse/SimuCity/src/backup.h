/*
 * backup.h
 *
 *  Created on: 11 juin 2021
 *      Author: Matthias
 */

#ifndef BACKUP_H_
#define BACKUP_H_

#include <string>
#include "Ville.h"
#include <fstream>
#include <vector>

void save(const std::string & filename, const Ville & ville);

template<class InputIterator>
void save_csv(const std::string & filename, InputIterator first, InputIterator last) {
	std::ofstream out(filename);
	while (first != last) {
		const auto & v = *first;
		// ecrire la ville
		out << v.nom() << ";" << v.departement() << ";" << v.population() << std::endl;
		++first;
	}
	out.close();
}

// NB: différentes pssibilité de retour d'un objet complexe
// std::vector<std::string>* read_csv(const std::string & filename);
// void read_csv(const std::string & filename, OutputIterator itVilles);
void read_csv(const std::string & filename, std::vector<Ville> &villes);
void read_csv2(const std::string & filename, std::vector<Ville> &villes);


//{
//	std::vector<std::string>* v = new std::vector<std::string>();
//	Ville * ville_ptr = new Ville();
//
//	return v;
//}

#endif /* BACKUP_H_ */
