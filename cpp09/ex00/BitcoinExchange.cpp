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

void BitcoinExchange::cleanString(std::string &s) const
{
    size_t first = s.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos)
        s = "";
    else
    {
        size_t last = s.find_last_not_of(" \t\n\r\f\v");
        s = s.substr(first, (last - first + 1));
    }
}

bool BitcoinExchange::checkDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int year, month, day;
    std::istringstream ss_year(date.substr(0, 4));
    std::istringstream ss_month(date.substr(5, 2));
    std::istringstream ss_day(date.substr(8, 2));
    if (!(ss_year >> year) || !(ss_month >> month) || !(ss_day >> day))
        return false;
    if (year <2008 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false; //pour les mois avec 30 jours
    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((day > 29) || (day == 29 && !isLeap))
            return false;
    }
    return true;
}

bool BitcoinExchange::checkValue(const std::string &value, float &val) const
{
    char* end;
    val = std::strtof(value.c_str(), &end);
    if (end == value.c_str() || *end != '\0')
        return false;
    return true;
}

void BitcoinExchange::readCsv(const std::string & filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error cant open database " << std::endl;
        std::exit(1);
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t separrateur = line.find(',');
        if (separrateur != std::string::npos)
        {
            std::string date = line.substr(0,separrateur);
            float rate = std::atof(line.substr(separrateur + 1).c_str());
            my_data[date] = rate;
        }
    }
    file.close();
}

void BitcoinExchange::readInputFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error cant open file" << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    if (line != "date | value")
    { }
    while (std::getline(file, line))
    {
        size_t separrateur = line.find('|');
        if (separrateur == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, separrateur);
        std::string val_str = line.substr(separrateur + 1);
        cleanString(date);
        cleanString(val_str);

        if (!checkDate(date))
        {
            std::cerr << "Error bad input " << date << std::endl;
            continue;
        }
        float val;
        if (!checkValue(val_str, val))
        {
            std::cerr << "Error bad input " << date << std::endl;
            continue;
        }

        if (val < 0)
        {
            std::cerr << "Error not positive num " << std::endl;
            continue;
        }
        if (val > 1000)
        {
            std::cerr << "Error num too large " << std::endl;
            continue;
        }
        std::map<std::string, float>::iterator it = my_data.upper_bound(date);
        if (it == my_data.begin())
            {
                std::cout << "Error data/date " << std::endl;
                continue;
            }
        --it;
        std::cout << date << " => " << val << " = " << std::fixed << std::setprecision(2) << val * it->second << std::endl;

    }
}

        
        