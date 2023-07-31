/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:41:21 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 21:04:06 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void): _type("Animal") {
  std::cout << "🐾 Animal default constructor called 🔨" << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type) {
  std::cout << "🐾 Animal type constructor called 🪛" << std::endl;
}

AAnimal::AAnimal(const AAnimal &rhs) {
  std::cout << "🐾 Animal copy constructor called 🛠️" << std::endl;
  *this = rhs;
}

AAnimal::~AAnimal(void) {
  std::cout << "🐾 Animal destructor called 💣" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &rhs) {
  std::cout << "🐾 Animal assignment operator called 🔧" << std::endl;
  if (this != &rhs)
    this->_type = rhs._type;
  return *this;
}

std::string AAnimal::getType(void) const {
  return this->_type;
}

std::ostream &operator<<(std::ostream &o, const AAnimal &rhs) {
  o << "🐾 This animal is " << rhs.getType() << " type 🔎";
  return o;
}
