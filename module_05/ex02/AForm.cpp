/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:37:34 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/02 21:30:10 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void)
: _name("Unnamed"), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {
  std::cout << "📄 AForm default constructor called 🔨" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
  std::cout << "📄 AForm constructor called 🪛" << std::endl;

  if (gradeToSign < 1 || gradeToExec < 1) {
    throw AForm::GradeTooHighException();
  }
  
  if (gradeToSign > 150 || gradeToExec > 150) {
    throw AForm::GradeTooLowException();
  }
}

AForm::AForm(const AForm &rhs)
: _name("Unnamed"), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {
  std::cout << "📄 AForm copy constructor called 🛠️"  << std::endl;

  if (rhs._gradeToSign < 1 || rhs._gradeToExec < 1) {
    throw AForm::GradeTooHighException();
  }

  if (rhs._gradeToSign > 150 || rhs._gradeToExec > 150) {
    throw AForm::GradeTooLowException();
  }
  
  *this = rhs;
}

AForm::~AForm(void) {
  std::cout << "📄 AForm destructor called 💣" << std::endl;
}

AForm &AForm::operator=(const AForm &rhs) {
  std::cout << "📄 AForm assignment operator called 🔧" << std::endl;

  if (rhs._gradeToSign < 1 || rhs._gradeToExec < 1) {
    throw AForm::GradeTooHighException();
  }

  if (rhs._gradeToSign > 150 || rhs._gradeToExec > 150) {
    throw AForm::GradeTooLowException();
  }

  if (this != &rhs) {
    const_cast<std::string&>(this->_name) = rhs._name;
    this->_isSigned = rhs._isSigned;
    const_cast<int&>(this->_gradeToSign) = rhs._gradeToSign;
    const_cast<int&>(this->_gradeToExec) = rhs._gradeToExec;
  }

  return *this;
}

std::string AForm::getName(void) const {
  return this->_name;
}

bool AForm::getIsSigned(void) const {
  return this->_isSigned;
}

int AForm::getGradeToSign(void) const {
  return this->_gradeToSign;
}

int AForm::getGradeToExec(void) const {
  return this->_gradeToExec;
}

std::string AForm::getTarget(void) const {
  return this->_target;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->_gradeToSign) {
    throw AForm::GradeTooLowException();
  }

  this->_isSigned = true;
}

const char *AForm::GradeTooHighException::what(void) const throw() {
  return "📄 AForm grade is too high ⬆️ ⚠️";
}

const char *AForm::GradeTooLowException::what(void) const throw() {
  return "📄 AForm grade is too low ⬇️ ⚠️";
}

const char *AForm::FormIsNotSignedException::what(void) const throw() {
  return "📄 AForm is not signed ✒️ ⚠️";
}

std::ostream &operator<<(std::ostream &o, const AForm &rhs) {
  o << "📄 AForm - Name: " << rhs.getName()
    << " - Is signed: " << (rhs.getIsSigned() ? "True" : "False")
    << " - Grade request to sign: " << rhs.getGradeToSign()
    << " - Grade request to execute: " << rhs.getGradeToExec();

  return o;
}
