/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:20:08 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/24 15:20:08 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	try
		{
			Bureaucrat boss("Boss", 1);
			Intern intern;
			AForm* form;

			std::cout << "trying to create shrubbery form" << std::endl;
			form = intern.makeForm("shrubbery creation", "Bender");
			if (form)
			{
				boss.signForm(*form);
				boss.executeForm(*form);
				delete form;
			}

			std::cout << "trying to create robotomy request" << std::endl;
			form = intern.makeForm("robotomy request", "Wall-E");
			if (form)
			{
				boss.signForm(*form);
				boss.executeForm(*form);
				delete form;
			}
			std::cout << "trying to create presidential pardon" << std::endl;
			form = intern.makeForm("presidential pardon", "Marvin");
			if (form)
			{
				boss.signForm(*form);
				boss.executeForm(*form);
				delete form;
			}

			std::cout << "trying to create an invalid form" << std::endl;
			form = intern.makeForm("coffee request", "Boss");
			if (form)
			{
				delete form;
			}
		}
		catch (std::exception const &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		return 0;
}