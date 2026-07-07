/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:00:07 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/23 16:00:07 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool 				_isSigned;
	public:

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		Form( void );
		Form( std::string name , int gradeToSign, int gradeToExec );
		Form( const Form& other );
		Form& operator=( const Form& other );
		~Form( void );

		std::string	getName( void ) const;
		bool		getIsSigned( void ) const;
		int			getGradeToSign( void ) const;
		int			getGradeToExec( void ) const;

		void		beSigned( Bureaucrat& b );
};

std::ostream& operator<<( std::ostream &o, const Form &form );

#endif