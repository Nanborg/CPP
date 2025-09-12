/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:06:22 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 16:15:02 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << &str << "\n"
              << stringPTR << "\n"
              << &stringREF << std::endl;
    std::cout << str << "\n"
              << *stringPTR << "\n"
              << stringREF << std::endl;
    return 0;
}

/*
str : variable de base.
stringPTR = &str : pointeur vers str (stocke une adresse, nécessite * pour accéder à la valeur, peut être réassigné).
stringREF = str : référence (alias obligatoire, toujours initialisée, ne peut pas changer de cible).
Affichages :
- &str, stringPTR, &stringREF ---> même adresse.
- str, *stringPTR, stringREF  ---> même valeur.
*/