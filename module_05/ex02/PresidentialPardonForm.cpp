/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:38:16 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/02 23:01:23 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: AForm("PresidentialPardonForm", 25, 5) {
  std::cout << "📄🎖️  RobotomyRequestForm default constructor called 🔨" << std::endl;
  this->_target = "Unknown";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
: AForm("PresidentialPardonForm", 25, 5) {
  std::cout << "📄🎖️  RobotomyRequestForm constructor called 🪛" << std::endl;
  this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs)
: AForm(rhs) {
  std::cout << "📄🎖️  RobotomyRequestForm copy constructor called 🛠️"  << std::endl;
  *this = rhs;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
  std::cout << "📄🎖️  RobotomyRequestForm destructor called 💣" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
  std::cout << "📄🎖️  RobotomyRequestForm assignment operator called 🔧" << std::endl;
  
  if (this != &rhs) {
    this->_target = rhs._target;
  }

  return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (!this->getIsSigned()) {
    throw AForm::FormIsNotSignedException();
  }

  if (executor.getGrade() > this->getGradeToExec()) {
    throw AForm::GradeTooLowException();
  }

  std::cout
    << "📄🎖️  "
    << this->_target
    << " has been pardoned by Zaphod Beeblebrox"
    << std::endl;
}
