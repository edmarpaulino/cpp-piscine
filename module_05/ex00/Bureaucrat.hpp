/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:35:53 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/31 22:23:40 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
public:
  Bureaucrat(void);
  Bureaucrat(const std::string name, int grade);
  Bureaucrat(const Bureaucrat &rhs);
  ~Bureaucrat(void);

  Bureaucrat &operator=(const Bureaucrat &rhs);

  std::string getName(void) const;
  int getGrade(void) const;

  void incrementGrade(void);
  void decrementGrade(void);

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
  int _grade;
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif /* BUREAUCRAT_HPP */
