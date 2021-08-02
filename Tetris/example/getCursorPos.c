#include <stdio.h>
#include <windows.h>

int main(void)
{
    CONSOLE_SCREEN_BUFFER_INFO curInfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    printf("[%d, %d]\n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y);

    puts("First Hello World");

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    printf("[%d, %d]\n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y);

    puts("Second Hello World");

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    printf("[%d, %d]\n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y);

    return 0;
}