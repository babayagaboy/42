/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:34:21 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/07 01:21:06 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

AForm::AForm( void ) : _name("Default"), _gradeToSign(150), _gradeToExec(150) {
	// std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm( std::string name , int gradeToSign, int gradeToExec ) :
	_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	// std::cout << "AForm Default constructor called" << std::endl;
	if (gradeToSign < 1)
		throw (AForm::GradeTooHighException());
	if (gradeToSign > 150)
		throw (AForm::GradeTooLowException());
	if (gradeToExec < 1)
		throw (AForm::GradeTooHighException());
	if (gradeToExec > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm( const AForm& other ) :
	_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec), _isSigned(other._isSigned)
{
	// std::cout << "AForm Copy constructor called" << std::endl;
}

AForm& AForm::operator=( const AForm& other )
{
	// std::cout << "AForm Copy assignment called" << std::endl;
	if(this != &other)
	{
		const_cast<std::string&>(this->_name) = other._name;
		const_cast<int&>(this->_gradeToSign) = other._gradeToSign;
		const_cast<int&>(this->_gradeToExec) = other._gradeToExec;
		this->_isSigned = other._isSigned;
	}
	return(*this);
}

AForm::~AForm( void ) {
	// std::cout << "AForm Destructor called" << std::endl;
}

std::string	AForm::getName( void ) const {
	return(this->_name);
}

int	AForm::getGradeToSign( void ) const {
	return(this->_gradeToSign);
}
int	AForm::getGradeToExec( void ) const {
	return(this->_gradeToExec);
}

bool AForm::getIsSigned( void ) const {
	return(this->_isSigned);
}

void	AForm::beSigned( Bureaucrat& b )
{
	if(b.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw (AForm::GradeTooLowException());
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("it's grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("it's grade is too low!");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("this form is not signed!");
}


std::ostream& operator<<( std::ostream &o, const AForm &form )
{
	o << form.getName() << " needs " <<
	form.getGradeToSign() << " grade to sign and " <<
	form.getGradeToExec() << " grade to exec.";
	return (o);
}