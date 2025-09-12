/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:51:46 by nicolsan          #+#    #+#             */
/*   Updated: 2025/08/13 20:25:09 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : contact_Count(0), next_Index(0)
{
    return;
}

PhoneBook::~PhoneBook(void)
{
    return;
}
bool PhoneBook::is_blank(const std::string &s) const
{
    return s.find_first_not_of(" \t\r\n") == std::string::npos;
}

std::string PhoneBook::prompt_non_empty(const char *label) const
{
    std::string in;
    do
    {
        std::cout << label;
        if (!std::getline(std::cin, in))
            return "";
    } while (is_blank(in));
    return in;
}

void PhoneBook::print_Str(std::string Str) const
{
    if (Str.length() > 10)
        std::cout << Str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << Str;
}

void PhoneBook::add_Contact(void)
{
    std::string input;
    int idx = this->next_Index;

    input = prompt_non_empty("Enter First Name: ");
    if (input == "")
        return; // EOF
    this->contacts[idx].set_First_Name(input);

    input = prompt_non_empty("Enter Last Name: ");
    if (input == "")
        return;
    this->contacts[idx].set_Last_Name(input);

    input = prompt_non_empty("Enter Nickname: ");
    if (input == "")
        return;
    this->contacts[idx].set_Nickname(input);

    input = prompt_non_empty("Enter Phone Number: ");
    if (input == "")
        return;
    this->contacts[idx].set_Phone_Number(input);

    input = prompt_non_empty("Enter Darkest Secret: ");
    if (input == "")
        return;
    this->contacts[idx].set_Secret(input);

    this->next_Index = (this->next_Index + 1) % 8;
    if (this->contact_Count < 8)
        this->contact_Count++;
}

void PhoneBook::search_Contacts(void) const
{
    std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << std::endl;

    int i = 0;
    while (i < this->contact_Count)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        print_Str(this->contacts[i].get_First_Name());
        std::cout << "|";
        print_Str(this->contacts[i].get_Last_Name());
        std::cout << "|";
        print_Str(this->contacts[i].get_Nickname());
        std::cout << std::endl;
        i++;
    }

    if (this->contact_Count > 0)
    {
        std::string input;
        std::cout << "Enter an index to see details (or EXIT): ";
        std::getline(std::cin, input);

        if (input == "EXIT")
            return;

        bool isNumber = true;
        for (size_t j = 0; j < input.size(); j++)
        {
            if (!std::isdigit(input[j]))
            {
                isNumber = false;
                break;
            }
        }
        if (isNumber)
        {
            int index = 0;
            for (size_t j = 0; j < input.size(); j++)
            {
                index = index * 10 + (input[j] - '0');
            }

            if (index > 0 && index <= this->contact_Count)
            {
                std::cout << "First Name:     " << this->contacts[index - 1].get_First_Name() << std::endl;
                std::cout << "Last Name:      " << this->contacts[index - 1].get_Last_Name() << std::endl;
                std::cout << "Nickname:       " << this->contacts[index - 1].get_Nickname() << std::endl;
                std::cout << "Phone Number:   " << this->contacts[index - 1].get_Phone_Number() << std::endl;
                std::cout << "Darkest Secret: " << this->contacts[index - 1].get_Secret() << std::endl;
            }
            else
            {
                std::cout << "Invalid index." << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid index." << std::endl;
        }
    }
}
// --- Explications Synthétiques ---
// Objectif : Gérer la logique du répertoire : ajout et recherche de contacts.
// Logique 'add_Contact' : Utilise 'std::getline' pour lire des entrées avec des espaces, ce qui est robuste.
// Stratégie 'add_Contact' : Un index 'next_Index' est utilisé pour savoir où ajouter le prochain contact.
// Syntaxe : 'this->next_Index = (this->next_Index + 1) % 8;' est une astuce pour un tableau circulaire.
// Logique 'search_Contacts' : Affiche un résumé de tous les contacts enregistrés.
// Stratégie 'search_Contacts' : Utilise une fonction privée 'print_Str' pour formater et tronquer le texte.
// Syntaxe : 'std::setw(10)' de la librairie '<iomanip>' sert à fixer la largeur d'une colonne à 10 caractères.
// Robustesse : 'std::cin.clear()' et 'std::cin.ignore()' sont utilisés pour nettoyer le flux d'entrée après une lecture d'entier, prévenant des bugs.
