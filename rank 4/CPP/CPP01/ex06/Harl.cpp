/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 22:11:58 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/25 22:11:58 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
	std::cout << "Harl constructed" 
	<< std::endl;
}

Harl::~Harl( void )
{
	std::cout << "Harl destroyed" 
	<< std::endl;
}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."
	<< " I really do!"
	<< std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money."
	<< " You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." 
	<< " I’ve been coming for years, whereas you started working here just last month."
	<< std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

void	Harl::complain( std::string level )
{
	void (Harl::*functions[]) ( void ) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string l[] = {
		"debug",
		"info",
		"warning",
		"error"
	};

	for(int i = 0; i < 4; ++i) {
		if (!level.compare(l[i]))
		{
			switch (i)
			{
			case 0:
				(this->*functions[i++])();
				/* fall through */
			case 1:
				(this->*functions[i++])();
				/* fall through */
			case 2:
				(this->*functions[i++])();
				/* fall through */
			case 3:
				(this->*functions[i])();
				return ;
			}
		}
	}
	std::cout 
	<< "cant find " 
	<< "\"" << level << "\""
	<< " comand." 
	<< std::endl;
}