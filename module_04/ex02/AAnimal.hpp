/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:41:18 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 21:04:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
public:
  AAnimal(void);
  AAnimal(std::string type);
  AAnimal(const AAnimal &rhs);
  virtual ~AAnimal(void);

  AAnimal &operator=(const AAnimal &rhs);

  std::string getType(void) const;
  virtual void makeSound(void) const = 0;

protected:
  std::string _type;
};

std::ostream &operator<<(std::ostream &o, const AAnimal &rhs);

#endif /* AANIMAL_HPP */
