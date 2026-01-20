/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:35:46 by marvin            #+#    #+#             */
/*   Updated: 2026/01/20 15:35:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T &min(const T &a, const T &b)
{
    if (a < b)
        return a;
    return b;
}

template <typename T>
const T &max(const T &a, const T &b)
{
    if (a > b)
        return a;
    return b;
} 

#endif