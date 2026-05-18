/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:18:03 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/18 21:51:22 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contacts.hpp"

class PhoneBook {
	private:
		Contact cont[8];
	public:
		void	addCmd();
		void	searchCmd();
		void	exitCmd();
};