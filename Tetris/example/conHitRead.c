#include <stdio.h>
#include <conio.h>

int main(void)
{
    int i, j;

    while(1)
    {
        while( !_kbhit() )
        {
            puts("Ű �Է�!!");
            for (i=0; i<5000; i++)
                for (j=0; j<5000; j++)
                    ;
        }
        printf("�Էµ� Ű�� �ƽ�Ű �ڵ� : %d \n", _getch());
    }

    return 0;
}