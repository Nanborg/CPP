/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:29:25 by marvin            #+#    #+#             */
/*   Updated: 2026/01/25 13:29:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this -> my_data = other.my_data;
    }
    return *this;
}

void BitcoinExchange::trim(std::string &s) const
 {

 }
bool BitcoinExchange::isValidDate(const std::string &date) const
{

}
bool BitcoinExchange::isValidValue(const std::string &value, float &val) const
{

}
void BitcoinExchange::loadDatabase(const std::string & filename)
{

}
void BitcoinExchange::processInput(const std::string &filename)
{

}

        
        