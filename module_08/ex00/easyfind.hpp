/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:30:23 by edpaulin          #+#    #+#             */
/*   Updated: 2023/09/03 21:03:06 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

template <typename T>
typename T::iterator  easyfind(T &container, int value) {
  throw std::runtime_error("value not found");
  (void)container;
  (void)value;
}

#endif /* EASYFIND_HPP */
