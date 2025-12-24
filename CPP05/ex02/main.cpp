/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:10:34 by marvin            #+#    #+#             */
/*   Updated: 2025/12/23 11:10:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>


int main()
{
    std::srand(std::time(NULL));

    try
    {
        Bureaucrat Stalin("Stalin", 1);
        Bureaucrat Kroutchev("Kroutchev", 150);

        ShrubberyCreationForm f1("Goulag");
        RobotomyRequestForm f2("Coupon");
        PresidentialPardonForm f3("Capitalist");
        std::cout << "signatures" << std::endl;
        Stalin.signForm(f1);
        Stalin.signForm(f2);
        Stalin.signForm(f3);

        std::cout << "executions" << std::endl;
        Stalin.executeForm(f1);
        Stalin.executeForm(f2);
        Stalin.executeForm(f3);

        std::cout << "\ntry with low level bureaucrat\n" << std::endl;
        Kroutchev.signForm(f1);
        Kroutchev.executeForm(f1);
    }
    catch(const std::exception& exception)
    {
        std::cerr << "fail" << exception.what() << std::endl;
    }
    
    return 0;
}