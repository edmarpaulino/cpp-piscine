/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:05:24 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/17 23:30:16 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs) {
  *this = rhs;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  static_cast<void>(rhs);

  return *this;
}

void ScalarConverter::convert(const std::string value) {
  if (value.length() == 0) {
    _printInvalidConversion();
    return;
  }
  
  if (_isNan(value)) {
    _printNan();
    return;
  }

  if (_isInf(value)) {
    _printInf(value[0] == '-' ? "-" : "+");
    return;
  }

  if (_isChar(value)) {
    _printConversions(static_cast<double>(value[0]));
    return;
  }

  if (_isInt(value)) {
    _printConversions(static_cast<double>(std::atoi(value.c_str())));
    return;
  }

  if (_isFloat(value)) {
    std::string tmp = value.substr(0, value.find('f'));
    _printConversions(static_cast<double>(std::strtod(tmp.c_str(), NULL)));
    return;
  }

  if (_isDouble(value)) {
    _printConversions(static_cast<double>(std::strtod(value.c_str(), NULL)));
    return;
  }

  _printInvalidConversion();
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
  if (value.length() == 0) {
    return false;
  }

  size_t f = 0;
  size_t dot = 0;

  for (size_t i = 0; i < value.length(); i++) {
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

  if (f != 1
    || dot != 1 
    || value[0] == '.'
    || value[value.length() - 2] == '.' 
    || value[value.length() - 1] != 'f')
    return false;

  return true;
}

bool ScalarConverter::_isDouble(const std::string value) {
  size_t dot = 0;

  for (size_t i = 0; i < value.length(); i++) {
    if (i == 0 && (value[i] == '-' || value[i] == '+'))
      continue;
    if (value[i] == '.') {
      dot++;
      continue;
    }

    if (!isdigit(value[i]))
      return false;
  }

  if (dot != 1 || value[0] == '.' || value[value.length() - 1] == '.')
    return false;
  
  return true;
}

void ScalarConverter::_printNan(void) {
  std::cout
    << "char: impossible"
    << std::endl
    << "int: impossible"
    << std::endl
    << "float: nanf"
    << std::endl
    << "double: nan"
    << std::endl;
}

void ScalarConverter::_printInf(std::string sign) {
  std::cout
    << "char: impossible"
    << std::endl
    << "int: impossible"
    << std::endl
    << "float: " << sign << "inff"
    << std::endl
    << "double: " << sign << "inf"
    << std::endl;
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

void ScalarConverter::_printConversions(const double value) {
  _printChar(value);
  _printInt(value);
  _printFloat(value);
  _printDouble(value);
}

void ScalarConverter::_printChar(const double value) {
  if (value < 0 || value > 127) {
    std::cout << "char: impossible" << std::endl;
  } else if (isprint(value)) {
    std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
  } else {
    std::cout << "char: Non displayable" << std::endl;
  }
}

void ScalarConverter::_printInt(const double value) {
  if (value < INT_MIN || value > INT_MAX) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << static_cast<int>(value) << std::endl;
  }
}

void ScalarConverter::_printFloat(const double value) {
  if (std::isinf(value) && !std::signbit(value)) {
    std::cout << "float: +inff" << std::endl;
    return;
  }
  
  long long int trunc = static_cast<long long int>(value);
  if (value - static_cast<float>(trunc) == 0)
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
  else 
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::_printDouble(const double value) {
  if (std::isinf(value) && !std::signbit(value)) {
    std::cout << "double: +inf" << std::endl;
    return;
  }
  long long int trunc = static_cast<long long int>(value);
  if (value - static_cast<double>(trunc) == 0)
    std::cout << "double: " << value << ".0" << std::endl;
  else
    std::cout << "double: " << value << std::endl;
}
