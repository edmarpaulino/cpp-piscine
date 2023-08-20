/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:03:56 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 19:46:58 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstdlib>

#include "ScalarValues.hpp"

class ScalarConverter {
public:
  static ScalarValues *convert(const std::string value);

private:
  static double _value;
  static double _truncatedValue;
  static bool _isUnkwnownType;

  ScalarConverter(void);
  ScalarConverter(const ScalarConverter &rhs);
  ~ScalarConverter(void);

  ScalarConverter &operator=(const ScalarConverter &rhs);

  static bool _isNan(const std::string value);
  static bool _isInf(const std::string value);
  static bool _isChar(const std::string value);
  static bool _isInt(const std::string value);
  static bool _isFloat(const std::string value);
  static bool _isDouble(const std::string value);

  static void _resetValues(void);
  static void _setValues(const std::string value);

  static std::string _getValueAsChar(void);
  static std::string _getValueAsInt(void);
  static std::string _getValueAsFloat(void);
  static std::string _getValueAsDouble(void);
};

#endif /* SCALAR_CONVERTER_HPP */
