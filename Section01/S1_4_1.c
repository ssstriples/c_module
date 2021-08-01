#include <stdio.h>

int main(void)
{
    int total = 0;
    char input;

    while(1)
    {
        fputs("Data input(Ctrl+Z to exit) : ", stdout);
        input = getchar();
        if (input == EOF){
            break;
        }
        fflush(stdin);
        total++;
    }
    printf("입력된 문자의 수 : %d \n", total);
    return 0;
}