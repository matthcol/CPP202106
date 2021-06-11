/*
 * Point2D.h
 *
 *  Created on: 11 juin 2021
 *      Author: Matthias
 */

#ifndef POINT2D_H_
#define POINT2D_H_

#include "Form.h"

class Point2D: public Form {
private:
	double m_x;
	double m_y;
public:
	Point2D();
	Point2D(const std::string & name, double x, double y);
	virtual ~Point2D();

	constexpr double x() const {
		return m_x;
	}

	constexpr void setX(double mX) {
		m_x = mX;
	}

	constexpr double y() const {
		return m_y;
	}

	constexpr void setY(double mY) {
		m_y = mY;
	}

	virtual std::string toString() const override;
};

#endif /* POINT2D_H_ */
