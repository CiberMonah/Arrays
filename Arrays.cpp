#include "Arrays.h"
#include <stdio.h>

void replace_(char* buf, int size_) {
    for(int i = 0 ; i < size_; i++) {
        if(buf[i] == '\n') buf[i] = '\0';
        }
}

int compare_str(const void *arg1, const void *arg2) {
   return strcmp(*(char**)arg1, *(char**)arg2);
}

static void str_rev(char *S) {
    int i = 0,j = 0,l = 0;
    char t = 0;
    l = strlen(S);
    i = 0;
    j = l - 1;
    while (i < j)
    {
        t = S[i];
        S[i] = S[j];
        S[j] = t;
        i++;
        j--;
    }
}

int compare_behind(const void *arg1, const void *arg2) {
    char* s1 = *(char**)arg1;
    char* s2 = *(char**)arg2;
    char* s1rev = strdup(s1);
    char* s2rev = strdup(s2);
    str_rev(s1rev);
    str_rev(s2rev);

    return strcmp(s1rev, s2rev);
}

void swap_(char** ptr1, char** ptr2) {
    char* temp = *ptr2;
    *ptr2 = *ptr1;
    *ptr1 = temp;
}


static void swap(void *a, void *b, size_t size) {
    char* tmp;
    tmp = (char*) malloc(size);
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
    free(tmp);
}


void bubble_sort(void* text, int size_, int size_of_elem, int(*comparator)(const void*, const void*)) {

    for(int n = 0; n < size_; n++) {
        int is_swap = 0;
        for(int i = 0; i < size_ - 1 - n; i++)
            if(comparator((char*)text + i * size_of_elem, (char*)text + (i + 1) * size_of_elem) == -1) {
                swap((char*)text + i * size_of_elem, (char*)text + (i + 1) * size_of_elem, size_of_elem);
                is_swap = 1;
            }
        if(is_swap == 0)
            break;
    }
}

void make_poem(char** text, int lines) {
    //srand(time(NULL));

    int rhyme_1 = rand() % (lines - 1);
    int rhyme_2 = rand() % (lines - 1);

    printf("%s\n%s\n%s\n%s\n", text[rhyme_1], text[rhyme_2], text[rhyme_1 + 1], text[rhyme_2 + 1]);
}
