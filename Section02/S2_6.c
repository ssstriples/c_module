#include <stdio.h>
#define DATA_CNT 7

int main(void)
{
    int num;
    int total = 0;
    int max = 0, min = 0;

    /** 초기 입력 **/
    fputs("정수형 데이터 입력 : ", stdout);
    scanf("%d", &num);
    min = num;
    max = num;
    total += num;

    /** 두 번째 이후 입력 **/
    for(int i = 0; i < DATA_CNT - 1; i++)
    {
        fputs("정수형 데이터 입력 : ", stdout);
        scanf("%d", &num);
        
        if(num > max)
            max = num;

        if(num < min)
            min = num;

        total += num;
    }
    printf("최대값 : %d \n", max);
    printf("최소값 : %d \n", min);
    printf("전체합 : %d \n", total);
    printf("평 균 : %f \n", (double)total/DATA_CNT);

    return 0;
}