/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:17:40 by marvin            #+#    #+#             */
/*   Updated: 2026/01/25 20:17:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vectorData = other.vectorData;
        dequeData = other.dequeData;
    }
    return *this;
}

void PmergeMe::sortVec()
{
    if (vectorData.size() <= 1)
        return;
    //a remplacer
    std::vector<int> list_A;
    std::vector<int> list_B;

    for (size_t i = 0; i < vectorData.size() - 1; i += 2)
    {
        int a = vectorData[i];
        int b = vectorData[i + 1];
        if (a < b)
            std::swap(a, b);
        list_A.push_back(a);
        list_B.push_back(b);
    }

    if (vectorData.size() % 2 != 0)
        list_B.push_back(vectorData.back());

    std::sort(list_A.begin(), list_A.end());
    std::vector<int> result = list_A;

    if (!list_B.empty())
    {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), list_B[0]);
        result.insert(pos, list_B[0]);
    }

    std::vector<size_t> jacob;
    size_t Jacob_A = 1;
    size_t Jacob_B = 2;

    jacob.push_back(1);
    while (Jacob_B < list_B.size())
    {
        jacob.push_back(Jacob_B);
        size_t next = Jacob_B + 2 * Jacob_A;
        Jacob_A = Jacob_B;
        Jacob_B = next;
    }

    std::vector<bool> insert_value(list_B.size(), false);
    if(!list_B.empty())
        insert_value[0] = true;

    for (size_t j = 0; j < jacob.size(); j++)
    {
        size_t index = jacob[j];
        if (index >= list_B.size())
            continue;
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), list_B[index]);
        result.insert(pos, list_B[index]);
        insert_value[index] = true;
    }
    for (size_t i = 0; i < list_B.size(); i++)
    {
        if (insert_value[i])
            continue;
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), list_B[i]);
        result.insert(pos, list_B[i]);
    }

    vectorData = result;

}


void PmergeMe::sortDeq()
{
    if (dequeData.size() <= 1)
        return;
    
    std::deque<int> list_A;
    std::deque<int> list_B;

    for (size_t i = 0; i < dequeData.size() - 1; i += 2)
    {
        int a = dequeData[i];
        int b = dequeData[i + 1];
        if (a < b)
            std::swap(a, b);
        list_A.push_back(a);
        list_B.push_back(b);
    }

    if (dequeData.size() % 2 != 0)
        list_B.push_back(dequeData.back());

    std::sort(list_A.begin(), list_A.end());
    std::deque<int> result = list_A;

    if (!list_B.empty())
    {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), list_B[0]);
        result.insert(pos, list_B[0]);
    }

    std::deque<size_t> jacob;
    size_t Jacob_A = 1;
    size_t Jacob_B = 2;

    jacob.push_back(1);
    while (Jacob_B < list_B.size())
    {
        jacob.push_back(Jacob_B);
        size_t next = Jacob_B + 2 * Jacob_A;
        Jacob_A = Jacob_B;
        Jacob_B = next;
    }

    std::deque<bool> insert_value(list_B.size(), false);
    if(!list_B.empty())
        insert_value[0] = true;

    for (size_t j = 0; j < jacob.size(); j++)
    {
        size_t index = jacob[j];
        if (index >= list_B.size())
            continue;
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), list_B[index]);
        result.insert(pos, list_B[index]);
        insert_value[index] = true;
    }
    for (size_t i = 0; i < list_B.size(); i++)
    {
        if (insert_value[i])
            continue;
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), list_B[i]);
        result.insert(pos, list_B[i]);
    }

    dequeData = result;
}

void PmergeMe::runSort(int ac, char **av)
{
    for (int index = 1; index < ac; index++)
    {
        std::stringstream inputstream(av[index]);
        std::string tok;

        while (inputstream >> tok)
        {
            std::stringstream convert(tok);
            int number;
            char letter;
            if(!(convert >> number) || (convert >> letter))
            {
                std::cerr << "Error: arg not valid" << std::endl;
                std::exit(1);
            }
            if (number < 0)
            {
                std::cerr << "Error: Negative numbers are not allowed." << std::endl;
                exit(1);
            }
            vectorData.push_back(number);
            dequeData.push_back(number);
        }
    }
    std::cout << "Before ";
    for (size_t index = 0; index < vectorData.size(); index++)
    {
        std::cout << vectorData[index] << " ";
    }
    std::cout << std::endl;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    sortVec();
    gettimeofday(&end, NULL);
    long vectorTime = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    gettimeofday(&start, NULL);
    sortDeq();
    gettimeofday(&end, NULL);
    long dequeTime = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    std::cout << "After ";
    for (size_t index = 0; index < vectorData.size(); index++)
    {
        std::cout << vectorData[index] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process  " << vectorData.size() << " with vector  " << vectorTime << " us" << std::endl;
    std::cout << "Time to process  " << dequeData.size() << " with deque   " << dequeTime << " us" << std::endl;
}
