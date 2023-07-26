/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:23:23 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/25 21:29:24 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed &rhs);
		Fixed &operator=(const Fixed &rhs);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int _rawBits;
		static const int _nbFractBits = 8;
};

#endif // FIXED_H
