#include <stdio.h>

int main(void)
{
    int total = 0;
    int input;

    while(1)
    {
        fputs("Data input(Ctrl+Z to exit) : ", stdout);

        if (scanf("%d", &input) == EOF){
            break;
        }
        total += input;
    }
    printf("총 합 : %d \n", total);
    return 0;
}