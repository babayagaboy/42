/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:17:39 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/20 15:37:49 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "PhoneBook.hpp"

inline void printvalue(std::string str)
{
	if (str.length() <= 10)
	{
		std::cout.width(10);
		std::cout << str << "|";
	}
	else
	{
		std::setw(10);
		for (int j = 0; j < 9; ++j) {
			std::cout << str[j];
		}
		std::cout << ".|";
	}
}

void	PhoneBook::addCmd(int i)
{
	Contact person;

	clearScreen();
	std::string input;

	std::cout << "Enter first name: ";
	getline(std::cin, input);
	std::cout << std::endl;

	while (!(isstring(input)) && !input.empty())
	{
		std::cout << "Try again: ";
		getline(std::cin, input);
	}
	person.setFirstName(input);

	std::cout << "Enter last name: ";
	getline(std::cin, input);
	std::cout << std::endl;

	while (!(isstring(input)) && !input.empty())
	{
		std::cout << "Try again: ";
		getline(std::cin, input);
	}
	person.setLastName(input);

	std::cout << "Enter nick name: ";
	getline(std::cin, input);
	std::cout << std::endl;

	while (!(isstring(input)) && !input.empty())
	{
		std::cout << "Try again: ";
		getline(std::cin, input);
	}
	person.setNickName(input);

	std::cout << "Enter phone number: ";
	getline(std::cin, input);
	std::cout << std::endl;

	while (!(isnumber(input)) && !input.empty())
	{
		std::cout << "Try again: ";
		getline(std::cin, input);
	}
	person.setPhoneNum(input);

	std::cout << "Enter darkest secret: ";
	getline(std::cin, input);
	std::cout << std::endl;

	while (!(isstring(input)) && !input.empty())
	{
		std::cout << "Try again: ";
		getline(std::cin, input);
	}
	person.setDarkestSecret(input);
	waitEnter("Successfully added contact to phonebook...");
	_cont[i] = person;
}

void	PhoneBook::searchCmd()
{
	std::string input;
	int exit = 0;

	while (!exit)
	{
		clearScreen();
		printvalue("INDEX");
		printvalue("FIRST NAME");
		printvalue("LAST NAME");
		printvalue("NICK NAME");
		std::cout << std::endl;
		for (int n = 0; n < 8; ++n) {
			std::cout.width(10);
			std::cout << n << "|";
			printvalue(_cont[n].getFirstName());
			printvalue(_cont[n].getLastName());
			printvalue(_cont[n].getNickName());
			std::cout << std::endl;
		}
		std::cout << "Enter an index to expand (or exit to leave): ";
		getline(std::cin, input);
		if (!input.compare("EXIT") || !input.compare("exit"))
			exit = 1;
		else if (!input.empty() && (input.find_first_not_of("0123456789") == std::string::npos))
		{
			_cont[std::atoi(input.c_str())].printContactInfo();
			waitEnter();
		}
	}
}

int	exitCmd() 
{
	std::cout << "Exiting program..." << std::endl;
	return (1);
}