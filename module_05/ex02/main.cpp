/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:32:28 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/02 23:02:18 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void printPenSeparator(void);

int main(void) {
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
