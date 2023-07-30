/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:36:46 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 20:45:57 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

static void testDeepCopy(void);
static void printBabyChickSeparator(void);
static void printTreeSeparator(void);
static void printFireSeparator(void);

int main(void) {
  Animal *animals[10];

  printBabyChickSeparator();

  for (unsigned int i = 0; i < 5; i++) {
    animals[i] = new Dog;
    printTreeSeparator();
  }

  printBabyChickSeparator();

  for (unsigned int i = 5; i < 10; i++) {
    animals[i] = new Cat;
    printTreeSeparator();
  }

  printBabyChickSeparator();

  for (unsigned int i = 0; i < 10; i++) {
    delete animals[i];
    printTreeSeparator();
  }

  printFireSeparator();

  testDeepCopy();
  
  printFireSeparator();

	return 0;
}

static void testDeepCopy(void) {
  Dog *snoopy = new Dog;

  printTreeSeparator();

  Dog *scooby = new Dog(*snoopy);

  printBabyChickSeparator();
  
  Brain *snoopyBrain = snoopy->getBrain();
  Brain *scoobyBrain = scooby->getBrain();

  snoopyBrain->setIdea(42 - 1, "Moulinette");
  scoobyBrain->setIdea(42 - 1, "Norminette");

  std::cout
    << "🚀 Snoopy brain - address: " << snoopyBrain
    << " - 42 idea: " << snoopyBrain->getIdea(42 - 1)
    << std::endl;

  std::cout
    << "🚀 Scooby brain - address: " << scoobyBrain
    << " - 42 idea: " << scoobyBrain->getIdea(42 - 1)
    << std::endl;

  printBabyChickSeparator();

  delete snoopy;

  printTreeSeparator();

  delete scooby;

  printBabyChickSeparator();

  Cat *neko = new Cat;

  printTreeSeparator();

  Cat *kitty = new Cat(*neko);

  printBabyChickSeparator();

  Brain *nekoBrain = neko->getBrain();
  Brain *kittyBrain = kitty->getBrain();

  nekoBrain->setIdea(42 - 1, "Moulinette");
  kittyBrain->setIdea(42 - 1, "Norminette");

  std::cout
    << "🚀 Neko brain - address: " << nekoBrain
    << " - 42 idea: " << nekoBrain->getIdea(42 - 1)
    << std::endl;

  std::cout
    << "🚀 Kitty brain - address: " << kittyBrain
    << " - 42 idea: " << kittyBrain->getIdea(42 - 1)
    << std::endl;

  printBabyChickSeparator();

  delete neko;

  printTreeSeparator();
  
  delete kitty;
}

static void printBabyChickSeparator(void) {
  std::cout
    << std::endl
    << "🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣"
    << std::endl
    << std::endl;
}

static void printTreeSeparator(void) {
  std::cout
    << "🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳🌲"
    << std::endl;
}

static void printFireSeparator(void) {
  std::cout
    << std::endl
    << "🔥🧨🔥🧨🔥🧨🔥🧨🔥🧨🔥🧨🔥🧨🔥🧨🔥🧨🔥🧨🔥🧨🔥🧨🔥🧨🔥"
    << std::endl
    << std::endl;
}
