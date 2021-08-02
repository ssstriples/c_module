/* Name : tetrisMain.c ver 1.1
 * Content : main 함수의 정의
 * Implementation : LSH
 *
 * Last modified 2021.08.02
 */
#include <windows.h>
#include "keyCurControl.h"
#include "blockStageControl.h"

#define START_CURPOS_X  (5 * 2)
#define START_CURPOS_Y  (0)

int main(void)
{
    /* 게임 속도 설정 */
    InitKeyDelayRate(10);

    /* 커서 깜빡임 제거 */
    RemoveCursor();

    /* 새 블록의 등장위치 설정 */
    InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

    /* 블록 선택 */
    ChooseBlock();

    /* 내리는 작업 시작 */
    while (1)
    {
        /* 블록 한 칸 아래로 이동 */
        BlockDown();

        /* 게이머 키 입력 처리 */
        ProcessKeyInput();
    }

    return 0;
}
/* end of file */