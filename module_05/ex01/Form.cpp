/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:37:34 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/03 21:54:30 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
: _name("Unnamed"), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {
  std::cout << "📄 Form default constructor called 🔨" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
  std::cout << "📄 Form constructor called 🪛" << std::endl;

  if (gradeToSign < 1 || gradeToExec < 1) {
    throw Form::GradeTooHighException();
  }
  
  if (gradeToSign > 150 || gradeToExec > 150) {
    throw Form::GradeTooLowException();
  }
}

Form::Form(const Form &rhs)
: _name("Unnamed"), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {
  std::cout << "📄 Form copy constructor called 🛠️"  << std::endl;

  if (rhs._gradeToSign < 1 || rhs._gradeToExec < 1) {
    throw Form::GradeTooHighException();
  }

  if (rhs._gradeToSign > 150 || rhs._gradeToExec > 150) {
    throw Form::GradeTooLowException();
  }
  
  *this = rhs;
}

Form::~Form(void) {
  std::cout << "📄 Form destructor called 💣" << std::endl;
}

Form &Form::operator=(const Form &rhs) {
  std::cout << "📄 Form assignment operator called 🔧" << std::endl;

  if (rhs._gradeToSign < 1 || rhs._gradeToExec < 1) {
    throw Form::GradeTooHighException();
  }

  if (rhs._gradeToSign > 150 || rhs._gradeToExec > 150) {
    throw Form::GradeTooLowException();
  }

  if (this != &rhs) {
    const_cast<std::string&>(this->_name) = rhs._name;
    this->_isSigned = rhs._isSigned;
    const_cast<int&>(this->_gradeToSign) = rhs._gradeToSign;
    const_cast<int&>(this->_gradeToExec) = rhs._gradeToExec;
  }

  return *this;
}

std::string Form::getName(void) const {
  return this->_name;
}

bool Form::getIsSigned(void) const {
  return this->_isSigned;
}

int Form::getGradeToSign(void) const {
  return this->_gradeToSign;
}

int Form::getGradeToExec(void) const {
  return this->_gradeToExec;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->_gradeToSign) {
    throw Form::GradeTooLowException();
  }

  this->_isSigned = true;
}

const char *Form::GradeTooHighException::what(void) const throw() {
  return "📄 Form grade is too high ⬆️ ⚠️";
}

const char *Form::GradeTooLowException::what(void) const throw() {
  return "📄 Form grade is too low ⬇️ ⚠️";
}

std::ostream &operator<<(std::ostream &o, const Form &rhs) {
  o << "📄 Form - Name: " << rhs.getName()
    << " - Is signed: " << (rhs.getIsSigned() ? "True" : "False")
    << " - Grade request to sign: " << rhs.getGradeToSign()
    << " - Grade request to execute: " << rhs.getGradeToExec();

  return o;
}
