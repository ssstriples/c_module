/* Name : keyCurControl.c ver 1.1
 * Content : 커서, 키보드 컨트롤 함수들의 정의
 * Implementation : LSH
 *
 * Last modified 2021.08.02
 */

#include <conio.h>
#include <windows.h>
#include "point.h"
#include "blockStageControl.h"

#define KEY_SENSITIVE   100
#define SYS_DELAY       20

#define LEFT    75
#define RIGHT   77
#define UP      72
#define DOWN    80

static int keyDelayRate;    // 값이 클수록 속도 증가

 /* 함 수 : void RemoveCursor(void)
  * 기 능 : 깜빡 거리는 커서의 제거
  * 반 환 : void
  *
  */
void RemoveCursor(void)
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

/* 함 수 : point GetCurrentCursorPos(void)
 * 기 능 : 현재 커서 위치 정보를 담은 구조체 변수 반환
 * 반 환 : point
 *
 */
point GetCurrentCursorPos(void)
{
    point curPoint;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curPoint.x = curInfo.dwCursorPosition.X;
    curPoint.y = curInfo.dwCursorPosition.Y;

    return curPoint;
}

/* 함 수 : void SetCurrentCursorPos(int x, int y)
 * 기 능 : 커서 위치를 설정
 * 반 환 : void
 *
 */
void SetCurrentCursorPos(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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

/* end of file */