/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 10:22:59 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 10:42:30 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &rhs) {
  *this = rhs;
}

Serializer::~Serializer(void) {}

Serializer &Serializer::operator=(const Serializer &rhs) {
  if (this != &rhs) {
    return (*this);
  }
  
  return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
  return (reinterpret_cast<Data*>(raw));
}
