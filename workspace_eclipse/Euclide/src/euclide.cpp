/*
 * euclide.cpp
 *
 *  Created on: 8 juin 2021
 *      Author: Matthias
 */
#include "euclide.h"

unsigned int pgcd(unsigned int a, unsigned int b) {
	unsigned int r;
	while (b != 0) {
		// calculer le reste r de la division euclidienne de a par b
		r = a % b;
		// a reçoit la valeur de b
		a = b;
		// b reçoit la valeur de r
		b = r;
	}
	// retourne la valeur de a
	return a;
}


