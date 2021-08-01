#include <stdio.h>
#define PI 3.14

int main(void)
{
    double rad;

    fputs("반지름 입력 : ", stdout);
    scanf("%lf", &rad);

    printf("원의 넓이 : %f \n", rad*rad*PI);
    return 0;
}