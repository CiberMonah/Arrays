#include <stdio.h>
#include "Arrays.h"


int main()
{
    FILE *fp;

    if ((fp = fopen("proba.txt", "r")) == NULL) {
        printf("File didnt open");
        getchar();
        return 0;
    }
    int num_of_lines = count_lines(fp);

    rewind(fp);   // move cursor to the start of file

    char** text = (char**)calloc(num_of_lines, sizeof(char));

    char buf[50] = "";

    for(int i = 0; i < num_of_lines; i++) {
        fgets(buf, 50, fp);
        //printf("%s\n", buf);
        //printf("%d\n", i);
        //ne rabotaet text[i] = strdup(buf);
        text[i] = my_str_dup(buf);

    }
    //printf("Vne cycle:\n");
    //printf("%s", text[0]);
    print_text_updated(text, num_of_lines);

    free_text(text, num_of_lines);
}
