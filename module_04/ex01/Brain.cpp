/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:54:27 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 19:56:59 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
  std::cout << "🧠 Brain default constructor called 🔨" << std::endl;
  for (unsigned int i = 0; i < IDEAS_SIZE; i++) {
    this->_ideas[i] = "...";
  }
}

Brain::Brain(const Brain &rhs) {
  std::cout << "🧠 Brain copy constructor called 🛠️" << std::endl;
  *this = rhs;
}

Brain::~Brain(void) {
  std::cout << "🧠 Brain destructor called 💣" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs) {
  std::cout << "🧠 Brain assignment operator called 🔧" << std::endl;
  
  if (this != &rhs) {
    for (unsigned int i = 0; i < IDEAS_SIZE; i++) {
      this->_ideas[i] = rhs._ideas[i];
    }
  }
  
  return *this;
}

std::string Brain::getIdea(const unsigned int index) const {
  if (index >= IDEAS_SIZE) {
    std::cout << "🧠 Brain does not have the capacity to have this idea 🫠" << std::endl;
    return "";
  }

  return this->_ideas[index];
}

void Brain::setIdea(const unsigned int index, std::string idea) {
  if (index >= IDEAS_SIZE) {
    std::cout << "🧠 Brain can't come up with any more ideas 🤯" << std::endl;
    return;
  }

  this->_ideas[index] = idea;
}

std::ostream &operator<<(std::ostream &o, const Brain &rhs) {
  for (int i = 0; i < IDEAS_SIZE; i++) {
    o << "🧠 "
      << std::setfill('0')
      << std::setw(3)
      << i + 1 << " 🤔 " << rhs.getIdea(i) << " 💭" << std::endl;
  }

  return o;
}
