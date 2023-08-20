/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:05:24 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 16:55:47 by edpaulin         ###   ########.fr       */
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

ScalarValues *ScalarConverter::convert(const std::string input) {
  _resetValues();
  _setValues(input);

  if (_isUnkwnownType) {
    return new ScalarValues();
  }

  std::string valueAsChar = _getValueAsChar();
  std::string valueAsInt = _getValueAsInt();
  std::string valueAsFloat = _getValueAsFloat();
  std::string valueAsDouble = _getValueAsDouble();

  return new ScalarValues(
    valueAsChar,
    valueAsInt,
    valueAsFloat,
    valueAsDouble
  );
}

bool ScalarConverter::_isNan(const std::string input) {
  return (input == "nan" || input == "nanf");
}

bool ScalarConverter::_isInf(const std::string input) {
  return (
    input == "inf"
    || input == "inff"
    || input == "+inf"
    || input == "+inff"
    || input == "-inf"
    || input == "-inff"
  );
}

bool ScalarConverter::_isChar(const std::string input) {
  return (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]));
}

bool ScalarConverter::_isInt(const std::string input) {
  if (input.length() == 0 || input.length() > 11) {
    return false;
  }
  
  for (size_t i = 0; i < input.length(); i++) {
    if (i == 0 && (input[i] == '-' || input[i] == '+')) {
      continue;
    }

    if (!isdigit(input[i])) {
      return false;
    }
  }

  const long int tmp = std::strtol(input.c_str(), NULL, 10);

  return (tmp >= INT_MIN && tmp <= INT_MAX);
}

bool ScalarConverter::_isFloat(const std::string input) {
  size_t f = 0;
  size_t dot = 0;
  size_t length = input.length();

  for (size_t i = 0; i < length; i++) {
    if (i == 0 && (input[i] == '-' || input[i] == '+')) {
      continue;
    }
      
    if (input[i] == 'f') {
      f++;
      continue;
    }
      
    if (input[i] == '.') {
      dot++;
      continue;
    }

    if (!isdigit(input[i])) {
      return false;
    }
  }

  size_t last = length - 1;
  size_t penult = length - 2;

  return (
    f == 1
    && dot == 1
    && input[0] != '.'
    && input[penult] != '.'
    && input[last] == 'f'
  );

}

bool ScalarConverter::_isDouble(const std::string input) {
  size_t dot = 0;
  size_t length = input.length();
  size_t last = length - 1;

  for (size_t i = 0; i < length; i++) {
    if (i == 0 && (input[i] == '-' || input[i] == '+')) {
      continue;
    }

    if (input[i] == '.') {
      dot++;
      continue;
    }

    if (!isdigit(input[i])) {
      return false;
    }
  }

  return (dot == 1 && input[0] != '.' && input[last] != '.');
}

void ScalarConverter::_resetValues(void) {
  _value = 0.0;
  _truncatedValue = 0.0;
  _isUnkwnownType = false;
}

void ScalarConverter::_setValues(const std::string input) {
   if (_isNan(input)) {
    _value = NAN;
    _truncatedValue = _value;
  } else if (_isInf(input)) {
    _value = (input[0] == '-') ? -INFINITY : INFINITY;
    _truncatedValue = _value;
  } else if (_isChar(input)) {
    _value = static_cast<double>(input[0]);
    _truncatedValue = _value;
  } else if (_isInt(input)) {
    _value = static_cast<double>(std::atoi(input.c_str()));
    _truncatedValue = _value;
  } else if (_isFloat(input) || _isDouble(input)) {
    std::string tmp = input.substr(0, input.find('f'));
    _value = static_cast<double>(std::strtod(tmp.c_str(), NULL));
    _truncatedValue = static_cast<double>(static_cast<long long int>(_value));
  } else {
    _isUnkwnownType = true;
  }
}

std::string ScalarConverter::_getValueAsChar(void) {
  std::stringstream ss;

  if (_truncatedValue < 0 || _truncatedValue > 127 || std::isnan(_truncatedValue) || std::isinf(_truncatedValue)) {
    ss << "impossible";
  } else if (!isprint(_truncatedValue)) {
    ss << "Non displayable";
  } else {
    ss << "'" << static_cast<char>(_truncatedValue) << "'";
  }

  return ss.str();
}

std::string ScalarConverter::_getValueAsInt(void) {
  std::stringstream ss;

  if (_truncatedValue < INT_MIN || _truncatedValue > INT_MAX || std::isnan(_truncatedValue) || std::isinf(_truncatedValue)) {
    ss << "impossible";
  } else {
    ss << static_cast<int>(_truncatedValue);
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
