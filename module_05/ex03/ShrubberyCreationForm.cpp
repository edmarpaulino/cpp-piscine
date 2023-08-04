/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:38:04 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/03 22:03:16 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("ShrubberyCreationForm", 145, 137) {
  std::cout << "📄🌳 ShrubberyCreationForm default constructor called 🔨" << std::endl;
  
  this->_target = "Unknown";
  this->_formType = "ShrubberyCreationForm";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
: AForm("ShrubberyCreationForm", 145, 137) {
  std::cout << "📄🌳 ShrubberyCreationForm constructor called 🪛" << std::endl;
  
  this->_target = target;
  this->_formType = "ShrubberyCreationForm";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
: AForm(rhs) {
  std::cout << "📄🌳 ShrubberyCreationForm copy constructor called 🛠️"  << std::endl;
  
  *this = rhs;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
  std::cout << "📄🌳 ShrubberyCreationForm destructor called 💣" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
  std::cout << "📄🌳 ShrubberyCreationForm assignment operator called 🔧" << std::endl;
  
  if (this != &rhs) {
    this->_target = rhs._target;
  }

  return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  if (!this->getIsSigned()) {
    throw AForm::FormIsNotSignedException();
  }

  if (executor.getGrade() > this->getGradeToExec()) {
    throw AForm::GradeTooLowException();
  }
  
  std::string filename = this->_target + "_shrubbery";
  std::ofstream file;

  file.open(filename.c_str());

  if (!file.is_open()) {
    throw std::runtime_error("Unable to open " + filename + ".");
  }

  file 
    << "       _-_" << std::endl
    << "    /~~   ~~\\" << std::endl
    << " /~~         ~~\\" << std::endl
    << "{               }" << std::endl
    << " \\  _-     -_  /" << std::endl
    << "   ~  \\\\ //  ~" << std::endl
    << "_- -   | | _- _" << std::endl
    << "  _ -  | |   -_" << std::endl
    << "      // \\\\" << std::endl;

  file.close();
}
