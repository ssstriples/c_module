#include <stdio.h>
#include <windows.h>

/* 게임 판의 크기 */
#define GBOARD_WIDTH    10
#define GBOARD_HEIGHT   20

/* 게임 판을 그릴 기준이 되는 위치 */
#define GBOARD_ORIGIN_X 4
#define GBOARD_ORIGIN_Y 2

void SetCurrentCursorPos(int x, int y);
void DrawGameBoard(void);

int main(void)
{
    DrawGameBoard();
    return 0;
}

void SetCurrentCursorPos(int x, int y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void DrawGameBoard(void)
{
    int x, y;

    /* 시각적인 부분 처리 */
    for (y=0; y<=GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);

        if (y == GBOARD_HEIGHT)
            printf("└─");
        else
            printf("│");
    }

    for (y=0; y<=GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + y);

        if (y == GBOARD_HEIGHT)
            printf("┘");
        else
            printf("│");
    }

    for (x=1 ; x < GBOARD_WIDTH + 1; x++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);

        printf("──");
    }
    SetCurrentCursorPos(0, 0);
}