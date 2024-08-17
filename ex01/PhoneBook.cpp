/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:21:26 by kyusulee          #+#    #+#             */
/*   Updated: 2024/08/17 15:01:53 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

/**
 * @brief IMPLEMENTATION UTIL FUNC
 */

static void	clearCin()
{
	if (std::cin.eof())
	{
		std::cin.clear();
		clearerr(stdin);
	}
}

static int isPrintable(std::string str)
{
	int i;

	i = 0;
	while (str[i])
		if (std::isprint(str[i++]) == 0)
			return (0);
	return (1);
}

static std::string getString(std::string str)
{
	std::string	ret;

	std::cout << str;
	std::getline(std::cin, ret);
	clearCin();
	while (isPrintable(ret) == 0 || ret == "")
	{
		if (ret == "")
			std::cout << "\n";
		std::cout << str;
		std::getline(std::cin, ret);
		clearCin();
	}
	return (ret);
}

/**
 * @brief IMPLEMENTATION OF PRIVATE FUNCTIONS
 */

/**
 * @brief Displays Contacts List
 * @detail Just Print Out all Contacts
 * @param void. Nothing
 * @return void. Nothing
 */
void	PhoneBook::displayContacts()
{
	std::cout << "---------------------------------------------\n";
	std::cout << "|     index|first name| last name|  nickname|\n";
	std::cout << "---------------------------------------------\n";

	for (int i = 0; i < m_size; i++)
	{
		m_contacts[i].DisplayBasic(i + 1);
		std::cout << "---------------------------------------------\n";
	}
}


/**
 * @brief IMPLEMENTATION OF OCCF
 */

PhoneBook::PhoneBook()
{
	m_insert_idx = 0;
	m_size = 0;
}

PhoneBook::~PhoneBook()
{
	// Nothing To Do
}

PhoneBook::PhoneBook(const PhoneBook& phoneBook)
{
	m_insert_idx = phoneBook.m_insert_idx;
	m_size = phoneBook.m_size;
	for (int i = 0 ; i < m_size ; ++i)
		m_contacts[i] = phoneBook.m_contacts[i];
}

PhoneBook& PhoneBook::operator=(const PhoneBook& phoneBook)
{
	m_insert_idx = phoneBook.m_insert_idx;
	m_size = phoneBook.m_size;
	for (int i = 0 ; i < m_size ; ++i)
		m_contacts[i] = phoneBook.m_contacts[i];
	return (*this);
}

/**
 * @brief IMPLEMENTATION OF PUBLIC FUNCTIONS
 */

/**
 * @brief Add New Contact
 * @detail Get User Input And Make New Contact
 * @param void. Nothing
 * @return void. Nothing
 */

void	PhoneBook::AddContact()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	first_name		= getString("Input first name: ");
	last_name		= getString("Input last name: ");
	nickname		= getString("Input nickname: ");
	phone_number	= getString("Input phone number: ");
	darkest_secret	= getString("Input darkest secret: ");

	m_contacts[m_insert_idx] = Contact(
							first_name,
							last_name,
							nickname,
							phone_number,
							darkest_secret
						);
	m_insert_idx = (m_insert_idx + 1) % MAX_SIZE;
	m_size = m_size + ((m_size < MAX_SIZE) ? 1 : 0);
}

/**
 * @brief Displays Contacts List
 * @detail Just Print Out all Contacts
 * @param void. Nothing
 * @return void. Nothing
 */
void	PhoneBook::SearchContact()
{
	std::string	input;
	int			search_idx;

	if (m_size == 0)
	{
		std::cout << " * PHONE BOOK IS EMPTY, ADD CONTACTS * \n";
		return ;
	}

	this->displayContacts();
	while (true)
	{
		std::cout << "Input Index: ";
		std::getline(std::cin, input);
		clearCin();
		if (input == "")
		{
			std::cout << "\n";
			continue;
		}
		search_idx = std::atoi(input.c_str());
		if (search_idx <= m_size && search_idx > 0)
			break;
		else
			std::cout << " * WRONG INDEX * \n";
	}
	m_contacts[search_idx - 1].DisplayDetails();
}

/**
 * @brief Exit Program Function
 * @detail If you need to add some codes when exit, edit this function
 * @param void. Nothing
 * @return void. Nothing
 */
void	PhoneBook::ExitProgram()
{
	std::cout << "BYE.\n";
	exit(0);
}
