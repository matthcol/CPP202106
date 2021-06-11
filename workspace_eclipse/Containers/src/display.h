/*
 * display.h
 *
 *  Created on: 10 juin 2021
 *      Author: Matthias
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <vector>
#include <string>
#include <iostream>
#include <utility>

template<class T>
void displayVector(const std::vector<T> & vect,
		const std::string & titre = " -- Liste -- ",
		const std::string & puce = "\t- ")
{
	std::cout << titre << std::endl;
	for (const auto & element : vect) {
		std::cout << puce << element << std::endl;
	}
}

template<class InputIterator>
void displayIterable(InputIterator first, InputIterator last,
		const std::string & titre = " -- Liste -- ",
		const std::string & puce = "\t- ")
{
	auto count_iterable = std::distance(first, last);
	std::cout << titre << "[" << count_iterable << "]" << std::endl;
	for ( ; first != last; ++first) {
		const auto & element = *first;
		std::cout << puce << element << std::endl;
	}
}

template<class Container>
void displayContainer(const Container & container,
		const std::string & titre = " -- Liste -- ",
		const std::string & puce = "\t- ")
{
	displayIterable(container.begin(), container.end(), titre, puce);
}

template<class U, class V>
std::ostream & operator<<(std::ostream & os, const std::pair<U,V> & p){
	return os << "<" << p.first << ", " << p.second << ">";
}

#endif /* DISPLAY_H_ */
