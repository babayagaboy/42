/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:18:03 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/20 16:30:14 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contacts.hpp"

class PhoneBook {
	private:
		Contact _cont[8];
	public:
		void		addCmd(int i);
		void		searchCmd();
		Contact*	getContacts();
};

int			exitCmd();
void		clearScreen();
void		printContactInfo(int index);
int			isstring(std::string str);
int			isnumber(std::string str);
void		waitEnter(std::string str = "");

#endif