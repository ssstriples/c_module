#include <stdio.h>

int main(void)
{
    char ch;
    int iNum;
    double dNum;
    char str[100];

    printf("[문자, 정수, 실수, 문자열]의 포맷으로 입력: ");
    scanf("%c, %d, %lf, %s", &ch, &iNum, &dNum, str);
    
    printf("입력된 데이터 출력: %c, %d, %.2lf, %s \n", ch, iNum, dNum, str);
    return 0;
}