#include <stdio.h>
#include <windows.h>

int main(void)
{
    COORD pos1 = {0, 2};        // x, y��ǥ�� ���� 0�� 2
    COORD pos2 = {6, 6};
    COORD pos3 = {15, 4};

    HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleCursorPosition(hConsoleOut, pos1);
    printf("ù ��° �λ� : �ȳ��ϼ���.");
    getchar();

    SetConsoleCursorPosition(hConsoleOut, pos2);
    printf("�� ��° �λ� : �ȳ��ϼ���.");
    getchar();

    SetConsoleCursorPosition(hConsoleOut, pos3);
    printf("�� ��° �λ� : �ȳ��ϼ���.");
    getchar();

    return 0;
}