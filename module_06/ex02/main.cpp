/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 10:50:16 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 12:00:03 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Derived.hpp"

static void printSeparator(void);
static void testGenerate(void);
static void testPointerIdentify(void);
static void testReferenceIdentify(void);

int main(void) {
  testGenerate();
  
  printSeparator();
  
  testPointerIdentify();
  
  printSeparator();
  
  testReferenceIdentify();
  
  return 0;
}

static void printSeparator(void) {
  std::cout << "🔥💣🔥💣🔥💣🔥💣🔥💣🔥💣🔥💣🔥💣🔥💣🔥" << std::endl << std::endl;
}

static void testGenerate(void) {
  std::cout << "🧪 Start generate test 🧪" << std::endl << std::endl;
  
  Base *ptrRandom = generate();
  
  std::cout << "ptrRandom1: ";
  identify(ptrRandom);
  std::cout << std::endl;

  delete ptrRandom;

  std::cout << "🧪 End pointer identify test 🧪" << std::endl << std::endl;
}

static void testPointerIdentify(void) {
  std::cout << "🧪 Start pointer identify test 🧪" << std::endl << std::endl;
  
  Base *ptrBase = new Base;
  A *ptrA = new A;
  B *ptrB = new B;
  C *ptrC = new C;

  std::cout << "Base pointer: " << std::endl;
  std::cout << "Expected: 👉 Pointer type: Unknown" << std::endl;
  std::cout << "Received: ";
  identify(ptrBase);
  std::cout << std::endl;
  
  std::cout << "A pointer: " << std::endl;
  std::cout << "Expected: 👉 Pointer type: A" << std::endl;
  std::cout << "Received: ";
  identify(ptrA);
  std::cout << std::endl;
  
  std::cout << "B pointer: " << std::endl;
  std::cout << "Expected: 👉 Pointer type: B" << std::endl;
  std::cout << "Received: ";
  identify(ptrB);
  std::cout << std::endl;
  
  std::cout << "C pointer: " << std::endl;
  std::cout << "Expected: 👉 Pointer type: C" << std::endl;
  std::cout << "Received: ";
  identify(ptrC);
  std::cout << std::endl;
  
  delete ptrA;
  delete ptrB;
  delete ptrC;
  delete ptrBase;
  std::cout << "🧪 End pointer identify test 🧪" << std::endl << std::endl;
}

static void testReferenceIdentify(void) {
  std::cout << "🧪 Start reference identify test 🧪" << std::endl << std::endl;
  
  Base refBase = Base();
  A refA = A();
  B refB = B();
  C refC = C();

  std::cout << "Base reference: " << std::endl;
  std::cout << "Expected: 🫵  Reference type: Unknown" << std::endl;
  std::cout << "Received: ";
  identify(refBase);
  std::cout << std::endl;
  
  std::cout << "A reference: " << std::endl;
  std::cout << "Expected: 🫵  Reference type: A" << std::endl;
  std::cout << "Received: ";
  identify(refA);
  std::cout << std::endl;
  
  std::cout << "B reference: " << std::endl;
  std::cout << "Expected: 🫵  Reference type: B" << std::endl;
  std::cout << "Received: ";
  identify(refB);
  std::cout << std::endl;
  
  std::cout << "C reference: " << std::endl;
  std::cout << "Expected: 🫵  Reference type: C" << std::endl;
  std::cout << "Received: ";
  identify(refC);
  std::cout << std::endl;
  
  std::cout << "🧪 End pointer identify test 🧪" << std::endl << std::endl;
}
