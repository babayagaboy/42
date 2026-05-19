/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:51:00 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/19 17:07:23 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int isstring(std::string str)
{
	for (int i = 0; str[i]; ++i) {
		if (!(std::isalpha(static_cast<int>(str[i]))))
			return (0);
	}
	return (1);
}

int isnumber(std::string str)
{
	for (int i = 0; str[i]; ++i) {
		if (!(std::isdigit(static_cast<int>(str[i]))))
			return (0);
	}
	return (1);
}

void waitEnter(std::string str)
{
	if (!str.empty())
		std::cout << str << std::endl;
	std::string temp;
	getline(std::cin, temp);
	temp.clear();
	return ;
}

void clearScreen() {
	std::cout << "\e[H\e[2J\e[3J";
}