/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief This file contains the implementation of various statistical functions for dataset analysis.
 *
 *  It includes functions to find the mean, median, maximum, minimum,
 *  and sort a given dataset. All functions are declared in stats.h
 *  and called through print_statistics which outputs the full analysis.
 *
 * @author Abdalrahman Al-Zaharna
 * @date May 8th 2026
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_statistics(test, SIZE);
  return;
}

/* Add other Implementation File Code Here */

/* Prints the statistical analysis on the given dataset */
void print_statistics(unsigned char* array, int length) {
}

/* Prints the elements of the array */
void print_array(unsigned char* array, int length) {
}

/* Finds the median value of the given dataset */
unsigned char find_median(unsigned char* array, int length) {
}

/* Finds the average for the dataset */
unsigned char find_mean(unsigned char* array, int length) {
}

/* Finds the maximum value of a given array */
unsigned char find_maximum(unsigned char* array, int length) {
}

/* Finds the minimum value of a given array */
unsigned char find_minimum(unsigned char* array, int length) {
}

/* Sorts the given array from largest to smallest */
void sort_array(unsigned char* array, int length) {
}
