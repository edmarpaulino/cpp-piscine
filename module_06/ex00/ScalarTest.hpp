/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTest.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:56:32 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 17:14:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_TEST_HPP
#define SCALAR_TEST_HPP

#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

class ScalarTest {
public:
  static void runTests(void);

private:
  static size_t _numOfTestsPassed;
  static size_t _numOfTestsFailed;
  static size_t _numOfTests;

  ScalarTest(void);
  ScalarTest(const ScalarTest &rhs);
  ~ScalarTest(void);

  ScalarTest &operator=(const ScalarTest &rhs);

  static void _resetTest(void);
  
  static void _test(std::string description, ScalarValues *sut, ScalarValues expected);
  
  static void _testImpossible(void);
  static void _testInf(void);
  static void _testNan(void);
  static void _testChar(void);
  static void _testInt(void);
  static void _testFloat(void);
  static void _testDouble(void);
};

#endif /* SCALAR_TEST_HPP */
