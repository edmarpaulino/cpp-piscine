/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:36:19 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/22 20:22:02 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*f)(T const &)) {
  for (size_t i = 0; i < length; i++) {
    f(array[i]);
  }
}

template <typename T>
void printIter(T const &element) {
  std::cout << "🖨️  " << element << std::endl;
}

#endif /* ITER_HPP */
