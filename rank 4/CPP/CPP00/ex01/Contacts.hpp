/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:54:45 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/18 19:54:45 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		int 		phoneNum;
		std::string	darkestSecret;
	public:
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		int			getPhoneNum();
		std::string	getDarkestSecret();
	
		void	setFirstName(std::string firstName);
		void	setLastName(std::string lastName);
		void	setNickName(std::string nickName);
		void	setPhoneNum(int phoneNum);
		void	setDarkestSecret(std::string darkestSecret);
};