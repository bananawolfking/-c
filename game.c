#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void meun(int n)//开始界面
{
	printf("************************************\n");
	printf("********  1:play   0.:exit  *********\n");
	printf("************************************\n");
	printf("请选择：>\n");
}
//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |    
void print_chessboard(char chessboard[ROW][LEF],int row, int lef)//打印棋盘
{
	int i = 0;
	int j = 0;
	for (j = 0; j < row; j++)
	{
		for (i = 0; i < lef; i++)
		{
			printf(" %c ", chessboard[j][i]);
			if (i < lef - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		i = 0;
		if (j < lef - 1)
		{
			for (i = 0; i < lef; i++)
			{
				printf("---");
				if (i < lef - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}


void initialize( char chessboard[ROW][LEF],int row,int lef)//初始化棋盘
{
	int x = 0;
	int y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < lef; y++)
		{
			chessboard[x][y] = ' ';
		}
	}
}


void playgame(char chessboard[ROW][LEF], int row, int lef)//玩家下棋
{
	int x = 1;
	int y = 1;
	
	while (1)
	{
		printf("请玩家下棋，写坐标：\n");
		scanf("%d%d", &x, &y);
		if (chessboard[x - 1][y - 1] == ' ' && x >= 1 && x<= row && y >= 1 && y <= lef)
		{
			chessboard[x - 1][y - 1] = '*'; 
			break;
		}
		else
			printf("输入格式错误，请重新输入\n");
	}
}



void computergame(char chessboard[ROW][LEF], int row, int lef, int j)//电脑随机下棋
{
	int x = 1;
	int y = 1;
	printf("电脑下棋：\n");
	
	while (1)             
	{
		x = rand() % row;
		y = rand() % lef;
		if (chessboard[x][y] == ' ' && x >= 0 && x <= row-1 && y >= 0 && y <= lef-1 && j == 0)
		{
			chessboard[x][y] = '#';
			break;
		}
	}
}

int computer(char chessboard[ROW][LEF], int x, int y,int j)//判断是否可以在这个位置下棋
{
	if (chessboard[x][y] == ' ' && j == 0)
	{
		chessboard[x][y] = '#';
		return 1;
	}
	return j;
}

int computer_centre(char chessboard[ROW][LEF], int row, int lef, int j)//优先在中间下棋
{
	if (chessboard[1][1] == ' ')
	{
		chessboard[1][1] = '#';
		j++;
	}
	return j;
}


int computer_corner(char chessboard[ROW][LEF], int row, int lef, int j)//只在角落随机下棋
{
	int x = 0;
	int y = 0;
	while (1)
	{
		if (chessboard[0][0] != ' ' && chessboard[2][2] != ' ' && chessboard[2][0] != ' ' && chessboard[0][2] != ' ')
		{
			break;
		}
		x = rand() % row;
		y = rand() % lef;
		if (chessboard[x][y] == ' ' && x >= 0 && x <= row - 1 && y >= 0 && y <= lef - 1 && x != 1 && y != 1 && j == 0)
		{
			chessboard[x][y] = '#';
			j++;
			break;
		}
	}
	return j;
}

int computer_corner22(char chessboard[ROW][LEF], int row, int lef, int j)//只在角落随机下棋!22
{
	int x = 0;
	int y = 0;
	while (1)
	{
		if (chessboard[0][0] != ' '  && chessboard[2][0] != ' ' && chessboard[0][2] != ' ')
		{
			break;
		}
		x = rand() % row;
		y = rand() % lef;
		if (chessboard[x][y] == ' ' && x >= 0 && x <= row - 1 && y >= 0 && y <= lef - 1 && x != 1 && y != 1 && j == 0 && (x != 2 || y != 2))
		{
			chessboard[x][y] = '#';
			j++;
			break;
		}
	}
	return j;
}

int computer_corner02(char chessboard[ROW][LEF], int row, int lef, int j)//只在角落随机下棋!02
{
	int x = 0;
	int y = 0;
	while (1)
	{
		if (chessboard[0][0] != ' ' && chessboard[2][2] != ' ' && chessboard[2][0] != ' ' )
		{
			break;
		}
		x = rand() % row;
		y = rand() % lef;
		if (chessboard[x][y] == ' ' && x >= 0 && x <= row - 1 && y >= 0 && y <= lef - 1 && x != 1 && y != 1 && j == 0 && (x != 0 || y != 2))
		{
			chessboard[x][y] = '#';
			j++;
			break;
		}
	}
	return j;
}

int computer_sxzy(char chessboard[ROW][LEF], int row, int lef, int j)//只在上下左右随机下棋
{
	int x = 0;
	int y = 0;
	while (1)
	{
		if (chessboard[0][1] != ' ' && chessboard[1][0] != ' ' && chessboard[1][2] != ' ' && chessboard[2][1] != ' ')
		{
			break;
		}
		x = rand() % row;
		y = rand() % lef;
		if (chessboard[x][y] == ' ' && x >= 0 && x <= row - 1 && y >= 0 && y <= lef - 1 && ((x == 1 && y == 0) || (x == 0 && y == 1) || (x == 1 && y == 2) || (x == 2 && y == 1)) && j == 0)
		{
			chessboard[x][y] = '#';
			j++;
			break;
		}
	}
	return j;
}



void du_king(char chessboard[ROW][LEF], int row, int lef, int n, int m)//赢棋->堵棋->先在中间下棋->在角落下棋->随机下棋
{
	int i = 0;
	int j = 0;
	if (m >= 2)
	{
		for (i = 0; i < row; i++)//同一行是否有相同的
		{
			if (chessboard[i][0] == chessboard[i][1] && chessboard[i][0] == '#')
			{
				j = computer(chessboard, i, 2, j);
			}
			else if (chessboard[i][0] == chessboard[i][2] && chessboard[i][0] == '#')
			{
				j = computer(chessboard, i, 1, j);
			}
			else if (chessboard[i][1] == chessboard[i][2] && chessboard[i][1] == '#')
			{
				j = computer(chessboard, i, 0, j);
			}
		}
		i = 0;
		for (i = 0; i < lef; i++)//同一列是否有相同的
		{
			if (chessboard[0][i] == chessboard[1][i] && chessboard[0][i] == '#')
			{
				j = computer(chessboard, 2, i, j);
			}
			else if (chessboard[0][i] == chessboard[2][i] && chessboard[0][i] == '#')
			{
				j = computer(chessboard, 1, i, j);
			}
			else if (chessboard[1][i] == chessboard[2][i] && chessboard[1][i] == '#')
			{
				j = computer(chessboard, 0, i, j);
			}
		}
		if (chessboard[0][0] == chessboard[1][1] && chessboard[0][0] == '#')//斜线的是否相同
		{
			j = computer(chessboard, 2, 2, j);
		}
		else if (chessboard[0][0] == chessboard[2][2] && chessboard[0][0] == '#')
		{
			j = computer(chessboard, 1, i, j);
		}
		else if (chessboard[1][1] == chessboard[2][2] && chessboard[1][1] == '#')
		{
			j = computer(chessboard, 0, 0, j);
		}
		else if (chessboard[0][2] == chessboard[1][1] && chessboard[0][2] == '#')
		{
			j = computer(chessboard, 2, 0, j);
		}
		else if (chessboard[0][2] == chessboard[2][0] && chessboard[0][2] == '#')
		{
			j = computer(chessboard, 1, 1, j);
		}
		else if (chessboard[1][1] == chessboard[2][0] && chessboard[1][1] == '#')
		{
			j = computer(chessboard, 0, 2, j);
		}
	}
	if (j == 0)
	{
		for (i = 0; i < row; i++)//同一行是否有相同的
		{
			if (chessboard[i][0] == chessboard[i][1] && chessboard[i][0] == '*')
			{
				j = computer(chessboard, i, 2, j);
			}
			else if (chessboard[i][0] == chessboard[i][2] && chessboard[i][0] == '*')
			{
				j = computer(chessboard, i, 1, j);
			}
			else if (chessboard[i][1] == chessboard[i][2] && chessboard[i][1] == '*')
			{
				j = computer(chessboard, i, 0, j);
			}
		}
		i = 0;
		for (i = 0; i < lef; i++)//同一列是否有相同的
		{
			if (chessboard[0][i] == chessboard[1][i] && chessboard[0][i] == '*')
			{
				j = computer(chessboard, 2, i, j);
			}
			else if (chessboard[0][i] == chessboard[2][i] && chessboard[0][i] == '*')
			{
				j = computer(chessboard, 1, i, j);
			}
			else if (chessboard[1][i] == chessboard[2][i] && chessboard[1][i] == '*')
			{
				j = computer(chessboard, 0, i, j);
			}
		}
		if (chessboard[0][0] == chessboard[1][1] && chessboard[0][0] == '*')//斜线的是否相同
		{
			j = computer(chessboard, 2, 2, j);
		}
		else if (chessboard[0][0] == chessboard[2][2] && chessboard[0][0] == '*')
		{
			j = computer(chessboard, 1, 1, j);
		}
		else if (chessboard[1][1] == chessboard[2][2] && chessboard[1][1] == '*')
		{
			j = computer(chessboard, 0, 0, j);
		}
		else if (chessboard[0][2] == chessboard[1][1] && chessboard[0][2] == '*')
		{
			j = computer(chessboard, 2, 0, j);
		}
		else if (chessboard[0][2] == chessboard[2][0] && chessboard[0][2] == '*')
		{
			j = computer(chessboard, 1, 1, j);
		}
		else if (chessboard[1][1] == chessboard[2][0] && chessboard[1][1] == '*')
		{
			j = computer(chessboard, 0, 2, j);
		}	
	}
	if (j == 0)
	{
		j = computer_centre(chessboard, row, lef, j);//中间下棋
	}
	if (j == 0)
	{
		j = computer_corner(chessboard, row, lef, j);//角落下棋
	}
	if (j == 0)
	{
		computergame(chessboard, row, lef,j);//随机
	}
}

int changexy(char chessboard[ROW][LEF], int row, int lef, int ch)//翻转棋盘
{
	int x = 0;
	int y = 0;
	char o = '@';
	if (ch == 1)//交换↙↗ 2表示翻转过一次 1表示翻转回来
	{
		for (x = 0; x < row-1; x++)
		{
			for (y = 0; y > x && y < lef-1; y++)
			{
				o = chessboard[x][y];
				chessboard[x][y] = chessboard[y][x];
				chessboard[y][x] = o;
			}
		}
		return 2;
	}
    else if (ch == 2)
	{
		for (x = 0; x < row - 1; x++)
		{
			for (y = 0; y > x && y < lef - 1; y++)
			{
				o = chessboard[x][y];
				chessboard[x][y] = chessboard[y][x];
				chessboard[y][x] = o;
			}
		}
		return 1;
	}
    else if (ch == 3)//交换↖↘ 4表示翻转过一次 3表示翻转回来
	{
		o = chessboard[0][0];
		chessboard[0][0] = chessboard[2][2];
		chessboard[2][2] = o;
		o = chessboard[0][1];
		chessboard[0][1] = chessboard[1][2];
		chessboard[1][2] = o;
		o = chessboard[1][0];
		chessboard[1][0] = chessboard[2][1];
		chessboard[2][1] = o;
		return 4;
	}
	else if (ch == 4)
	{
		o = chessboard[0][0];
		chessboard[0][0] = chessboard[2][2];
		chessboard[2][2] = o;
		o = chessboard[0][1];
		chessboard[0][1] = chessboard[1][2];
		chessboard[1][2] = o;
		o = chessboard[1][0];
		chessboard[1][0] = chessboard[2][1];
		chessboard[2][1] = o;
		return 3;
	}
	else if (ch == 5)//↑↓翻转棋盘 6代表已经上下翻转过 5代表要上下翻转
	{
		x = 0;
		for (y = 0; y < lef; y++)
		{
			o = chessboard[x][y];
			chessboard[x][y] = chessboard[x+2][y];
			chessboard[x+2][y] = o;
		}
		return 6;
	}
	else if (ch == 6)
	{
		x = 0;
		for (y = 0; y < lef; y++)
		{
			o = chessboard[x][y];
			chessboard[x][y] = chessboard[x + 2][y];
			chessboard[x + 2][y] = o;
		}
		return 5;
	}
    else if (ch == 7)//←→翻转 7表示要翻转 8表示翻转过
	{
		y = 0;
		for (x = 0; x < row; x++)
		{
			o = chessboard[x][y];
			chessboard[x][y] = chessboard[x][y + 2];
			chessboard[x][y + 2] = o;
		}
		return 8;
	}
	else if (ch == 8)
	{
		y = 0;
		for (x = 0; x < row; x++)
		{
			o = chessboard[x][y];
			chessboard[x][y] = chessboard[x][y + 2];
			chessboard[x][y + 2] = o;
		}
		return 7;
	}
}







int changechess(char chessboard[ROW][LEF], int row, int lef, int n, int ret, int m,int chi)//控制翻转棋盘
{
	int ch = 0;
	if (n == 1)
	{
		if (chessboard[0][2] == '*')
		{
			ch = 7;
			chi = changexy(chessboard, row, lef, ch);//翻转棋盘
			return chi;
		}
		else if (chessboard[2][0] == '*')
		{
			ch = 5;
			chi = changexy(chessboard, row, lef, ch);//翻转棋盘
			return chi;
		}
		else if (chessboard[2][2] == '*')
		{
			ch = 3;
			chi = changexy(chessboard, row, lef, ch);//翻转棋盘
			return chi;
		}
		else if (chessboard[0][1] == '*')
		{
			ch = 1;
			chi = changexy(chessboard, row, lef, ch);//翻转棋盘
			return chi;
		}
		else if (chessboard[2][1] == '*')
		{
			ch = 3;
			chi = changexy(chessboard, row, lef, ch);//翻转棋盘
			return chi;
		}
		else if (chessboard[1][2] == '*')
		{
			ch = 7;
			chi = changexy(chessboard, row, lef, ch);//翻转棋盘
			return chi;
		}
		else
		{
			return 0;
		}
	}
	if (m >= 1)
	{
		if (chi == 1)
		{
			ch = 1;
			chi = changexy(chessboard, row, lef, ch);//翻转棋盘
			return chi;
		}
		else if (chi == 2)
		{
			ch = 2;
			chi = changexy(chessboard, row, lef, ch);//翻转棋盘
			return chi;
		}
		else if (chi == 3)
		{
			ch = 3;
			chi = changexy(chessboard, row, lef, ch);//翻转棋盘
			return chi;
		}
		else if (chi == 4)
		{
			ch = 4;
			chi = changexy(chessboard, row, lef, ch);//翻转棋盘
			return chi;
		}
		else if (chi == 5)
		{
			ch = 5;
			chi = changexy(chessboard, row, lef, ch);//翻转棋盘
			return chi;
		}
		else if (chi == 6)
		{
			ch = 6;
			chi = changexy(chessboard, row, lef, ch);//翻转棋盘
			return chi;
		}
		else if (chi == 7)
		{
			ch = 7;
			chi = changexy(chessboard, row, lef, ch);//翻转棋盘
			return chi;
		}
		else if (chi == 8)
		{
			ch = 8;
			chi = changexy(chessboard, row, lef, ch);//翻转棋盘
			return chi;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}

int computergameend(char chessboard[ROW][LEF], int row, int lef,int n,int ret ,int m)//无敌版 ret接收下一步怎么走返回值，也是接收值
{
	if (n == 1)//n判断下的第几颗棋
	{
		if (chessboard[1][1] == '*')
		{
			int j = 0;
			du_king(chessboard, row, lef, n, m);
			//chessboard[0][0] = '#';
			return 1;
		}
		else if (chessboard[0][0] == '*')
		{
			int j = 0;
			j = computer_centre(chessboard, row, lef, j);//中间下棋
			//chessboard[1][1] = '#';
			return 2;
		}
		else if (chessboard[1][0] == '*')
		{
			int j = 0;
			j = computer_centre(chessboard, row, lef, j);//中间下棋
			//chessboard[1][1] = '#';
			return 3;
		}
	}
	if (n >= 2)//第二步棋
	{
		if (ret == 1)
		{
			du_king(chessboard, row, lef , n, m);
			return 1;//开堵就行
		} 
		else if (ret == 2)
		{
			if (chessboard[2][2] == '*')
			{
				int j = 0;
				j = computer_sxzy(chessboard, row, lef, j);//只在上下左右随机下棋
				return 1;//开堵就行
			}
			else if (chessboard[0][2] == '*' || chessboard[2][0] == '*' || chessboard[0][1] == '*' || chessboard[1][0] == '*')
			{
				du_king(chessboard, row, lef, n, m);
				return 1;//开堵就行
			}
			else if (chessboard[1][2] == '*')
			{
				chessboard[0][2] = '#';
				return 1;//开堵就行
			}
			else if (chessboard[2][1] == '*')
			{
				chessboard[2][0] = '#';
				return 1;//开堵就行
			}
		}
		else if (ret == 3)
		{
			if (chessboard[1][2] == '*')
			{
				du_king(chessboard, row, lef, n, m);
				return 1;//开堵就行
			}
			else if (chessboard[0][0] == '*' || chessboard[2][0] == '*')
			{
				du_king(chessboard, row, lef, n, m);
				return 1;//开堵就行
			}
			else if (chessboard[0][1] == '*' || chessboard[0][2] == '*')
			{
				int j = 0;
				j = computer_corner22(chessboard, row, lef, j); //角落下棋除了22
				return 1;
			}
			else if (chessboard[2][1] == '*' || chessboard[2][2] == '*')
			{
				int j = 0;
				j = computer_corner02(chessboard, row, lef, j); //角落下棋除了02
				return 1;
			}

		}
	
	}
}
//j = computer_corner22(chessboard, row, lef, j);角落下棋除了22
char draw(char chessboard[ROW][LEF], int row, int lef)//判断是不是平局
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lef; j++)
		{
			if (chessboard[i][j] == ' ')
			{
				return 'c';
			}
		}
	}
	return 'd';
}

char judgment(char chessboard[ROW][LEF], int row, int lef)//裁判
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (chessboard[i][0] == chessboard[i][1] && chessboard[i][1] == chessboard[i][2] && chessboard[i][1] != ' ')
		{
			if (chessboard[i][1] == '*')
			{
				return 'A';
			}
			if (chessboard[i][1] == '#')
			{
				return 'B';
			}
		}
		if (chessboard[0][i] == chessboard[1][i] && chessboard[1][i] == chessboard[2][i] && chessboard[1][i] != ' ')
		{
			if (chessboard[1][i] == '*')
			{
				return 'A';
			}
			if (chessboard[1][i] == '#')
			{
				return 'B';
			}
		}
		if (chessboard[0][0] == chessboard[1][1] && chessboard[1][1] == chessboard[2][2] && chessboard[1][1] != ' ')
		{
			if (chessboard[1][1] == '*')
			{
				return 'A';
			}
			else
			{
				return 'B';
			}
		}
		if (chessboard[0][2] == chessboard[1][1] && chessboard[1][1] == chessboard[2][0] && chessboard[1][1] != ' ')
		{
			if (chessboard[1][1] == '*')
			{
				return 'A';
			}
			else
			{
				return 'B';
			}
		}
	}
	if ('d' == draw(chessboard, ROW, LEF))
	{
		return 'D';
	}
	return 'C';
}

