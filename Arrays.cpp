#include "Arrays.h"
#include <stdio.h>

void replace_(char* buf, int size_) {
    for(int i = 0 ; i < size_; i++) {
        if(buf[i] == '\n') buf[i] = '\0';
        }
}

int compare(const void *arg1, const void *arg2) {
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

void make_poem(char** text, int lines) {
    //srand(time(NULL));

    int rhyme_1 = rand() % (lines - 1);
    int rhyme_2 = rand() % (lines - 1);

    printf("%s\n%s\n%s\n%s\n", text[rhyme_1], text[rhyme_2], text[rhyme_1 + 1], text[rhyme_2 + 1]);
}
