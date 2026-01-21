/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:44:25 by marvin            #+#    #+#             */
/*   Updated: 2026/01/21 10:44:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>


class NoValueException : public std::exception 
{
    public:
        virtual const char * what() const throw()
        {
            return "Error no value";
        }
};

template <typename T>
typename T::iterator easyfind(T &container, int to_find)
{
    typename T::iterator x = std::find(container.begin(), container.end(), to_find);
    if (x == container.end())
    {
        throw NoValueException();
    }
    return x;
}

#endif