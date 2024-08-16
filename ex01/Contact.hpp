/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:21:36 by kyusulee          #+#    #+#             */
/*   Updated: 2024/08/16 16:18:36 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	private:
		std::string m_first_name;
		std::string m_last_name;
		std::string m_nickname;
		std::string m_phone_number;
		std::string m_darkest_secret;

	public:
		// OCCF
		Contact();									// Constructor
		~Contact();									// Destructor
		Contact(const Contact &contact);			// Copy Constructor
		Contact& operator=(const Contact &contact);	// Assign Operator Overloading
		
		// Public Functions
		Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
		void DisplayBasic(int i);
		void DisplayDetails();

};

#endif
