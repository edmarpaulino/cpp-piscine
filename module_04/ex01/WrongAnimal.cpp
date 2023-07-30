/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 08:26:47 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 18:34:08 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("WrongAnimal") {
  std::cout << "👽 WrongAnimal default constructor called 🔨" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
  std::cout << "👽 WrongAnimal type constructor called 🪛" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs) {
  std::cout << "👽 WrongAnimal copy constructor called 🛠️" << std::endl;
  *this = rhs;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "👽 WrongAnimal destructor called 💣" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
  std::cout << "👽 WrongAnimal assignment operator called 🔧" << std::endl;
  if (this != &rhs)
    this->_type = rhs._type;
  return *this;
}

std::string WrongAnimal::getType(void) const {
  return this->_type;
}

void WrongAnimal::makeSound(void) const {
  std::cout << "👽 Ring-ding-ding-ding-dingeringeding! 🎵" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const WrongAnimal &rhs) {
  o << "👽 This wrong animal is " << rhs.getType() << " type? 👀";
  return o;
}
