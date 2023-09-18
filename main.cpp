#include <stdio.h>
#include <locale.h>
#include "Arrays.h"

const char fname[] = "Onegin1.txt";

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

    char* buf = (char*)calloc(size_of_file + 1, sizeof(char));
    if(buf == NULL) {
        printf("Memory allocation error\n");
        return 0;
    }

    fread(buf, sizeof(char), size_of_file, fp);//reading buf

    int num_of_lines = count_lines(fp); //reading number of lines        //��  ������ ��������� replace

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
    printf("Type 1 to sort behind using qsort from stdlib\nType 2 to normal sort using qsort from stdlib\nType 3 to make poem\n");

    switch(getchar()) {
    case '1':
        qsort(text, num_of_lines, sizeof(char*), compare_behind);
        for(int i = 0; i < num_of_lines; i++)
            printf("%s\n", text[i]);
        break;
    case '2':
        qsort(text, num_of_lines, sizeof(char*), compare);
        for(int i = 0; i < num_of_lines; i++)
            printf("%s\n", text[i]);
        break;
    case '3':
        srand(time(NULL));
        for(int i = 0; i < 5; i++) {
            qsort(text, num_of_lines, sizeof(char*), compare_behind);
            make_poem(text, num_of_lines);
            printf("\n");
        }
        break;
    default: break;
    }


    free(*text);
    free(text);
    fclose(fp);
}
