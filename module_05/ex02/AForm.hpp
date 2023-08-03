/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:37:29 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/02 22:53:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
#define A_FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
  AForm(void);
  AForm(std::string name, const int gradeToSign, const int gradeToExec);
  AForm(const AForm &rhs);
  virtual ~AForm(void);

  AForm &operator=(const AForm &rhs);

  std::string getName(void) const;
  bool getIsSigned(void) const;
  int getGradeToSign(void) const;
  int getGradeToExec(void) const;
  std::string getTarget(void) const;

  void beSigned(const Bureaucrat &bureaucrat);

  virtual void execute(const Bureaucrat &executor) const = 0;

  class GradeTooHighException: public std::exception {
  public:
    const char *what(void) const throw();
  };

  class GradeTooLowException: public std::exception {
  public:
    const char *what(void) const throw();
  };

  class FormIsNotSignedException: public std::exception {
  public:
    const char *what(void) const throw();
  };

protected:
  std::string _target;

private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExec;
};

std::ostream &operator<<(std::ostream &o, const AForm &rhs);

#endif /* A_FORM_HPP */
