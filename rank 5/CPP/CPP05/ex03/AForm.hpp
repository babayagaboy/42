/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:34:27 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/07 16:01:28 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
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

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		AForm( void );
		AForm( std::string name , int gradeToSign, int gradeToExec );
		AForm( const AForm& other );
		AForm& operator=( const AForm& other );
		virtual ~AForm( void ) = 0;

		std::string	getName( void ) const;
		bool		getIsSigned( void ) const;
		int			getGradeToSign( void ) const;
		int			getGradeToExec( void ) const;

		void			beSigned( Bureaucrat& b );
		virtual	void	execute( Bureaucrat const & executor ) const = 0;
};

std::ostream& operator<<( std::ostream &o, const AForm &Aform );

#endif