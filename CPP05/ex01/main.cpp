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
#include "Form.hpp"
#include <iostream>
#include <exception>

int main()
{
    std::cout << "Form :" << std::endl;

    try
    {
        Form form1("A1", 0, 50);
    }
    catch (std::exception &exception)
    {
        std::cerr << exception.what() << std::endl;
    }

    std::cout << "\nSigning..." << std::endl;

    try
    {
        Bureaucrat Spielberg("Spielberg", 150);
        Bureaucrat Nolan("Nolan", 1);
        Form AdminForm("TopSecret", 50, 100);

        std::cout << Spielberg << std::endl;
        std::cout << Nolan << std::endl;
        std::cout << AdminForm << std::endl;

        std::cout << "\nNolan tries to sign the form..." << std::endl;
        Nolan.signForm(AdminForm);

        std::cout << "\nSpielberg tries to sign the form..." << std::endl;
        Spielberg.signForm(AdminForm);

        std::cout << "\nFinal state of the form:" << std::endl;
        std::cout << AdminForm << std::endl;
    }
    catch (std::exception &exception)
    {
        std::cerr << "Unexpected error: " << exception.what() << std::endl;
    }

    return 0;
}
