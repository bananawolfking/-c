#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void meun(int n)//��ʼ����
{
	printf("************************************\n");
	printf("********  1:play   0.:exit  *********\n");
	printf("************************************\n");
	printf("��ѡ��>\n");
}
//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |    
void print_chessboard(char chessboard[ROW][LEF],int row, int lef)//��ӡ����
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


void initialize( char chessboard[ROW][LEF],int row,int lef)//��ʼ������
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


void playgame(char chessboard[ROW][LEF], int row, int lef)//�������
{
	int x = 1;
	int y = 1;
	
	while (1)
	{
		printf("��������壬д���꣺\n");
		scanf("%d%d", &x, &y);
		if (chessboard[x - 1][y - 1] == ' ' && x >= 1 && x<= row && y >= 1 && y <= lef)
		{
			chessboard[x - 1][y - 1] = '*'; 
			break;
		}
		else
			printf("�����ʽ��������������\n");
	}
}



void computergame(char chessboard[ROW][LEF], int row, int lef, int j)//�����������
{
	int x = 1;
	int y = 1;
	printf("�������壺\n");
	
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

int computer(char chessboard[ROW][LEF], int x, int y,int j)//�ж��Ƿ���������λ������
{
	if (chessboard[x][y] == ' ' && j == 0)
	{
		chessboard[x][y] = '#';
		return 1;
	}
	return j;
}

int computer_centre(char chessboard[ROW][LEF], int row, int lef, int j)//�������м�����
{
	if (chessboard[1][1] == ' ')
	{
		chessboard[1][1] = '#';
		j++;
	}
	return j;
}


int computer_corner(char chessboard[ROW][LEF], int row, int lef, int j)//ֻ�ڽ����������
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

int computer_corner22(char chessboard[ROW][LEF], int row, int lef, int j)//ֻ�ڽ����������!22
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

int computer_corner02(char chessboard[ROW][LEF], int row, int lef, int j)//ֻ�ڽ����������!02
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

int computer_sxzy(char chessboard[ROW][LEF], int row, int lef, int j)//ֻ�����������������
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



void du_king(char chessboard[ROW][LEF], int row, int lef, int n, int m)//Ӯ��->����->�����м�����->�ڽ�������->�������
{
	int i = 0;
	int j = 0;
	if (m >= 2)
	{
		for (i = 0; i < row; i++)//ͬһ���Ƿ�����ͬ��
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
		for (i = 0; i < lef; i++)//ͬһ���Ƿ�����ͬ��
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
		if (chessboard[0][0] == chessboard[1][1] && chessboard[0][0] == '#')//б�ߵ��Ƿ���ͬ
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
		for (i = 0; i < row; i++)//ͬһ���Ƿ�����ͬ��
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
		for (i = 0; i < lef; i++)//ͬһ���Ƿ�����ͬ��
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
		if (chessboard[0][0] == chessboard[1][1] && chessboard[0][0] == '*')//б�ߵ��Ƿ���ͬ
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
		j = computer_centre(chessboard, row, lef, j);//�м�����
	}
	if (j == 0)
	{
		j = computer_corner(chessboard, row, lef, j);//��������
	}
	if (j == 0)
	{
		computergame(chessboard, row, lef,j);//���
	}
}

int changexy(char chessboard[ROW][LEF], int row, int lef, int ch)//��ת����
{
	int x = 0;
	int y = 0;
	char o = '@';
	if (ch == 1)//�����L�J 2��ʾ��ת��һ�� 1��ʾ��ת����
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
    else if (ch == 3)//�����I�K 4��ʾ��ת��һ�� 3��ʾ��ת����
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
	else if (ch == 5)//������ת���� 6�����Ѿ����·�ת�� 5����Ҫ���·�ת
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
    else if (ch == 7)//������ת 7��ʾҪ��ת 8��ʾ��ת��
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







int changechess(char chessboard[ROW][LEF], int row, int lef, int n, int ret, int m,int chi)//���Ʒ�ת����
{
	int ch = 0;
	if (n == 1)
	{
		if (chessboard[0][2] == '*')
		{
			ch = 7;
			chi = changexy(chessboard, row, lef, ch);//��ת����
			return chi;
		}
		else if (chessboard[2][0] == '*')
		{
			ch = 5;
			chi = changexy(chessboard, row, lef, ch);//��ת����
			return chi;
		}
		else if (chessboard[2][2] == '*')
		{
			ch = 3;
			chi = changexy(chessboard, row, lef, ch);//��ת����
			return chi;
		}
		else if (chessboard[0][1] == '*')
		{
			ch = 1;
			chi = changexy(chessboard, row, lef, ch);//��ת����
			return chi;
		}
		else if (chessboard[2][1] == '*')
		{
			ch = 3;
			chi = changexy(chessboard, row, lef, ch);//��ת����
			return chi;
		}
		else if (chessboard[1][2] == '*')
		{
			ch = 7;
			chi = changexy(chessboard, row, lef, ch);//��ת����
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
			chi = changexy(chessboard, row, lef, ch);//��ת����
			return chi;
		}
		else if (chi == 2)
		{
			ch = 2;
			chi = changexy(chessboard, row, lef, ch);//��ת����
			return chi;
		}
		else if (chi == 3)
		{
			ch = 3;
			chi = changexy(chessboard, row, lef, ch);//��ת����
			return chi;
		}
		else if (chi == 4)
		{
			ch = 4;
			chi = changexy(chessboard, row, lef, ch);//��ת����
			return chi;
		}
		else if (chi == 5)
		{
			ch = 5;
			chi = changexy(chessboard, row, lef, ch);//��ת����
			return chi;
		}
		else if (chi == 6)
		{
			ch = 6;
			chi = changexy(chessboard, row, lef, ch);//��ת����
			return chi;
		}
		else if (chi == 7)
		{
			ch = 7;
			chi = changexy(chessboard, row, lef, ch);//��ת����
			return chi;
		}
		else if (chi == 8)
		{
			ch = 8;
			chi = changexy(chessboard, row, lef, ch);//��ת����
			return chi;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}

int computergameend(char chessboard[ROW][LEF], int row, int lef,int n,int ret ,int m)//�޵а� ret������һ����ô�߷���ֵ��Ҳ�ǽ���ֵ
{
	if (n == 1)//n�ж��µĵڼ�����
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
			j = computer_centre(chessboard, row, lef, j);//�м�����
			//chessboard[1][1] = '#';
			return 2;
		}
		else if (chessboard[1][0] == '*')
		{
			int j = 0;
			j = computer_centre(chessboard, row, lef, j);//�м�����
			//chessboard[1][1] = '#';
			return 3;
		}
	}
	if (n >= 2)//�ڶ�����
	{
		if (ret == 1)
		{
			du_king(chessboard, row, lef , n, m);
			return 1;//���¾���
		} 
		else if (ret == 2)
		{
			if (chessboard[2][2] == '*')
			{
				int j = 0;
				j = computer_sxzy(chessboard, row, lef, j);//ֻ�����������������
				return 1;//���¾���
			}
			else if (chessboard[0][2] == '*' || chessboard[2][0] == '*' || chessboard[0][1] == '*' || chessboard[1][0] == '*')
			{
				du_king(chessboard, row, lef, n, m);
				return 1;//���¾���
			}
			else if (chessboard[1][2] == '*')
			{
				chessboard[0][2] = '#';
				return 1;//���¾���
			}
			else if (chessboard[2][1] == '*')
			{
				chessboard[2][0] = '#';
				return 1;//���¾���
			}
		}
		else if (ret == 3)
		{
			if (chessboard[1][2] == '*')
			{
				du_king(chessboard, row, lef, n, m);
				return 1;//���¾���
			}
			else if (chessboard[0][0] == '*' || chessboard[2][0] == '*')
			{
				du_king(chessboard, row, lef, n, m);
				return 1;//���¾���
			}
			else if (chessboard[0][1] == '*' || chessboard[0][2] == '*')
			{
				int j = 0;
				j = computer_corner22(chessboard, row, lef, j); //�����������22
				return 1;
			}
			else if (chessboard[2][1] == '*' || chessboard[2][2] == '*')
			{
				int j = 0;
				j = computer_corner02(chessboard, row, lef, j); //�����������02
				return 1;
			}

		}
	
	}
}
//j = computer_corner22(chessboard, row, lef, j);�����������22
char draw(char chessboard[ROW][LEF], int row, int lef)//�ж��ǲ���ƽ��
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

char judgment(char chessboard[ROW][LEF], int row, int lef)//����
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

