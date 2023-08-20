/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 10:22:10 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 10:40:23 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

class Data;

class Serializer {
public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);

private:
  Serializer(void);
  Serializer(const Serializer &rhs);
  ~Serializer(void);

  Serializer &operator=(const Serializer &rhs);
};

#endif /* SERIALIZER_HPP */
