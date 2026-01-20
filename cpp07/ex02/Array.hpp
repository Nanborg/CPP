/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:06:26 by marvin            #+#    #+#             */
/*   Updated: 2026/01/20 16:06:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>


template <typename T>
class Array
{
    private:
        T* _data;
        unsigned int _size;
    public:
        Array() : _data(new T[0]), _size(0) {}
        Array(unsigned int n) : _data(new T[n]()), _size(n) {}
        Array(const Array &src) : _data(NULL), _size(0)
        {
            *this = src;
        }
        Array &operator=(const Array &src)
        {
            if(this != &src)
            {
                if (this->_data)
                    delete[] this->_data;
                this->_size = src._size;
                this->_data = new T[this->_size];
                for (unsigned int i = 0; i < this->_size; i++)
                    this->_data[i] = src._data[i];
            }
            return *this;
        }
        ~Array()
        {
            if (this->_data)
                delete[] this->_data;
        }

        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw OutofException();

            return _data[index];
        }
        const T& operator[](unsigned int index) const
        {
            if (index >= _size)
                throw OutofException();

            return _data[index];
        }

        unsigned int size() const
        {
            return _size;
        }

        //special exeption class
        class OutofException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Array index not valid";
                }
        };
    };

#endif