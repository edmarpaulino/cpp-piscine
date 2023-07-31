/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:43:49 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/31 19:54:22 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
  std::cout << "🐶 Dog default constructor called 🔨" << std::endl;
  this->_type = "Dog";
  this->_brain = new Brain();
}

Dog::Dog(const Dog &rhs): AAnimal(rhs) {
  std::cout << "🐶 Dog copy constructor called 🛠️" << std::endl;
  this->_brain = new Brain(*rhs._brain);
  *this = rhs;
}

Dog::~Dog(void) {
  std::cout << "🐶 Dog destructor called 💣" << std::endl;
  delete this->_brain;
}

Dog	&Dog::operator=(const Dog &rhs) {
  std::cout << "🐶 Dog assignment operator called 🔧" << std::endl;
  if (this != &rhs) {
    this->_type = rhs._type;
    for (unsigned int i = 0; i < IDEAS_SIZE; i++) {
      this->_brain->setIdea(i, rhs._brain->getIdea(i));
    }
  }
  return *this;
}

void Dog::makeSound(void) const {
  std::cout << "🐶 Au Au 🦴" << std::endl;
}

Brain *Dog::getBrain(void) const {
  return this->_brain;
}
