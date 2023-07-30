/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:36:46 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 19:56:05 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void printSeparator(void);

int main(void) {
  Brain brain;

  std::cout << brain << std::endl;

  printSeparator();

  Brain brain2(brain);

  printSeparator();

  brain.setIdea(42 - 1, "Marvin");
  brain2.setIdea(21 - 1, "Mar");

  brain.getIdea(420);
  brain2.setIdea(420, "Everything");

  printSeparator();

  std::cout << brain << std::endl;

  printSeparator();
  
  std::cout << brain2 << std::endl;

  printSeparator();

	return 0;
}

void printSeparator(void) {
  std::cout
    << std::endl
    << "🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣"
    << std::endl
    << std::endl;
}
