/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:00:00 by ana               #+#    #+#             */
/*   Updated: 2026/05/08 01:52:53 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vec(), vec_sorted(), dq(), dq_sorted() {}

PmergeMe::PmergeMe(const PmergeMe &other) : vec(other.vec), vec_sorted(other.vec_sorted), dq(other.dq), dq_sorted(other.dq_sorted) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) 
{
    if (this != &other) 
    {
        vec = other.vec;
        vec_sorted = other.vec_sorted;
        dq = other.dq;
        dq_sorted = other.dq_sorted;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::add_number(std::string number)
{
    int num = std::atoi(number.c_str());
    vec.push_back(num);
    dq.push_back(num);
}
/*
int get_pair(std::vector<std::pair<int, int> > pairs, std::vector<int> vec_bN, int lN)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (lN == pairs[i].first)
        {
            size_t bi = 0;
            for (; bi < vec_bN.size(); bi++)
            {
                if (pairs[i].second == vec_bN[bi])
                    return bi;
            }
        }
    }
    return -1;
}

int get_pair_d(std::deque<std::pair<int, int> > pairs, std::deque<int> deq_bN, int lN)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (lN == pairs[i].first)
        {
            size_t bi = 0;
            for (; bi < deq_bN.size(); bi++)
            {
                if (pairs[i].second == deq_bN[bi])
                    return bi;
            }
        }
    }
    return -1;
}*/

std::vector<int> getJacobsthalOrderVec(int size)
{
    if (size <= 1)
        return std::vector<int>();
    
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    
    while (jacob.back() < size)
    {
        int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    
    std::vector<int> order;
    order.push_back(1);
    
    for (size_t i = 2; i < jacob.size(); i++)
    {
        int high = jacob[i];
        int low = jacob[i - 1];
        
        for (int j = std::min(high, size); j > low; j--)
        {
            order.push_back(j);
        }
    }
    
    for (int i = 1; i <= size; i++)
    {
        bool found = false;
        for (size_t j = 0; j < order.size(); j++)
        {
            if (order[j] == i)
            {
                found = true;
                break;
            }
        }
        if (!found)
            order.push_back(i);
    }
    
    return order;
}

std::deque<int> getJacobsthalOrderDeque(int size)
{
    if (size <= 1)
        return std::deque<int>();
    
    std::deque<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    
    while (jacob.back() < size)
    {
        int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    
    std::deque<int> order;
    order.push_back(1);
    
    for (size_t i = 2; i < jacob.size(); i++)
    {
        int high = jacob[i];
        int low = jacob[i - 1];
        
        for (int j = std::min(high, size); j > low; j--)
        {
            order.push_back(j);
        }
    }
    
    for (int i = 1; i <= size; i++)
    {
        bool found = false;
        for (size_t j = 0; j < order.size(); j++)
        {
            if (order[j] == i)
            {
                found = true;
                break;
            }
        }
        if (!found)
            order.push_back(i);
    }
    
    return order;
}

int PmergeMe::vec_sort(std::vector<int>& v)
{
    std::vector<int> vec_bN;
    std::vector<int> vec_lN;
    std::vector<std::pair<int, int> > pairs;

    if (v.size() < 2)
        return 0;
    for (size_t i = 0; i < v.size(); i += 2)
    {
        if (i == v.size() - 1)
        {
            vec_lN.push_back(v[i]);
            pairs.push_back(std::make_pair(v[i], -1));
            break;
        }
        if (v[i] > v[i + 1])
        {
            vec_bN.push_back(v[i]);
            vec_lN.push_back(v[i + 1]);
            pairs.push_back(std::make_pair(v[i + 1], v[i]));
        }
        else
        {
            vec_bN.push_back(v[i + 1]);
            vec_lN.push_back(v[i]);
            pairs.push_back(std::make_pair(v[i], v[i + 1]));
        }
    }
    if (vec_bN.size() > 1)
        vec_sort(vec_bN);
    std::vector<int> order = getJacobsthalOrderVec(vec_lN.size());
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t idx = order[i] - 1;

        if (idx >= vec_lN.size())
             continue;
		int small = vec_lN[idx];
		if (idx < pairs.size()) {
			int big = pairs[idx].second;
			std::vector<int>::iterator bound = std::find(vec_bN.begin(), vec_bN.end(), big);
			std::vector<int>::iterator pos = std::lower_bound(vec_bN.begin(), bound, small);
			vec_bN.insert(pos, small);
		} else { // Check if unpaired (odd element)
			std::vector<int>::iterator pos = std::lower_bound(vec_bN.begin(), vec_bN.end(), small);
			vec_bN.insert(pos, small);
		}
    }
    v = vec_bN;
    return 0;   
}

int PmergeMe::dq_sort(std::deque<int>& d)
{
    std::deque<int> deq_bN;
    std::deque<int> deq_lN;
    std::deque<std::pair<int, int> > pairs;

    if (d.size() < 2)
        return 0;
    
    for (size_t i = 0; i < d.size(); i += 2)
    {
        if (i == d.size() - 1)
        {
            deq_lN.push_back(d[i]);
            pairs.push_back(std::make_pair(d[i], -1));
            break;
        }
        if (d[i] > d[i + 1])
        {
            deq_bN.push_back(d[i]);
            deq_lN.push_back(d[i + 1]);
            pairs.push_back(std::make_pair(d[i + 1], d[i]));
        }
        else
        {
            deq_bN.push_back(d[i + 1]);
            deq_lN.push_back(d[i]);
            pairs.push_back(std::make_pair(d[i], d[i + 1]));
        }
    }
    
    if (deq_bN.size() > 1)
        dq_sort(deq_bN);
    
    std::deque<int> order = getJacobsthalOrderDeque(deq_lN.size());
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t idx = order[i] - 1;
 
        if (idx >= deq_lN.size())
             continue;
		int small = deq_lN[idx];
		if (idx < pairs.size()) 
        {
			int bi = pairs[idx].second;
			std::deque<int>::iterator bound = std::find(deq_bN.begin(), deq_bN.end(), bi);
			std::deque<int>::iterator pos = std::lower_bound(deq_bN.begin(), bound, small);
			deq_bN.insert(pos, small);
		}  else { // Check if unpaired (odd element)
			std::deque<int>::iterator pos = std::lower_bound(deq_bN.begin(), deq_bN.end(), small);
			deq_bN.insert(pos, small);
		}
    }
    d = deq_bN;
    return 0;
}

void PmergeMe::funcSort()
{
    vec_sorted = vec;
    dq_sorted = dq;

    struct timeval start, end;
    gettimeofday(&start, NULL);
	int resultVec = vec_sort(vec_sorted);
    gettimeofday(&end, NULL);
    long vecTime = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    gettimeofday(&start, NULL);
	int resultDeq = dq_sort(dq_sorted);
	gettimeofday(&end, NULL);
	long deqTime = (end.tv_sec - start.tv_sec) *1000000 + (end.tv_usec - start.tv_usec);
    
    
    std::cout << "Vector Before: " << std::endl;
    for(size_t i = resultVec; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << "\nVector After: " << std::endl;
    for(size_t i = 0; i < vec_sorted.size(); i++)
        std::cout << vec_sorted[i] << " ";
    std::cout << std::endl;
    std::cout << "Deque Before: " << std::endl;
    for(size_t i = resultDeq; i < dq.size(); i++)
        std::cout << dq[i] << " ";
    std::cout << "\nDeque After: " << std::endl;
    for(size_t i = 0; i < dq_sorted.size(); i++)
        std::cout << dq_sorted[i] << " ";

    std::cout << "\nTime to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " us";
	std::cout << "\nTime to process a range of " << dq.size() << " elements with std::deque : " << deqTime << " us" << std::endl;
}




