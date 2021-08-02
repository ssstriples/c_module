# C Power Upgrade
# Part2. 기본실력 점검 및 향상
## Section4. 테트리스 게임 프로젝트
---
### 1. 블록 만들고 움직이기

- 커서의 위치이동
```
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
```
- 현재 커서의 위치 정보 얻어오기
```
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
```
- 벽돌을 그리는 원리
```
#include <stdio.h>
#include <windows.h>

void showBlock(char blockInfo[][4]);
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos(void);

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
```
- 커서 깜빡임 제거
```
void RemoveCursor(void)
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
```
- 테트리스 블록 
```

```