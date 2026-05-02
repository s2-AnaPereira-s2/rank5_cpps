/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:20:44 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/05/02 03:03:27 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) 
{
    if (argc < 2)
        std::cerr << "Error: Invalid number of arguments" << std::endl;
    PmergeMe ln;
    for (int i = 1; i < argc; i++)
        ln.add_number(argv[i]);
    ln.funcSort();
    return 0;
}
