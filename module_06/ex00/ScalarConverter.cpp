/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:05:24 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/16 22:44:31 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

char ScalarConverter::_c = 0;
int ScalarConverter::_i = 0;
float ScalarConverter::_f = 0.0f;
double ScalarConverter::_d = 0.0;
SCALAR_TYPE ScalarConverter::_type = UNKNOWN_TYPE;

ScalarConverter::ScalarConverter(void) {
  this->_resetValues();
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs) {
  *this = rhs;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  static_cast<void>(rhs);

  return *this;
}
// TODO - remove std::cout from this function
void ScalarConverter::convert(const std::string value) {
  std::stringstream ss;

  ss << value;

  std::cout << value << std::endl;
  
  ScalarConverter::_type = ScalarConverter::_identifyType(value);

  switch (ScalarConverter::_type) {
    case CHAR_TYPE:
      ss >> ScalarConverter::_c;
      ScalarConverter::_convert(ScalarConverter::_c);
      std::cout << CHAR_TYPE << std::endl;
      break;
    case INT_TYPE:
      ss >> ScalarConverter::_i;
      ScalarConverter::_convert(ScalarConverter::_i);
      std::cout << INT_TYPE << std::endl;
      break;
    case FLOAT_TYPE:
      ss >> ScalarConverter::_f;
      ScalarConverter::_convert(ScalarConverter::_f);
      std::cout << FLOAT_TYPE << std::endl;
      break;
    case DOUBLE_TYPE:
      ss >> ScalarConverter::_d;
      ScalarConverter::_convert(ScalarConverter::_d);
      std::cout << DOUBLE_TYPE << std::endl;
      break;
    case UNKNOWN_TYPE:
      // fallthrough
    default:
      std::cout << UNKNOWN_TYPE << std::endl;
      break;
  }

  if (ScalarConverter::_type != UNKNOWN_TYPE) {
    ScalarConverter::_printValues();
  } else {
    ScalarConverter::_printUnknownValues();
  }
  
  ScalarConverter::_resetValues();
}

SCALAR_TYPE ScalarConverter::_identifyType(const std::string value) {
  if (ScalarConverter::_isChar(value)) {
    return CHAR_TYPE;
  } else if (ScalarConverter::_isInt(value)) {
    return INT_TYPE;
  } else if (ScalarConverter::_isFloat(value)) {
    return FLOAT_TYPE;
  } else if (ScalarConverter::_isDouble(value)) {
    return DOUBLE_TYPE;
  } else {
    return UNKNOWN_TYPE;
  }
}

bool ScalarConverter::_isChar(const std::string value) {
  return (value.length() == 1 && !isdigit(value[0]) && isprint(value[0]));
}
// FIXME
bool ScalarConverter::_isInt(const std::string value) {
  if (value.empty() || ((!isdigit(value[0])) && (value[0] != '-') && (value[0] != '+'))) {
    return false;
  }
  
  char *p;
  strtol(value.c_str(), &p, 10);
  return (*p == 0);
}
// FIXME
bool ScalarConverter::_isFloat(const std::string value) {
  if (value.empty() || ((!isdigit(value[0])) && (value[0] != '-') && (value[0] != '+'))) {
    return false;
  }
  
  char *p;
  strtof(value.c_str(), &p);
  return (*p == 0);
}
// FIXME
bool ScalarConverter::_isDouble(const std::string value) {
  if (value.empty() || ((!isdigit(value[0])) && (value[0] != '-') && (value[0] != '+'))) {
    return false;
  }
  
  char *p;
  strtod(value.c_str(), &p);
  return (*p == 0);
}

void ScalarConverter::_convert(char value) {
  ScalarConverter::_i = static_cast<int>(value);
  ScalarConverter::_f = static_cast<float>(value);
  ScalarConverter::_d = static_cast<double>(value);
}

void ScalarConverter::_convert(int value) {
  ScalarConverter::_c = static_cast<char>(value);
  ScalarConverter::_f = static_cast<float>(value);
  ScalarConverter::_d = static_cast<double>(value);
}

void ScalarConverter::_convert(float value) {
  ScalarConverter::_c = static_cast<char>(value);
  ScalarConverter::_i = static_cast<int>(value);
  ScalarConverter::_d = static_cast<double>(value);
}

void ScalarConverter::_convert(double value) {
  ScalarConverter::_c = static_cast<char>(value);
  ScalarConverter::_i = static_cast<int>(value);
  ScalarConverter::_f = static_cast<float>(value);
}

void ScalarConverter::_printValues(void) {
  std::cout
    << "char: " << ScalarConverter::_getFormatedChar() << std::endl
    << "int: " << ScalarConverter::_getFormatedInt() << std::endl
    << "float: " << ScalarConverter::_getFormatedFloat() << std::endl
    << "double: " << ScalarConverter::_getFormatedDouble() << std::endl;
}

void ScalarConverter::_printUnknownValues(void) {
  std::cout
    << "char: impossible" << std::endl
    << "int: impossible" << std::endl
    << "float: impossible" << std::endl
    << "double: impossible" << std::endl;
}

void ScalarConverter::_resetValues(void) {
  ScalarConverter::_c = 0;
  ScalarConverter::_i = 0;
  ScalarConverter::_f = 0.0f;
  ScalarConverter::_d = 0.0;
  ScalarConverter::_type = UNKNOWN_TYPE;
}

std::string ScalarConverter::_getFormatedChar(void) {
  std::stringstream ss;

  if (ScalarConverter::_i < 0 || ScalarConverter::_i > 127) {
    ss << "impossible";
  } else if (!isprint(ScalarConverter::_c)) {
    ss << "Non displayable";
  } else {
    ss << "'" << ScalarConverter::_c << "'";
  }

  return ss.str();
}
// FIXME
std::string ScalarConverter::_getFormatedInt(void) {
  std::stringstream ss;

  ss << ScalarConverter::_i;

  return ss.str();
}
// FIXME
std::string ScalarConverter::_getFormatedFloat(void) {
  std::stringstream ss;

  ss << ScalarConverter::_f << "f";

  return ss.str();
}
// FIXME
std::string ScalarConverter::_getFormatedDouble(void) {
  std::stringstream ss;

  ss << ScalarConverter::_d;

  return ss.str();
}
