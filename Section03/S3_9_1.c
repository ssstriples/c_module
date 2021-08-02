#include <stdio.h>

int main(void)
{
    int num, i;
    int total = 0;

    while(1)
    {
        fputs("1 이상의 정수 입력 : ", stdout);
        scanf("%d", &num);
        
        if (num > 0)
            break;
        else
            puts("1 이상의 정수를 입력해야 합니다.");
    }
    
    for (i = 1; i <= num; i++)
        total += i;

    printf("1부터 %d까지의 합은 %d. \n", num, total);

    return 0;
}