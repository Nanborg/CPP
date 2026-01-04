/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:33:37 by marvin            #+#    #+#             */
/*   Updated: 2026/01/04 21:33:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
    *this = src;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm* Intern::createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm( std::string formName, std::string target)
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*methods[])(std::string) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return (this->*methods[i])(target);
        }
    }

    std::cerr << "Errpr: intern can't create " << formName << " form." << std::endl;
    return NULL;
}