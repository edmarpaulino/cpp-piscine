/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:58:15 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 17:15:30 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarTest.hpp"

size_t ScalarTest::_numOfTestsPassed = 0;
size_t ScalarTest::_numOfTestsFailed = 0;
size_t ScalarTest::_numOfTests = 0;

ScalarTest::ScalarTest(void) {}

ScalarTest::ScalarTest(const ScalarTest &rhs) {
  *this = rhs;
}

ScalarTest::~ScalarTest(void) {}

ScalarTest &ScalarTest::operator=(const ScalarTest &rhs) {
  if (this != &rhs) {
    return *this;
  }

  return *this;
}

void ScalarTest::_resetTest(void) {
  _numOfTestsPassed = 0;
  _numOfTestsFailed = 0;
  _numOfTests = 0;
}

void ScalarTest::runTests(void) {
  _resetTest();
  _testImpossible();
  _testInf();
  _testNan();
  _testChar();
  _testInt();
  _testFloat();
  _testDouble();
  std::cout << std::endl;
  std::cout << "Passed: " << _numOfTestsPassed << std::endl;
  std::cout << "Failed: " << _numOfTestsFailed << std::endl;
  std::cout << "Total tests: " << _numOfTests << std::endl;
}

void ScalarTest::_test(std::string description, ScalarValues *sut, ScalarValues expected) {
  _numOfTests++;
  if (*sut == expected) {
    _numOfTestsPassed++;
    std::cout << "✅ PASS: " << description << std::endl;
  } else {
    _numOfTestsFailed++;
    std::cout << "❌ FAIL: " << description << std::endl;
    std::cout << "Expected: " << std::endl;
    std::cout << expected << std::endl;
    std::cout << "Actual: " << std::endl;
    std::cout << *sut << std::endl;
  }
}

void ScalarTest::_testImpossible(void) {
  ScalarValues expected;

  {
    std::string input = "";
    std::string description = "Should return impossible to an empty input";
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);    
    delete sut;
  }

  {
    std::string input = "infff";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "nann";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "-nanf";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "-nan";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "+nanf";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "+nan";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "**";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);    
    delete sut;
  }

  {
    std::string input = "123c123";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "123123.f";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = ".1231234f";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "123123.0ff";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "f123123.0f";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "1231.23.0f";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "123123.0ff";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "123123.";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = ".123123";
    std::string description = "Should return impossible to " + input;
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
}

void ScalarTest::_testInf(void) {
  {
    std::string input = "inff";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("impossible", "impossible", "+inff", "+inf");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "inf";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("impossible", "impossible", "+inff", "+inf");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "+inff";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("impossible", "impossible", "+inff", "+inf");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "+inf";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("impossible", "impossible", "+inff", "+inf");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "-inff";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("impossible", "impossible", "-inff", "-inf");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "-inf";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("impossible", "impossible", "-inff", "-inf");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
}

void ScalarTest::_testNan(void) {
  {
    std::string input = "nanf";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("impossible", "impossible", "nanf", "nan");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "nan";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("impossible", "impossible", "nanf", "nan");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
}

void ScalarTest::_testChar(void) {
  {
    std::string input = " ";
    std::string description = "Should return valid values to '" + input + "'";
    ScalarValues expected = ScalarValues("' '", "32", "32.0f", "32.0");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "*";
    std::string description = "Should return valid values to '" + input + "'";
    ScalarValues expected = ScalarValues("'*'", "42", "42.0f", "42.0");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "f";
    std::string description = "Should return valid values to '" + input + "'";
    ScalarValues expected = ScalarValues("'f'", "102", "102.0f", "102.0");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
}

void ScalarTest::_testInt(void) {
  {
    std::string input = "0";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("Non displayable", "0", "0.0f", "0.0");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "127";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("Non displayable", "127", "127.0f", "127.0");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "32";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("' '", "32", "32.0f", "32.0");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "42";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("'*'", "42", "42.0f", "42.0");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }

  {
    std::string input = "-2147483648";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("impossible", "-2147483648", "-2.14748e+09.0f", "-2.14748e+09.0");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "+2147483647";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("impossible", "2147483647", "2.14748e+09.0f", "2.14748e+09.0");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "2147483647";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("impossible", "2147483647", "2.14748e+09.0f", "2.14748e+09.0");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
}

void ScalarTest::_testFloat(void) {
  {
    std::string input = "0.0f";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("Non displayable", "0", "0.0f", "0.0");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "42.42f";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("'*'", "42", "42.42f", "42.42");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "-0.011f";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("Non displayable", "0", "-0.011f", "-0.011");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
}

void ScalarTest::_testDouble(void) {
  {
    std::string input = "0.0";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("Non displayable", "0", "0.0f", "0.0");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "42.42";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("'*'", "42", "42.42f", "42.42");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "-42.42";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("impossible", "-42", "-42.42f", "-42.42");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
  
  {
    std::string input = "-0.011";
    std::string description = "Should return valid values to " + input;
    ScalarValues expected = ScalarValues("Non displayable", "0", "-0.011f", "-0.011");
    ScalarValues *sut = ScalarConverter::convert(input);
    _test(description, sut, expected);
    delete sut;
  }
}
