#include <stdio.h>

int main(void)
{
    int num1, num2, i;
    int total = 0;

    int start, end;

    fputs("두 개의 정수 입력 : ", stdout);
    scanf("%d %d", &num1, &num2);

    if (num1 > num2)
    {
        start = num2;
        end = num1;
    }
    else{
        start = num1;
        end = num2;
    }

    for (i = start; i <= end; i++)
        total += i;

    printf("%d과 %d을 포함하여 그 사이에 있는 정수들의 합 :  %d \n",\ 
        num1, num2, total);

    return 0;
}