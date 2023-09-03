#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>

const unsigned int MAX_LEN_STR = 50;

void print_data (const char data[][MAX_LEN_STR], unsigned int nums);
void print_data_as_line(const char data [], unsigned int raws, unsigned int cols);
void print_data_as_triangle(const int data [], unsigned int raws);
void read_data_as_triangle_from_file (int data[], unsigned int raws, FILE *fp);
void read_data_from_file(char data[][MAX_LEN_STR], FILE *fp);




#endif // ARRAYS_H_INCLUDED
