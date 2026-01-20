/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:45:13 by marvin            #+#    #+#             */
/*   Updated: 2026/01/20 09:45:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <climits>
#include <cmath>
#include <iomanip>

class ScalarConverter {

    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const & src);
        ~ScalarConverter();
        ScalarConverter & operator=(ScalarConverter const & other);

        static bool isPseudoLiteral(const std::string & input);
        static void printPseudoLiteral(const std::string & input);

    public:
        static void convert(const std::string & input);

};
#endif