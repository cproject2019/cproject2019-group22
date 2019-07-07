#pragma once
#include<stdio.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
#define bool int
#define true 1
#define false 0
//red piece
#define RED_K    1//帥
#define RED_S    2//仕 
#define RED_X    3//相
#define RED_M    4//马 
#define RED_J    5//车
#define RED_P    6//炮 
#define RED_B    7//兵 

//black peice
#define BLACK_K    8//将
#define BLACK_S    9//士
#define BLACK_X    10//象 
#define BLACK_M    11//馬 
#define BLACK_J    12//車 
#define BLACK_P    13//砲
#define BLACK_B    14//卒

typedef struct __POINT {
	int x;
	int y;
} _POINT;

typedef struct _chessmove {
	_POINT ptFrom;     
	_POINT ptTo;         
} CHESSMOVE;        // move


const int RED = 1;
const int BLACK = 0;
//Chessboard
int Chessboard[9][10] = {
	5,  0,  0,  7,  0,  0,  14,  0,  0,  12,
	4,  0,  6,  0,  0,  0,  0,  13,  0,  11,
	3,  0,  0,  7,  0,  0,  14,  0,  0,  10,
	2,  0,  0,  0,  0,  0,  0,  0,  0,  9,
	1,  0,  0,  7,  0,  0,  14,  0,  0,  8,
	2,  0,  0,  0,  0,  0,  0,  0,  0,  9,
	3,  0,  0,  7,  0,  0,  14,  0,  0,  10,
	4,  0,  6,  0,  0,  0,  0,  13,  0,  11,
	5,  0,  0,  7,  0,  0,  14,  0,  0,  12
};
int Flag[15] = { 0,1,1,1,1,1,1,1,0,0,0,0,0,0,0 };//judge the flag

CHESSMOVE Movelist[12][80];
int totalmove;
//add a point
void addmove(_POINT ptFrom, _POINT ptTo, int nDepth)
{
	Movelist[nDepth][totalmove].ptFrom.x = ptFrom.x;
	Movelist[nDepth][totalmove].ptFrom.y = ptFrom.y;
	Movelist[nDepth][totalmove].ptTo.x = ptTo.x;
	Movelist[nDepth][totalmove].ptTo.y = ptTo.y;
	totalmove++;
}
void addmove(_POINT ptFrom, int x, int y, int nDepth)
{
	Movelist[nDepth][totalmove].ptFrom.x = ptFrom.x;
	Movelist[nDepth][totalmove].ptFrom.y = ptFrom.y;
	Movelist[nDepth][totalmove].ptTo.x = x;
	Movelist[nDepth][totalmove].ptTo.y = y;
	totalmove++;
}
//judge a position exist friend
 bool Friend(_POINT ptPosition, int flag)
{
	if (Chessboard[ptPosition.x][ptPosition.y] == 0)
		return false;
	else if (Flag[Chessboard[ptPosition.x][ptPosition.y]] == flag)
		return true;
	else
		return false;
}

 bool Friend(int x, int y, int flag)
{
	if (Chessboard[x][y] == 0)
		return false;
	else if (Flag[Chessboard[x][y]] == flag)
		return true;
	else
		return false;
}
 //judge a position is taken
 bool taken(_POINT ptPosition)
{
	if (Chessboard[ptPosition.x][ptPosition.y] == 0)
		return false;
	else
		return true;
}

 bool taken(int x, int y)
{
	if (Chessboard[x][y] == 0)
		return false;
	else
		return true;
}
 // add point for possible move
 void addpoint(_POINT ptFrom, _POINT ptTo, int nDepth)
 {
	 Movelist[nDepth][totalmove].ptFrom.x = ptFrom.x;
	 Movelist[nDepth][totalmove].ptFrom.y = ptFrom.y;
	 Movelist[nDepth][totalmove].ptTo.x = ptTo.x;
	 Movelist[nDepth][totalmove].ptTo.y = ptTo.y;

	 totalmove++;
 }

 void addpoint(_POINT ptFrom, int x, int y, int nDepth)
 {
	 Movelist[nDepth][totalmove].ptFrom.x = ptFrom.x;
	 Movelist[nDepth][totalmove].ptFrom.y = ptFrom.y;
	 Movelist[nDepth][totalmove].ptTo.x = x;
	 Movelist[nDepth][totalmove].ptTo.y = y;

	 totalmove++;
 }



int kingmeet(int x, int y, int flag)
{
	bool possiblemeet = false;
	int i, j;

	if (flag == 1)
	{
		for (i = 9; i >= 7; i--)  
		{
			if (Chessboard[x][i] == BLACK_K)
			{
				possiblemeet = true;
				break;
			}
		}

		if (possiblemeet == false)
			return -1;

		for (j = y + 1; j <= i - 1; j++) 
		{
			if (Chessboard[x][j] != 0) 
				return -1;
		}

		return i;  
	}
	else 
	{
		for (i = 0; i <= 2; i++) 
		{
			if (Chessboard[x][i] == RED_K)
			{
				possiblemeet = true;
				break;
			}
		}

		if (possiblemeet == false)
			return -1;

		for (j = y - 1; j >= i + 1; j--)  
		{
			if (Chessboard[x][j] != 0)  
				return -1;
		}

		return i;  // if meet return y value
	}

}
//make possible list
int makepossiblemove(int flag, int nDepth)
{
	int    nameofpiece;
	_POINT  ptFrom, ptTo, ptHalf;
	int i;

	totalmove = 0;

	int x, y;
	for (x = 0; x <= 8; x++)
		for (y = 0; y <= 9; y++)
		{
			if (Chessboard[x][y] != 0)
			{
				nameofpiece = Chessboard[x][y];
				if (Flag[nameofpiece] != flag)
					continue;

				ptFrom.x = x;
				ptFrom.y = y;

				switch (nameofpiece)
				{

				case RED_J://red车
					ptTo.x = ptFrom.x;
					for (ptTo.y = ptFrom.y + 1; ptTo.y <= 9; ptTo.y++)
					{
						if (taken(ptTo))
						{
							if (!Friend(ptTo, flag))
								addpoint(ptFrom, ptTo, nDepth);
							break;
						}
						addpoint(ptFrom, ptTo, nDepth);
					}
					for (ptTo.y = ptFrom.y - 1; ptTo.y >= 0; ptTo.y--)
					{
						if (taken(ptTo))
						{
							if (!Friend(ptTo, flag))
								addpoint(ptFrom, ptTo, nDepth);
							break;
						}
						addpoint(ptFrom, ptTo, nDepth);
					}
					ptTo.y = ptFrom.y;
					for (ptTo.x = ptFrom.x - 1; ptTo.x >= 0; ptTo.x--)
					{
						if (taken(ptTo))
						{
							if (!Friend(ptTo, flag))
								addpoint(ptFrom, ptTo, nDepth);
							break;
						}
						addpoint(ptFrom, ptTo, nDepth);
					}
					for (ptTo.x = ptFrom.x + 1; ptTo.x <= 8; ptTo.x++)
					{
						if (taken(ptTo))
						{
							if (!Friend(ptTo, flag))
								addpoint(ptFrom, ptTo, nDepth);
							break;
						}
						addpoint(ptFrom, ptTo, nDepth);
					}
					break;
				case BLACK_J://blcak车
					ptTo.x = ptFrom.x;	
					for (ptTo.y = ptFrom.y - 1; ptTo.y >= 0; ptTo.y--)
					{
						if (taken(ptTo))
						{
							if (!Friend(ptTo, flag))
								addpoint(ptFrom, ptTo, nDepth);
							break;
						}
						addpoint(ptFrom, ptTo, nDepth);
					}
					for (ptTo.y = ptFrom.y + 1; ptTo.y <= 9; ptTo.y++)
					{
						if (taken(ptTo))
						{
							if (!Friend(ptTo, flag))
								addpoint(ptFrom, ptTo, nDepth);
							break;
						}
						addpoint(ptFrom, ptTo, nDepth);
					}
					ptTo.y = ptFrom.y;
					for (ptTo.x = ptFrom.x + 1; ptTo.x <= 8; ptTo.x++)
					{
						if (taken(ptTo))
						{
							if (!Friend(ptTo, flag))
								addpoint(ptFrom, ptTo, nDepth);
							break;
						}
						addpoint(ptFrom, ptTo, nDepth);
					}
					for (ptTo.x = ptFrom.x - 1; ptTo.x >= 0; ptTo.x--)
					{
						if (taken(ptTo))
						{
							if (!Friend(ptTo, flag))
								addpoint(ptFrom, ptTo, nDepth);
							break;
						}
						addpoint(ptFrom, ptTo, nDepth);
					}
					break;
				

					
				case RED_X://red 相

					if (ptFrom.x == 0)
					{
						if (!Friend(2, 4, flag) && !taken(1, 3))
							addpoint(ptFrom, 2, 4, nDepth);

						if (!Friend(2, 0, flag) && !taken(1, 1))
							addpoint(ptFrom, 2, 0, nDepth);
					}
					else if (ptFrom.x == 2)
					{
						if (ptFrom.y == 4)
						{
							if (!Friend(0, 2, flag) && !taken(1, 3))
								addpoint(ptFrom, 0, 2, nDepth);

							if (!Friend(4, 2, flag) && !taken(3, 3))
								addpoint(ptFrom, 4, 2, nDepth);
						}
						else 
						{
							if (!Friend(0, 2, flag) && !taken(1, 1))
								addpoint(ptFrom, 0, 2, nDepth);

							if (!Friend(4, 2, flag) && !taken(3, 1))
								addpoint(ptFrom, 4, 2, nDepth);
						}
					}
					else if (ptFrom.x == 4)
					{
						if (!Friend(2, 4, flag) && !taken(3, 3))
							addpoint(ptFrom, 2, 4, nDepth);

						if (!Friend(2, 0, flag) && !taken(3, 1))
							addpoint(ptFrom, 2, 0, nDepth);

						if (!Friend(6, 4, flag) && !taken(5, 3))
							addpoint(ptFrom, 6, 4, nDepth);

						if (!Friend(6, 0, flag) && !taken(5, 1))
							addpoint(ptFrom, 6, 0, nDepth);
					}
					else if (ptFrom.x == 6)
					{
						if (ptFrom.y == 4)
						{
							if (!Friend(4, 2, flag) && !taken(5, 3))
								addpoint(ptFrom, 4, 2, nDepth);

							if (!Friend(8, 2, flag) && !taken(7, 3))
								addpoint(ptFrom, 8, 2, nDepth);
						}
						else // ptFrom.y == 0
						{
							if (!Friend(24, 2, flag) && !taken(5, 1))
								addpoint(ptFrom, 4, 2, nDepth);

							if (!Friend(8, 2, flag) && !taken(7, 1))
								addpoint(ptFrom, 8, 2, nDepth);
						}
					}
					else 
					{
						if (!Friend(6, 4, flag) && !taken(7, 3))
							addpoint(ptFrom, 6, 4, nDepth);

						if (!Friend(6, 0, flag) && !taken(7, 1))
							addpoint(ptFrom, 6, 0, nDepth);
					}

					break;

					
				case BLACK_X://black象

					if (ptFrom.x == 0)
					{
						if (!Friend(2, 5, flag) && !taken(1, 6))
							addpoint(ptFrom, 2, 5, nDepth);

						if (!Friend(2, 9, flag) && !taken(1, 8))
							addpoint(ptFrom, 2, 9, nDepth);
					}
					else if (ptFrom.x == 2)
					{
						if (ptFrom.y == 5)
						{
							if (!Friend(0, 7, flag) && !taken(1, 6))
								addpoint(ptFrom, 0, 7, nDepth);

							if (!Friend(4, 7, flag) && !taken(3, 6))
								addpoint(ptFrom, 4, 7, nDepth);
						}
						else // ptFrom.y == 9
						{
							if (!Friend(0, 7, flag) && !taken(1, 8))
								addpoint(ptFrom, 0, 7, nDepth);

							if (!Friend(4, 7, flag) && !taken(3, 8))
								addpoint(ptFrom, 4, 7, nDepth);
						}
					}
					else if (ptFrom.x == 4)
					{
						if (!Friend(2, 5, flag) && !taken(3, 6))
							addpoint(ptFrom, 2, 5, nDepth);

						if (!Friend(2, 9, flag) && !taken(3, 8))
							addpoint(ptFrom, 2, 9, nDepth);

						if (!Friend(6, 5, flag) && !taken(5, 6))
							addpoint(ptFrom, 6, 5, nDepth);

						if (!Friend(6, 9, flag) && !taken(5, 8))
							addpoint(ptFrom, 6, 9, nDepth);
					}
					else if (ptFrom.x == 6)
					{
						if (ptFrom.y == 5)
						{
							if (!Friend(4, 7, flag) && !taken(5, 6))
								addpoint(ptFrom, 4, 7, nDepth);

							if (!Friend(8, 7, flag) && !taken(7, 6))
								addpoint(ptFrom, 8, 7, nDepth);
						}
						else 
						{
							if (!Friend(4, 7, flag) && !taken(5, 8))
								addpoint(ptFrom, 4, 7, nDepth);

							if (!Friend(8, 7, flag) && !taken(7, 8))
								addpoint(ptFrom, 8, 7, nDepth);
						}
					}
					else 
					{
						if (!Friend(6, 5, flag) && !taken(7, 6))
							addpoint(ptFrom, 6, 5, nDepth);

						if (!Friend(6, 9, flag) && !taken(7, 8))
							addpoint(ptFrom, 6, 9, nDepth);
					}

					break;

				case RED_S://red仕

					if (ptFrom.x == 3)
					{
						if (!Friend(4, 1, flag))
							addpoint(ptFrom, 4, 1, nDepth);
					}
					else if (ptFrom.x == 4)
					{
						if (!Friend(3, 2, flag))
							addpoint(ptFrom, 3, 2, nDepth);

						if (!Friend(3, 0, flag))
							addpoint(ptFrom, 3, 0, nDepth);

						if (!Friend(5, 2, flag))
							addpoint(ptFrom, 5, 2, nDepth);

						if (!Friend(5, 0, flag))
							addpoint(ptFrom, 5, 0, nDepth);
					}
					else 
					{
						if (!Friend(4, 1, flag))
							addpoint(ptFrom, 4, 1, nDepth);
					}

					break;

					
				case BLACK_S://blcak士

					if (ptFrom.x == 3)
					{
						if (!Friend(4, 8, flag))
							addpoint(ptFrom, 4, 8, nDepth);
					}
					else if (ptFrom.x == 4)
					{
						if (!Friend(3, 7, flag))
							addpoint(ptFrom, 3, 7, nDepth);

						if (!Friend(3, 9, flag))
							addpoint(ptFrom, 3, 9, nDepth);

						if (!Friend(5, 7, flag))
							addpoint(ptFrom, 5, 7, nDepth);

						if (!Friend(5, 9, flag))
							addpoint(ptFrom, 5, 9, nDepth);
					}
					else 
					{
						if (!Friend(4, 8, flag))
							addpoint(ptFrom, 4, 8, nDepth);
					}

					break;

				case RED_M://red马
						   //ptHalf to judge the leg of house  
					ptHalf.x = ptFrom.x;
					ptHalf.y = ptFrom.y + 1;
					if (ptHalf.y <= 8 && !taken(ptHalf))
					{
						ptTo.x = ptFrom.x - 1;
						ptTo.y = ptFrom.y + 2;
						if (ptTo.x >= 0 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
						ptTo.x = ptFrom.x + 1;
						ptTo.y = ptFrom.y + 2;
						if (ptTo.x <= 8 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
					}
					ptHalf.x = ptFrom.x + 1;
					ptHalf.y = ptFrom.y;
					if (ptHalf.x <= 7 && !taken(ptHalf))
					{
						ptTo.x = ptFrom.x + 2;
						ptTo.y = ptFrom.y + 1;
						if (ptTo.y <= 9 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
						ptTo.x = ptFrom.x + 2;
						ptTo.y = ptFrom.y - 1;
						if (ptTo.y >= 0 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
					}
					ptHalf.x = ptFrom.x;
					ptHalf.y = ptFrom.y - 1;
					if (ptHalf.y >= 1 && !taken(ptHalf))
					{
						ptTo.x = ptFrom.x + 1;
						ptTo.y = ptFrom.y - 2;
						if (ptTo.x <= 8 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
						ptTo.x = ptFrom.x - 1;
						ptTo.y = ptFrom.y - 2;
						if (ptTo.x >= 0 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
					}
					ptHalf.x = ptFrom.x - 1;
					ptHalf.y = ptFrom.y;
					if (ptHalf.x >= 1 && !taken(ptHalf))
					{
						ptTo.x = ptFrom.x - 2;
						ptTo.y = ptFrom.y - 1;
						if (ptTo.y >= 0 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
						ptTo.x = ptFrom.x - 2;
						ptTo.y = ptFrom.y + 1;
						if (ptTo.y <= 9 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
					}

					break;
				case BLACK_M://black马
					ptHalf.x = ptFrom.x;
					ptHalf.y = ptFrom.y + 1;
					if (ptHalf.y <= 8 && !taken(ptHalf))
					{
						ptTo.x = ptFrom.x - 1;
						ptTo.y = ptFrom.y + 2;
						if (ptTo.x >= 0 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
						ptTo.x = ptFrom.x + 1;
						ptTo.y = ptFrom.y + 2;
						if (ptTo.x <= 8 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
					}
					ptHalf.x = ptFrom.x + 1;
					ptHalf.y = ptFrom.y;
					if (ptHalf.x <= 7 && !taken(ptHalf))
					{
						ptTo.x = ptFrom.x + 2;
						ptTo.y = ptFrom.y + 1;
						if (ptTo.y <= 9 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
						ptTo.x = ptFrom.x + 2;
						ptTo.y = ptFrom.y - 1;
						if (ptTo.y >= 0 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
					}
					ptHalf.x = ptFrom.x;
					ptHalf.y = ptFrom.y - 1;
					if (ptHalf.y >= 1 && !taken(ptHalf))
					{
						ptTo.x = ptFrom.x + 1;
						ptTo.y = ptFrom.y - 2;
						if (ptTo.x <= 8 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
						ptTo.x = ptFrom.x - 1;
						ptTo.y = ptFrom.y - 2;
						if (ptTo.x >= 0 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
					}
					ptHalf.x = ptFrom.x - 1;
					ptHalf.y = ptFrom.y;
					if (ptHalf.x >= 1 && !taken(ptHalf))
					{
						ptTo.x = ptFrom.x - 2;
						ptTo.y = ptFrom.y - 1;
						if (ptTo.y >= 0 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
						ptTo.x = ptFrom.x - 2;
						ptTo.y = ptFrom.y + 1;
						if (ptTo.y <= 9 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
					}
					break;
				case RED_P://red炮
					ptTo.x = ptFrom.x;


					ptHalf.x = -1;
					for (ptTo.y = ptFrom.y + 1; ptTo.y <= 9; ptTo.y++)
					{
						if (ptHalf.x == -1)
						{
							if (!taken(ptTo))
							{
								addpoint(ptFrom, ptTo, nDepth);
							}
							else
							{
								ptHalf.x = ptTo.x;
								ptHalf.y = ptTo.y;
							}
						}
						else
						{
							if (taken(ptTo))
							{
								if (!Friend(ptTo, flag))
									addpoint(ptFrom, ptTo, nDepth);

								break;
							}
						}

					}


					ptHalf.x = -1;
					for (ptTo.y = ptFrom.y - 1; ptTo.y >= 0; ptTo.y--)
					{
						if (ptHalf.x == -1)
						{
							if (!taken(ptTo))
							{
								addpoint(ptFrom, ptTo, nDepth);
							}
							else
							{
								ptHalf.x = ptTo.x;
								ptHalf.y = ptTo.y;
							}
						}
						else
						{
							if (taken(ptTo))
							{
								if (!Friend(ptTo, flag))
									addpoint(ptFrom, ptTo, nDepth);

								break;
							}
						}

					}


					ptTo.y = ptFrom.y;


					ptHalf.x = -1;
					for (ptTo.x = ptFrom.x - 1; ptTo.x >= 0; ptTo.x--)
					{
						if (ptHalf.x == -1)
						{
							if (!taken(ptTo))
							{
								addpoint(ptFrom, ptTo, nDepth);
							}
							else
							{
								ptHalf.x = ptTo.x;
								ptHalf.y = ptTo.y;
							}
						}
						else
						{
							if (taken(ptTo))
							{
								if (!Friend(ptTo, flag))
									addpoint(ptFrom, ptTo, nDepth);

								break;
							}
						}

					}


					ptHalf.x = -1;
					for (ptTo.x = ptFrom.x + 1; ptTo.x <= 8; ptTo.x++)
					{
						if (ptHalf.x == -1)
						{
							if (!taken(ptTo))
							{
								addpoint(ptFrom, ptTo, nDepth);
							}
							else
							{
								ptHalf.x = ptTo.x;
								ptHalf.y = ptTo.y;
							}
						}
						else
						{
							if (taken(ptTo))
							{
								if (!Friend(ptTo, flag))
									addpoint(ptFrom, ptTo, nDepth);

								break;
							}
						}

					}

					break;

				case BLACK_P://black炮

							 //ptHalf to judge mid piece   


					ptTo.x = ptFrom.x;


					ptHalf.x = -1;
					for (ptTo.y = ptFrom.y + 1; ptTo.y <= 9; ptTo.y++)
					{
						if (ptHalf.x == -1)
						{
							if (!taken(ptTo))
							{
								addpoint(ptFrom, ptTo, nDepth);
							}
							else
							{
								ptHalf.x = ptTo.x;
								ptHalf.y = ptTo.y;
							}
						}
						else
						{
							if (taken(ptTo))
							{
								if (!Friend(ptTo, flag))
									addpoint(ptFrom, ptTo, nDepth);

								break;
							}
						}

					}


					ptHalf.x = -1;
					for (ptTo.y = ptFrom.y - 1; ptTo.y >= 0; ptTo.y--)
					{
						if (ptHalf.x == -1)
						{
							if (!taken(ptTo))
							{
								addpoint(ptFrom, ptTo, nDepth);
							}
							else
							{
								ptHalf.x = ptTo.x;
								ptHalf.y = ptTo.y;
							}
						}
						else
						{
							if (taken(ptTo))
							{
								if (!Friend(ptTo, flag))
									addpoint(ptFrom, ptTo, nDepth);

								break;
							}
						}

					}


					ptTo.y = ptFrom.y;


					ptHalf.x = -1;
					for (ptTo.x = ptFrom.x - 1; ptTo.x >= 0; ptTo.x--)
					{
						if (ptHalf.x == -1) 
						{
							if (!taken(ptTo))
							{
								addpoint(ptFrom, ptTo, nDepth);
							}
							else
							{
								ptHalf.x = ptTo.x;
								ptHalf.y = ptTo.y;
							}
						}
						else
						{
							if (taken(ptTo))
							{
								if (!Friend(ptTo, flag))
									addpoint(ptFrom, ptTo, nDepth);

								break;
							}
						}

					}


					ptHalf.x = -1;
					for (ptTo.x = ptFrom.x + 1; ptTo.x <= 8; ptTo.x++)
					{
						if (ptHalf.x == -1)
						{
							if (!taken(ptTo))
							{
								addpoint(ptFrom, ptTo, nDepth);
							}
							else
							{
								ptHalf.x = ptTo.x;
								ptHalf.y = ptTo.y;
							}
						}
						else
						{
							if (taken(ptTo))
							{
								if (!Friend(ptTo, flag))
									addpoint(ptFrom, ptTo, nDepth);

								break;
							}
						}

					}

					break;
				case RED_K://red帅
					i = kingmeet(ptFrom.x, ptFrom.y, flag);
					if (i != -1)
						addpoint(ptFrom, ptFrom.x, i, nDepth);
					ptTo.x = ptFrom.x;
					ptTo.y = ptFrom.y + 1;
					if ((ptTo.y <= 2) && (!Friend(ptTo, flag)))
						addpoint(ptFrom, ptTo, nDepth);
					ptTo.y = ptFrom.y - 1;
					if ((ptTo.y >= 0) && (!Friend(ptTo, flag)))
						addpoint(ptFrom, ptTo, nDepth);
					ptTo.y = ptFrom.y;
					ptTo.x = ptFrom.x - 1;
					if ((ptTo.x >= 3) && (!Friend(ptTo, flag))
						&& (kingmeet(ptTo.x, ptTo.y, flag) == -1))
						addpoint(ptFrom, ptTo, nDepth);
					ptTo.x = ptFrom.x + 1;
					if ((ptTo.x <= 5) && (!Friend(ptTo, flag))
						&& (kingmeet(ptTo.x, ptTo.y, flag) == -1))
						addpoint(ptFrom, ptTo, nDepth);
					break;
				case BLACK_K://black将
					i = kingmeet(ptFrom.x, ptFrom.y, flag);
					if (i != -1)
						addpoint(ptFrom, ptFrom.x, i, nDepth);
					ptTo.x = ptFrom.x;
					ptTo.y = ptFrom.y - 1;
					if ((ptTo.y >= 7) && (!Friend(ptTo, flag)))
						addpoint(ptFrom, ptTo, nDepth);
					ptTo.y = ptFrom.y + 1;
					if ((ptTo.y <= 9) && (!Friend(ptTo, flag)))
						addpoint(ptFrom, ptTo, nDepth);
					ptTo.y = ptFrom.y;
					ptTo.x = ptFrom.x + 1;
					if ((ptTo.x <= 5) && (!Friend(ptTo, flag))
						&& (kingmeet(ptTo.x, ptTo.y, flag) == -1))
						addpoint(ptFrom, ptTo, nDepth);
					ptTo.x = ptFrom.x - 1; 
						if ((ptTo.x >= 3) && (!Friend(ptTo, flag))
							&& (kingmeet(ptTo.x, ptTo.y, flag) == -1))
							addpoint(ptFrom, ptTo, nDepth);
					break;
					
				case RED_B://red 兵 

		
					ptTo.x = ptFrom.x;
					ptTo.y = ptFrom.y + 1;
					if (ptTo.y <= 9 && !Friend(ptTo, flag))
						addpoint(ptFrom, ptTo, nDepth);

					if (ptFrom.y >= 5) //across river
					{
						ptTo.y = ptFrom.y;

						
						ptTo.x = ptFrom.x - 1;
						if (ptTo.x >= 0 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);

						
						ptTo.x = ptFrom.x + 1;
						if (ptTo.x <= 8 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
					}

					break;

			
				case BLACK_B://black 卒

				
					ptTo.x = ptFrom.x;
					ptTo.y = ptFrom.y - 1;
					if (ptTo.y >= 0 && !Friend(ptTo, flag))
						addpoint(ptFrom, ptTo, nDepth);

					if (ptFrom.y <= 4)//arcoss river
					{
						ptTo.y = ptFrom.y;

				
						ptTo.x = ptFrom.x - 1;
						if (ptTo.x >= 0 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);


						ptTo.x = ptFrom.x + 1;
						if (ptTo.x <= 8 && !Friend(ptTo, flag))
							addpoint(ptFrom, ptTo, nDepth);
					}

					break;

				}     

			}    

		}  

	return totalmove;  
}

 