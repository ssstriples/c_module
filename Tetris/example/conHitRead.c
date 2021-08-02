#include <stdio.h>
#include <conio.h>

int main(void)
{
    int i, j;

    while(1)
    {
        while( !_kbhit() )
        {
            puts("키 입력!!");
            for (i=0; i<5000; i++)
                for (j=0; j<5000; j++)
                    ;
        }
        printf("입력된 키의 아스키 코드 : %d \n", _getch());
    }

    return 0;
}