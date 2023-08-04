/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:32:28 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/03 21:45:06 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void testForm(AForm *form, Bureaucrat *can, Bureaucrat *cant);
static void printPenSeparator(void);
static void printLineSeparator(void);

int main(void) {
  printPenSeparator();
  
  {
    ShrubberyCreationForm form("Albuquerque");
    Bureaucrat kim("Kim Wexler", 137);
    Bureaucrat saul("Saul Goodman", 146);
    testForm(&form, &kim, &saul);
  }
  
  printPenSeparator();
  
  {
    RobotomyRequestForm form("Heisenberg");
    Bureaucrat kim("Kim Wexler", 45);
    Bureaucrat saul("Saul Goodman", 73);
    testForm(&form, &kim, &saul);
  }
  
  printPenSeparator();
  
  {
    PresidentialPardonForm form("Jesse Pinkman");
    Bureaucrat kim("Kim Wexler", 1);
    Bureaucrat saul("Saul Goodman", 150);
    testForm(&form, &kim, &saul);
  }
  
  printPenSeparator();
  
  return 0;
}

static void testForm(AForm *form, Bureaucrat *can, Bureaucrat *cant) {
  printLineSeparator();

  // can execute - without sign
  try {
    can->executeForm(*form);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  printLineSeparator();

  // can't sign
  try {
    cant->signForm(*form);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  printLineSeparator();
  
  // can sign
  try {
    can->signForm(*form);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  printLineSeparator();

  // can't execute
  try {
    cant->executeForm(*form);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  printLineSeparator();
  
  // can execute
  try {
    can->executeForm(*form);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  
  printLineSeparator();
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

static void printLineSeparator(void) {
  std::cout << std::endl;
}
