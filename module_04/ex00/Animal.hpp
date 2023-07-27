/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:41:18 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/27 13:19:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
public:
  Animal(void);
  Animal(std::string type);
  Animal(const Animal &rhs);
  virtual ~Animal(void);

  Animal &operator=(const Animal &rhs);

  std::string getType(void) const;
  virtual void makeSound(void) const;

protected:
  std::string _type;
};

std::ostream &operator<<(std::ostream &o, const Animal &rhs);

#endif /* ANIMAL_HPP */
