#include <stdio.h>
#define STR_LEN 50

int main(void)
{
    char name[STR_LEN];

    fputs("문자열 입력 : ", stdout);
    gets(name);

    fputs("입력된 문자열 : ", stdout);
    puts(name);

    return 0;
}