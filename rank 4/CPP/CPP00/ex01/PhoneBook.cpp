/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:17:39 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/20 16:28:56 by hgutterr         ###   ########.fr       */
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
	if (!std::getline(std::cin, input))
	{
		std::cin.clear();
		exit(1);
	}
	std::cout << std::endl;

	while (!(isstring(input)) && !input.empty())
	{
		std::cout << "Try again: ";
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			exit(1);
		}
	}
	person.setFirstName(input);

	std::cout << "Enter last name: ";
	if (!std::getline(std::cin, input))
	{
		std::cin.clear();
		exit(1);
	}
	std::cout << std::endl;

	while (!(isstring(input)) && !input.empty())
	{
		std::cout << "Try again: ";
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			exit(1);
		}
	}
	person.setLastName(input);

	std::cout << "Enter nick name: ";
	if (!std::getline(std::cin, input))
	{
		std::cin.clear();
		exit(1);
	}
	std::cout << std::endl;

	while (!(isstring(input)) && !input.empty())
	{
		std::cout << "Try again: ";
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			exit(1);
		}
	}
	person.setNickName(input);

	std::cout << "Enter phone number: ";
	if (!std::getline(std::cin, input))
	{
		std::cin.clear();
		exit(1);
	}
	std::cout << std::endl;

	while (!(isnumber(input)) && !input.empty())
	{
		std::cout << "Try again: ";
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			exit(1);
		}
	}
	person.setPhoneNum(input);

	std::cout << "Enter darkest secret: ";
	if (!std::getline(std::cin, input))
	{
		std::cin.clear();
		exit(1);
	}
	std::cout << std::endl;

	while (!(isstring(input)) && !input.empty())
	{
		std::cout << "Try again: ";
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			exit(1);
		}
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
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			break ;
		}
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