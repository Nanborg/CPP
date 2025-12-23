/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:07:30 by marvin            #+#    #+#             */
/*   Updated: 2025/12/23 11:07:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int gradeSign, int gradeExecute) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) 
{
    if (_gradeSign < 1 || _gradeExecute < 1)
        throw Form::GradeTooHighException();
    if (_gradeSign > 150 || _gradeExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name), _isSigned(src._isSigned), _gradeSign(src._gradeSign), _gradeExecute(src._gradeExecute)
{

}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {}

const std::string Form::getName() const 
{
    return _name;
}
bool Form::getSigned() const
{
    return _isSigned;
}

int Form::getGradeSign() const
{
    return _gradeSign;
}

int Form::getGradeExecute() const
{
    return _gradeExecute;
}

void Form::beSigned(const Bureaucrat &Bureaucrat)
{
    if (Bureaucrat.getGrade() > _gradeSign)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too Low!";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form " << form.getName()
        << ", signed: " << (form.getSigned() ? "yes" : "no")
        << ", sign grade: " << form.getGradeSign()
        << ", exec grade: " << form.getGradeExecute();
    return out;
}
