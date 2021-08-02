#include <stdio.h>
#include <windows.h>

void showBlock(char blockInfo[][4]);
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos(void);
void RemoveCursor(void);

char blockModel[][4][4] = 
{
    /* ■
       ■ ■ ■  */
    {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0}
    },
    {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0}
    },
    {
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    },
    {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    }
};

int main(void)
{
    RemoveCursor();
    
    SetCurrentCursorPos(0, 0);
    showBlock(blockModel[0]);

    SetCurrentCursorPos(0, 8);
    showBlock(blockModel[1]);

    SetCurrentCursorPos(12, 0);
    showBlock(blockModel[2]);

    SetCurrentCursorPos(12, 8);
    showBlock(blockModel[3]);
    getchar();
    return 0;
}

void showBlock(char blockInfo[][4])
{
    int y, x;
    COORD curPos = GetCurrentCursorPos();
    
    for (y=0; y<4; y++)
    {
        for (x=0; x<4; x++)
        {
            SetCurrentCursorPos(curPos.X + (x*2), curPos.Y + y);

            if (blockInfo[y][x] == 1)
                printf("■");
        }
    }
    SetCurrentCursorPos(curPos.X, curPos.Y);    // 커서 위치 원래대로
}

void SetCurrentCursorPos(int x, int y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD GetCurrentCursorPos(void)
{
    COORD curPoint;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curPoint.X = curInfo.dwCursorPosition.X;
    curPoint.Y = curInfo.dwCursorPosition.Y;

    return curPoint;
}

void RemoveCursor(void)
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}