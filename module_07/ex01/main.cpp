/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:34:57 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/21 21:57:04 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static void printSeparator(void);
static void testSuite(void);
static void testInt(void);
static void testString(void);
static void testChar(void);
static void testFloat(void);
static void testDouble(void);
static void testBool(void);

int main(void) {
  testSuite();
  
  return 0;
}

static void printSeparator(void) {
  std::cout << std::endl <<  "🕛🕧🕐🕜🕑🕝🕒🕛🕧🕐🕜🕑🕝🕒" << std::endl << std::endl;
}

static void testSuite(void) {
  std::cout << "🧪 TEST SUITE 🧪" << std::endl << std::endl;
  
  printSeparator();

  testInt();
  
  printSeparator();
  
  testString();

  printSeparator();

  testChar();

  printSeparator();

  testFloat();

  printSeparator();

  testDouble();

  printSeparator();

  testBool();

  printSeparator();
}

static void testInt(void) {
  std::cout << "🧪 INT 🧪" << std::endl << std::endl;
  int array[] = {1, 2, 3, 4, 5};
  iter(array, 5, printIter);
}

static void testString(void) {
  std::cout << "🧪 STRING 🧪" << std::endl << std::endl;
  std::string array[] = {"1", "2", "3", "4", "5"};
  iter(array, 5, printIter);
}

static void testChar(void) {
  std::cout << "🧪 CHAR 🧪" << std::endl << std::endl;
  char array[] = {'1', '2', '3', '4', '5'};
  iter(array, 5, printIter);
}

static void testFloat(void) {
  std::cout << "🧪 FLOAT 🧪" << std::endl << std::endl;
  float array[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
  iter(array, 5, printIter);
}

static void testDouble(void) {
  std::cout << "🧪 DOUBLE 🧪" << std::endl << std::endl;
  double array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  iter(array, 5, printIter);
}

static void testBool(void) {
  std::cout << "🧪 BOOL 🧪" << std::endl << std::endl;
  bool array[] = {true, false, true, false, true};
  iter(array, 5, printIter);
}
