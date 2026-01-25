/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:29:21 by marvin            #+#    #+#             */
/*   Updated: 2026/01/25 13:29:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdlib>

class BitcoinExchange 
{
    private:
        std::map<std::string, float> my_data;
        bool isValidDate(const std::string &date) const;
        bool isValidValue(const std::string &value, float &val) const;
        void trim(std::string &s) const;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        void loadDatabase(const std::string & filename);
        void processInput(const std::string &filename);


};

#endif