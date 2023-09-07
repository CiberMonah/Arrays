#include <stdio.h>
#include "Arrays.h"


int main()
{
    char text[][MAX_LEN_STR] = {};

    FILE *fp;

    if ((fp = fopen("rect.txt", "r")) == NULL) {
        printf("File didnt open");
        getchar();
        return 0;
    }
    //printf("%s", read_text_from_file_rect(text, fp));
    print_text(text, read_text_from_file_rect(text, fp));

}
