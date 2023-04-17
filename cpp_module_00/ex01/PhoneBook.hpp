/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:17:47 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/17 19:56:35 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define MAX_CONTACTS 3
# define LAST (MAX_CONTACTS - 1)
# define NUM_FIELDS 5

# include <iostream>
# include <string>

# include "Contact.hpp"

class PhoneBook
{

	private:

		int		_index;
		int		_length;
		Contact _contacts[MAX_CONTACTS];
		
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;

		void _printAllContacts(void) const;

		void _requestAllFields(void);
		void _requestField(std::string prompt, std::string &fieldStorage);
		void _createNewContact(void);
		void _updateLastContact(void);
		void _clearFields(void);

	public:

		void add(void);

		PhoneBook(void);
		~PhoneBook(void);

};

#endif
