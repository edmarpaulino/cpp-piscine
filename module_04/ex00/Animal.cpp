/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:41:21 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/27 13:19:07 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("Fox") {
  std::cout << "🐾 Animal default constructor called 🔨" << std::endl;
}

Animal::Animal(std::string type): _type(type) {
  std::cout << "🐾 Animal type constructor called 🪛" << std::endl;
}

Animal::Animal(const Animal &rhs) {
  std::cout << "🐾 Animal copy constructor called 🛠️" << std::endl;
  *this = rhs;
}

Animal::~Animal(void) {
  std::cout << "🐾 Animal destructor called 💣" << std::endl;
}

Animal	&Animal::operator=(const Animal &rhs) {
  std::cout << "🐾 Animal assignment operator called 🔧" << std::endl;
  if (this != &rhs)
    this->_type = rhs._type;
  return *this;
}

std::string Animal::getType(void) const {
  return this->_type;
}

void Animal::makeSound(void) const {
  std::cout << "🐾 What does the 🦊 say? 🎵" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Animal &rhs) {
  o << "🐾 This animal is " << rhs.getType() << " type 🔎";
  return o;
}
