/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:03:56 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/17 23:06:48 by edpaulin         ###   ########.fr       */
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

// remove this later
#include <iomanip>

class ScalarConverter {
public:
  static void convert(const std::string value);

private:
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
  
  static void _printNan(void);
  static void _printInf(std::string sign);
  static void _printInvalidConversion(void);
  static void _printConversions(const double value);

  static void _printChar(const double value);
  static void _printInt(const double value);
  static void _printFloat(const double value);
  static void _printDouble(const double value);

};

#endif /* SCALAR_CONVERTER_HPP */
