#include <stdio.h>
#define ARR_LEN 20

int main(void)
{
    int num;
    int binaryArr[ARR_LEN];
    int binaryCnt = 0;

    fputs("10진수 정수 입력 : ", stdout);
    scanf("%d", &num);

    printf("%d를 2진수로 변환하면 : ", num);
    /* 2진수로 변환하기 위한 나머지 연산 */
    while(num > 0)
    {
        binaryArr[binaryCnt++] = num % 2;
        num /= 2;
    }

    /* 나머지를 거꾸로 출력하여 2진수를 보임 */
    while(binaryCnt > 0)
    {
        printf("%d", binaryArr[binaryCnt - 1]);
        binaryCnt -= 1;
    }
    puts("");
    return 0;
}