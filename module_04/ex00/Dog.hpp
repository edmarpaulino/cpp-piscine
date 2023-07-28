/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:39:08 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/27 21:14:08 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal {
public:
  Dog(void);
  Dog(const Dog &rhs);
  virtual ~Dog(void);

  Dog &operator=(const Dog &rhs);

  virtual void makeSound(void) const;
};

#endif /* DOG_HPP */
