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
    printf("\n---The statistics of the following array---\n\n");

    print_array(array, length); // initially printing the elements of the dataset

    // printing all the values: mean, median, max, and min
    printf("\nThe mean, median, max, and min goes as follows: \n\n");

    unsigned char max = find_maximum(array, length); // max is initialized to the returned max value
    printf("Maximum = %i\n\n", max);

    unsigned char min = find_minimum(array, length); // min is initialized to the returned min value
    printf("Minimum = %i\n\n", min);

    sort_array(array, length); // sorting the dataset in descending order

    unsigned char median = find_median(array, length); // after sorting, median is initialized to the returned rounded median value
    printf("Median = %i\n\n", median);

    unsigned char mean = find_mean(array, length); // mean is initialized to the returned rounded mean value
    printf("Mean = %i\n", mean);

    // printing the sorted array at the end so that max and min indexes match the original dataset
    printf("\nAfter sorting the array:\n");
    print_array(array, length); // printing the sorted dataset
    printf("\n"); // extra line for better output visibility in the terminal
}

/* Prints the elements of the array */
void print_array(unsigned char* array, int length){
    if(length <= 0){ // checking if the received length is less than or equal to zero
        return; // if it is, return to avoid accessing wrong memory
    }

    int count = 0; // count is used to organize the printing of elements, used only for aesthetics
    printf("Elements of the array: \n{");
    for(int i = 0; i < length; i++){ // looping over the dataset to print each element
        if(i < length-1){ // print the regular format if i is less than length - 1
            printf("%i ,", array[i]); // printing the dataset elements
            count++; // adding 1 to count
            if(count % 8 == 0){ // if count reaches 8, reset count and go to next line
                printf("\n");
                count = 0;
            }
        } else printf("%i", array[i]); // print the last element without comma
    }
    printf("}\n"); // close the bracket, done for aesthetics
}

/* Finds the median value of the given dataset */
unsigned char find_median(unsigned char* array, int length) {
    if(length <= 0){ // checking if the received length is less than or equal to zero
        return 0; // if it is, return to avoid accessing wrong memory
    }

    int middle = length/2; // extract the middle index to compute the median
    double med = 0.0; // initialize med to 0
    int index = middle; // index of the median element

    if(length % 2 == 0) { // if length is even
        med = (array[middle] + array[middle - 1]) / 2.0; // average the two middle elements
        int index2 = middle - 1; // second middle index
        printf("Median between index %i and index %i\n", index2, index); // print both indexes
    } else { // if length is odd
        med = array[middle]; // median is the middle element
        printf("Median at index %i\n", index); // print the index
    }

    int rounded_median = (int)(med + 0.5); // round to nearest integer
    return (unsigned char)rounded_median; // return as unsigned char
}

/* Finds the average for the dataset */
unsigned char find_mean(unsigned char* array, int length) {
    if(length <= 0){ // checking if the received length is less than or equal to zero
        return 0; // if it is, return to avoid accessing wrong memory
    }

    double sum = 0;
    for(int i = 0; i < length; i++) {
        sum += array[i]; // adding each element to sum
    }

    double average = sum/length; // dividing sum by length to get the average
    int rounded_average = (int)(average + 0.5); // rounding to nearest integer
    return (unsigned char)rounded_average; // return as unsigned char
}

/* Finds the maximum value of a given array */
unsigned char find_maximum(unsigned char* array, int length) {
    if(length <= 0){ // checking if the received length is less than or equal to zero
        return 0; // if it is, return to avoid accessing wrong memory
    }

    unsigned char max = array[0]; // assume first element is the maximum
    int index = 0; // store index of maximum

    for(int i = 1; i < length; i++) {
        if(max < array[i]) { // if current element is greater than max
            max = array[i]; // update max
            index = i; // update index
        }
    }
    printf("Maximum at index %i\n", index); // print the index of maximum
    return max; // return the maximum value
}

/* Finds the minimum value of a given array */
unsigned char find_minimum(unsigned char* array, int length) {
    if(length <= 0){ // checking if the received length is less than or equal to zero
        return 0; // if it is, return to avoid accessing wrong memory
    }

    unsigned char min = array[0]; // assume first element is the minimum
    int index = 0; // store index of minimum

    for(int i = 1; i < length; i++) {
        if(min > array[i]) { // if current element is less than min
            min = array[i]; // update min
            index = i; // update index
        }
    }
    printf("Minimum at index %i\n", index); // print the index of minimum
    return min; // return the minimum value
}


/* Sorts the given array from largest to smallest */
void sort_array(unsigned char* array, int length){
    if(length <= 0){ // checking if the received length is less than or equal to zero
        return; // if it is, return to avoid accessing wrong memory
    }

    for(int i = 0; i < length-1; i++) { // outer loop picks one element at a time
        for(int j = i+1; j < length; j++) { // inner loop compares with all elements after it
            if(array[i] < array[j]) { // if a bigger value is found, swap
                int temp = array[i]; // store current value in temp
                array[i] = array[j]; // replace with bigger value
                array[j] = temp; // put old value in new position
            }
        }
    }
}
























