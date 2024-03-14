/*
 * Created by Aimuel Emmanuel on 2024-03-10.
 * This module serves as the header file. 
 *
 * The header file contains all preprocessor directives with libraries and namespaces.
 * It also contains the function declarations for all functions used in this program.
 */

/* Preprocessor directive */
#pragma once

/* Libraries & Namespace */
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>


/* Function Declarations */

/*
 * shakerSort
 *
 * Module: helpers
 * Author: Emmanuel Aimuel
 * Date: 2024-03-10
 *
 * Purpose: Implement shaker sort algorithm that alternates the direction in which the array elements are scanned during each pass
 * Precondition: None
 *
 * \param vector string containing array to be sorted
 * \return None
 *
 * Side effect: None
 */
void shakerSort(std::vector<int>& arr);