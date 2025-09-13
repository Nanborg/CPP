/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:51:39 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 18:37:11 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
    PhoneBook pb;
    std::string cmd;
    while (true)
    {
        std::cout << "PhoneBook> ";
        if (!std::getline(std::cin, cmd))
            break;
        if (cmd == "ADD")
            pb.add();
        else if (cmd == "SEARCH")
            pb.search();
        else if (cmd == "EXIT")
            break;
    }
    return 0;
}
