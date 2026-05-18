/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:17:39 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/18 22:06:55 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

static void clearScreen()
{
	std::cout << "\e[H\e[2J\e[3J";
}

void	addCmd()
{
	std::string fn;
	std::string ln;
	int 		pn;
	std::string ds;

	std::cout << "Enter first name: ";
	std::cin >> fn;
	std::cout << std::endl;

	std::cout << "Enter last name: ";
	std::cin >> ln;
	std::cout << std::endl;

	std::cout << "Enter phone number: ";
	std::cin >> pn;
	std::cout << std::endl;

	std::cout << "Enter darkest secret: ";
	std::cin >> ds;
	std::cout << std::endl;
}

void	searchCmd()
{
	;
}

void	exitCmd()
{
	;
}