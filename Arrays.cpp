#include "Arrays.h"
#include <stdio.h>

void print_text(const char data[][MAX_LEN_STR], size_t x) {
    assert(data != NULL);

    for(size_t i = 0; i < x; i++) {
        printf("%p : \n", data[i]);
        printf("%s", (data[i]));
    }
}

void print_data_int(const int data[], unsigned int nums) {
    for(unsigned int i = 0; i < nums; i++)
        printf("%d ", data[i]);
    printf("\n");
}

void read_data_from_file(char data[][MAX_LEN_STR], FILE* fp) {
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

void read_data_as_triangle_from_file (int data[], unsigned int raws, FILE* fp) {
    unsigned int cols = 1;
    unsigned int next = 0;

    for(unsigned int i = 0; i < raws; i++) {
        for(unsigned int j = 0; j < cols; j++)
            fscanf(fp, "%d", &*(data + next + j));
        next += cols;
        cols = cols + 1;
    }
}

void print_special_data(int *data) {
    size_t x = *data;
    size_t y = *(data + 1);

    for(unsigned int i = 0; i < x; i++) {
        for(unsigned int j = 0; j < y; j++)
            printf("%d ", *(data + i * x + j + 2));
        printf("\n");
    }
}

size_t read_text_from_file_rect(char text[][MAX_LEN_STR], FILE* fp) {
    size_t x, y;

    fscanf(fp, "%d %d\n", &x, &y);

    for(size_t i = 0; i < x; i++)
        fgets(text[i], y, fp);
    return x;
}
