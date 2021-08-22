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
---
### 2. 블록의 좌우 이동과 회전
- 콘솔 I/O
```
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
```
- 블록의 회전과 이동원리
```
/* 함 수 : void ShiftLeft(void)
 * 기 능 : 블록을 왼쪽으로 한 칸 이동
 * 반 환 : void
 *
 */
void ShiftLeft(void)
{
    DeleteBlock(blockModel[GetCurrentBlockIdx()]);
    curPosX -= 2;

    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

/* 함 수 : void ShiftRight(void)
 * 기 능 : 블록을 오른쪽으로 한 칸 이동
 * 반 환 : void
 *
 */
void ShiftRight(void)
{
    DeleteBlock(blockModel[GetCurrentBlockIdx()]);
    curPosX += 2;

    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

/* 함 수 : void RotateBlock(void)
 * 기 능 : 블록을 90도 회전
 * 반 환 : void
 *
 */
void RotateBlock(void)
{
    int nextRotSte;

    DeleteBlock(blockModel[GetCurrentBlockIdx()]);
    
    nextRotSte = rotateSte + 1;
    nextRotSte %= 4;
    rotateSte = nextRotSte;

    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

/* 함 수 : void ProcessKeyInput(void)
 * 기 능 : 키 입력 처리
 * 반 환 : void
 *
 */
void ProcessKeyInput(void)
{
    int i;
    int key;

    for (i = 0; i < KEY_SENSITIVE; i++)
    {
        if (_kbhit() != 0)
        {
            key = _getch();
            
            switch (key)
            {
            case LEFT:
                ShiftLeft();
                break;
            case RIGHT:
                ShiftRight();
                break;
            case UP:
                RotateBlock();
            }
        }
        if (i % keyDelayRate == 0)
        {
            Sleep(SYS_DELAY);
        }
    }
}

/* 함 수 : void InitKeyDelayRate(int rate)
 * 기 능 : 속도 조절, 값이 클수록 속도 증가
 * 반 환 : void
 *
 */
void InitKeyDelayRate(int rate)
{
    if (rate < 1)
        return;
    keyDelayRate = rate;
}
```
---
### 3. 충돌 검사와 블록 쌓기
- 특수문자를 이용해서 그림 그리기
```
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
```
---
### 4. 블록의 소멸과 레벨 그리고 스페이스바 입력 처리
- 끝!