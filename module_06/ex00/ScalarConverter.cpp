/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:05:24 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/19 18:18:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

double ScalarConverter::_value = 0.0;
double ScalarConverter::_truncatedValue = 0.0;
bool ScalarConverter::_isUnkwnownType = false;

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs) {
  *this = rhs;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  if (this != &rhs) {
    _value = rhs._value;
    _truncatedValue = rhs._truncatedValue;
    _isUnkwnownType = rhs._isUnkwnownType;
  }
  
  return *this;
}

void ScalarConverter::convert(const std::string value) {
  std::cout << "convert ~ value: " << value << std::endl;
  _setValues(value);

  if (_isUnkwnownType) {
    _printInvalidConversion();
  } else {
    _printConversion();
  }

  _resetValues();
}

bool ScalarConverter::_isNan(const std::string value) {
  return (value == "nan" || value == "nanf");
}

bool ScalarConverter::_isInf(const std::string value) {
  return (
    value == "inf"
    || value == "inff"
    || value == "+inf"
    || value == "+inff"
    || value == "-inf"
    || value == "-inff"
  );
}

bool ScalarConverter::_isChar(const std::string value) {
  return (value.length() == 1 && isprint(value[0]) && !isdigit(value[0]));
}

bool ScalarConverter::_isInt(const std::string value) {
  if (value.length() == 0 || value.length() > 11) {
    return false;
  }
  
  for (size_t i = 0; i < value.length(); i++) {
    if (i == 0 && (value[i] == '-' || value[i] == '+'))
      continue;
    if (!isdigit(value[i]))
      return false;
  }

  const long int tmp = std::strtol(value.c_str(), NULL, 10);

  return (tmp >= INT_MIN && tmp <= INT_MAX);
}

bool ScalarConverter::_isFloat(const std::string value) {
  size_t f = 0;
  size_t dot = 0;
  size_t length = value.length();

  for (size_t i = 0; i < length; i++) {
    if (i == 0 && (value[i] == '-' || value[i] == '+'))
      continue;
      
    if (value[i] == 'f')
      f++;
      
    if (value[i] == '.')
      dot++;

    if (value[i] == 'f' || value[i] == '.')
      continue;

    if (!isdigit(value[i]))
      return false;
  }

  size_t last = length - 1;
  size_t penult = length - 2;

  return (f == 1 && dot == 1 && value[0] != '.' && value[penult] != '.' && value[last] == 'f');

}

bool ScalarConverter::_isDouble(const std::string value) {
  size_t dot = 0;
  size_t length = value.length();
  size_t last = length - 1;

  for (size_t i = 0; i < length; i++) {
    if (i == 0 && (value[i] == '-' || value[i] == '+'))
      continue;
    if (value[i] == '.') {
      dot++;
      continue;
    }

    if (!isdigit(value[i]))
      return false;
  }

  return (dot == 1 && value[0] != '.' && value[last] != '.');
}

void ScalarConverter::_resetValues(void) {
  _value = 0.0;
  _truncatedValue = 0.0;
  _isUnkwnownType = false;
}

void ScalarConverter::_setValues(const std::string value) {
   if (_isNan(value)) {
    _value = NAN;
    _truncatedValue = _value;
  } else if (_isInf(value)) {
    _value = (value[0] == '-') ? -INFINITY : INFINITY;
    _truncatedValue = _value;
  } else if (_isChar(value)) {
    _value = static_cast<double>(value[0]);
    _truncatedValue = _value;
  } else if (_isInt(value)) {
    _value = static_cast<double>(std::atoi(value.c_str()));
    _truncatedValue = _value;
  } else if (_isFloat(value) || _isDouble(value)) {
    std::string tmp = value.substr(0, value.find('f'));
    _value = static_cast<double>(std::strtod(tmp.c_str(), NULL));
    _truncatedValue = static_cast<double>(static_cast<long long int>(_value));
  } else {
    _isUnkwnownType = true;
  }
}

std::string ScalarConverter::_getValueAsChar(void) {
  std::stringstream ss;

  if (_value < 0 || _value > 127 || std::isnan(_value) || std::isinf(_value)) {
    ss << "impossible";
  } else if (!isprint(_value)) {
    ss << "Non displayable";
  } else {
    ss << "'" << static_cast<char>(_value) << "'";
  }

  return ss.str();
}

std::string ScalarConverter::_getValueAsInt(void) {
  std::stringstream ss;

  if (_value < INT_MIN || _value > INT_MAX || std::isnan(_value) || std::isinf(_value)) {
    ss << "impossible";
  } else {
    ss << static_cast<int>(_value);
  }

  return ss.str();
}

std::string ScalarConverter::_getValueAsFloat(void) {
  std::stringstream ss;

  if (std::isinf(_value)) {
    ss << (std::signbit(_value) ? "-inff" : "+inff");
  } else {
    ss << static_cast<float>(_value) << (_value - _truncatedValue == 0 ? ".0f" : "f");
  }

  return ss.str();
}

std::string ScalarConverter::_getValueAsDouble(void) {
  std::stringstream ss;

  if (std::isinf(_value)) {
    ss << (std::signbit(_value) ? "-inf" : "+inf");
  } else {
    ss << static_cast<float>(_value) << (_value - _truncatedValue == 0 ? ".0" : "");
  }

  return ss.str();
}

void ScalarConverter::_printInvalidConversion(void) {
  std::cout
    << "char: impossible"
    << std::endl
    << "int: impossible"
    << std::endl
    << "float: impossible"
    << std::endl
    << "double: impossible"
    << std::endl;
}

void ScalarConverter::_printConversion(void) {
  const std::string valueAsChar = _getValueAsChar();
  const std::string valueAsInt = _getValueAsInt();
  const std::string valueAsFloat = _getValueAsFloat();
  const std::string valueAsDouble = _getValueAsDouble();

  std::cout
    << "char: " << valueAsChar
    << std::endl
    << "int: " << valueAsInt
    << std::endl
    << "float: " << valueAsFloat
    << std::endl
    << "double: " << valueAsDouble
    << std::endl;
}
