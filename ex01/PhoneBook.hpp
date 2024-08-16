/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:21:31 by kyusulee          #+#    #+#             */
/*   Updated: 2024/08/16 16:14:52 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

/**
 * @brief Size Of PhoneBook
 * @detail 1 <= MAX_SIZE <= INT_MAX - 1
 */
const int MAX_SIZE = 8;

class	PhoneBook
{
	private:
		Contact	m_contacts[MAX_SIZE];
		int		m_insert_idx;
		int		m_size;

		void	displayContacts();

	public:
		PhoneBook();
		~PhoneBook();
		PhoneBook(const PhoneBook& phoneBook);
		PhoneBook& operator=(const PhoneBook& phoneBook);
		void	AddContact();
		void	SearchContact();
		void	ExitProgram();
};

#endif
