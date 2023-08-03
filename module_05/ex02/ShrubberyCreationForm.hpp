/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:38:02 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/02 22:05:15 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <fstream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm {
public:
  ShrubberyCreationForm(void);
  ShrubberyCreationForm(const std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
  ~ShrubberyCreationForm(void);

  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

  void execute(const Bureaucrat &executor) const;
};

#endif /* SHRUBBERY_CREATION_FORM_HPP */
