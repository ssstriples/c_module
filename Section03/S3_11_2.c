#include <stdio.h>

int main(void)
{
    int num, i;
    int total = 0;

    while(1)
    {    
        fputs("2 이상 입력 : ", stdout);
        scanf("%d", &num);
        
        if (num > 1)
            break;
        else
            puts("2 이상이 아닙니다. 다시 입력!");
    }

    i = 1;
    while( num >= (total + i))
    {
        total += i;
        i++;
    }
    
    printf("%d를 더할 때 처음 %d를 넘기 시작한다. \n", i, num);
    printf("%d를 넘기 이전의 합 : %d \n", num, total);
    printf("%d를 넘은 이후의 합 : %d \n", num, total + i);

    return 0;
}