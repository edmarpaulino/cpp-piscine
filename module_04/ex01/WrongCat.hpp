/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 08:34:29 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 18:38:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
public:
  WrongCat(void);
  WrongCat(const WrongCat &rhs);
  ~WrongCat(void);

  WrongCat	&operator=(const WrongCat &rhs);

  void		makeSound(void) const;
};

#endif /* WRONG_CAT_HPP */
