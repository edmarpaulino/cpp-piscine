/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 08:25:39 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 18:38:02 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>
#include <string>

class WrongAnimal {
public:
  WrongAnimal(void);
  WrongAnimal(std::string type);
  WrongAnimal(const WrongAnimal &rhs);
  virtual ~WrongAnimal(void);

  WrongAnimal	&operator=(const WrongAnimal &rhs);

  std::string	getType(void) const;  
  void		makeSound(void) const;

protected:
  std::string	_type;
};

std::ostream &operator<<(std::ostream &o, const WrongAnimal &rhs);

#endif /* WRONG_ANIMAL_HPP */
