/*
 * Point2D.cpp
 *
 *  Created on: 11 juin 2021
 *      Author: Matthias
 */

#include "Point2D.h"
#include <sstream>

Point2D::Point2D():Point2D("?",0,0) {
}

Point2D::Point2D(const std::string &name, double x, double y):
		Form(name), m_x(x), m_y(y)
{
}

Point2D::~Point2D() {
	// TODO Auto-generated destructor stub
}

std::string Point2D::toString() const {
	std::stringstream buf;
	buf << name() << "(" << m_x << "," << m_y << ")";
	return buf.str();
}
