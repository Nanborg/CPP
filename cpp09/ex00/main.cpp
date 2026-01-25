/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:29:17 by marvin            #+#    #+#             */
/*   Updated: 2026/01/25 13:29:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error . cant open file" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    btc.readCsv("data.csv");
    btc.readInputFile(av[1]);
    return 0;
}