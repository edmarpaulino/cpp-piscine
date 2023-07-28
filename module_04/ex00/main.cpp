/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:36:46 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/27 21:21:19 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void printSeparator(void);

int main(void) {
  Animal *ani = new Animal();
  Dog *dog = new Dog();
  Cat *cat = new Cat();

  printSeparator();
  
  std::cout << *ani << std::endl;
  std::cout << *dog << std::endl;
  std::cout << *cat << std::endl;

  printSeparator();

  ani->makeSound();
  dog->makeSound();
  cat->makeSound();

  printSeparator();

  Animal ani1(*ani);
  Dog dog1(*dog);
  Cat cat1(*cat);

  printSeparator();
  
  delete ani;
  delete dog;
  delete cat;

  printSeparator();

  Animal ani2;
  Dog dog2;
  Cat cat2;

  printSeparator();

  ani2 = ani1;
  dog2 = dog1;
  cat2 = cat1;

  return 0;
}

void printSeparator(void) {
  std::cout << "🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣🐥🐣" << std::endl;
}
