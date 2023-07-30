/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:47:48 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 20:50:10 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {
public:
  Cat(void);
  Cat(const Cat &rhs);
  ~Cat(void);

  Cat &operator=(const Cat &rhs);

  void makeSound(void) const;
};

#endif /* CAT_HPP */
