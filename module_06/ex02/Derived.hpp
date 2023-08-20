/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Derived.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 10:57:14 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 11:17:47 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DERIVED_HPP
# define DERIVED_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif /* DERIVED_HPP */
