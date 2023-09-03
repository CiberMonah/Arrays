#include "Arrays.h"
#include <stdio.h>

void print_data (const char data[][MAX_LEN_STR], unsigned int nums) {
    for(unsigned int i = 0; i < nums; i++) {
        puts(data[i]);
    }
}

void read_data_from_file(char data[][MAX_LEN_STR], FILE *fp) {
    unsigned int i = 0;
    while(fgets(data[i], MAX_LEN_STR, fp) != NULL)
        i++;
}
void print_data_as_line(const char data [], unsigned int raws, unsigned int cols) {
    for(unsigned int i = 0; i < raws; i++) {
        for(unsigned int j = 0; j < cols; j++)
            printf("%c", *(data + i * cols + j));
        printf("\n");
    }
}

void print_data_as_triangle(const int data[], unsigned int raws) {
    unsigned int cols = 1;
    unsigned int next = 0;

    for(unsigned int i = 0; i < raws; i++) {
        for(unsigned int j = 0; j < cols; j++)
            printf("%d ", *(data + next + j));
        next += cols;
        cols = cols + 1;
        printf("\n");
    }
}

void read_data_as_triangle_from_file (int data[], unsigned int raws, FILE *fp) {
    unsigned int cols = 1;
    unsigned int next = 0;

    for(unsigned int i = 0; i < raws; i++) {
        for(unsigned int j = 0; j < cols; j++)
            fscanf(fp, "%d", &*(data + next + j));
        next += cols;
        cols = cols + 1;
    }
}
