#include <stdio.h>

int main(void)
{
    double n1;
    double n2;

    fputs("두 개의 실수 입력 : ", stdout);
    scanf("%lf %lf", &n1, &n2);

    printf("덧셈 결과 : %f \n", n1 + n2);
    printf("뺄셈 결과 : %f \n", n1 - n2);
    printf("곱셈 결과 : %f \n", n1 * n2);
    printf("나눗셈 결과 : %f \n", n1 / n2);
    return 0;
}