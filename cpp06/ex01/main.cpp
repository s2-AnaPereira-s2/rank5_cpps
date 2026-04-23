/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:18:27 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/24 00:11:25 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    // Create a Data object
    Data original;
    original.id = 42;
    original.name = "Test Data";

    std::cout << "Original Data:" << std::endl;
    std::cout << "  Address: " << &original << std::endl;
    std::cout << "  ID: " << original.id << std::endl;
    std::cout << "  Name: " << original.name << std::endl;

    // Serialize the pointer
    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "\nSerialized value: " << raw << std::endl;

    // Deserialize back to pointer
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized back to pointer: " << deserialized << std::endl;


    std::cout << "\nData:" << std::endl;
    std::cout << "  Original ID: " << original.id << std::endl;
    std::cout << "  Original Name: " << original.name << std::endl;
    std::cout << "  Deserialized ID: " << deserialized->id << std::endl;
    std::cout << "  Deserialized Name: " << deserialized->name << std::endl;


    return (0);
}
