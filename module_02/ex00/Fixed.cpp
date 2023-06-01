/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:30:57 by edpaulin          #+#    #+#             */
/*   Updated: 2023/06/01 20:08:22 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;

	return;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = src;

	return;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &src)
	{
		this->_rawBits = src.getRawBits();
	}

	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;

	return;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	this->_rawBits = raw;

	return;
}