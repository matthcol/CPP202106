/*
 * main.cpp
 *
 *  Created on: 9 juin 2021
 *      Author: Matthias
 */

#include <iostream>
#include <utility>

using namespace std;

void scenario1(){
	double distance = 3.14;
	double distance_copy = distance; // copy
	double & r_distance = distance; // shared
	cout << "Distance (direct): " << distance << endl
			<< "Distance_copy (direct): " << distance_copy << endl
			<< "Distance (reference): " << r_distance << endl;
	cout << "----------------------------------------" << endl;
	// modification de la variable distance est vue par la reference
	// également
	distance *= 2;
	cout << "Distance (direct): " << distance << endl
			<< "Distance_copy (direct): " << distance_copy << endl
			<< "Distance (reference): " << r_distance << endl;
}

void scenario2_swap() {
	double distance1 = 3.14;
	double distance2 = 42.195;
	cout << "d1: " << distance1 << " ; d2: " << distance2 << endl;

	// Doc: void swap ( T& a, T& b )
	swap(distance1, distance2); // passage de parametre par reference
	cout << "d1: " << distance1 << " ; d2: " << distance2 << endl;
}

// text par reference en lecture seule
void displayBegin(const string & text, unsigned int len) {
	cout << text.substr(0, len) << endl;
	// text[0] = 'Z';  // interdit avec du const &
	cout << "Texte (inside display): " << text << " @ " << &text << endl;
}

// text par reference en modification
void automaticCorrection(string & text) {
	text[0] = 'Z';  // autorisé avec  & sans const
	cout << "Texte (inside correction): " << text << " @ " << &text << endl;
}

void scenario3_string() {
	string texte("il fait beau aujourd'hui !");
	displayBegin(texte, 5);
	cout << "Texte (inside scenario3): " << texte << " @ " << &texte <<  endl;
	automaticCorrection(texte);
	cout << "Texte (inside scenario3): " << texte << " @ " << &texte <<  endl;
}

int main(int argc, char **argv) {
	// scenario1();
	// scenario2_swap();
	scenario3_string();
	return 0;
}




