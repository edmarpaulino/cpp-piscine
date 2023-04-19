/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:17:47 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/18 21:26:58 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define MAX_CONTACTS 3
# define LAST (MAX_CONTACTS - 1)
# define WIDTH 10
# define SPACE ' '

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>

# include "Contact.hpp"

class PhoneBook
{

	public:

		void add(void);
		void search(void) const;

		PhoneBook(void);
		~PhoneBook(void);

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
		void _requestField(std::string prompt, std::string& fieldStorage);
		void _createNewContact(void);
		void _updateLastContact(void);
		void _printSearch(void) const;
		void _printHeader(void) const;
		void _printRow(int index) const;
		void _printFooter(void) const;
		void _truncateString(std::string& str) const;
		int _validateSearchIndex(std::string searchIndex) const;
		void _clearFields(void);
};

#endif
