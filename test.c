#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void meun()
{
	printf("******************************\n");
	printf("*******    1:play    *********\n");
	printf("*******    0:exit    *********\n");
	printf("******************************\n");
	printf("�����룺\n");
}

void game()
{
	char mine[ROWS][LEFS] = { 0 };
	char out[ROWS][LEFS] = { 0 };
	initialize(mine, ROWS, LEFS, '0');//��ʼ��
	initialize(out, ROWS, LEFS, '#');
	//print(mine, ROW, LEF);
	print(out, ROW, LEF);
	Lay_mines(mine, ROW, LEF, Easy_Count);//����
	//print(mine, ROW, LEF);
	Find_mines(mine, out, ROW, LEF, Easy_Count);//ɨ��
}


void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		
		meun();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�����ʽ�������������룡\n");
			break;
		}
	} while (input);


}




int main()
{
	test();
	return 0;
}