/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:38:13 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/02 22:53:15 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm {
public:
  PresidentialPardonForm(void);
  PresidentialPardonForm(const std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &rhs);
  ~PresidentialPardonForm(void);

  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

  void execute(const Bureaucrat &executor) const;
};

#endif /* PRESIDENTIAL_PARDON_FORM_HPP */
