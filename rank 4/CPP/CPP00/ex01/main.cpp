/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:54:42 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/18 19:54:42 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
	int exit = 0;
	std::string input;
	int index = 0;
	PhoneBook phonebook;

	while (!exit)
	{
		clearScreen();
		std::cout << "Enter a comand: ADD; SEARCH; EXIT." << std::endl;
		std::cout << "-> ";
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			break ;
		}
		else if (!input.compare("ADD"))
			phonebook.addCmd(index++);
		else if (!input.compare("SEARCH"))
			phonebook.searchCmd();
		else if (!input.compare("EXIT"))
			exit = exitCmd();
		else
			waitEnter("Wrong comand...");
		index = index % 8;
	}
}