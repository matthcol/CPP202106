/*
 * Form.cpp
 *
 *  Created on: 11 juin 2021
 *      Author: Matthias
 */

#include "Form.h"

Form::Form():m_name("?") {
}

Form::Form(const std::string &name):m_name(name) {
}

Form::~Form() {
	// NB: delete here data allocated by constructeur
}

std::string Form::toString() const {
	return m_name;
}
