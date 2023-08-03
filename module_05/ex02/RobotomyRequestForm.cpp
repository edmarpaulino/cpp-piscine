/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:38:10 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/02 23:00:47 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
: AForm("RobotomyRequestForm", 72, 45) {
  std::cout << "📄🤖 RobotomyRequestForm default constructor called 🔨" << std::endl;
  this->_target = "Unknown";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
: AForm("RobotomyRequestForm", 72, 45) {
  std::cout << "📄🤖 RobotomyRequestForm constructor called 🪛" << std::endl;
  this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs)
: AForm(rhs) {
  std::cout << "📄🤖 RobotomyRequestForm copy constructor called 🛠️"  << std::endl;
  *this = rhs;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
  std::cout << "📄🤖 RobotomyRequestForm destructor called 💣" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
  std::cout << "📄🤖 RobotomyRequestForm assignment operator called 🔧" << std::endl;
  
  if (this != &rhs) {
    this->_target = rhs._target;
  }

  return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  if (!this->getIsSigned()) {
    throw AForm::FormIsNotSignedException();
  }

  if (executor.getGrade() > this->getGradeToExec()) {
    throw AForm::GradeTooLowException();
  }

  std::srand(std::time(0));
  int wasRobotomized = std::rand() % 2;

  std::cout << "📄🤖 Zzzzzzzzzzzzzzzzzzzzzzzz " << this->_target;
  if (wasRobotomized) {
    std::cout << " was robotomized";
  } else {
    std::cout << " was not robotomized";
  }
  std::cout << " zzzzzzzzzzzzzzzzzzzzzzzzZ" << std::endl;
}
