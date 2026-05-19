/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:17:39 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/19 20:00:59 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"

Contact PhoneBook::getContact(int index) {
	return (cont[index]);
}

void	addCmd(PhoneBook &phonebook, int i)
{
	clearScreen();
	std::string input;

	std::cout << "Enter first name: ";
	getline(std::cin, input);
	std::cout << std::endl;

	while (!(isstring(input)))
	{
		std::cout << "Try again: ";
		getline(std::cin, input);
	}
	phonebook.getContact(i).setFirstName(input);

	std::cout << "Enter last name: ";
	getline(std::cin, input);
	std::cout << std::endl;

	while (!(isstring(input)))
	{
		std::cout << "Try again: ";
		getline(std::cin, input);
	}
	phonebook.getContact(i).setLastName(input);

	std::cout << "Enter nick name: ";
	getline(std::cin, input);
	std::cout << std::endl;

	while (!(isstring(input)))
	{
		std::cout << "Try again: ";
		getline(std::cin, input);
	}
	phonebook.getContact(i).setNickName(input);

	std::cout << "Enter phone number: ";
	getline(std::cin, input);
	std::cout << std::endl;

	while (!(isnumber(input)))
	{
		std::cout << "Try again: ";
		getline(std::cin, input);
	}
	phonebook.getContact(i).setPhoneNum(std::atoi(input.c_str()));

	std::cout << "Enter darkest secret: ";
	getline(std::cin, input);
	std::cout << std::endl;
	phonebook.getContact(i).setDarkestSecret(input);
	waitEnter("Successfully added contact to phonebook...");
}

void	searchCmd(PhoneBook &phonebook)
{
	std::cout << "INDEX"     << "|";
	std::cout << "NAME"      << "|";
	std::cout << "LAST NAME" << "|";
	std::cout << "NICK NAME" << "|" << std::endl;

	std::setw(10);
	std::right;
	for (int n = 0; n < 8; ++n) {
		std::cout << n << "|";
		std::cout << phonebook.getContact(n).getFirstName() << "|";
		std::cout << phonebook.getContact(n).getLastName()<< "|";
		std::cout << phonebook.getContact(n).getNickName() << std::endl;
	}
	waitEnter();
}

int	exitCmd() 
{
	std::cout << "Exiting program..." << std::endl;
	return (1);
}