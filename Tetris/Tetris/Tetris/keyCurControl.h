/* Name : keyCurControl.h ver 1.2
 * Content : 커서, 키보드 컨트롤 함수들의 정리
 * Implementation : LSH
 *
 * Last modified 2021.08.22
 */

#ifndef __KEY_CURSOR_H_
#define __KEY_CURSOR_H_

#include "point.h"

void RemoveCursor(void);
point GetCurrentCursorPos(void);
void SetCurrentCursorPos(int x, int y);
int ProcessKeyInput(void);
void InitKeyDelayRate(int rate);
void KeyDelaySpeedCtl(int addSpeed);

#endif