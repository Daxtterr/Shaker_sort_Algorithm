/* 
 * This module contains the main function of this program.
 *
 * This file calls the header file as well as the file containing
 * the helper functions and demonstrates Object-Oriented Programming
 */

/* Include header files */
#include "headers.h"
#include "helpers.cpp"

/*
 * Module: main
 * Author: Aimuel Emmanuel
 * Date: 2024-03-10
 *
 * Purpose: Point of execution in this program
 * Parameter: None
 * Precondition: None
 * \return 0 if no errors, otherwise 1
 * Side effect: None
 */
int main() {
    int size;
    std::cout << "Enter the size of the vector: ";
    std::cin >> size;
    
    std::vector<int> numbers(size);
    for (int i = 0; i < size; ++i) {
        numbers[i] = rand() % 1000; // Random numbers between 0 and 999
    }
    
    // Save the generated vector in a file
    std::ofstream outFile("input.txt");
    if (outFile.is_open()) {
        for (const auto& num : numbers) {
            outFile << num << "\n";
        }
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing.\n";
        return 1;
    }
    
    // Sort the input file in ascending order
    clock_t startAscending = clock();
    shakerSort(numbers);
    clock_t endAscending = clock();
    
    // Save the sorted array in ascending order
    std::ofstream outFileAsc("ascending.txt");
    if (outFileAsc.is_open()) {
        for (const auto& num : numbers) {
            outFileAsc << num << "\n";
        }
        outFileAsc.close();
    } else {
        std::cerr << "Unable to open file for writing.\n";
        return 1;
    }
    
    // Sort the input file in descending order
    clock_t startDescending = clock();
    std::reverse(numbers.begin(), numbers.end());
    shakerSort(numbers);
    std::reverse(numbers.begin(), numbers.end());
    clock_t endDescending = clock();
    
    // Save the sorted array in descending order
    std::ofstream outFileDesc("descending.txt");
    if (outFileDesc.is_open()) {
        for (const auto& num : numbers) {
            outFileDesc << num << "\n";
        }
        outFileDesc.close();
    } else {
        std::cerr << "Unable to open file for writing.\n";
        return 1;
    }
    
    // Report the time of execution for sorting
    double ascendingTime = double(endAscending - startAscending) / CLOCKS_PER_SEC;
    double descendingTime = double(endDescending - startDescending) / CLOCKS_PER_SEC;
    std::cout << "Time taken for ascending sort: " << ascendingTime << " seconds\n";
    std::cout << "Time taken for descending sort: " << descendingTime << " seconds\n";


    /* Quit program successfully */
    return 0;
}