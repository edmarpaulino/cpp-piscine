/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:17:47 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/16 17:58:59 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define MAX_CONTACTS 8

# include "Contact.hpp"

class PhoneBook
{

	private:

		int		_index;
		Contact _contacts[MAX_CONTACTS];

	public:

		PhoneBook(void);
		~PhoneBook(void);

};

#endif
