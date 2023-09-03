#include <iostream>
#include "Arrays.h"

using namespace std;

int main()
{
    /*char data[10][MAX_LEN_STR] = {"Hello world",
                    "How do you do?",
                    "Lets go for a walk",
                    "fsfsfsfs"};
    print_data_as_line (*data, 4, MAX_LEN_STR);*/
    /*int data[] = {1,
                  2,  4,
                  3,  18, -5,
                  23, 44, -8, 10};
    print_data_as_triangle(data, 4);*/

    //int triangle[10] = {};
    FILE *fp;
    /*if ((fp = fopen("my.txt", "r")) == NULL)
    {
        printf("File didnt open");
        getchar();
        return 0;
    }fclose(fp);*/
    if ((fp = fopen("my1.txt", "r")) == NULL)
    {
        printf("File didnt open");
        getchar();
        return 0;
    }
    char data[4][MAX_LEN_STR] = {};
    read_data_from_file(data, fp);
    print_data(data, sizeof(data) / sizeof(data[0]));

    /*read_data_as_triangle_from_file(triangle, 4, fp);
    fclose(fp);
    print_data_as_triangle(triangle, 4);*/
}
