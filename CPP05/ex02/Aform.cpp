/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:26:32 by marvin            #+#    #+#             */
/*   Updated: 2025/12/24 13:26:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aform.hpp"

AForm::AForm(const std::string name, int gradeSign, int gradeExec) 
    : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
    {
        if (gradeSign < 1 || gradeExec < 1)
            throw AForm::GradeTooHighException();
        if (gradeSign > 150 || gradeExec > 150)
            throw AForm::GradeTooLowException();
    }

AForm::AForm(const AForm &src)
    : _name(src._name), _isSigned(src._isSigned), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec)
{}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm()
{}

const std::string AForm::getname() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _isSigned;
}
int AForm::getGradeSign() const
{
    return _gradeSign;
}
int AForm::getgradeExec() const
{
    return _gradeExec;
}
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_isSigned)
        throw AForm::NotSignedException();
    if (executor.getGrade() > _gradeExec)
        throw AForm::GradeTooLowException();
    this-> execAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm Exception: Grade too high";
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm Exception: Grade too low";
}
const char *AForm::NotSignedException::what() const throw()
{
    return "AForm Exception: Form not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "AForm Name: " << form.getname() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
        << ", Grade Required to Sign: " << form.getGradeSign()
        << ", Grade Required to Execute: " << form.getgradeExec();
    return out;
}

