#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


void game()
{
	
	
	char chessboard[ROW][LEF] = { 0 };
	initialize(chessboard, ROW, LEF);
	int ret = 0;//���������������ô��
	int n = 0;
	int m = 0;
	int chi = 0;//�������̷�ת�Ĺؼ���
	while (1)
	{
		n++;
		chi = changechess(chessboard, ROW, LEF, n, ret, m, chi);//���Ʒ�ת��������
		n--;
		print_chessboard(chessboard, ROW, LEF);//��ӡ����
		if (m > 2)
		{
			if ('A' == judgment(chessboard, ROW, LEF))//�ж�
			{

				printf("��ϲ���ʤ��,������\n");
				break;
			}
			else if ('B' == judgment(chessboard, ROW, LEF))
			{

				printf("����ɣ���ô��\n");
				break;
			}
			else if ('D' == judgment(chessboard, ROW, LEF))
			{

				printf("�����֣����Կ���\n");
				break;
			}
		}
		playgame(chessboard, ROW, LEF);//�������
		n++;
		print_chessboard(chessboard, ROW, LEF);//��ӡ����
		if (n > 2)
		{
			if ('A' == judgment(chessboard, ROW, LEF))//�ж�
			{
				
				printf("��ϲ���ʤ��,������\n");
				break;
			}
			else if ('B' == judgment(chessboard, ROW, LEF))
			{
				
				printf("����ɣ���ô��\n");
				break;
			}
			else if ('D' == judgment(chessboard, ROW, LEF))
			{
				
				printf("�����֣����Կ���\n");
				break;
			}
			else
			{
				printf("���ͣ�\n");
			}
		}
		chi = changechess(chessboard, ROW, LEF ,  n,  ret,  m,  chi);//���Ʒ�ת����
		//print_chessboard(chessboard, ROW, LEF);//��ӡ����
		Sleep(1000);
		//computergame(chessboard, ROW, LEF);//��������
		ret = computergameend(chessboard, ROW, LEF, n, ret, m);
		//print_chessboard(chessboard, ROW, LEF);//��ӡ����
		m++;
		
	}

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		
		meun(1);//��ʼ����
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			break;
		default:
			printf("�����������������");
			break;
		}
	} while (input);
	return 0;
}