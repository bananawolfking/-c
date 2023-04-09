#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void initialize(char mine[ROWS][LEFS], int row, int lef, int key)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lef; j++)
		{
			mine[i][j] = key;
		}
	}
}

void print(char mine[ROWS][LEFS], int row, int lef)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	printf("-------------------\n");
		//printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d|", i);
		for (j = 1; j <= lef; j++)
		{
			printf("%c ", mine[i][j]);
		}
		printf("\n");
	}
}

void Lay_mines(char mine[ROWS][LEFS], int row, int lef, int count)
{
	int x = 0;
	int y = 0;
	int m = 0;
	while (m < count)
	{
		x = rand() % row + 1;
		y = rand() % lef + 1;
		if (x > 0 && x <= row && y > 0 && y <= lef && mine[x][y] != '1')
		{
			mine[x][y] = '1';
			m++;
		}
	}
}

int count_mines(char mine[ROWS][LEFS], int row, int lef, int x, int y)
{
	char minecopy[ROWS][LEFS] = { 0 };
	initialize(minecopy, ROWS, LEFS, '0');
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < LEFS; j++)
		{
			if (mine[i][j] == '$')
			{
				minecopy[i][j] = '0';
			}
			else
			{
				minecopy[i][j] = mine[i][j];
			}
		}
	}
	return minecopy[x - 1][y] +
				minecopy[x - 1][y - 1] +
				minecopy[x][y - 1] +
		        minecopy[x + 1][y - 1] +
		        minecopy[x + 1][y] +
		        minecopy[x + 1][y + 1] +
		        minecopy[x][y + 1] +
		        minecopy[x - 1][y + 1] - 8 * '0';

}

void count_plus(char mine[ROWS][LEFS], char out[ROWS][LEFS], int row, int lef, int x, int y, int ret)
{
	if (mine[x][y] != '$')
	{
		ret = count_mines(mine, ROW, LEF, x, y);
		out[x][y] = ret + '0';
		mine[x][y] = '$';
			if (ret == 0)
			{
				if (x == 1)
				{
					if (y == 1)
					{
						count_plus(mine, out, ROW, LEF, x + 1, y, ret);
						count_plus(mine, out, ROW, LEF, x + 1, y + 1, ret);
						count_plus(mine, out, ROW, LEF, x, y + 1, ret);
					}
					else if (y == lef)
					{
						count_plus(mine, out, ROW, LEF, x, y - 1, ret);
						count_plus(mine, out, ROW, LEF, x + 1, y - 1, ret);
						count_plus(mine, out, ROW, LEF, x + 1, y, ret);
					}
					else
					{
						count_plus(mine, out, ROW, LEF, x, y - 1, ret);
						count_plus(mine, out, ROW, LEF, x + 1, y - 1, ret);
						count_plus(mine, out, ROW, LEF, x + 1, y, ret);
						count_plus(mine, out, ROW, LEF, x + 1, y + 1, ret);
						count_plus(mine, out, ROW, LEF, x, y + 1, ret);

					}
				}
				else if (x == row)
				{
					if (y == 1)
					{
						count_plus(mine, out, ROW, LEF, x - 1, y, ret);
						count_plus(mine, out, ROW, LEF, x, y + 1, ret);
						count_plus(mine, out, ROW, LEF, x - 1, y + 1, ret);
					}
					else if (y == lef)
					{
						count_plus(mine, out, ROW, LEF, x - 1, y, ret);
						count_plus(mine, out, ROW, LEF, x - 1, y - 1, ret);
						count_plus(mine, out, ROW, LEF, x, y - 1, ret);
					}
					else
					{
						count_plus(mine, out, ROW, LEF, x - 1, y, ret);
						count_plus(mine, out, ROW, LEF, x - 1, y - 1, ret);
						count_plus(mine, out, ROW, LEF, x, y - 1, ret);
						count_plus(mine, out, ROW, LEF, x, y + 1, ret);
						count_plus(mine, out, ROW, LEF, x - 1, y + 1, ret);
					}
				}
				else if (y == 1)
				{
					count_plus(mine, out, ROW, LEF, x - 1, y, ret);
					count_plus(mine, out, ROW, LEF, x + 1, y, ret);
					count_plus(mine, out, ROW, LEF, x + 1, y + 1, ret);
					count_plus(mine, out, ROW, LEF, x, y + 1, ret);
					count_plus(mine, out, ROW, LEF, x - 1, y + 1, ret);
				}
				else if (y == lef)
				{
					count_plus(mine, out, ROW, LEF, x - 1, y, ret);
					count_plus(mine, out, ROW, LEF, x - 1, y - 1, ret);
					count_plus(mine, out, ROW, LEF, x, y - 1, ret);
					count_plus(mine, out, ROW, LEF, x + 1, y - 1, ret);
					count_plus(mine, out, ROW, LEF, x + 1, y, ret);
				}
				else if (x > 1 && x < row && y > 1 && y < lef)
				{
					count_plus(mine, out, ROW, LEF, x - 1, y, ret);
					count_plus(mine, out, ROW, LEF, x - 1, y - 1, ret);
					count_plus(mine, out, ROW, LEF, x, y - 1, ret);
					count_plus(mine, out, ROW, LEF, x + 1, y - 1, ret);
					count_plus(mine, out, ROW, LEF, x + 1, y, ret);
					count_plus(mine, out, ROW, LEF, x + 1, y + 1, ret);
					count_plus(mine, out, ROW, LEF, x, y + 1, ret);
					count_plus(mine, out, ROW, LEF, x - 1, y + 1, ret);
				}
			}
	}
	
}


void Find_mines(char mine[ROWS][LEFS], char out[ROWS][LEFS], int row, int lef, int count)
{
	int x = 0;
	int y = 0;

	
	do
	{
		while (1)
		{
			printf("ÇëÊäÈë×ø±ê:\n");
			scanf("%d%d", &x, &y);
			if (x > 0 && x <= row && y > 0 && y <= lef)
			{
				break;
			}
			else
			{
				printf("ÊäÈë¸ñÊ½´íÎó,ÇëÖØÐÂÊäÈë!\n");
			}
		}
		if (mine[x][y] == '1')
		{
			printf("Äã²ÈÀ×¸ÁÁË!!!\n");
			out[x][y] = '*';
			print(out, ROW, LEF);
			break;
		}
		else
		{
			int ret = 0;
			count_plus(mine, out, ROW, LEF, x, y, ret);
			print(out, ROW, LEF);
			int i = 0;
			int j = 0;
			count = 1;
			for (i = 1; i <= row; i++)
			{
				for (j = 1; j <= lef; j++)
				{
					if (out[i][j] == '#')
						count++;
				}
			}
		}
	} while (count != 11);
	if (count == 11)
	{
		printf("¹§Ï²ÄãÓ®ÁË!!!!!\n");
		
	}
	
}