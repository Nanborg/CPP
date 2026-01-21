/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:12:10 by marvin            #+#    #+#             */
/*   Updated: 2026/01/21 11:12:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iterator>
#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>

class Span
{
    private:
        unsigned int num;
        std::vector<int> storage;
        Span();

    public:
        Span(unsigned int num);
        Span(const Span &src);
        Span &operator=(const Span &src);
        ~Span();

        void addNumber(int number);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        template <typename T>
        void addNumber(T begin, T end)
        {
            if (storage.size() + std::distance(begin, end) > num)
                throw SpanException();
            storage.insert(storage.end(), begin, end);
        }

    class SpanException : public std::exception 
    {
        public:
            virtual const char * what() const throw()
            {
                return "Span Exception, no space for that";
            }
    };

    class NoSpanException : public std::exception 
    {
        public:
            virtual const char * what() const throw()
            {
                return "No Span found Exception, numbers too low ";
            }
    };

};

#endif