/* Name : blockStageControl.c ver 1.3
 * Content : 블록, 게임화면 컨트롤 함수들의 정의
 * Implementation : LSH
 *
 * Last modified 2021.08.22
 */

#include <time.h>
#include "common.h"
#include "point.h"
#include "blockInfo.h"
#include "keyCurControl.h"
#include "blockStageControl.h"
#include "scoreLevelControl.h"

#define GBOARD_WIDTH    10
#define GBOARD_HEIGHT   20

#define GBOARD_ORIGIN_X 4
#define GBOARD_ORIGIN_Y 2

static int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2] = { 0, };

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

/* 함 수 : int BlockDown(void)
 * 기 능 : 모니터에 그려진 블록을 아래로 한 칸 내림
 * 반 환 : 성공 시 1, 실패 시 0
 *
 */
int BlockDown(void)
{
    if (!DetectCollision(curPosX, curPosY + 1, blockModel[GetCurrentBlockIdx()]))
    {
        /* 행 단위로 채워진 블록 정보 검사 */
        AddCurrentBlockInfoToBoard();
        RemoveFillUpline();
        return 0;
    }

    DeleteBlock(blockModel[GetCurrentBlockIdx()]);
    curPosY += 1;

    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[GetCurrentBlockIdx()]);

    return 1;
}

/* 함 수 : void ShiftLeft(void)
 * 기 능 : 블록을 왼쪽으로 한 칸 이동
 * 반 환 : void
 *
 */
void ShiftLeft(void)
{
    if (!DetectCollision(curPosX - 2, curPosY, blockModel[GetCurrentBlockIdx()]))
        return;

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
    if (!DetectCollision(curPosX + 2, curPosY, blockModel[GetCurrentBlockIdx()]))
        return;

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
    int beforeRotSte = rotateSte;   // 복원을 위한 정보

    DeleteBlock(blockModel[GetCurrentBlockIdx()]);
    
    nextRotSte = rotateSte + 1;
    nextRotSte %= 4;
    rotateSte = nextRotSte;

    if (!DetectCollision(curPosX, curPosY, blockModel[GetCurrentBlockIdx()]))
    {
        rotateSte = beforeRotSte;
        return;
    }

    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

/* 함 수 : int DetectCollision(int posX, int posY, char blockModel[][4])
 * 기 능 : 블록의 이동 및 회전 가능 여부 판단
 * 반 환 : 이동 및 회전 가능 시 1 반환
 *
 */
int DetectCollision(int posX, int posY, char blockModel[][4])
{
    int x, y;

    /* gameBoardInfo 배열의 좌표로 변경 */
    int arrX = (posX - GBOARD_ORIGIN_X) / 2;
    int arrY = posY - GBOARD_ORIGIN_Y;
    
    /* 충돌 검사 */
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            /* Short Circuit Evaluation에 의해 배열 일부만 검사 */
            if (blockModel[y][x] == 1 && gameBoardInfo[arrY + y][arrX + x] == 1)
                return 0;
        }
    }
    return 1;
}

/* 함 수 : void DrawSolidBlocks(void)
 * 기 능 : 게임 판에 굳어진 블록을 그린다.
 * 반 환 : void
 *
 */
void DrawSolidBlocks(void)
{
    int x, y;
    int cursX, cursY;

    for (y = 0; y < GBOARD_HEIGHT; y++)
    {
        for (x = 1; x < GBOARD_WIDTH + 1; x++)
        {
            cursX = x * 2 + GBOARD_ORIGIN_X;
            cursY = y + GBOARD_ORIGIN_Y;
            SetCurrentCursorPos(cursX, cursY);
            
            if (gameBoardInfo[y][x] == 1)
                printf("■");
            else
                printf("  ");
        }
    }
}

/* 함 수 : void RemoveFillUpline(void)
 * 기 능 : 행 단위로 채워진 블록을 삭제한다.
 * 반 환 : void
 *
 */
void RemoveFillUpline(void)
{
    int x, y;
    int line;

    for (y = GBOARD_HEIGHT - 1; y > 0; y--)
    {
        for (x = 1; x < GBOARD_WIDTH + 1; x++)
        {
            if (gameBoardInfo[y][x] != 1)
                break;
        }

        if (x == (GBOARD_WIDTH + 1))    // 라인이 다 채워지면
        {
            for (line = 0; y - line > 0; line++)
            {
                memcpy(&gameBoardInfo[y-line][1], &gameBoardInfo[(y-line) - 1][1], GBOARD_WIDTH * sizeof(int));
            }

            y++;    // 배열 정보가 아래로 한 칸씩 이동했으므로
            AddGameScore(10);
            ShowCurrentScoreAndLevel();
        }
    }
    DrawSolidBlocks();
}

/* 함 수 : void SolidCurrentBlock(void)
 * 기 능 : 현재의 블록을 바닥으로 이동시켜 굳힌다.
 * 반 환 : void
 *
 */
void SolidCurrentBlock(void)
{
    while (BlockDown());
}

/* 함 수 : void DrawGameBoard(void)
 * 기 능 : 게임 판의 경계 면을 그린다.
 * 반 환 : void
 *
 */
void DrawGameBoard(void)
{
    int x, y;

    /* 시각적인 부분 처리 */
    for (y = 0; y <= GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);

        if (y == GBOARD_HEIGHT)
            printf("└─");
        else
            printf("│");
    }

    for (y = 0; y <= GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + y);

        if (y == GBOARD_HEIGHT)
            printf("┘");
        else
            printf("│");
    }

    for (x = 1; x < GBOARD_WIDTH + 1; x++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);

        printf("──");
    }
    SetCurrentCursorPos(0, 0);

    /* 데이터 부분 처리 */
    for (y = 0; y < GBOARD_HEIGHT; y++)
    {
        gameBoardInfo[y][0] = 1;
        gameBoardInfo[y][GBOARD_WIDTH+1] = 1;
    }

    for (x = 0; x < GBOARD_WIDTH + 2; x++)
    {
        gameBoardInfo[GBOARD_HEIGHT][x] = 1;
    }
}

/* 함 수 : void AddCurrentBlockInfoToBoard(void)
 * 기 능 : 배열에 현재 블록의 정보를 추가한다.
 * 반 환 : void
 *
 */
void AddCurrentBlockInfoToBoard(void)
{
    int x, y;

    int arrCurX;
    int arrCurY;

    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            /* 커서 위치 정보를 배열 index 정보로 변경 */
            arrCurX = (curPosX - GBOARD_ORIGIN_X) / 2;
            arrCurY = curPosY - GBOARD_ORIGIN_Y;

            if (blockModel[GetCurrentBlockIdx()][y][x] == 1)
                gameBoardInfo[arrCurY + y][arrCurX + x] = 1;
        }
    }
}

/* 함 수 : int IsGameOver(void)
 * 기 능 : 게임이 종료되었는지 확인하는 함수
 * 반 환 : 게임 종료 시 1 반환
 *
 */
int IsGameOver(void)
{
    if (!DetectCollision(curPosX, curPosY, blockModel[GetCurrentBlockIdx()]))
        return 1;
    else
        return 0;
}

