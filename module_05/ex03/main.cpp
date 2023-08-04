/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:32:28 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/03 21:44:32 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"

static void printPenSeparator(void);

int main(void) {
  Intern someRandomIntern;

  printPenSeparator();

  try {
    AForm *form = someRandomIntern.makeForm("shrubbery creation", "Albuquerque");

    if (form->getFormType() != "ShrubberyCreationForm") {
      delete form;
      throw std::runtime_error("❌ Invalid form ❌");
    }

    std::cout << "✅ Valid form ✅" << std::endl;
    delete form;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  printPenSeparator();
  
  try {
    AForm *form = someRandomIntern.makeForm("robotomy request", "Heisenberg");

    if (form->getFormType() != "RobotomyRequestForm") {
      delete form;
      throw std::runtime_error("❌ Invalid form ❌");
    }

    std::cout << "✅ Valid form ✅" << std::endl;
    delete form;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  printPenSeparator();
  
  try {
    AForm *form = someRandomIntern.makeForm("presidential pardon", "Jesse Pinkman");

    if (form->getFormType() != "PresidentialPardonForm") {
      delete form;
      throw std::runtime_error("❌ Invalid form ❌");
    }

    std::cout << "✅ Valid form ✅" << std::endl;
    delete form;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  printPenSeparator();
  
  try {
    AForm *form = someRandomIntern.makeForm("voices in my head", "Far Far Away");

    if (form) {
      delete form;
      throw std::runtime_error("❌ Invalid form ❌");
    }
    
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  
  printPenSeparator();
  
  return 0;
}

static void printPenSeparator(void) {
  std::cout
    << std::endl
    << "🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ "
    << "✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️"
    << "🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ "
    << "✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️"
    << std::endl
    << std::endl;
}
