#include <stdio.h>
#include <locale.h>
#include "Arrays.h"

const char fname[] = "poem.txt";

int main()
{
    FILE *fp = nullptr;
    unsigned long size_of_file = 0;

    if ((fp = fopen(fname, "r")) == NULL) {
        printf("File reading error");
        return 0;
    }

    //TEXT_5
    fseek (fp, 0, SEEK_END);
    size_of_file = ftell(fp);
    rewind (fp);

    //printf("Size of %s : %ld bytes.\n", fname, size_of_file);

    char* buf = (char*)calloc(size_of_file + 1, sizeof(char));
    if(buf == NULL) {
        printf("Memory allocation error\n");
        return 0;
    }

    fread(buf, sizeof(char), size_of_file, fp);//reading buf

    int num_of_lines = count_lines(fp); //reading number of lines        //по  буферу пробежать replace

    char** text = (char**)calloc(num_of_lines, 8); //allocate memory for text array of pointers

    if(text == NULL) {
        printf("Memory allocation error\n");
    }

    text[0] = buf; // set first pointer on first char of buf
    /*for(size_t i = 0; i < size_of_file; i++)
        buf[i] = tolower((char)buf[i]);*/
    int lines = 1;

    replace_(buf, size_of_file + 1);

    for(size_t i = 0; i < size_of_file; i++) { //run through all buf
        if(buf[i] == '\n' || buf[i] == '\0')// if buf[i] == \n set next pointer of text on next line
            text[lines++] = buf + i + 1;
    }

    qsort(text, num_of_lines, sizeof(char*), compare_behind);
    for(int i = 0; i < num_of_lines; i++)
        printf("%s\n", text[i]);

    free(*text);
    free(text);
    fclose(fp);
}
