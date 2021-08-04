/* Name : tetrisMain.c ver 1.2
 * Content : main �Լ��� ����
 * Implementation : LSH
 *
 * Last modified 2021.08.04
 */
#include <windows.h>
#include "common.h"
#include "keyCurControl.h"
#include "blockStageControl.h"

#define START_CURPOS_X  (5 * 2)
#define START_CURPOS_Y  (0)

int main(void)
{
    /* ���� �ӵ� ���� */
    InitKeyDelayRate(10);

    /* Ŀ�� ������ ���� */
    RemoveCursor();

    /* ���� ���� �׸��� */
    DrawGameBoard();

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
                AddCurrentBlockInfoToBoard();
                break;
            }

            /* ���̸� Ű �Է� ó�� */
            ProcessKeyInput();
        }
    }

    SetCurrentCursorPos(10, 10);
    puts("Game Over ^^");

    return 0;
}
/* end of file */