/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:38:07 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/02 22:55:57 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <cstdlib>
#include <ctime>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm {
public:
  RobotomyRequestForm(void);
  RobotomyRequestForm(const std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &rhs);
  ~RobotomyRequestForm(void);

  RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

  void execute(const Bureaucrat &executor) const;
};

#endif /* ROBOTOMY_REQUEST_FORM_HPP */
