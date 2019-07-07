#pragma once
#include"algorithm.h"
#include<string.h>
#include "Windows.h"
#pragma comment(lib,"WinMM.Lib")

int** Chessboard_init()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int j = 9; j>=0; j--)
	{
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
		printf("%4d", j);
		for (int i = 0; i < 9; i++)
		{
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			printf("%4d", Chessboard[i][j]);
		}
		printf("\n");
	}
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf("       0   1   2   3   4   5   6   7   8   \n") ;
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	return (int**)Chessboard;
}
int flag;
void do1(int* step) {
	CHESSMOVE move;
	makepossiblemove(RED, 1);
	scanf_s("%d%d%d%d", &move.ptFrom.x, &move.ptFrom.y, &move.ptTo.x, &move.ptTo.y);
	flag = -1;
	if ((move.ptFrom.x < 9) && (move.ptFrom.x >= 0) && (move.ptFrom.y < 10) && (move.ptFrom.y >= 0) && (move.ptTo.x < 9) && (move.ptTo.x >= 0) && (move.ptTo.y < 10) && (move.ptTo.y >= 0))
	{
		int i;
		for (i = 0; i < totalmove; i++)
		{
			if ((move.ptFrom.x == Movelist[1][i].ptFrom.x) && (move.ptFrom.y == Movelist[1][i].ptFrom.y) && (move.ptTo.x == Movelist[1][i].ptTo.x) && (move.ptTo.y == Movelist[1][i].ptTo.y))
			{
				flag = i;
				DoMove(&move);
				system("cls");
				Chessboard_init();
				(*step)++;
				break;
			}

		}

		if (flag == -1)
		{
			printf("走错子啦!\n");
		}
		if (gameover(BLACK) != 0)
		{
			printf("恭喜红方获得胜利\n游戏结束\n");
			exit(0);
		}
	}
	else printf("走错啦，重新走\n");
}
	void do2(int* step){
		CHESSMOVE move;
		makepossiblemove(BLACK, 1);
		scanf_s("%d%d%d%d", &move.ptFrom.x, &move.ptFrom.y, &move.ptTo.x, &move.ptTo.y);
			flag = -1;
		if ((move.ptFrom.x < 9) && (move.ptFrom.x >= 0) && (move.ptFrom.y < 10) && (move.ptFrom.y >= 0) && (move.ptTo.x < 9) && (move.ptTo.x >= 0) && (move.ptTo.y < 10) && (move.ptTo.y >= 0))
		{
			int i;
			for (i = 0; i < totalmove; i++)
			{
				if ((move.ptFrom.x == Movelist[1][i].ptFrom.x) && (move.ptFrom.y == Movelist[1][i].ptFrom.y) && (move.ptTo.x == Movelist[1][i].ptTo.x) && (move.ptTo.y == Movelist[1][i].ptTo.y))
				{
					flag = i;
					DoMove(&move);
					system("cls");
					Chessboard_init();
					(*step)++;
					break;
				}

			}

			if (flag == -1)
			{
				printf("走错子啦!\n");
			}
			if (gameover(RED) != 0)
			{
				printf("恭喜黑方获得胜利\n游戏结束\n");
				exit(0);
			}
		}
		else printf("走错啦，重新走\n");
}
void p2p() {
	for (;;)
	{
		int step = 0;
		
		do
		{
			printf("请红方走子：");
			do1(&step);
		} while (step % 2 == 0);
		do {
			printf("请黑方走子：");
			do2(&step);
		} while (step % 2 == 1);
	}


}
void do3(int* step) {

	  SearchAGoodMove();
	  system("cls");
	Chessboard_init();
	if (gameover(RED) != 0)
	{
		printf("你输了\n游戏结束\n");
		exit(0);
	}
	(*step)++;

}
void pm() 
{
	for (;;)
	{
		int step1 = 0;
		do
		{
			printf("请红方走子：");
			do1(&step1);
		} while (step1 % 2 == 0);
		do {
			do3(&step1);
			} while (step1 % 2 == 1);
		}
	}






void main(void)
{
	int a;
		
			PlaySound(TEXT("F:\\C PROJECT\\background2.wav"), 0, SND_ASYNC | SND_LOOP);
		
	

	for (;;)
	{
		printf("please chose the mode \n 1 people to people \n 2 peopel to machine");
		scanf_s("%d", &a);
		Chessboard_init();
		if (a == 1)
		{
			p2p();
		}
		else if (a == 2)
		{
			pm();
		}
		else system("cls");
	}
	
}