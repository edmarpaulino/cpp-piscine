/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:35:55 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/02 21:11:25 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Unnamed"), _grade(1) {
  std::cout << "🏛️  Bureaucrat default constructor called 🔨" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {
  std::cout << "🏛️  Bureaucrat constructor called 🪛" << std::endl;
  if (grade < 1) throw GradeTooHighException();
  if (grade > 150) throw GradeTooLowException();
  this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) {
  std::cout << "🏛️  Bureaucrat copy constructor called 🛠️" << std::endl;
  *this = rhs;
}

Bureaucrat::~Bureaucrat(void) {
  std::cout << "🏛️  Bureaucrat destructor called 💣" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  std::cout << "🏛️  Bureaucrat assignment operator called 🔧" << std::endl;
  if (this != &rhs) {
    const_cast<std::string&>(this->_name) = rhs._name;
    this->_grade = rhs._grade;
  }
  return *this;
}

std::string Bureaucrat::getName(void) const {
  return this->_name;
}

int Bureaucrat::getGrade(void) const {
  return this->_grade;
}

void Bureaucrat::incrementGrade(void) {
  if (this->_grade == 1) throw GradeTooHighException();
  this->_grade--;
}

void Bureaucrat::decrementGrade(void) {
  if (this->_grade == 150) throw GradeTooLowException();
  this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
  return "🏛️  Bureaucrat grade is too high ⬆️ ⚠️";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
  return "🏛️  Bureaucrat grade is too low ⬇️ ⚠️";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs) {
  o << "🏛️  " << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";

  return o;
}
