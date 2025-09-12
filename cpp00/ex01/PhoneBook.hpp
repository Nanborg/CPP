/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:51:51 by nicolsan          #+#    #+#             */
/*   Updated: 2025/08/13 20:23:23 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
private:
    Contact contacts[8];
    int contact_Count;
    int next_Index;

    void print_Str(std::string Str) const;
    bool is_blank(const std::string &s) const;
    std::string prompt_non_empty(const char *label) const;

public:
    PhoneBook(void);
    ~PhoneBook(void);
    void add_Contact(void);
    void search_Contacts(void) const;
};

#endif

// --- Explications Synthétiques ---
// Objectif : Déclarer la classe qui gère l'ensemble du répertoire.
// Logique : Contient un tableau de 8 objets Contact. Pas de pointeur, pas d'allocation dynamique.
// Stratégie : Deux membres privés contact_Count et next_Index gèrent l'état du répertoire.
// Encapsulation : 'print_Str' est une fonction d'aide (helper) privée. Elle n'est pas accessible de l'extérieur.
// '#include "Contact.hpp"' : Un fichier header peut en inclure un autre pour utiliser ses déclarations.
