#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <assert.h>
#include <ctype.h>
#define Ptr(value) printf("%p\n", value);

const unsigned int MAX_LEN_STR = 50;

void print_special_data(int *data);
void print_text(const char data[][MAX_LEN_STR], unsigned int nums);
void print_data_int(const int data[], unsigned int nums);
void print_data_as_line(const char data [], unsigned int raws, unsigned int cols);
void print_data_as_triangle(const int data [], unsigned int raws);
void read_data_as_triangle_from_file (int data[], unsigned int raws, FILE *fp);
void read_data_from_file(char data[][MAX_LEN_STR], FILE *fp);
size_t read_text_from_file_rect(char text[][MAX_LEN_STR], FILE* fp);
char** read_dinamic_text_from_file(char** text, int N_lines, FILE *fp);
void free_text(char** text, int N_lines);
int count_lines(FILE *fp);
void print_text_updated(char** text, int N_lines);
char* my_str_dup(const char *str);
void my_super_print(char** text, int num_of_lines);
void replace_(char* buf, int size_);
int compare(const void *s1, const void* s2);
void swap_(char** ptr1, char** ptr2);

#endif // ARRAYS_H_INCLUDED
