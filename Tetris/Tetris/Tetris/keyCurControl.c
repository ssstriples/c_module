/* Name : keyCurControl.c ver 1.0
 * Content : Ŀ��, Ű���� ��Ʈ�� �Լ����� ����
 * Implementation : LSH
 *
 * Last modified 2021.08.02
 */

#include <stdio.h>
#include <windows.h>
#include "point.h"

 /* �� �� : void RemoveCursor(void)
  * �� �� : ���� �Ÿ��� Ŀ���� ����
  * �� ȯ : void
  *
  */
void RemoveCursor(void)
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

/* �� �� : point GetCurrentCursorPos(void)
 * �� �� : ���� Ŀ�� ��ġ ������ ���� ����ü ���� ��ȯ
 * �� ȯ : point
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

/* �� �� : void SetCurrentCursorPos(int x, int y)
 * �� �� : Ŀ�� ��ġ�� ����
 * �� ȯ : void
 *
 */
void SetCurrentCursorPos(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/* end of file */