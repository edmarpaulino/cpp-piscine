/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:48:31 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/22 21:24:35 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>

#include "Array.hpp"

static void printRocketSeparator(void);
static void printFilmFrameSeparator(void);
static void testSuite(void);
static void testExceptions(void);
static void testBool(void);
static void testChar(void);
static void testInt(void);
static void testFloat(void);
static void testDouble(void);
static void testString(void);
static void testDefault(void);
static void copyTest(void);

int main(void) {
  testSuite();
  
  return 0;
}

static void printRocketSeparator(void) {
  std::cout
    << std::endl
    << "🚀🚀🚀🚀🚀🚀🚀🚀🚀🚀🚀🚀🚀🚀🚀🚀🚀🚀🚀🚀🚀🚀"
    << std::endl
    << std::endl;
}

static void printFilmFrameSeparator(void) {
  std::cout << "🎞️🎞️🎞️🎞️🎞️🎞️🎞️🎞️🎞️🎞️🎞️🎞️🎞️🎞️🎞️🎞️🎞️🎞️🎞️🎞️" << std::endl;
}

static void testSuite(void) {
  testExceptions();

  printRocketSeparator();
  
  testBool();

  printRocketSeparator();

  testChar();
  
  printRocketSeparator();
  
  testInt();
  
  printRocketSeparator();
  
  testFloat();
  
  printRocketSeparator();
  
  testDouble();
  
  printRocketSeparator();
  
  testString();
  
  printRocketSeparator();
  
  testDefault();
  
  printRocketSeparator();
  
  copyTest();
  
  printRocketSeparator();
}

static void testExceptions(void) {
  std::cout << "🧪 EXCEPTIONS 🧪" << std::endl << std::endl;

  try {
    Array<int> arr;

    std::cout << "arr.size(): " << arr.size() << std::endl;

    arr[-42] = -42;

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  printFilmFrameSeparator();

  try {
    Array<int> arr;

    std::cout << "arr.size(): " << arr.size() << std::endl;

    arr[42] = 42;

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  printFilmFrameSeparator();

  try {
    Array<int> arr(42);

    std::cout << "arr.size(): " << arr.size() << std::endl;

    arr[42] = 42;

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  printFilmFrameSeparator();
}

static void testBool(void) {
  std::cout << "🧪 BOOL 🧪" << std::endl << std::endl;
  
  Array<bool> arr(2);
  
  std::cout << "arr.size(): " << arr.size() << std::endl;
  
  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = i % 2;
  }

  std::cout << arr << std::endl;

  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = (i + 1) % 2;
  }

  std::cout << arr << std::endl;
}

static void testChar(void) {
  std::cout << "🧪 CHAR 🧪" << std::endl << std::endl;
  
  Array<char> arr(3);
  
  std::cout << "arr.size(): " << arr.size() << std::endl;

  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = i + 65;
  }

  std::cout << arr << std::endl;

  arr[arr.size() - 1] = 'Z';

  std::cout << arr << std::endl;
}

static void testInt(void) {
  std::cout << "🧪 INT 🧪" << std::endl << std::endl;
  
  Array<int> arr(4);

  std::cout << "arr.size(): " << arr.size() << std::endl;

  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = 100 * (i + 1);
  }

  std::cout << arr << std::endl;

  arr[arr.size() / 2] = 42;
  
  std::cout << arr << std::endl;
}

static void testFloat(void) {
  std::cout << "🧪 FLOAT 🧪" << std::endl << std::endl;
  
  Array<float> arr(5);

  std::cout << "arr.size(): " << arr.size() << std::endl;

  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = i + 1 + ((float)(i + 1) / 10);
  }

  std::cout << arr << std::endl;

  arr[arr.size() / 2] = 42.42f; 

  std::cout << arr << std::endl;
}

static void testDouble(void) {
  std::cout << "🧪 DOUBLE 🧪" << std::endl << std::endl;

  Array<double> arr(6);

  std::cout << "arr.size(): " << arr.size() << std::endl;

  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = i + 1 + ((double)(i + 1) / 10);
  }

  std::cout << arr << std::endl;

  arr[arr.size() / 3] = 42.42;

  std::cout << arr << std::endl;
}

static void testString(void) {
  std::cout << "🧪 STRING 🧪" << std::endl << std::endl;
  
  Array<std::string> arr(7);

  std::cout << "arr.size(): " << arr.size() << std::endl;

  std::ostringstream ss;
  
  for (unsigned int i = 0; i < arr.size(); i++) {
    ss << (i + 1);
    arr[i] = ss.str();
    ss.str("");
  }

  std::cout << arr << std::endl;

  arr[arr.size() - 3] = "42";

  std::cout << arr << std::endl;
}


static void testDefault(void) {
  std::cout << "🧪 DEFAULT 🧪" << std::endl << std::endl;
  
  Array<int> arr(8);

  std::cout << "arr.size(): " << arr.size() << std::endl;
  
  std::cout << arr << std::endl;

  arr[arr.size() - 3] = 42;

  std::cout << arr << std::endl;
}

static void copyTest(void) {
  std::cout << "🧪 DEFAULT 🧪" << std::endl << std::endl;
  
  Array<std::string> arr(9);

  std::cout << "arr.size(): " << arr.size() << std::endl;

  std::ostringstream ss;

  for (unsigned int i = 0; i < arr.size(); i++) {
    ss << (i + 1);
    arr[i] = ss.str();
    ss.str("");
  }
  
  std::cout << arr << std::endl;

  Array<std::string> copy;

  copy = arr;

  copy[arr.size() - 3] = 42;

  std::cout << arr << std::endl;
  std::cout << copy << std::endl;
}
