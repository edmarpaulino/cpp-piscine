/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 08:35:53 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 09:02:11 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
  std::cout << "🦊 WrongCat default constructor called 🔨" << std::endl;
  this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &rhs): WrongAnimal(rhs) {
  std::cout << "🦊 WrongCat copy constructor called 🛠️" << std::endl;
  *this = rhs;
}

WrongCat::~WrongCat(void) {
  std::cout << "🦊 WrongCat destructor called 💣" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
  std::cout << "🦊 WrongCat assignment operator called 🔧" << std::endl;
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

void WrongCat::makeSound(void) const {
  std::cout << "🦊 Wa-pa-pa-pa-pa-pa-pow! 🎵" << std::endl;
}
