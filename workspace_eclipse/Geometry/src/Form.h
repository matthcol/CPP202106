/*
 * Form.h
 *
 *  Created on: 11 juin 2021
 *      Author: Matthias
 */

#ifndef FORM_H_
#define FORM_H_

#include <string>

class Form {
private:
	std::string m_name;
public:
	Form();
	Form(const std::string & name);
	virtual ~Form(); // destructeur

	constexpr const std::string& name() const {
		return m_name;
	}

	void setName(const std::string &mName) {
		m_name = mName;
	}

	virtual std::string toString() const;

};

#endif /* FORM_H_ */
