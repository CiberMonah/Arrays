#include <stdio.h>
#include <locale.h>
#include "Arrays.h"

const char fname[] = "poem.txt";

int main()
{
    FILE *fp = nullptr;
    unsigned long size_of_file = 0;

    if ((fp = fopen(fname, "r")) == NULL) {
        printf("File didnt open");
        getchar();
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
    }

    fread(buf, sizeof(char), size_of_file, fp);//reading buf

    int num_of_lines = count_lines(fp); //reading number of lines
    char** text = (char**)calloc(num_of_lines, 8); //allocate memory for text array of pointers
    text[0] = buf; // set first pointer on first char of buf
    /*for(size_t i = 0; i < size_of_file; i++)
        buf[i] = tolower((char)buf[i]);*/
    int lines = 1;

    for(size_t i = 0; i < size_of_file; i++) { //run through all buf
        if(buf[i] == '\n' || buf[i] == '\0')// if buf[i] == \n set next pointer of text on next line
            text[lines++] = buf + i + 1;
    }

    replace_(buf, size_of_file + 1);

    //char** text_sort = (char**)calloc(num_of_lines, 8);


    //my_super_print(text, num_of_lines);
    //printf("%s", buf);
    //qsort(text_sort, num_of_lines, sizeof(char*), compare);

    //my_super_print(text_sort, num_of_lines);
    /*for(int i = 0; i < num_of_lines; i++)
        printf("%s", text[i]);*/

    qsort(text, num_of_lines, sizeof(char*), compare);

    for(int i = 0; i < num_of_lines; i++)
        printf("%s", text[i]);

    free(buf);
    free(text);
    fclose(fp);



    /* TEXT_4


    int num_of_lines = count_lines(fp);

    //   move cursor to the start of file

    char** text = (char**)calloc(num_of_lines, 8);
    if(text == nullptr) return 0;

    char buf[50] = "";
    //printf("Input adress and string\n");
    for(int i = 0; i < num_of_lines; i++) {
        fgets(buf, MAX_LEN_STR, fp);
        //detecting error
        text[i] = strdup(buf);
        //printf("iter nu m : %d\n", i + 1);
        //print_text_updated(text, i + 1);
        //Ptr(text[i])
        //printf("%s", text[i]);
    }

    //printf("\n\nPrinted text with adresses:\n");
    //printf("Vne cycle:\n");
    //printf("%s", text[0]);
    print_text_updated(text, num_of_lines);

    free_text(text, num_of_lines);
    fclose(fp);
    */
}
