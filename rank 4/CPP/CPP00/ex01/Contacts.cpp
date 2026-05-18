/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:54:46 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/18 19:54:46 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contacts.hpp"

std::string Contact::getFirstName()
{
	return (this->firstName);
}

std::string Contact::getLastName()
{
	return (this->lastName);
}

int Contact::getPhoneNum()
{
	return (this->phoneNum);
}

std::string Contact::getDarkestSecret()
{
	return (this->darkestSecret);
}

void Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void Contact::setPhoneNum(int phoneNum)
{
	this->phoneNum = phoneNum;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}