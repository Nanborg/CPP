/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:51:33 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 19:29:14 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip> //pour setw , best pour definir la largeur d'affichage
#include <string>
#include <cctype>

static bool blank(const std::string &s)
{
    std::string::size_type i = 0;
    while (i < s.length())
    {
        if (!isspace(s[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}

static bool prompt(const char *label, std::string &out)
{
    do
    {
        std::cout << label;
        if (!std::getline(std::cin, out))
            return false;
    } while (blank(out));
    return true;
}
static void col10(const std::string &s)
{
    if (s.size() > 10)
        std::cout << s.substr(0, 9) << '.';
    else
        std::cout << std::setw(10) << s;
}

Contact::Contact()
{
}

bool Contact::read_Stdin()
{
    std::string s;
    if (!prompt("Enter First Name: ", first))
        return false;
    if (!prompt("Enter Last Name: ", last))
        return false;
    if (!prompt("Enter Nickname: ", nick))
        return false;
    if (!prompt("Enter Phone Number: ", phone))
        return false;
    if (!prompt("Enter Darkest Secret: ", secret))
        return false;
    return true;
}

void Contact::prt_Search(int idx) const
{
    std::cout << std::setw(10) << idx << '|';
    col10(first);
    std::cout << '|';
    col10(last);
    std::cout << '|';
    col10(nick);
    std::cout << '\n';
}

void Contact::prt_Details() const
{
    std::cout << "First Name:     " << first << '\n'
              << "Last Name:      " << last << '\n'
              << "Nickname:       " << nick << '\n'
              << "Phone Number:   " << phone << '\n'
              << "Darkest Secret: " << secret << '\n';
}
