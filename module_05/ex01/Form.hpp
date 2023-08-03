/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:37:29 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/02 21:08:38 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
  Form(void);
  Form(std::string name, const int gradeToSign, const int gradeToExec);
  Form(const Form &rhs);
  ~Form(void);

  Form &operator=(const Form &rhs);

  std::string getName(void) const;
  bool getIsSigned(void) const;
  int getGradeToSign(void) const;
  int getGradeToExec(void) const;

  void beSigned(const Bureaucrat &bureaucrat);

  class GradeTooHighException: public std::exception {
  public:
    const char *what(void) const throw();
  };

  class GradeTooLowException: public std::exception {
  public:
    const char *what(void) const throw();
  };

private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExec;
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif /* FORM_HPP */
