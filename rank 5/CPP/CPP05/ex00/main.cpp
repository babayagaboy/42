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

int main()
{
	try
	{
		Bureaucrat it("hugo", 3);
		std::cout << it << std::endl;
		it.incrementGrade();
		std::cout << it << std::endl;
		it.incrementGrade();
		std::cout << it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try 
	{
		Bureaucrat it("hugo", 200);
		std::cout << it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat it("hugo", 149);
		std::cout << it << std::endl;
		it.decrementGrade();
		it.decrementGrade();
		std::cout << it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}