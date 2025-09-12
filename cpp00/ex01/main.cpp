/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:51:39 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/12 15:34:36 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "PhoneBook> ";
        if (!std::getline(std::cin, command))
            break;

        if (command == "ADD")
        {
            phoneBook.add_Contact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.search_Contacts();
        }
        else if (command == "EXIT")
        {
            break;
        }
    }
    return 0;
}

/*
Explications Synthétiques
 Objectif : Créer la boucle principale interactive qui attend les commandes de l'utilisateur.
 Stratégie : Une boucle 'while(true)' s'exécute indéfiniment jusqu'à une commande 'EXIT' ou un signal de fin.
 Logique : Crée une seule instance de 'PhoneBook' qui conserve son état (les contacts) durant toute l'exécution.
 Robustesse : 'std::getline' est utilisé pour lire la commande. C'est plus sûr que 'std::cin >>'.
 Syntaxe : 'if (!std::getline(...))' est une manière idiomatique de détecter CTRL+D (fin de fichier/EOF).
 Logique : Une chaîne de 'if/else if' est utilisée pour dispatcher la commande à la bonne méthode de l'objet 'phoneBook'.
*/