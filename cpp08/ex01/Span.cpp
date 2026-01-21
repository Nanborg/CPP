/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:12:53 by marvin            #+#    #+#             */
/*   Updated: 2026/01/21 11:12:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

Span::Span(unsigned int n) : num(n)
{
    storage.reserve(n);
}

Span::Span(const Span &src) : num(src.num), storage(src.storage)
{}

Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        this->num = src.num;
        this->storage = src.storage;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (storage.size() >= num)
        throw SpanException();
    storage.push_back(number);
}

unsigned int Span::longestSpan() const 
{
    if (storage.size() < 2)
        throw NoSpanException();

    int min = *std::min_element(storage.begin(), storage.end());
    int max = *std::max_element(storage.begin(), storage.end());
    return static_cast<unsigned int>(max - min);
}

unsigned int Span::shortestSpan() const 
{
    if (storage.size() < 2)
        throw NoSpanException();
    
    std::vector<int> sorted = storage;
    std::sort(sorted.begin(), sorted.end());
    unsigned int diff = std::numeric_limits<unsigned int>::max();
    for (size_t i = 0; i < sorted.size() - 1; ++i)
    {
        unsigned int difference = static_cast<unsigned int>(sorted[i + 1] - sorted[i]);
        if (difference <diff)
            diff = difference;
    }
    return diff;
}
