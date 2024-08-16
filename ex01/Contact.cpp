/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:21:43 by kyusulee          #+#    #+#             */
/*   Updated: 2024/08/16 16:18:35 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <iostream>

/**
 * @brief IMPLEMENTATION OF OCCF
 */

/**
 * @brief Default Constructor
 * @detail If you need a Empty Contact (in the future), you can edit this constructor
 * @param void. Nothing
 */
Contact::Contact()
{
	this->m_first_name = "";
	this->m_last_name = "";
	this->m_nickname = "";
	this->m_phone_number = "";
	this->m_darkest_secret = "";
}

/**
 * @brief Destructor
 * @detail If you need to add some codes when the Contact destructor calling, remove the comment and add codes. there is nothing to do right now.
 */
Contact::~Contact()
{
	// Nothing To Do
}

/**
 * @brief Copy Constructor
 */
Contact::Contact(const Contact& contact)
{
	this->m_first_name		= contact.m_first_name;
	this->m_last_name		= contact.m_last_name;
	this->m_nickname		= contact.m_nickname;
	this->m_phone_number	= contact.m_phone_number;
	this->m_darkest_secret	= contact.m_darkest_secret;
}

/**
 * @brief Assign Operator Overloading
 */
Contact&	Contact::operator=(const Contact& contact)
{
	this->m_first_name		= contact.m_first_name;
	this->m_last_name		= contact.m_last_name;
	this->m_nickname		= contact.m_nickname;
	this->m_phone_number	= contact.m_phone_number;
	this->m_darkest_secret	= contact.m_darkest_secret;
	return (*this);
}

/**
 * @brief IMPLEMENTATION OF PUBLIC FUNCTIONS
 */

/**
 * @brief Constructor For Init
 * @param All the member variables' value in Contact class.
 */
Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->m_first_name		= first_name;
	this->m_last_name		= last_name;
	this->m_nickname		= nickname;
	this->m_phone_number	= phone_number;
	this->m_darkest_secret	= darkest_secret;
}

/**
 * @brief Display Basic Infos
 */
void	Contact::DisplayBasic(int idx)
{
	std::string	str_temp;

	std::cout << "|";

	std::cout << std::setw(10) << std::right << idx;
	std::cout << "|";

	str_temp = m_first_name;
	if (m_first_name.length() > 10)
	{
		str_temp = m_first_name.substr(0, 10);
		str_temp[9] = '.';
	}
	std::cout << std::setw(10) << std::right << str_temp;
	std::cout << "|";

	str_temp = m_last_name;
	if (m_last_name.length() > 10)
	{
		str_temp = m_last_name.substr(0, 10);
		str_temp[9] = '.';
	}
	std::cout << std::setw(10) << std::right << str_temp;
	std::cout << "|";

	str_temp = m_nickname;
	if (m_nickname.length() > 10)
	{
		str_temp = m_nickname.substr(0, 10);
		str_temp[9] = '.';
	}
	std::cout << std::setw(10) << std::right << str_temp;
	std::cout << "|";
	std::cout << "\n";
}

/**
 * @brief Display Detail Infos (ALL)
 */
void	Contact::DisplayDetails()
{
	std::cout << " * first name: "		<< m_first_name		<< "\n";
	std::cout << " * last name: "		<< m_last_name		<< "\n";
	std::cout << " * nick name: "		<< m_nickname		<< "\n";
	std::cout << " * phone number: "	<< m_phone_number	<< "\n";
	std::cout << " * darkest secret: "	<< m_darkest_secret	<< "\n";
}
