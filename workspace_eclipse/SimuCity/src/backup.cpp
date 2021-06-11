/*
 * backup.cpp
 *
 *  Created on: 11 juin 2021
 *      Author: Matthias
 */

#include "backup.h"

#include <fstream>
#include <regex>

void save(const std::string &filename, const Ville &ville) {
	// 1. ouvrir un canal en sortie vers un fichier
	// NB: ofstream spécialise un ostream
	//std::ofstream out(filename);
	//std::ofstream out(filename, std::ofstream::app);
	std::ofstream out(filename, std::ofstream::out | std::ofstream::trunc);
	// 2. ecrit dans le fichier via le canal
	out << ville << std::endl;
	// 3. fermer le canal vers le fichier (vider les buffers, libérer le fichier)
	out.close();
}

void read_csv(const std::string &filename, std::vector<Ville> &villes) {
	std::ifstream in(filename);
	char buffer[1000]; // string en C

	while (in.getline(buffer, 1000)) {
		std::string line(buffer);
		std::cout << "Buffer lu:[" << line << "]" << std::endl;

		auto pos = line.find(";");
		std::string nom = line.substr(0, pos);

		auto pos2 = line.find(";", pos+1);
		std::string dep = line.substr(pos+1, pos2-pos-1);
		std::cout << "Département extrait: [" << dep << "]" << std::endl;

		auto pos3 = line.find(";", pos2+1);
		std::string pop = line.substr(pos2+1, pos3-pos2-1);
		std::cout << "Population extraits: [" << pop << "]" << std::endl;

		Ville v(nom, stoul(dep), stoul(pop));

		villes.push_back(v);
	}

	in.close();
}


void read_csv2(const std::string &filename, std::vector<Ville> &villes) {
	std::ifstream in(filename);
	char buffer[1000]; // string en C

	while (in.getline(buffer, 1000)) {
		std::string line(buffer);
		std::cout << "Buffer lu:[" << line << "]" << std::endl;

		std::regex pattern("[^;]+");
		std::regex_iterator<std::string::iterator> it(line.begin(), line.end(), pattern);
		std::regex_iterator<std::string::iterator> end; // utile si boucle

		std::string nom = it->str();
		++it;
		std::string dep = it->str();
		++it;
		std::string pop = it->str();

		Ville v(nom, stoul(dep), stoul(pop));
		villes.push_back(v);
	}

	in.close();
}








