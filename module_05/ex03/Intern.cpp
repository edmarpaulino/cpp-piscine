/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:14:13 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/03 22:01:59 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
  std::cout << "🧟 Intern default constructor called 🔨" << std::endl;
}

Intern::Intern(const Intern &rhs) {
  std::cout << "🧟 Intern copy constructor called 🛠️"  << std::endl;

  *this = rhs;
}

Intern::~Intern(void) {
  std::cout << "🧟 Intern destructor called 💣" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs) {
  std::cout << "🧟 Intern assignment operator called 🔧" << std::endl;

  (void)rhs;
  
  return *this;
}

AForm *Intern::makeForm(const std::string form, const std::string target) const {
  const std::string forms[] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
  };

  AForm *(Intern::*methods[])(const std::string target) const = {
    &Intern::makeShrubberyCreationForm,
    &Intern::makeRobotomyRequestForm,
    &Intern::makePresidentialPardonForm
  };

  for (unsigned int i = 0; i < 3; i++) {
    if (forms[i].compare(form) == 0) {
      return (this->*methods[i])(target);
    }
  }

  throw Intern::InvalidFormToMake();
}

AForm *Intern::makeShrubberyCreationForm(const std::string target) const {
  std::cout << "🧟 Intern creates 📄🌳 ShrubberyCreationForm" << std::endl;
  
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string target) const {
  std::cout << "🧟 Intern creates 📄🤖 RobotomyRequestForm" << std::endl;
  
  return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string target) const {
  std::cout << "🧟 Intern creates 📄🎖️  PresidentialPardonForm" << std::endl;
  
  return new PresidentialPardonForm(target);
}

const char *Intern::InvalidFormToMake::what(void) const throw() {
  return "🧟 Intern receive an invalid form to make ⚠️";
}
