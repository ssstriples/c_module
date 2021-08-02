/* Name : blockStageControl.h ver 1.0
 * Content : ���, ����ȭ�� ��Ʈ�� �Լ����� ����
 * Implementation : LSH
 *
 * Last modified 2021.08.02
 */
#ifndef __BLOCK_STAGE_H_
#define __BLOCK_STAGE_H_

void InitNewBlockPos(int x, int y);
void ChooseBlock(void);
int GetCurrentBlockIdx(void);
void ShowBlock(char blockInfo[][4]);
void DeleteBlock(char blockInfo[][4]);
void BlockDown(void);


#endif