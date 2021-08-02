/* Name : blockStageControl.c ver 1.0
 * Content : ����, ����ȭ�� ��Ʈ�� �Լ����� ����
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

/* �� �� : void InitNewBlockPos(int x, int y)
 * �� �� : ������ ù ��ġ ����
 * �� ȯ : void
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

/* �� �� : void ChooseBlock(void)
 * �� �� : ����� ������ ������ ����
 * �� ȯ : void
 *
 */
void ChooseBlock(void)
{
    srand((unsigned int)time(NULL));
    currentBlockModel = (rand() % NUM_OF_BLOCK_MODEL) * 4;
}

/* �� �� : int GetCurrentBlockIdx(void)
 * �� �� : ���� ����ؾ� �ϴ� ������ index ���� ��ȯ
 * �� ȯ : int
 *
 */
int GetCurrentBlockIdx(void)
{
    return currentBlockModel;
}

/* �� �� : void ShowBlock(char blockInfo[][4])
 * �� �� : ���޵� ���ڸ� �����Ͽ� ���� ���
 * �� ȯ : void
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
                printf("��");
        }
    }
    SetCurrentCursorPos(curPos.x, curPos.y);
}

/* �� �� : void DeleteBlock(char blockInfo[][4])
 * �� �� : ���� ��ġ�� ��µ� ���� ����
 * �� ȯ : void
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
                printf("  ");   // ���� �� ĭ
        }
    }
    SetCurrentCursorPos(curPos.x, curPos.y);
}

/* �� �� : void BlockDown(void)
 * �� �� : ����Ϳ� �׷��� ������ �Ʒ��� �� ĭ ����
 * �� ȯ : void
 *
 */
void BlockDown(void)
{
    DeleteBlock(blockModel[GetCurrentBlockIdx()]);
    curPosY += 1;

    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[GetCurrentBlockIdx()]);
}