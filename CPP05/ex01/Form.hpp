/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:07:44 by marvin            #+#    #+#             */
/*   Updated: 2025/12/23 11:07:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
        const std::string  _name;
        bool                _isSigned;
        const int          _gradeSign;
        const int          _gradeExecute;
        Form();

    public:
        Form(const std::string name, int gradeSign, int gradeExecute);
        Form(const Form &src);
        Form &operator=(const Form &other);
        ~Form();

        const std::string getName() const;
        bool              getSigned() const;
        int              getGradeSign() const;
        int              getGradeExecute() const;

        void           beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif