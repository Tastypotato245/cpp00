/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:12:13 by kyusulee          #+#    #+#             */
/*   Updated: 2024/08/16 16:15:32 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (true)
	{
		std::cout<<"Input Number [ 1. ADD | 2. SEARCH | 3. EXIT ]: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cin.clear();
			clearerr(stdin);
		}
		if (input == "1")
			phonebook.AddContact();
		else if (input == "2")
			phonebook.SearchContact();
		else if (input == "3")
			phonebook.ExitProgram();
		else
			std::cout<<" * WRONG INPUT * \n"<<std::endl;
	}
	return (0);
}
