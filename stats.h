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
 * @file stats.h
 * @brief This is the header file that contains all the function declaration that will be used in the stats.c file
 *
 * 	This file, stats.h, contains brief and detailed information on the declared functions prototype 
 *	Explaining what the functions functionality, parameters, and return values.
 *
 * @author Abdalrahman Al-Zaharna
 * @date May 8th 2026
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Prints the statistical analysis on the given dataset
 *
 * 	This functions purpose is to print some common statistics operations
 *	on the given dataset that includes :
 *		1. sorting
 *		2. Max
 *		3. Min
 *		4. Median
 *		5. Mean
 *	This is done by calling different functions that computes these values
 *
 * @param array: A pointer that points to the unsigned char array
 * @param length: An integer that stores the length of the array
 *
 * @return void
 */

void print_statistics(unsigned char* array, int length);

/**
 * @brief Prints the elements of the array
 *
 * 	This function iterates over an array of size "length" 
 *	and prints out the elements one by one
 *
 * @param array: A pointer that points to the unsigned char array
 * @param length: An integer that stores the length of the array
 *
 * @return void
 */

void print_array(unsigned char* array, int length);

/**
 * @brief Finds the median value of the given dataset
 *
 *	This function must start with the array being sorted, then finds the middle element.
 * 	If the length is even, it adds the two middle elements and divides by 2 and returns the rounded value.
 * 	If the length is odd, it returns the middle element directly.
 *
 * @param array: A pointer that points to the unsigned char array
 * @param length: An integer that stores the length of the array
 * 
 * @return median value of type unsigned char
 */

unsigned char find_median(unsigned char* array, int length);

/**
 * @brief Finds the average for the dataset
 *
 *	This function iterates over the dataset and sums all the values 
 *	and at the end, finds the average value by dividing the sum over the length
 *	then returns a rounded average.	
 *
 * @param array: A pointer that points to the unsigned char array
 * @param length: An integer that stores the length of the array
 *
 * @return mean value of type unsigned char
 */

unsigned char find_mean(unsigned char* array, int length);

/**
 * @brief Finds the maximum value of a given array
 *
 * 	This function will assume the zeroth element to be the biggest value in the array
 *	then loops over the array and compares each element with current max.
 *	If the compared value is greater than current max we set max to that value.
 *	At the end, the largest value will be stored in max
 *	and the function will return the maximum value in the array.
 *
 * @param array: A pointer that points to the unsigned char array
 * @param length: An integer that stores the length of the array
 *
 * @return max value of type unsigned char
 */

unsigned char find_maximum(unsigned char* array, int length);

/**
 * @brief Finds the minimum value of a given array
 *
 *	This function will assume the zeroth element to be the smallest 
 *	then loops over the array and compares each element with current min.
 *	If the compared value is lower than current min we set min to that value.
 *	At the end, the smallest value will be stored in min
 *	and the function will return the minimum value in the array.
 *
 * @param array: A pointer that points to the unsigned char array
 * @param length: An integer that stores the length of the array
 *
 * @return min value of type unsigned char
 */

unsigned char find_minimum(unsigned char* array, int length);

/**
 * @brief Sorts the given array from largest to smallest
 *
 * 	This function sorts the array using selection sort.
 *	It picks one element and compares it with all the elements after it one by one.
 * 	If a bigger value is found, we swap the two elements using a temp variable.
 * 	This keeps going until the whole array is sorted from largest to smallest.
 *
 * @param array: A pointer that points to the unsigned char array
 * @param length: An integer that stores the length of the array
 *
 * @return void
 */

void sort_array(unsigned char* array, int length);


#endif /* __STATS_H__ */











