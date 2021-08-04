/* Name : blockStageControl.h ver 1.1
 * Content : 블록, 게임화면 컨트롤 함수들의 선언
 * Implementation : LSH
 *
 * Last modified 2021.08.04
 */
#ifndef __BLOCK_STAGE_H_
#define __BLOCK_STAGE_H_

void InitNewBlockPos(int x, int y);
void ChooseBlock(void);
int GetCurrentBlockIdx(void);
void ShowBlock(char blockInfo[][4]);
void DeleteBlock(char blockInfo[][4]);
int BlockDown(void);
void ShiftLeft(void);
void ShiftRight(void);
void RotateBlock(void);
int DetectCollision(int posX, int posY, char blockModel[][4]);
void DrawGameBoard(void);
void AddCurrentBlockInfoToBoard(void);
int IsGameOver(void);

#endif