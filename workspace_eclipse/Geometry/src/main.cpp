/*
 * main.cpp
 *
 *  Created on: 11 juin 2021
 *      Author: Matthias
 */

#include <iostream>
#include "Point2D.h"
#include "Form.h"

int main(int argc, char **argv) {
	Point2D pA("A",3.3, 5.5);
	Point2D pB("B", 7.7, 9.9);

	std::cout << "1er point: " << pA.toString() << std::endl;

	Form & f = pA;
	std::cout << "Forme: " << f.toString() << std::endl;

	return 0;
}

