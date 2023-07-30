/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:36:46 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 20:50:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void printBabyChickSeparator(void);

int main(void) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();


	printBabyChickSeparator();

	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wac = new WrongCat();
	const WrongCat* wc = new WrongCat();
  
  std::cout << wac->getType() << " " << std::endl;
  std::cout << wc->getType() << " " << std::endl;
  wa->makeSound();
  wac->makeSound();
  wc->makeSound();

	printBabyChickSeparator();

	delete meta;
	delete j;
	delete i;

	printBabyChickSeparator();

	delete wa;
	delete wac;
	delete wc;

	return 0;
}

void printBabyChickSeparator(void) {
  std::cout
    << std::endl
    << "🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣"
    << std::endl
    << std::endl;
}
