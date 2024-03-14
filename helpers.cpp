/*
 * Created by Aimuel Emmanuel on 2024-03-10.
 * This module contains all the helper functions to be used in this program.
 *
 * This file contains 1 function used to implement the shaker sort algorithm.
 */

/* Include header file */
#include "headers.h"


/* Function Definitions */

/*
 * shakerSort
 *
 * Purpose: Implement shaker sort algorithm that alternates the direction in which the array elements are scanned during each pass
 * Parameter:
 *  <1> arr: array to be sorted as a vector
 * Precondition: None
 * Returns: tNone
 * Side effect: None
 */


void shakerSort(std::vector<int>& arr) {
    bool swapped = true;
    int start = 0;
    int end = arr.size() - 1;


    // reset the swapped flag on entering the loop, because it might be true from a previous iteration.
    while (swapped) {
        swapped = false;

        // loop from left to right same as the bubble sort   
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // if nothing moved, then array is sorted.
        if (!swapped) break;

        // otherwise, reset the swapped flag so that it can be used in the next stage
        swapped = false;

        // move the end point back by one, because item at the end is in its rightful spot
        --end;

        // from right to left, doing the same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        // increase the starting point, because the last stage would have moved the next smallest number to its rightful spot.
        ++start;
    }
}

