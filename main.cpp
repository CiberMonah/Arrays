#include <iostream>
#include "Arrays.h"

using namespace std;

int main()
{
    int data[] = {3, 5,
                  11, 12, 13, 14, 15,
                  21, 22, 23, 24, 25,
                  31, 32, 33, 34, 35};
    print_special_data(data);
    print_data_int(data + 2, sizeof(data) / sizeof(int) - 2);
}
