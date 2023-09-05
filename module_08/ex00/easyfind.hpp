/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:30:23 by edpaulin          #+#    #+#             */
/*   Updated: 2023/09/05 18:38:53 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
  typename T::iterator result = std::find(container.begin(), container.end(), value);
  if (result == container.end()) {
    throw std::runtime_error("value not found");
  }
  return result;
}

#endif /* EASYFIND_HPP */
