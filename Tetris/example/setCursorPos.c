#include <stdio.h>
#include <windows.h>

int main(void)
{
    COORD pos1 = {0, 2};        // x, y좌표가 각각 0과 2
    COORD pos2 = {6, 6};
    COORD pos3 = {15, 4};

    HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleCursorPosition(hConsoleOut, pos1);
    printf("첫 번째 인사 : 안녕하세요.");
    getchar();

    SetConsoleCursorPosition(hConsoleOut, pos2);
    printf("두 번째 인사 : 안녕하세요.");
    getchar();

    SetConsoleCursorPosition(hConsoleOut, pos3);
    printf("세 번째 인사 : 안녕하세요.");
    getchar();

    return 0;
}