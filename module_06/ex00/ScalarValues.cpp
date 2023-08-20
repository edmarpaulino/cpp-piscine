/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarValues.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:59:04 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 17:11:31 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarValues.hpp"

ScalarValues::ScalarValues(void): _c(IMP), _i(IMP), _f(IMP), _d(IMP) {}

ScalarValues::ScalarValues(std::string c, std::string i, std::string f, std::string d):
  _c(c), _i(i), _f(f), _d(d) {}

ScalarValues::ScalarValues(const ScalarValues &rhs) {
  *this = rhs;
}

ScalarValues::~ScalarValues(void) {}

ScalarValues &ScalarValues::operator=(const ScalarValues &rhs) {
  if (this != &rhs) {
    _c = rhs._c;
    _i = rhs._i;
    _f = rhs._f;
    _d = rhs._d;
  }

  return *this;
}

bool ScalarValues::operator==(const ScalarValues &rhs) {
  return (_c == rhs._c && _i == rhs._i && _f == rhs._f && _d == rhs._d);
}

std::string ScalarValues::getValueChar(void) const {
  return _c;
}

std::string ScalarValues::getValueInt(void) const {
  return _i;
}

std::string ScalarValues::getValueFloat(void) const {
  return _f;
}

std::string ScalarValues::getValueDouble(void) const {
  return _d;
}

std::ostream &operator<<(std::ostream &out, const ScalarValues &rhs) {
  out << "char: " << rhs.getValueChar() << std::endl;
  out << "int: " << rhs.getValueInt() << std::endl;
  out << "float: " << rhs.getValueFloat() << std::endl;
  out << "double: " << rhs.getValueDouble() << std::endl;

  return out;
}
