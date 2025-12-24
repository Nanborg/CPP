/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:26:29 by marvin            #+#    #+#             */
/*   Updated: 2025/12/24 13:26:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private :
        const std::string _name;
        bool             _isSigned;
        const int       _gradeSign;
        const int       _gradeExec;
        AForm();

    public :
        AForm(const std::string name, int gradeSign, int gradeExec);
        AForm(const AForm &src);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        const std::string getname() const;
        bool isSigned() const;
        int getGradeSign() const;
        int getgradeExec() const;

        void beSigned(const Bureaucrat &bureaucrat);
        void execute(Bureaucrat const & executor) const;
        virtual void execAction() const = 0;

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
        class NotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif