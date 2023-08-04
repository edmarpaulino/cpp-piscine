/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:14:10 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/03 20:53:29 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern {
public:
  Intern(void);
  Intern(const Intern &rhs);
  ~Intern(void);

  Intern &operator=(const Intern &rhs);

  AForm *makeForm(const std::string form, const std::string target) const;
  AForm *makeShrubberyCreationForm(const std::string target) const;
  AForm *makeRobotomyRequestForm(const std::string target) const;
  AForm *makePresidentialPardonForm(const std::string target) const;

  class InvalidFormToMake: public std::exception {
  public:
    const char *what(void) const throw();
  };
};

#endif /* INTERN_HPP */
