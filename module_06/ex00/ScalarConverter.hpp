/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:03:56 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/16 22:31:12 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#define CHAR_TYPE 'c'
#define INT_TYPE 'i'
#define FLOAT_TYPE 'f'
#define DOUBLE_TYPE 'd'
#define UNKNOWN_TYPE 'u'

typedef char SCALAR_TYPE;

class ScalarConverter {
public:
  static void convert(const std::string value);

private:
  static char _c;
  static int _i;
  static float _f;
  static double _d;
  static SCALAR_TYPE _type;
  
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter &rhs);
  ~ScalarConverter(void);

  ScalarConverter &operator=(const ScalarConverter &rhs);

  static SCALAR_TYPE _identifyType(const std::string value);
  
  static bool _isChar(const std::string value);
  static bool _isInt(const std::string value);
  static bool _isFloat(const std::string value);
  static bool _isDouble(const std::string value);
  
  static void _convert(char value);
  static void _convert(int value);
  static void _convert(float value);
  static void _convert(double value);
  
  static void _printValues(void);
  static void _printUnknownValues(void);
  static void _resetValues(void);
  
  static std::string _getFormatedChar(void);
  static std::string _getFormatedInt(void);
  static std::string _getFormatedFloat(void);
  static std::string _getFormatedDouble(void);
};

#endif /* SCALAR_CONVERTER_HPP */
