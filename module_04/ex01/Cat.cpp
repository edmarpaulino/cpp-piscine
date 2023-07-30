/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:48:33 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 18:35:21 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
  std::cout << "🐱 Cat default constructor called 🔨" << std::endl;
  this->_type = "Cat";
}

Cat::Cat(const Cat &rhs): Animal(rhs) {
  std::cout << "🐱 Cat copy constructor called 🛠️" << std::endl;
  *this = rhs;
}

Cat::~Cat(void) {
  std::cout << "🐱 Cat destructor called 💣" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
  std::cout << "🐱 Cat assignment operator called 🔧" << std::endl;
  if (this != &rhs)
    this->_type = rhs._type;
  return *this;
}

void Cat::makeSound(void) const {
  std::cout << "🐱 Miau 🐟" << std::endl;
}
