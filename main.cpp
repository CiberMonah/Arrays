#include <stdio.h>
#include "Arrays.h"


int main()
{
    FILE *fp;

    if ((fp = fopen("poem.txt", "r")) == NULL) {
        printf("File didnt open");
        getchar();
        return 0;
    }
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
}
