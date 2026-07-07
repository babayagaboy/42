/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:59:58 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/23 15:59:58 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name("Default"), _gradeToSign(150), _gradeToExec(150) {
	// std::cout << "Form Default constructor called" << std::endl;
}

Form::Form( std::string name , int gradeToSign, int gradeToExec ) :
	_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	// std::cout << "Form Default constructor called" << std::endl;
	if (gradeToSign < 1)
		throw (Form::GradeTooHighException());
	if (gradeToSign > 150)
		throw (Form::GradeTooLowException());
	if (gradeToExec < 1)
		throw (Form::GradeTooHighException());
	if (gradeToExec > 150)
		throw (Form::GradeTooLowException());
}

Form::Form( const Form& other ) :
	_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec), _isSigned(other._isSigned)
{
	// std::cout << "Form Copy constructor called" << std::endl;
}

Form& Form::operator=( const Form& other )
{
	// std::cout << "Form Copy assignment called" << std::endl;
	if(this != &other)
	{
		const_cast<std::string&>(this->_name) = other._name;
		const_cast<int&>(this->_gradeToSign) = other._gradeToSign;
		const_cast<int&>(this->_gradeToExec) = other._gradeToExec;
		this->_isSigned = other._isSigned;
	}
	return(*this);
}

Form::~Form( void ) {
	// std::cout << "Form Destructor called" << std::endl;
}

std::string	Form::getName( void ) const {
	return(this->_name);
}

int	Form::getGradeToSign( void ) const {
	return(this->_gradeToSign);
}
int	Form::getGradeToExec( void ) const {
	return(this->_gradeToExec);
}

bool Form::getIsSigned( void ) const {
	return(this->_isSigned);
}

void	Form::beSigned( Bureaucrat& b )
{
	if(b.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw (Form::GradeTooLowException());
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("it's grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("it's grade is too high!");
}

std::ostream& operator<<( std::ostream &o, const Form &form )
{
	o << form.getName() << " needs " <<
	form.getGradeToSign() << " grade to sign and " <<
	form.getGradeToExec() << " grade to exec.";
	return (o);
}