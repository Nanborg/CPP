/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:10:34 by marvin            #+#    #+#             */
/*   Updated: 2025/12/23 11:10:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>


int main()
{
    Intern intern;
    Bureaucrat Bolos("Bolos", 1);
    AForm* form;

    form = intern.makeForm("shrubbery creation", "pelouze");
    if (form)
    {
        Bolos.signForm(*form);
        Bolos.executeForm(*form);
        delete form;
    }

    form = intern.makeForm("robotomy request", "H2G2");
    if (form)
    {
        Bolos.signForm(*form);
        Bolos.executeForm(*form);
        delete form;
    }

    form = intern.makeForm("presidential pardon", "Stalin");
    if (form)
    {
        Bolos.signForm(*form);
        Bolos.executeForm(*form);
        delete form;
    }
    
    form = intern.makeForm("unknown form", "target");
    if (form)
    {
        delete form;
    }
    return 0;
}