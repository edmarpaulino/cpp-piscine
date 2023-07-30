/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:47:48 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 20:34:51 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
public:
  Cat(void);
  Cat(const Cat &rhs);
  ~Cat(void);

  Cat &operator=(const Cat &rhs);

  void makeSound(void) const;
  Brain *getBrain(void) const;

private:
  Brain *_brain;
};

#endif /* CAT_HPP */
