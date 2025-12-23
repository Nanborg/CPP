/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 00:22:37 by marvin            #+#    #+#             */
/*   Updated: 2025/12/23 00:22:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "constructors" << std::endl;
    try
    {
		Bureaucrat high("Trop Haut", 0);
    }
    catch (std::exception &exception)
    {
        std::cerr << "Erreur : " << exception.what() << std::endl;
    }

	try
	{
		Bureaucrat Low("Trop Bas", 151);
	}
	catch (std::exception &exception)
	{
		std::cerr << "Erreur : " << exception.what() << std::endl;
	}

	std::cout << "Grade increment/decrement" << std::endl;
	try
	{
		Bureaucrat Spielberg("Spielberg", 2);
		std::cout << Spielberg << std::endl;
		Spielberg.incrementGrade();
		std::cout << "apres increment: " << Spielberg << std::endl;
		Spielberg.incrementGrade();
	}
	catch(std::exception &exception)
	{
		std::cerr << "Erreur : " << exception.what() << '\n';
	}

	try
	{
		Bureaucrat Tarantino("Tarantino", 149);
		std::cout << Tarantino << std::endl;
		Tarantino.decrementGrade();
		std::cout << "apres decrement: " << Tarantino << std::endl;
		Tarantino.decrementGrade();
	}
	catch(std::exception &exception)
	{
		std::cerr << "Erreur : " << exception.what() << '\n';
	}

	return 0;  
}