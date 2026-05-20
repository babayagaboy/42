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

std::string Contact::getFirstName() {
	return (this->_firstName);
}

std::string Contact::getLastName() {
	return (this->_lastName);
}

std::string Contact::getNickName() {
	return (this->_nickName);
}

std::string Contact::getPhoneNum() {
	return (this->_phoneNum);
}

std::string Contact::getDarkestSecret() {
	return (this->_darkestSecret);
}

void Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

void Contact::setNickName(std::string nickName) {
	this->_nickName = nickName;
}

void Contact::setPhoneNum(std::string phoneNum) {
	this->_phoneNum = phoneNum;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}

void	Contact::printContactInfo()
{
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nick Name: " << this->_nickName << std::endl;
	std::cout << "Phone Number: " << this->_phoneNum << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}