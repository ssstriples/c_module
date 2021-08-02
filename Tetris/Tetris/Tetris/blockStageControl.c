/* Name : blockStageControl.c ver 1.1
 * Content : 블록, 게임화면 컨트롤 함수들의 정의
 * Implementation : LSH
 *
 * Last modified 2021.08.02
 */

#include <time.h>
#include "common.h"
#include "point.h"
#include "blockInfo.h"
#include "keyCurControl.h"

static int currentBlockModel;
static int curPosX, curPosY;
static int rotateSte;

/* 함 수 : void InitNewBlockPos(int x, int y)
 * 기 능 : 블록의 첫 위치 지정
 * 반 환 : void
 *
 */
void InitNewBlockPos(int x, int y)
{
    if (x < 0 || y < 0)
        return;

    curPosX = x;
    curPosY = y;

    SetCurrentCursorPos(x, y);
}

/* 함 수 : void ChooseBlock(void)
 * 기 능 : 출력할 블록을 무작위 선택
 * 반 환 : void
 *
 */
void ChooseBlock(void)
{
    srand((unsigned int)time(NULL));
    currentBlockModel = (rand() % NUM_OF_BLOCK_MODEL) * 4;
}

/* 함 수 : int GetCurrentBlockIdx(void)
 * 기 능 : 현재 출력해야 하는 블록의 index 정보 반환
 * 반 환 : int
 *
 */
int GetCurrentBlockIdx(void)
{
    return currentBlockModel + rotateSte;
}

/* 함 수 : void ShowBlock(char blockInfo[][4])
 * 기 능 : 전달된 인자를 참조하여 블록 출력
 * 반 환 : void
 *
 */
void ShowBlock(char blockInfo[][4])
{
    int y, x;
    point curPos = GetCurrentCursorPos();

    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            SetCurrentCursorPos(curPos.x + x * 2, curPos.y + y);
            if (blockInfo[y][x] == 1)
                printf("■");
        }
    }
    SetCurrentCursorPos(curPos.x, curPos.y);
}

/* 함 수 : void DeleteBlock(char blockInfo[][4])
 * 기 능 : 현재 위치에 출력된 블록 삭제
 * 반 환 : void
 *
 */
void DeleteBlock(char blockInfo[][4])
{
    int y, x;
    point curPos = GetCurrentCursorPos();

    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            SetCurrentCursorPos(curPos.x + x * 2, curPos.y + y);
            if (blockInfo[y][x] == 1)
                printf("  ");   // 공백 두 칸
        }
    }
    SetCurrentCursorPos(curPos.x, curPos.y);
}

/* 함 수 : void BlockDown(void)
 * 기 능 : 모니터에 그려진 블록을 아래로 한 칸 내림
 * 반 환 : void
 *
 */
void BlockDown(void)
{
    DeleteBlock(blockModel[GetCurrentBlockIdx()]);
    curPosY += 1;

    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

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