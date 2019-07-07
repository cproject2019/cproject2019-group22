#pragma once
#include"basicrules.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int nMaxSearchDepth = 2;
CHESSMOVE cmBestMove;
void findaim(int x, int y);
int Eveluate(int turn);

int DoMove(CHESSMOVE * move)
{
	int nameofpiece;
	nameofpiece = Chessboard[move->ptTo.x][move->ptTo.y];
	Chessboard[move->ptTo.x][move->ptTo.y]
		= Chessboard[move->ptFrom.x][move->ptFrom.y];
	Chessboard[move->ptFrom.x][move->ptFrom.y] = 0;
	return nameofpiece;
}

void UndoMove(CHESSMOVE * move, BYTE nameofpiece)
{
	Chessboard[move->ptFrom.x][move->ptFrom.y]
		= Chessboard[move->ptTo.x][move->ptTo.y];
	Chessboard[move->ptTo.x][move->ptTo.y] = nameofpiece;
}

int gameover(int turn)//judge king is or not existed
{
	int x, y;

	if (turn == RED)  
	{
		for (x = 3; x <= 5; x++)
			for (y = 0; y <= 2; y++)
			{
				if (Chessboard[x][y] == RED_K)
				{
					return 0; 
				}
			}

		return -1000000000;
		      

	}
	else 
	{
		
		for (x = 3; x <= 5; x++)
			for (y = 9; y >= 7; y--)
			{
				if (Chessboard[x][y] == BLACK_K)
				{
					return 0;  
				}
			}

		return -1000000000;  

	}

}




int alphabetaalgorithm(int nDepth, int alpha, int beta)
{
	int nCount;
	int nameofpiece;
	int nScore;
	int i;
	i = gameover((nMaxSearchDepth - nDepth) % 2);
	if (i != 0)  // gameover
		return i;

	if (nDepth == 0)  
		return Eveluate((nMaxSearchDepth - nDepth) % 2);

	nCount = makepossiblemove((nMaxSearchDepth - nDepth) % 2, nDepth);

	int iBestmove = -1;

	for (i = 0; i < nCount; i++)
	{

		nameofpiece = DoMove(&Movelist[nDepth][i]);  // do it
		nScore = -alphabetaalgorithm(nDepth - 1, -beta, -alpha);//use algorithm again
		UndoMove(&Movelist[nDepth][i], nameofpiece);  

		if (nScore > alpha)
		{
			alpha = nScore;    // record max value 

			if (nDepth == nMaxSearchDepth)
				cmBestMove = Movelist[nDepth][i];

			iBestmove = i;  // record best move
		}
		if (alpha >= beta)
		{
			iBestmove = i;  
			break;
		}

	}

	return alpha;
}
CHESSMOVE SearchAGoodMove()
{
	int i;
	i = alphabetaalgorithm(nMaxSearchDepth, -1000000000, 1000000000);

	DoMove(&cmBestMove);

	return (cmBestMove);
}
typedef struct _relation {

	int nameofpiece;
	int attacknumber;
	int defendnumber;
	int attackaim[7];
	int guradaim[7];

} relation;

_POINT pointlist[30];   
int pointnumber;        

relation RelationOfMan[9][10];  


const int MaxValue = 10000;  // 最大极值（最小极值为最大极值的负值）    

							 
							 //basicvalue of 将， 士， 象， 马， 车， 炮， 卒
const int Basicvalue[15] = { 0, 0, 250, 250, 300, 500, 300, 80,
0, 250, 250, 300, 500, 300, 80 };


//flexiabilityvalue of 将， 士， 象， 马， 车， 炮， 卒
const int Flexiabiliytvalue[8] = { 0,  0,   1,   1,  12,   6,   6,  15 };

//position value
const int PositionValues[8][90] = {
	{
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0
	},
	{ // 帅
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    1, -8, -9,  0,  0,  0,  0,  0,  0,  0,
	    5, -8, -9,  0,  0,  0,  0,  0,  0,  0,
	    1, -8, -9,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0
	},
	{ // 士
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  3,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0
	},
	{ // 相
		0,  0, -2,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  3,  0,  0,  0,  0,  0,  0,  0,
     	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    	0,  0, -2,  0,  0,  0,  0,  0,  0,  0
	},
	{ // 马
		0, -3,  5,  4,  2,  2,  5,  4,  2,  2,
	   -3,  2,  4,  6, 10, 12, 20, 10,  8,  2,
 	    2,  4,  6, 10, 13, 11, 12, 11, 15,  2,
	    0,  5,  7,  7, 14, 15, 19, 15,  9,  8,
	    2,-10,  4, 10, 15, 16, 12, 11,  6,  2,
	    0,  5,  7,  7, 14, 15, 19, 15,  9,  8,
	    2,  4,  6, 10, 13, 11, 12, 11, 15,  2,
	   -3,  2,  4,  6, 10, 12, 20, 10,  8,  2,
	    0, -3,  5,  4,  2,  2,  5,  4,  2,  2
	},
	{ // 车
	   -6,  5, -2,  4,  8,  8,  6,  6,  6,  6,
		6,  8,  8,  9, 12, 11, 13,  8, 12,  8,
	    4,  6,  4,  4, 12, 11, 13,  7,  9,  7,
	   12, 12, 12, 12, 14, 14, 16, 14, 16, 13,
	    0,  0, 12, 14, 15, 15, 16, 16, 33, 14,
	   12, 12, 12, 12, 14, 14, 16, 14, 16, 13,
	    4,  6,  4,  4, 12, 11, 13,  7,  9,  7,
     	6,  8,  8,  9, 12, 11, 13,  8, 12,  8,
       -6,  5, -2,  4,  8,  8,  6,  6,  6,  6
	},
	{ // 炮
		0,  0,  1,  0, -1,  0,  0,  1,  2,  4,
		0,  1,  0,  0,  0,  0,  3,  1,  2,  4,
	    1,  2,  4,  0,  3,  0,  3,  0,  0,  0,
	    3,  2,  3,  0,  0,  0,  2, -5, -4, -5,
	    3,  2,  5,  0,  4,  4,  4, -4, -7, -6,
	    3,  2,  3,  0,  0,  0,  2, -5, -4, -5,
	    1,  2,  4,  0,  3,  0,  3,  0,  0,  0,
	    0,  1,  0,  0,  0,  0,  3,  1,  2,  4,
	    0,  0,  1,  0, -1,  0,  0,  1,  2,  4
	},
	{ // 兵
		0,  0,  0, -2,  3, 10, 20, 20, 20,  0,
		0,  0,  0,  0,  0, 18, 27, 30, 30,  0,
	    0,  0,  0, -2,  4, 22, 30, 45, 50,  0,
	    0,  0,  0,  0,  0, 35, 40, 55, 65,  2,
	    0,  0,  0,  6,  7, 40, 42, 55, 70,  4,
	    0,  0,  0,  0,  0, 35, 40, 55, 65,  2,
	    0,  0,  0, -2,  4, 22, 30, 45, 50,  0,
	    0,  0,  0,  0,  0, 18, 27, 30, 30,  0,
	    0,  0,  0, -2,  3, 10, 20, 20, 20,  0
	}
};

// to grade a situation
int Eveluate(int turn)
{
	int RedValues = 0;  
	int BlackValues = 0;     

	int nBasicVal[2] = { 0 , 0 };  
	int nMobilityVal[2] = { 0 , 0 };  
	int nPositionVal[2] = { 0 , 0 };  
	int nRelationVal[2] = { 0 , 0 };  
	int nameofpiece;
	int aimname;
	int flag;
	int nPosition;
	int i;
	bool bHaveHalf;


	memset(RelationOfMan, 0, sizeof(relation) * 90);

	int x, y;
	for (x = 0; x <= 8; x++)
		for (y = 0; y <= 9; y++)
		{
			if (Chessboard[x][y] != 0)
			{
				nameofpiece = Chessboard[x][y];
				flag = Flag[nameofpiece];

				
				nPosition = x * 10 + y * 9;

				if (flag == RED)
				{
					nBasicVal[flag] += Basicvalue[nameofpiece];
					nPositionVal[flag] += PositionValues[nameofpiece][nPosition];
				}
				else
				{
					nBasicVal[flag] += Basicvalue[nameofpiece];
					nPositionVal[flag] += PositionValues[nameofpiece - 7][89 - nPosition];
				}
				
				pointnumber = 0;

				switch (nameofpiece)
				{

				case RED_K:

					
					i = kingmeet(x, y, flag);
					if (i != -1)
						findaim(x, i);

					
					if (y < 2)
						findaim(x, y + 1);

					
					if (y > 0)
						findaim(x, y - 1);

					
					if (x > 3)
						findaim(x - 1, y);

					
					if (x < 5)
						findaim(x + 1, y);

					break;

				case BLACK_K:

				
					i = kingmeet(x, y, flag);
					if (i != -1)
						findaim(x, i);

					
					if (y > 7)
						findaim(x, y - 1);

					
					if (y < 9)
						findaim(x, y + 1);

					
					if (x < 5)
						findaim(x + 1, y);

					
					if (x > 3)
						findaim(x - 1, y);

					break;

				case RED_J:          
				case BLACK_J:

					
					for (i = y + 1; i <= 9; i++)
					{
						findaim(x, i);

						if (taken(x, i))
							break;
					}

					for (i = y - 1; i >= 0; i--)
					{
						findaim(x, i);

						if (taken(x, i))
							break;
					}

					
					for (i = x - 1; i >= 0; i--)
					{
						findaim(i, y);

						if (taken(i, y))
							break;
					}

					for (i = x + 1; i <= 8; i++)
					{
						findaim(i, y);

						if (taken(i, y))
							break;
					}

					break;

				case RED_M:          
				case BLACK_M:

					if (y <= 7 && !taken(x, y + 1))
					{
						
						if (x > 0)
							findaim(x - 1, y + 2);

						
						if (x < 8)
							findaim(x + 1, y + 2);
					}

					if (x <= 6 && !taken(x + 1, y))
					{
						
						if (y < 9)
							findaim(x + 2, y + 1);

						
						if (y > 0)
							findaim(x + 2, y - 1);
					}

					if (y >= 2 && !taken(x, y - 1))
					{
						
						if (x < 8)
							findaim(x + 1, y - 2);

						
						if (x > 0)
							findaim(x - 1, y - 2);
					}

					if (x >= 2 && !taken(x - 1, y))
					{
						
						if (y > 0)
							findaim(x - 2, y - 1);

						
						if (y < 9)
							findaim(x - 2, y + 1);
					}

					break;

				case RED_P:     
				case BLACK_P:

				
					bHaveHalf = false;  
					for (i = y + 1; i <= 9; i++)
					{
						if (!bHaveHalf) 
						{
							if (!taken(x, i))
							{
								findaim(x, i);
							}
							else 
							{
								bHaveHalf = true;
							}
						}
						else 
						{
							if (taken(x, i))
							{
								findaim(x, i);
								break;
							}
						}
					}

					bHaveHalf = false;  
					for (i = y - 1; i >= 0; i--)
					{
						if (!bHaveHalf) 
						{
							if (!taken(x, i))
							{
								findaim(x, i);
							}
							else
							{
								bHaveHalf = true;
							}
						}
						else 
						{
							if (taken(x, i))
							{
								findaim(x, i);
								break;
							}
						}
					}

					
					bHaveHalf = false;  
					for (i = x - 1; i >= 0; i--)
					{
						if (!bHaveHalf) 
						{
							if (!taken(i, y))
							{
								findaim(i, y);
							}
							else 
							{
								bHaveHalf = true;
							}
						}
						else 
						{
							if (taken(i, y))
							{
								findaim(i, y);
								break;
							}
						}
					}

					bHaveHalf = false;  
					for (i = x + 1; i <= 8; i++)
					{
						if (!bHaveHalf) 
						{
							if (!taken(i, y))
							{
								findaim(i, y);
							}
							else 
							{
								bHaveHalf = true;
							}
						}
						else 
						{
							if (taken(i, y))
							{
								findaim(i, y);
								break;
							}
						}
					}

					break;

				case RED_X:

					if (x == 0)
					{
						if (!taken(1, 3))
							findaim(2, 4);

						if (!taken(1, 1))
							findaim(2, 0);
					}
					else if (x == 2)
					{
						if (y == 4)
						{
							if (!taken(1, 3))
								findaim(0, 2);

							if (!taken(3, 3))
								findaim(4, 2);
						}
						else 
						{
							if (!taken(1, 1))
								findaim(0, 2);

							if (!taken(3, 1))
								findaim(4, 2);
						}
					}
					else if (x == 4)
					{
						if (!taken(3, 3))
							findaim(2, 4);

						if (!taken(3, 1))
							findaim(2, 0);

						if (!taken(5, 3))
							findaim(6, 4);

						if (!taken(5, 1))
							findaim(6, 0);
					}
					else if (x == 6)
					{
						if (y == 4)
						{
							if (!taken(5, 3))
								findaim(4, 2);

							if (!taken(7, 3))
								findaim(8, 2);
						}
						else 
						{
							if (!taken(5, 1))
								findaim(4, 2);

							if (!taken(7, 1))
								findaim(8, 2);
						}
					}
					else 
					{
						if (!taken(7, 3))
							findaim(6, 4);

						if (!taken(7, 1))
							findaim(6, 0);
					}

					break;

				case BLACK_X:

					if (x == 0)
					{
						if (!taken(1, 6))
							findaim(2, 5);

						if (!taken(1, 8))
							findaim(2, 9);
					}
					else if (x == 2)
					{
						if (y == 5)
						{
							if (!taken(1, 6))
								findaim(0, 7);

							if (!taken(3, 6))
								findaim(4, 7);
						}
						else // y == 9
						{
							if (!taken(1, 8))
								findaim(0, 7);

							if (!taken(3, 8))
								findaim(4, 7);
						}
					}
					else if (x == 4)
					{
						if (!taken(3, 6))
							findaim(2, 5);

						if (!taken(3, 8))
							findaim(2, 9);

						if (!taken(5, 6))
							findaim(6, 5);

						if (!taken(5, 8))
							findaim(6, 9);
					}
					else if (x == 6)
					{
						if (y == 5)
						{
							if (!taken(5, 6))
								findaim(4, 7);

							if (!taken(7, 6))
								findaim(8, 7);
						}
						else 
						{
							if (!taken(5, 8))
								findaim(4, 7);

							if (!taken(7, 8))
								findaim(8, 7);
						}
					}
					else 
					{
						if (!taken(7, 6))
							findaim(6, 5);

						if (!taken(7, 8))
							findaim(6, 9);
					}

					break;

				case RED_S:

					if (x == 3)
					{
						findaim(4, 1);
					}
					else if (x == 4)
					{
						findaim(3, 2);

						findaim(3, 0);

						findaim(5, 2);

						findaim(5, 0);
					}
					else 
					{
						findaim(4, 1);
					}

					break;

				case BLACK_S:

					if (x == 3)
					{
						findaim(4, 8);
					}
					else if (x == 4)
					{
						findaim(3, 7);

						findaim(3, 9);

						findaim(5, 7);

						findaim(5, 9);
					}
					else // x == 5
					{
						findaim(4, 8);
					}

					break;

				case RED_B:

					
					if (y < 9)
						findaim(x, y + 1);

					if (y >= 5)
					{
						
						if (x > 0)
							findaim(x - 1, y);

						
						if (x < 8)
							findaim(x + 1, y);
					}

					break;

				case BLACK_B:

					
					if (y > 0)
						findaim(x, y - 1);

					if (y <= 4) 
					{
						
						if (x > 0)
							findaim(x - 1, y);

						
						if (x < 8)
							findaim(x + 1, y);
					}

					break;

				}   

				for (i = 0; i < pointnumber; i++)
				{
					
					aimname = Chessboard[pointlist[i].x][pointlist[i].y];

				
					if (aimname == 0)
					{
						if (flag == RED)
							nMobilityVal[flag] += Flexiabiliytvalue[nameofpiece];
						else
							nMobilityVal[flag] += Flexiabiliytvalue[nameofpiece - 7];
					}
					
					else if (Flag[aimname] != flag)
					{
						
						if (aimname == RED_K)
						{
							if (turn == BLACK)  
							{
								return MaxValue - 10;  
							}
							else            
							{
								nRelationVal[RED] -= 20;
								continue;
							}

						}
						if (aimname == BLACK_K)
						{
							if (turn == RED)    
							{
								return MaxValue - 10;  
													   
							}
							else           
							{
								nRelationVal[BLACK] -= 20;
								continue;
							}
						}

						RelationOfMan[pointlist[i].x][pointlist[i].y]
							.nameofpiece = aimname;

						RelationOfMan[pointlist[i].x][pointlist[i].y]
							.attackaim[RelationOfMan[pointlist[i].x][pointlist[i].y].attacknumber++]
							= nameofpiece;

					}

				
					else 
					{
						
						if (aimname == RED_K || aimname == BLACK_K)
							continue;

						RelationOfMan[pointlist[i].x][pointlist[i].y]
							.nameofpiece = aimname;

						RelationOfMan[pointlist[i].x][pointlist[i].y]
							.guradaim[RelationOfMan[pointlist[i].x][pointlist[i].y].defendnumber++]
							= nameofpiece;
					}

				}  

			}  

		} 
		for (x = 0; x <= 8; x++)
			for (y = 0; y <= 9; y++)
			{
				if (RelationOfMan[x][y].nameofpiece != 0)
				{
					nameofpiece = RelationOfMan[x][y].nameofpiece;
					flag = Flag[nameofpiece];
					int value1, value2, value3;
					if (RelationOfMan[x][y].attacknumber == 0)
						value1 = 0;
					else	if (RelationOfMan[x][y].attacknumber == 1)
						value1 = Basicvalue[RelationOfMan[x][y].attackaim[1]];
					else {
						for (i = 2; i < RelationOfMan[x][y].attacknumber; i++) {
							value1 = Basicvalue[RelationOfMan[x][y].attackaim[1]];
							if (Basicvalue[RelationOfMan[x][y].attackaim[i]] >= Basicvalue[RelationOfMan[x][y].attackaim[i - 1]])
								value1 = Basicvalue[RelationOfMan[x][y].attackaim[i]];
							else
								value1 = Basicvalue[RelationOfMan[x][y].attackaim[i - 1]];

						}
					}
					if (RelationOfMan[x][y].defendnumber == 0)
						value2 = 0;
					else	if (RelationOfMan[x][y].defendnumber == 1)
						value2 = Basicvalue[RelationOfMan[x][y].guradaim[1]];
					else {
						for (i = 2; i < RelationOfMan[x][y].defendnumber; i++) {
							value2 = Basicvalue[RelationOfMan[x][y].guradaim[1]];
							if (Basicvalue[RelationOfMan[x][y].guradaim[i]] >= Basicvalue[RelationOfMan[x][y].guradaim[i - 1]])
								value2 = Basicvalue[RelationOfMan[x][y].guradaim[i]];
							else
								value2 = Basicvalue[RelationOfMan[x][y].guradaim[i - 1]];
						}
					}

					if (value1 >= value2)
						value3 = value1;
					else value3 = value2;
					nRelationVal[flag] = value3;
				}
			}
		

		RedValues = nBasicVal[RED] + nPositionVal[RED]
			+ nMobilityVal[RED] + nRelationVal[RED];
		BlackValues = nBasicVal[BLACK] + nPositionVal[BLACK]
			+ nMobilityVal[BLACK] + nRelationVal[BLACK];

	if (turn == RED)
		return (RedValues - BlackValues);
	else
		return (BlackValues - RedValues);
}

 void findaim(int x, int y)
{
	pointlist[pointnumber].x = x;
	pointlist[pointnumber].y = y;

	pointnumber++;
}   
