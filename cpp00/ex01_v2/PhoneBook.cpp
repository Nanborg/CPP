/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:51:46 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 19:11:34 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cctype>

PhoneBook::PhoneBook() : count(0), next(0) {}

void PhoneBook::add()
{
    Contact c;
    if (!c.read_Stdin())
        return;
    book[next] = c;
    next = (next + 1) % 8;
    if (count < 8)
        ++count;
}

void PhoneBook::search() const
{
    std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME\n";
    for (int i = 0; i < count; ++i)
        book[i].prt_Search(i + 1);
    if (count == 0)
        return;

    std::string input;
    std::cout << "Enter an index (num) to see details (or EXIT): ";
    if (!std::getline(std::cin, input) || input == "EXIT")
        return;

    std::istringstream iss(input);
    int index;
    char extra;
    if (!(iss >> index) || (iss >> extra) || index < 1 || index > count)
    {
        std::cout << "Invalid index.\n";
        return;
    }
    book[index - 1].prt_Details();
}
