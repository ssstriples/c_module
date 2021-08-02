#include <stdio.h>

int main(void)
{
    int num, i;
    int oddTotal = 0;
    int evenTotal = 0;

    while(1)
    {    
        fputs("자연수 입력 : ", stdout);
        scanf("%d", &num);
        
        if (num > 0)
            break;
        else
            puts("자연수가 아닙니다. 다시 입력!");
    }

    for (i = 1; i <= num; i++)
    {
        if ( i % 2 == 0 )
            evenTotal += i;
        else
            oddTotal += i;
    }

    printf("%d 이하 홀수 합 : %d \n", num, oddTotal);
    printf("%d 이하 짝수 합 : %d \n", num, evenTotal);

    return 0;
}