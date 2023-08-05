/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:14:10 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/04 21:31:33 by edpaulin         ###   ########.fr       */
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

  class InvalidFormToMake: public std::exception {
  public:
    const char *what(void) const throw();
  };

private:
  AForm *_makeShrubberyCreationForm(const std::string target) const;
  AForm *_makeRobotomyRequestForm(const std::string target) const;
  AForm *_makePresidentialPardonForm(const std::string target) const;
};

#endif /* INTERN_HPP */
