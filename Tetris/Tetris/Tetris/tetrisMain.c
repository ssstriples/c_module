/* Name : tetrisMain.c ver 1.3
 * Content : main �Լ��� ����
 * Implementation : LSH
 *
 * Last modified 2021.08.22
 */
#include <windows.h>
#include "common.h"
#include "keyCurControl.h"
#include "blockStageControl.h"
#include "scoreLevelControl.h"

#define START_CURPOS_X  (5 * 2)
#define START_CURPOS_Y  (0)

int main(void)
{
    /* ���� �ӵ� ���� */
    InitKeyDelayRate(5);

    /* Ŀ�� ������ ���� */
    RemoveCursor();

    /* ���� ���� �׸��� */
    DrawGameBoard();

    /* ���� ����, ���� ǥ�� */
    ShowCurrentScoreAndLevel();

    /* �ݺ������� ���ο� ����� ���� */
    while (1)
    {
        /* �� ����� ������ġ ���� */
        InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

        /* ��� ���� */
        ChooseBlock();

        /* ���� ���� Ȯ�� */
        if (IsGameOver())
            break;

        /* ������ �۾� ���� */
        while (1)
        {
            /* ��� �� ĭ �Ʒ��� �̵� */
            if (BlockDown() == 0)   // ��� �̵� ���� ��
            {
                //AddCurrentBlockInfoToBoard();
                break;
            }

            /* ���̸� Ű �Է� ó�� */
            if (ProcessKeyInput())
                break;  // �����̽� �� �Է� ��
        }
    }

    SetCurrentCursorPos(10, 10);
    puts("Game Over ^^");

    return 0;
}
/* end of file */