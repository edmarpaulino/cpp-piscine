/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:39:08 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 20:59:25 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal {
public:
  Dog(void);
  Dog(const Dog &rhs);
  ~Dog(void);

  Dog &operator=(const Dog &rhs);

  void makeSound(void) const;
  Brain *getBrain(void) const;

private:
  Brain *_brain;
};

#endif /* DOG_HPP */
