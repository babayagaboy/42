/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:18:03 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/19 19:59:34 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contacts.hpp"

class PhoneBook {
	private:
		Contact cont[8];
	public:
		Contact getContact(int index);
};

void	addCmd(PhoneBook &phonebook, int i);
void	searchCmd(PhoneBook &phonebook);
int		exitCmd();

void	clearScreen();
int		isstring(std::string str);
int		isnumber(std::string str);
void	waitEnter(std::string str = "");