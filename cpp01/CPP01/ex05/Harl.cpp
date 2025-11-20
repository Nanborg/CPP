/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:44:52 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/10 14:51:50 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

typedef void (Harl::*action)();
void Harl::debug()
{
    std::cout << "[ DEBUG ]\n"
              << "\"Why is a raven like a writing-desk?\" I'm sure I can guess that.\n"
              << "(from Alice's Adventures in Wonderland by Lewis Carroll)\n";
}

void Harl::info()
{
    std::cout << "[ INFO ]\n"
              << "\"All animals are equal, but some animals are more equal than others.\" This doesn't seem right.\n"
              << "(from Animal Farm by George Orwell)\n";
}

void Harl::warning()
{
    std::cout << "[ WARNING ]\n"
              << "\"I will be with you on your wedding-night.\" I'm warning you, this is not a threat to be ignored.\n"
              << "(from Frankenstein by Mary Shelley)\n";
}

void Harl::error()
{
    std::cout << "[ ERROR ]\n"
              << "\"Blow, winds, and crack your cheeks! Rage! Blow!\" This situation is utterly unacceptable!\n"
              << "(from King Lear by William Shakespeare)\n";
}

void Harl::complain(std::string level)
{
    const char *lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    action act[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;
    while (i < 4)
    {
        if (level == lvl[i])
        {
            (this->*act[i])();
            return;
        }
        i++;
    }
}
