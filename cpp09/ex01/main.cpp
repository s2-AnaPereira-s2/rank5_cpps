/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:20:44 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/30 22:40:59 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2)
        return (std::cerr << "Invalid number of argument" << std::endl, 1);
    RPN rpn;
    rpn.RPN_calc(argv[1]);
    return 0;
}
