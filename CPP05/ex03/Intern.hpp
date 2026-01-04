/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:34:12 by marvin            #+#    #+#             */
/*   Updated: 2026/01/04 21:34:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        typedef AForm* (Intern::*FormCreator)(std::string target);
        AForm* createShrubbery(std::string target);
        AForm* createRobotomy(std::string target);
        AForm* createPresidential(std::string target);
    public:
        Intern();
        Intern(const Intern &src);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm* makeForm(const std::string formName,std::string target);
};
#endif
