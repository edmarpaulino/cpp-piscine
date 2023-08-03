/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:32:28 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/02 21:00:10 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void printPenSeparator(void);

int main(void) {
  printPenSeparator();

  try {
    Bureaucrat howard("Howard Hamlim", 100);
    Form dayReport("Day Report", -1, -1);
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  printPenSeparator();

  try {
    Bureaucrat chuck("Chuck McGill", 100);
    Form weekReport("Week Report", 151, 151);
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  
  printPenSeparator();

  try {
    Bureaucrat saul("Saul Goodman", 100);
    Form annualReport("Annual Report", 99, 100);
    std::cout << annualReport << std::endl;
    saul.signForm(annualReport);
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  
  printPenSeparator();

  try {
    Bureaucrat kim("Kim Wexler", 1);
    Form monthlyReport("Monthly Report", 1, 1);
    std::cout << monthlyReport << std::endl;
    kim.signForm(monthlyReport);
    std::cout << monthlyReport << std::endl;
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
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
    << "✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️ 🖋️ ✒️🖋️ ✒️🖋️ ✒️"
    << std::endl
    << std::endl;
}
