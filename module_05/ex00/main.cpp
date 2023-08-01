/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:32:28 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/31 22:38:07 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void printPenSeparator(void);

int main(void) {
  printPenSeparator();

  try {
    Bureaucrat howard("Howard Hamlim", -1);
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  printPenSeparator();

  try {
    Bureaucrat chuck("Chuck McGill", 151);
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  printPenSeparator();

  try {
    Bureaucrat saul("Saul Goodman", 2);
    std::cout << saul << std::endl;
    saul.incrementGrade();
    std::cout << saul << std::endl;
    saul.incrementGrade();
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  
  printPenSeparator();

  try {
    Bureaucrat kim("Kim Wexler", 149);
    std::cout << kim << std::endl;
    kim.decrementGrade();
    std::cout << kim << std::endl;
    kim.decrementGrade();
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
    << std::endl
    << std::endl;
}
