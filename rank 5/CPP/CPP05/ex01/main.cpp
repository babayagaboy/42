/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:28:15 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/10 19:28:15 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat  it( "hugo", 100 );
		Form		contract( "Contract", 100, 50 );
		
		std::cout	<< "before signing: "
					<< it 
					<< std::endl;
		
		it.signForm( contract );
		
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat  it( "hugo", 6 );
		Form		contract( "contract", 5, 1 );
		
		std::cout	<< "before increment: "
					<< contract
					<< "\nb: " << it
					<< std::endl;
		it.signForm( contract );
		
		it.incrementGrade();
		
		std::cout	<< "after increment: "
					<< contract
					<< "\nb: " << it
					<< std::endl;
		it.signForm( contract );
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}