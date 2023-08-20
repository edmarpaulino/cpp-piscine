/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 10:16:58 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 10:46:18 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {
  Data *data = new Data("Hello World!");

  std::cout << "🎲 Data content before serialization: " << data->getContent() << std::endl;

  uintptr_t raw = Serializer::serialize(data);

  std::cout << "🪄  Serialized data: " << raw << std::endl;

  Data *deserialized = Serializer::deserialize(raw);

  std::cout << "🎲 Data content after deserialization: " << deserialized->getContent() << std::endl;

  delete deserialized;

  return 0;
}
